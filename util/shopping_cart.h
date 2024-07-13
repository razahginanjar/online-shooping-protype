#pragma once
#include "Category.h"

class shopping_cart : public Category::men_category, public Category::women_category, public Category::kids_category
{
public:
    void show_cart();
    void select_item(const char filename[]);
};
