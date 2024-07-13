#include "Customer.hpp"
#include <iostream>

void Pelanggan::Customer::enter_details()
{
    int i = 0, temp = 0, check = 0;
    std::cout << "\nPlease enter your details below: \n";

    while (1)
    {
        std::cout << "\nFull name: ";
        std::cin >> full_name;

        for (i = 0; i < strlen(full_name); i++)
        {
            if (toupper(full_name[i]) >= 65 && toupper(full_name[i]) <= 90 || full_name[i] == 32)
            {
                check = 1;
                continue;
            }
            else
            {
                check = 0;
                break;
            }
        }

        if (check == 1 && (i == strlen(full_name)))
            break;
        if (check == 0)
            std::cout << "\nInvalid name. Please enter again.";
    }

    while (1)
    {
        std::cout << "\nPhone number: ";
        std::cin >> phone_number;
        for (i = 0; i < strlen(phone_number); i++)
        {
            if ((phone_number[i] - 48 >= 0 && phone_number[i] - 48 <= 9) && strlen(phone_number) <= 11)
            {
                temp = 1;
                continue;
            }
            else
            {
                temp = 0;
                break;
            }
        }
        if (temp == 1 && (i == strlen(phone_number)) && strlen(phone_number) >= 8)
        {
            break;
        }
        else
            std::cout << "\nInvalid phone number. Please enter again.";
    }
    std::cout << "\nHome address: ";
    std::cin >> home_address;
    std::cout << "\nEmail: ";
    std::cin >> email_address;
}

void Pelanggan::Customer::display_details()
{
    std::cout << "\n\t\tName:              " << full_name;
    std::cout << "\n\t\tContact Number:    " << phone_number;
    std::cout << "\n\t\tEmail address:     " << email_address;
}

double Pelanggan::Silver_Customer::applyDiscount_S(double totalAmount)
{
    if (totalAmount >= 1500 && totalAmount < 2500) { return 0.1 * totalAmount; }
    else{ return 0.0; }
}

double Pelanggan::Golden_Customer::applyDiscount_G(double totalAmount)
{
    if (totalAmount >= 2500 && totalAmount < 3000) { return 0.25 * totalAmount; }
    else { return 0.0; }
}

double Pelanggan::Diamond_Customer::applyDiscount_D(double totalAmount)
{
    if (totalAmount >= 3000) { return 0.3 * totalAmount; }
    else { return 0.0; }
}
