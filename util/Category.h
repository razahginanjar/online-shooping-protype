#pragma once
#include "stroe_item.hpp"

namespace Category
{
    class men_category : public virtual store_item
    {
    public:
        char show_more();
        void show_eastern();
        void show_western();
    };

    class women_category : public virtual store_item
    {
    public:
        char show_more();
        void show_eastern();
        void show_western();
    };
    class kids_category : public virtual store_item
    {
    public:
        char show_more();
        void show_girl();
        void show_boy();
    };

}