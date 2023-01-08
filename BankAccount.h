//
// Created by abdelrahman wael on 1/8/2023.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H


#include <iostream>
#include "Client.h"

using namespace std;

class Client;

class BankAccount {
protected:
    double balance;
    Client *client;

public:
    explicit BankAccount();

    explicit BankAccount( const double &);

    virtual bool Deposit(const double &);

    virtual bool Withdraw(const double &);

    void set_client(Client *);

    Client & get_client();


    double get_balance();

    ~BankAccount();
};

#endif //UNTITLED1_BANKACCOUNT_H
