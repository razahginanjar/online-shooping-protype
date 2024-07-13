#include "Transaction.hpp"
#include <iostream>
#include <fstream>
#include <string>

void transaction::set_amount(int qty, double p)
{
    quantity = qty;
    price = p;
    total_amount += qty * p;
}

transaction transaction::operator*(const transaction& temp)
{
    transaction result;
    result.total_amount = this->quantity * this->price;
    return result;
}

void transaction::generate_bill()
{
    char item_code[6];
    std::string item_name;
    double item_price;
    int item_qty;
    transaction Customer_transaction;
    Customer_transaction.enter_details();
    std::cout << "\n\t\t---------------------------------------------------------------------------------------\n";
    std::cout << "\t\t\t\t\t\tINVOICE";
    std::cout << "\n\t\t---------------------------------------------------------------------------------------\n";
    Customer_transaction.display_details();
    std::cout << "\n\t\t---------------------------------------------------------------------------------------\n";

    std::cout << "\t\tItem name\tPrice\t\tQuantity" << std::endl;

    std::ifstream cart;
    cart.open("assets/customer_data/ShoppingCart.txt");

    double total_amount = 0;

    while (cart >> item_code >> item_name >> item_price >> item_qty)
    {
        std::cout << "\t\t" << item_name << "\t\t" << item_price << "\t\t" << item_qty << std::endl;
        set_amount(item_qty, item_price);
        total_amount += item_qty * item_price;
    }

    Pelanggan::Silver_Customer silverCustomer;
    Pelanggan::Golden_Customer goldenCustomer;
    Pelanggan::Diamond_Customer diamondCustomer;

    double discount = 0.0;

    if (total_amount >= 3000)
    {
        discount = diamondCustomer.applyDiscount_D(total_amount);
    }
    else if (total_amount >= 2500)
    {
        discount = goldenCustomer.applyDiscount_G(total_amount);
    }
    else if (total_amount >= 1500)
    {
        discount = silverCustomer.applyDiscount_S(total_amount);
    }

    double result = total_amount - discount;
    std::cout << "\n\t\tTotal balance due (before discount): " << total_amount;
    std::cout << "\n\t\tDiscount applied: " << discount;
    std::cout << "\n\t\tTotal balance due (after discount): " << result;
    std::cout << "\n\t\t---------------------------------------------------------------------------------------\n";
    print_time();
    cart.close();
    std::ofstream transactionRecord("assets/clothes_data/TransactionRecord.txt", std::ios::out | std::ios::app);
    cart.open("assets/customer_data/ShoppingCart.txt");

    while (cart >> item_code >> item_name >> item_price >> item_qty)
    {
        transactionRecord << item_code << "   " << item_name << "   " << item_price << "   " << item_qty << std::endl;
    }

    cart.close();
    transactionRecord.close();
    remove("assets/customer_data/ShoppingCart.txt");
}
void transaction::print_time()
{
    time_t t;
    time(&t);
    char str[26];
    printf("\t\t%s", ctime_s(str, sizeof(str), &t));
}