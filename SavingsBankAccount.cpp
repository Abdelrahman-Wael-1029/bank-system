
#include "SavingsBankAccount.h"

SavingsBankAccount::SavingsBankAccount(const double &amount) : BankAccount(amount) {
    balance = amount;
}

bool SavingsBankAccount::Deposit(const double &amount) {

    if (amount < 1000)
        return false;
//    balance += amount;
    BankAccount::Deposit(amount);
    return true;
}

bool SavingsBankAccount::Withdraw(const double &amount) {
    if(balance - amount < 1000)
        return false;
//    balance -= amount;
    BankAccount::Withdraw(amount);
    return true;
}
