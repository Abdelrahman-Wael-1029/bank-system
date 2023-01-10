#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "BankAccount.h"

using namespace std;

class BankAccount;

using namespace std;
class Client {
    string name, phone, address, password, id;
    BankAccount *bank;
public:
    static int number_client;

    explicit Client();

    explicit Client(const string &, const string &, const string &, const string &, const string &);

    void info();

    void set_bank(BankAccount *);

    BankAccount& get_bank();

    string get_id();

    string get_password();

    ~Client();
};


#endif