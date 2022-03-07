#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Saving_Account.h"

class Trust_Account : public Saving_Account
{
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);

private:
    static constexpr const char *def_name = "Unamed Trust Account";
    static constexpr const double def_balance = 0;
    static constexpr const double def_int_rate = 0;
    static constexpr const double bonus_amount = 50;
    static constexpr const double bonus_threshold = 5000;
    static constexpr const int max_withdraw = 3;
    static constexpr const double max_withdraw_percent = 0.2;

protected:
    int num_withdraw;

public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

    // Deposit of $5000 or more will receive $50 bonus
    bool deposit(double amount);

    // Only allowed maximum of 3 withdrawals, each can be up to a maximum of 20% of the account's value
    bool withdraw(double amount);
};

#endif //_TRUST_ACCOUNT_H_