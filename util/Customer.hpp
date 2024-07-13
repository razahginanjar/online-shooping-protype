#pragma once
#include <string>

namespace Pelanggan
{
    class Customer
    {
    private:
        char home_address[200];
        char phone_number[12];
        std::string email_address;

    public:
        char full_name[30];
        void enter_details();
        void display_details();
    };

    class Silver_Customer : public Customer
    {
    public:
        double applyDiscount_S(double totalAmount);
    };

    class Golden_Customer : public Customer
    {
    public:
        double applyDiscount_G(double totalAmount);
    };

    class Diamond_Customer : public Customer
    {
    public:
        double applyDiscount_D(double totalAmount);
    };

}
