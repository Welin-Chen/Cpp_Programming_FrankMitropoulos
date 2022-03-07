#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
    std::unique_ptr<Account> moes_account;
    std::unique_ptr<Account> larrys_account;
    try
    {
        larrys_account = std::make_unique<Savings_Account>("Larry", -2000);
        cout << *larrys_account << endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        cerr << ex.what() << endl;
    }

    try
    {
        moes_account = make_unique<Savings_Account>("Moe", 1000);
        cout << *moes_account << endl;
        moes_account->withdraw(500);
        cout << *moes_account << endl;
        moes_account->withdraw(1000);
        cout << *moes_account << endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        cerr << ex.what() << endl;
    }
    catch (const InsufficientFundsException &ex)
    {
        cerr << ex.what() << endl;
    }
    // test your code here
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}
