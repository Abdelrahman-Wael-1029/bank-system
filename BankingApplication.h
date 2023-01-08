#ifndef BANKINGAPPLICATION_H
#define BANKINGAPPLICATION_H

#include <iostream>
#include <vector>

#define endl '\n'

#include "Client.h"
#include "SavingsBankAccount.h"
using namespace std;

class BankApplication
{
public:
    explicit BankApplication() = default;
    vector<Client *>clients;

    bool add_client();
    bool Withdraw();
    bool Deposit();
    void run();
};

#endif
