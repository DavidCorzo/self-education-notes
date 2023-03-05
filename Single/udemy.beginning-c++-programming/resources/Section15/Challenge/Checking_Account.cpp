#pragma once
#include <iostream>
#include "Checking_Account.h"

using namespace std;

Checking_Account::Checking_Account(std::string name, double balance) : 
    Account::Account(name, balance) {}

bool Checking_Account::withdraw(double amount) {
    if (balance - (amount + withdrawl_fee) < 0) {
        cout << "Now enough funds" << endl;
        return false;
    }
    balance -= withdrawl_fee;
    return Account::withdraw(amount);
}

