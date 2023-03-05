#pragma once
#include <iostream>
#include "Account.h"

using namespace std;

class Checking_Account : public Account {
private:

protected:
    float const withdrawl_fee {1.50};
public:
    Checking_Account(std::string name = "unnamed", double balance = 0.0);
    bool deposit(double amount);
    bool withdraw(double amount);
};


