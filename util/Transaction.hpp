#pragma once
#include "Customer.hpp"
#include <ctime>

class transaction : public Pelanggan::Customer
{
private:
    double total_amount = 0;
    int quantity = 0;
    double price = 0;

public:
    void set_amount(int qty, double p);
    transaction operator*(const transaction& temp);
    void generate_bill();
    void print_time();
};


