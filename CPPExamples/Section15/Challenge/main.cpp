#include <iostream>
#include <vector>
#include "Account.h"
#include "Saving_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;

    // Account
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{"Larry"});
    accounts.push_back(Account{"Moe", 2000});
    accounts.push_back(Account{"Curly", 5000});

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // Saving Account
    vector<Saving_Account> sav_accounts;
    sav_accounts.push_back(Saving_Account{});
    sav_accounts.push_back(Saving_Account{"Superman"});
    sav_accounts.push_back(Saving_Account{"Batman", 2000});
    sav_accounts.push_back(Saving_Account{"Wonderwoman", 5000, 5});

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    cout << endl;
    return 0;
}