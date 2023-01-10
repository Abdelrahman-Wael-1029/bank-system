#ifndef BANKINGAPPLICATION_H
#define BANKINGAPPLICATION_H

#include <iostream>
#include <vector>
#include <regex>
#include <set>
#include <fstream>

#define endl '\n'

#include "Client.h"
#include "SavingsBankAccount.h"
using namespace std;

class BankApplication
{
    bool valid_name(const string &);
    bool valid_phone(const string &);
    bool valid_password(const string &);
    set<string> password;
public:
    explicit BankApplication() = default;
    vector<Client *>clients;

    bool add_client();
    void Withdraw();
    void Deposit();
    void run();
};

#endif
