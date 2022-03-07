#include <iostream>
#include "Saving_Account.h"

Saving_Account::Saving_Account()
    : Saving_Account{0, 0}
{
}

Saving_Account::Saving_Account(double balance, double int_rate)
    : Account(balance), int_rate{int_rate}
{
}
Saving_Account::~Saving_Account()
{
}

void Saving_Account::deposit(double amount)
{
    amount = amount + amount * int_rate / 100;
    Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Saving_Account &account)
{
    os << "Saving account balance: " << account.balance << " Interest rate: " << account.int_rate;
    return os;
}