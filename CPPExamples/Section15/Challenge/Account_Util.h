#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "Account.h"
#include "Saving_Account.h"

void display(const std::vector<Account> &accounts);
void deposit(std::vector<Account> &accounts, double amount);
void withdraw(std::vector<Account> &accounts, double amount);

void display(const std::vector<Saving_Account> &accounts);
void deposit(std::vector<Saving_Account> &accounts, double amount);
void withdraw(std::vector<Saving_Account> &accounts, double amount);
#endif //_ACCOUNT_UTIL_H_