#include "Client.h"

void Client::info() {
    cout << "--------------" << name << "--------------" << endl <<
         "id: " << id << endl <<
         "address: " << address << endl <<
         "phone: " << phone << endl <<
         "balance: " << bank->get_balance() << endl;
    cout << endl;
}

void Client::set_bank(BankAccount *new_bank) {
    bank = new_bank;
}

Client::Client(const string &name, const string &phone, const string &id, const string &address,
               const string &password) : name(name), phone(phone), id(id), address(address),
                                                            password(password){}

BankAccount &Client::get_bank() {
    return *bank;
}

Client::~Client() {
    delete bank;
}

Client::Client() : bank(nullptr) {
}

string Client::get_id() {
    return id;
}

string Client::get_password() {
    return password;
}
