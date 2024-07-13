#include "stroe_item.hpp"
#include "Category.h"
#include "shopping_cart.h"
#include <iostream>

void store_item::order_item(void)
{
    shopping_cart cart;
    char type;
    do
    {
        type = show_more();
        if (type == 'M' || type == 'm')
        {
            Category::men_category men;
            do
            {
                type = men.show_more();
                if (type == 'E' || type == 'e')
                {
                    men.show_eastern();
                    cart.select_item("assets/clothes_data/MenEasternItems.txt");
                }
                else if (type == 'W' || type == 'w')
                {
                    men.show_western();
                    cart.select_item("assets/clothes_data/MenWesternItems.txt");
                }
                else
                {
                    std::cout << "\nInvalid Choice! Please enter correct choice";
                }

            } while (!(type == 'E' || type == 'e' || type == 'W' || type == 'w'));
        }
        else if (type == 'W' || type == 'w')
        {
            Category::women_category women;
            do
            {
                type = women.show_more();
                if (type == 'E' || type == 'e')
                {
                    women.show_eastern();
                    cart.select_item("assets/clothes_data/WomenEasternItems.txt");
                }
                else if (type == 'W' || type == 'w')
                {
                    women.show_western();
                    cart.select_item("assets/clothes_data/WomenWesternItems.txt");
                }
                else
                {
                    std::cout << "\nInvalid Choice! Please enter correct choice";
                }

            } while (!(type == 'E' || type == 'e' || type == 'W' || type == 'w'));
        }
        else if (type == 'K' || type == 'k')
        {
            Category::kids_category k;
            do
            {
                type = k.show_more();
                if (type == 'G' || type == 'g')
                {
                    k.show_girl();
                    cart.select_item("assets/clothes_data/KidsGirlItems.txt");
                }
                else if (type == 'B' || type == 'b')
                {
                    k.show_boy();
                    cart.select_item("assets/clothes_data/KidsBoyItems.txt");
                }
                else
                {
                    std::cout << "\nInvalid Choice! Please enter correct choice";
                }

            } while (!(type == 'G' || type == 'B' || type == 'b' || type == 'g'));
        }
        else
        {
            std::cout << "\nInvalid Choice! Please enter correct choice";
        }

    } while (!(type == 'M' || type == 'm' || type == 'W' || type == 'w'));
}

char store_item::show_more()
{
    char type;
    std::cout << "\n\tW >>> Women";
    std::cout << "\n\tM >>> Men";
    std::cout << "\n\tK >>> Kids";
    std::cout << "\n\n\tEnter type: ";
    std::cin >> type;
    return type;
}