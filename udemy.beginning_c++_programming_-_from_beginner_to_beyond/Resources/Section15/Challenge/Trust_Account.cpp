#pragma once
#include <iostream>
#include "Trust_Account.h"

using namespace std;

Trust_Account::Trust_Account(std::string name, double balance) : {}

bool Trust_Account::deposit(double amount) {
    if (times_withdrawn > 3) {
        cout << "Times withdrawn are greater than 3" << endl;
        return false;
    }
    if (amount >= 5000.00) {
        amount += 50.00;
    }
    Savings_Account::deposit(amount);
    return true;
}