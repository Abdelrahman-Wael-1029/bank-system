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
    vector<Client *> clients;

public:
    explicit BankApplication() = default;

    bool add_client();
    void Withdraw();
    void Deposit();
    void run();
    ~BankApplication();
};

#endif
