#include "Category.h"
#include <fstream>
#include <iostream>

char Category::kids_category::show_more()
{
    char type;
    std::cout << "\nG>>>> Girl\n";
    std::cout << " B>>>> boy\n";
    std::cout << "\n\nEnter type: ";
    std::cin >> type;
    return type;
}
void Category::kids_category::show_girl()
{
    std::ifstream infile("assets/clothes_data/KidsGirlItems.txt");
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    std::cout << "\n                                  Quantity (Sizes)";
    std::cout << "\nCode   Names\t\tSmall   Medium   Large\n";
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    while (infile >> product_code >> product_name >> small_size >> medium_size >> large_size >> item_price)
    {
        std::cout << product_code << "   " << product_name << "\t\t" << small_size << "    " << medium_size << "    " << large_size << "   " << item_price << std::endl;
    }
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    infile.close();
}
void Category::kids_category::show_boy()
{
    std::ifstream infile("assets/clothes_data/KidsBoyItems.txt");
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    std::cout << "\n                                  Quantity (Sizes)";
    std::cout << "\nCode   Names\t\tSmall   Medium   Large\n";
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    while (infile >> product_code >> product_name >> small_size >> medium_size >> large_size >> item_price)
    {
        std::cout << product_code << "   " << product_name << "\t\t" << small_size << "    " << medium_size << "    " << large_size << "   " << item_price << std::endl;
    }
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    infile.close();
}
char Category::women_category::show_more()
{
    char type;
    std::cout << "\n E >>>> Eastern\n";
    std::cout << " W >>>> Western\n";
    std::cout << "\n\nEnter type: ";
    std::cin >> type;
    return type;
}

void Category::women_category::show_eastern()
{
    std::ifstream infile("assets/clothes_data/WomenEasternItems.txt");
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    std::cout << "\n                                  Quantity (Sizes)";
    std::cout << "\nCode   Names\t\tSmall   Medium   Large\n";
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    while (infile >> product_code >> product_name >> small_size >> medium_size >> large_size >> item_price)
    {
        std::cout << product_code << "   " << product_name << "\t\t" << small_size << "    " << medium_size << "    " << large_size << "   " << item_price << std::endl;
    }
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    infile.close();
}

void Category::women_category::show_western()
{
    std::ifstream infile("assets/clothes_data/WomenWesternItems.txt");
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    std::cout << "\n                                  Quantity (Sizes)";
    std::cout << "\nCode   Names\t\tSmall   Medium   Large\n";
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    while (infile >> product_code >> product_name >> small_size >> medium_size >> large_size >> item_price)
    {
        std::cout << product_code << "   " << product_name << "\t\t" << small_size << "   " << medium_size << "   " << large_size << "   " << item_price << std::endl;
    }
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    infile.close();
}

char Category::men_category::show_more()
{
    char type;
    std::cout << "\n E >>>> Eastern\n";
    std::cout << " W >>>> Western\n";
    std::cout << "\n\nEnter type: ";
    std::cin >> type;
    return type;
}

void Category::men_category::show_eastern()
{
    std::ifstream infile("assets/clothes_data/MenEasternItems.txt");
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    std::cout << "\n                                  Quantity (Sizes)";
    std::cout << "\nCode   Names\t\tSmall   Medium   Large\n";
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    while (infile >> product_code >> product_name >> small_size >> medium_size >> large_size >> item_price)
    {
        std::cout << product_code << "   " << product_name << "\t\t" << small_size << "   " << medium_size << "   " << large_size << "   " << item_price << std::endl;
    }
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    infile.close();
}

void Category::men_category::show_western()
{
    std::ifstream infile("assets/clothes_data/MenWesternItems.txt");
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    std::cout << "\n                                  Quantity (Sizes)";
    std::cout << "\nCode   Names\t\tSmall   Medium   Large\n";
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    while (infile >> product_code >> product_name >> small_size >> medium_size >> large_size >> item_price)
    {
        std::cout << product_code << "   " << product_name << "\t\t" << small_size << "   " << medium_size << "   " << large_size << "   " << item_price << std::endl;
    }
    std::cout << "\n---------------------------------------------------------------------------------------\n";
    infile.close();
}
