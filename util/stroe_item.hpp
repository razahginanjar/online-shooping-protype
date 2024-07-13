#pragma once
#include <string>

class store_item
{
protected:
    char product_code[6];
    std::string product_name;
    int small_size;
    int medium_size;
    int large_size;
    double item_price;

public:
    char show_more();
    void order_item(void);
};