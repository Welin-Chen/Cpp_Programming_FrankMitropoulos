#ifndef _SAVING_ACCOUNT_H_
#define _SAVING_ACCOUNT_H_
#include "Account.h"

class Saving_Account : public Account
{
    friend std::ostream &operator<<(std::ostream &os, const Saving_Account &account);

private:
    static constexpr const char *def_name = "Unamed Saving Account";
    static constexpr double def_balance = 0;
    static constexpr double def_int_rate = 0;

protected:
    double int_rate;

public:
    Saving_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

    bool deposit(double amount);
    //inherits Account::withdraw methods
};
#endif //_SAVING_ACCOUNT_H_
