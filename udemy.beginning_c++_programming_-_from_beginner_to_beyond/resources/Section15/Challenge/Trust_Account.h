#pragma once
#include <iostream>
#include "Savings_Account.h"

using namespace std;

class Trust_Account : public Savings_Account {
private:
    uint16_t times_withdrawn {0};
public:
    Trust_Account(std::string name, double balance);
    bool deposit(double amount);
};