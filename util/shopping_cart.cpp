#include "shopping_cart.h"
#include "Transaction.hpp"
#include "util.h"
#include <fstream>
#include <iostream>

void shopping_cart::select_item(const char filename[])
{
    char option[6], sizes, answer;
    int temp = 0, quantity = 0;
    std::ifstream infile;
    std::ofstream updated_file, cart_file;
    updated_file.open("assets/customer_data/temp.txt");
    cart_file.open("assets/customer_data/ShoppingCart.txt", std::ios::out | std::ios::app);

    do
    {
        std::cout << "\nEnter code to select: ";
        std::cin >> option;
        infile.open(filename);

        while (infile >> product_code >> product_name >> small_size >> medium_size >> large_size >> item_price)
        {
            if (strcmp(option, product_code) == 0)
            {
                temp = 0;
                break;
            }
            else
                temp = 1;
        }

        if (temp == 1)
        {
            std::cout << "\nInvalid code entered! Please enter correct code";
            infile.close();
        }

        infile.close();
    } while (temp == 1);

    infile.open(filename);

    std::cout << "\nS >>> Small\n";
    std::cout << "\nM >>> Medium\n";
    std::cout << "\nL >>> Large\n";

    std::cout << "\nEnter Size: ";
    std::cin >> sizes;
    while (!(sizes == 'S' || sizes == 's' || sizes == 'M' || sizes == 'm' || sizes == 'L' || sizes == 'l'))
    {
        std::cout << "Invalid choice .... Please enter again: ";
        std::cin >> sizes;
    }

    std::cout << "\n\nEnter Quantity: ";
    std::cin >> quantity;

    while (infile >> product_code >> product_name >> small_size >> medium_size >> large_size >> item_price)
    {
        if (strcmp(option, product_code) == 0)
        {
            if (((sizes == 'S' || sizes == 's') && small_size < quantity) ||
                ((sizes == 'M' || sizes == 'm') && medium_size < quantity) ||
                ((sizes == 'L' || sizes == 'l') && large_size < quantity))
            {
                std::cout << "\n\nSorry for inconvenience. This item is out of stock for your required size and quantity.";
                updated_file.close();
                remove("assets/customer_data/temp.txt");
                cart_file.close();
                infile.close();
                continue;
            }
            else
            {
                if (sizes == 'S' || sizes == 's')
                {
                    small_size = small_size - quantity;
                }
                else if (sizes == 'M' || sizes == 'm')
                {
                    medium_size = medium_size - quantity;
                }
                else if (sizes == 'L' || sizes == 'l')
                {
                    large_size = large_size - quantity;
                }
            }
            cart_file << product_code << "   " << product_name << "   " << item_price << "   " << quantity << std::endl;
            std::cout << std::endl
                << product_code << "\t\t" << product_name << "\t\t" << item_price << "\t\t" << quantity << std::endl;
        }
        updated_file << product_code << "   " << product_name << "   " << small_size << "   " << medium_size << "   " << large_size << "   " << item_price << std::endl;
    }
    infile.close();
    cart_file.close();
    updated_file.close();
    remove(filename);
    rename("assets/customer_data/temp.txt", filename);

    std::cout << "\nDo you want to buy anything else?(y/n)";
    std::cin >> answer;
    if (answer == 'y')
    {
        order_item();
    }
    else
    {
        show_cart();
    }
}

void shopping_cart::show_cart()
{
    Application app;
    int quantity = 0;
    std::ifstream cart_file("assets/customer_data/ShoppingCart.txt");
    std::cout << "\n\t\t\t\t\t\tYour Cart";
    std::cout << "\n\t\t---------------------------------------------------------------------------------------\n";
    std::cout << "\n\t\t\tCode   Names\t\t\tPrice\t\tQuantity\n";
    std::cout << "\n\t\t---------------------------------------------------------------------------------------\n";
    while (cart_file >> product_code >> product_name >> item_price >> quantity)
    {
        std::cout << "\t\t\t" << product_code << "   " << product_name << "\t\t\t" << item_price << "\t\t" << quantity << std::endl;
    }
    std::cout << "\n\t\t---------------------------------------------------------------------------------------\n";
    cart_file.close();
    // Display the bill
    transaction transaction_obj;
    transaction_obj.generate_bill();
    char q;
    std::cout << "Press 1 to go to main menu: " << std::endl;
    std::cout << "Press 2 to exit :" << std::endl;
    std::cin >> q;
    switch (q)
    {
    case '1':
    {
        app.main_page();
        break;
    }
    case '2':
    {
        exit(0);
    }
    default:
        std::cout << "Enter right option " << std::endl;
    }
}