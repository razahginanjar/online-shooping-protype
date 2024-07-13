#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "stroe_item.hpp"

class Application
{
public:
    bool admin_login()
    {
        std::string admin_email = "username@gmail.com";
        std::string admin_password = "password";

        std::string entered_email, entered_password;

        std::cout << "Enter Admin Email: ";
        std::cin >> entered_email;

        std::cout << "Enter Admin Password: ";
        std::cin >> entered_password;

        return (entered_email == admin_email && entered_password == admin_password);
    }

    void show_transaction_records()
    {
        std::ifstream transactionRecord("TransactionRecord.txt");
        char c, q;
        std::cout << "Press 1 to see all transactions: " << std::endl;
        std::cout << "Press 2 to see transaction of specific Id :" << std::endl;
        std::cin >> c;
        if (c == '1')
        {
            std::cout << "\n\t\t\t\t\tTransaction Records";
            std::cout << "\n\t\t---------------------------------------------------------------------------------------\n";
            std::cout << "\n\t\t\tCode   Names\tPrice\tQuantity\n";
            std::cout << "\n\t\t---------------------------------------------------------------------------------------\n";
            std::string line;
            while (getline(transactionRecord, line))
            {
                std::cout << "\t\t\t" << line << std::endl;
            }

            std::cout << "\n\t\t---------------------------------------------------------------------------------------\n";
            transactionRecord.close();
            std::cout << "Press 1 to go to main menu: " << std::endl;
            std::cout << "Press 2 to exit :" << std::endl;
            std::cin >> q;
            switch (q)
            {
            case '1':
            {
                main_page();
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
        else if (c == '2')
        {
            char c;
            std::string productCode;
            std::cout << "Enter product code to display details: ";
            std::cin >> productCode;
            bool found = false;
            std::string product_code, product_name;
            double item_price;
            int quantity;

            std::ifstream cart_file("TransactionRecord.txt");
            while (cart_file >> product_code >> product_name >> item_price >> quantity)
            {
                if (product_code == productCode)
                {
                    found = true;
                    std::cout << "\n\t\t\t" << product_code << "   " << product_name << "\t" << item_price << "\t" << quantity << std::endl;
                }
            }

            cart_file.close();

            if (!found)
            {
                std::cout << "\nProduct with code " << productCode << " not found in the transaction records.\n";
                show_transaction_records();
            }
        }
        else
        {
            std::cout << "Enter right choice: " << std::endl;
        }
        std::cout << "Press 1 to go to main menu: " << std::endl;
        std::cout << "Press 2 to exit :" << std::endl;
        std::cin >> q;
        switch (q)
        {
        case '1':
        {
            main_page();
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

    void admin_login_menu()
    {
        char admin_choice;
        if (admin_login())
        {

            std::cout << "\n\t\t _________________________________________________________________\n";
            std::cout << "\t\t|                         ADMIN MENU                                |\n";
            std::cout << "\t\t|___________________________________________________________________|\n\n";
            std::cout << "\t\t| Press 1 to view transaction records                              |\n";
            std::cout << "\t\t| Press 2 to go back to the main menu                              |\n";
            std::cout << "\n\t\tPlease enter your choice:";
            std::cin >> admin_choice;

            switch (admin_choice)
            {
            case '1':
                show_transaction_records();
                break;

            case '2':
                main_page();
                break;

            default:
                std::cout << "Please select from the options given above.\n";
            }
        }
        else
        {
            std::cout << "Enter right username or password" << std::endl;
        }
    }

    void main_menu()
    {
        char choice;

        std::cout << "\t\t\t _________________________________________________________________\n";
        std::cout << "\t\t\t|                    WELCOME TO LOGIN PAGE                        |\n";
        std::cout << "\t\t\t|                                                                 |\n";
        std::cout << "\t\t\t|______________________      MENU        _________________________|\n\n\n";
        std::cout << "\t| Press 1 to login                  |" << std::endl;
        std::cout << "\t| Press 2 to registration           |" << std::endl;
        std::cout << "\t| Press 3 if you forget password    |" << std::endl;
        std::cout << "\t| Press 4 to exit                   |" << std::endl;
        std::cout << "\n\t\tPlease enter your choice:";
        std::cin >> choice;
        switch (choice)
        {
        case '1':
            login();
            break;
        case '2':
            registration();
            break;
        case '3':
            forget();
            break;
        case '4':
            std::cout << "\t\t\t Thank you!\n\n";
            exit(0);
        default:
            system("cls");
            std::cout << "Please select from the options given above\n";
            main_menu();
        }
    }

    void registration()
    {
        std::string username, password;
        system("cls");
        std::cout << "\t\t\tEnter username:" << std::endl;
        std::cin >> username;
        std::cout << "\t\t\tEnter password:" << std::endl;
        std::cin >> password;

        std::ofstream out("data.txt", std::ios::app);
        out << username << " " << password << std::endl;
        system("cls");
        std::cout << "Registration is successful" << std::endl;
        main_menu();
    }

    void login(void)
    {
        store_item store;
        int count = 0;
        std::string username, password, stored_username, stored_password;
        system("cls");
        std::cout << "\t\tPlease enter username and password:" << std::endl;
        std::cout << "\t\t  USERNAME:  " << std::endl;
        std::cin >> username;
        std::cout << "\t\t   PASSWORD:  " << std::endl;
        std::cin >> password;

        std::ifstream in("data.txt");

        while (in >> stored_username >> stored_password)
        {
            if (stored_username == username && stored_password == password)
            {
                count = 1;
                system("cls");
                break;
            }
        }

        in.close();
        system("cls");
        if (count == 1)
        {
            std::cout << username << "\n Your login is successful \n Thanks for logging in! \n"
                << std::endl;

            std::cout << "\t\t\t _________________________________________________________________\n";
            std::cout << "\t\t\t|                WELCOME TO ONLINE SHOPPING                       |\n";
            std::cout << "\t\t\t|                                                                 |\n";
            std::cout << "\t\t\t|______________________      MENU        _________________________|\n\n\n";

            store.order_item();
        }
        else
        {
            std::cout << "Login error! \n Please check your username and password\n";
            main_menu();
        }
    }

    void forget()
    {
        char option;
        std::cout << "\t\t Forgot your password? No worries" << std::endl;
        std::cout << " Press 1 to search your Id by name" << std::endl;
        std::cout << " Press 2 to go to the main menu" << std::endl;
        std::cout << "\t\t Enter your choice " << std::endl;
        std::cin >> option;

        switch (option)
        {
        case '1':
            search();
            break;
        case '2':
            main_menu();
            break;
        default:
            std::cout << "Invalid option. Please enter 1 or 2." << std::endl;
            forget();
        }
    }

    void search()
    {
        int option;
        std::string search_name, stored_username, stored_password, name;

        std::cout << "Enter your name: ";
        std::cin >> search_name;

        std::ifstream in("data.txt");

        while (in >> stored_username >> stored_password)
        {
            if (stored_username == search_name)
            {
                name = stored_username;
                break;
            }
        }
        in.close();
        if (name == search_name)
        {
            std::cout << "Your Id is: " << name << "\n Enter 3 to go to main menu: ";
            std::cin >> option;
            if (option == 3)
            {
                main_menu();
            }
            else
            {
                std::cout << "Invalid option. Please enter 3." << std::endl;
                search();
            }
        }
        else
        {
            std::cout << "Name not found. Please try again." << std::endl;
            search();
        }
    }

    void main_page()
    {
        while (true)
        {
            char c;
            system("cls");
            std::cout << "\t\t\t _________________________________________________________________\n";
            std::cout << "\t\t\t|                    WELCOME TO LOGIN PAGE                        |\n";
            std::cout << "\t\t\t|                                                                 |\n";
            std::cout << "\t\t\t|______________________      MENU        _________________________|\n\n\n";
            std::cout << "\t| Enter 1 for user:       |" << std::endl;
            std::cout << "\t| Enter 2 for admin       |" << std::endl;
            std::cin >> c;
            if (c == '1')
            {
                main_menu();
            }
            else if (c == '2')
            {
                admin_login_menu();
            }
            else
            {
                std::cout << "Invalid input. Please enter 1 or 2.\n";
                std::cout << "Continue? (y/n)";
                char answer{};
                std::cin >> answer;
                if (answer == 'N' || answer == 'n')
                {
                    break;
                }
            }
        }
    }
};
//
//void login(void);
//void registration();
//void forget();
//void search();
//void main_menu();
//void main_page();
//void admin_login_menu();


