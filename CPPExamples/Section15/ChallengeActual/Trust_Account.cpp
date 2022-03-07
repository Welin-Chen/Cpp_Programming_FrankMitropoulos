#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Saving_Account{name, balance, int_rate}, num_withdraw{0}
{
}

bool Trust_Account ::deposit(double amount)
{
    if (amount >= bonus_threshold)
        amount += bonus_amount;
    return Saving_Account::deposit(amount);
}

bool Trust_Account ::withdraw(double amount)
{
    if (num_withdraw >= max_withdraw || (amount > balance * max_withdraw_percent))
        return false;
    else
    {
        num_withdraw++;
        return Saving_Account::withdraw(amount);
    }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account)
{
    os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%, withdrawals: " << account.num_withdraw << "]";
    return os;
}
