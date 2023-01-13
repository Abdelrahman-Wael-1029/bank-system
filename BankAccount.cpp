
#include "BankAccount.h"

BankAccount::BankAccount(const double &balance) : balance(balance){}

void BankAccount::set_client(Client *client1) {
    client = client1;
}

Client &BankAccount::get_client() {
    return *client;
}

double BankAccount::get_balance() {
    return balance;
}

bool BankAccount::Deposit(const double &amount) {
    balance += amount;
    return true;

}

bool BankAccount::Withdraw(const double &amount) {
    if (amount > balance) {
        return false;
    }
    balance -= amount;
    return true;
}

BankAccount::~BankAccount() = default;

BankAccount::BankAccount() :client(nullptr), balance(0){
}


