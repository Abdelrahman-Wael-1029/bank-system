#ifndef SABINGSBANKACCOUNT_H
#define SABINGSBANKACCOUNT_H

#include <iostream>
#include "BankAccount.h"

using namespace std;

class SavingsBankAccount : public BankAccount {
    int mini_amount = 1000;

public:
    explicit SavingsBankAccount() = default;

    explicit SavingsBankAccount(const double &);

    bool Deposit(const double &amount) override ;

    bool Withdraw(const double &) override ;

};
#endif