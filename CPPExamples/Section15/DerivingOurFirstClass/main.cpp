#include <iostream>
#include "Account.h"
#include "Saving_Account.h"

using namespace std;

int main()
{
    cout << "\n=====Account===============" << endl;
    Account acc{};
    acc.deposit(2000);
    acc.withdraw(500);

    cout << endl;

    Account *p_acc{nullptr};
    p_acc = new Account();
    p_acc->deposit(1000);
    p_acc->withdraw(500);
    delete p_acc;

    cout << "\n=====Saving Account===============" << endl;
    Saving_Account sav_acc{};
    sav_acc.deposit(2000);
    sav_acc.withdraw(500);

    cout << endl;

    Saving_Account *p_sav_acc{nullptr};
    p_sav_acc = new Saving_Account();
    p_sav_acc->deposit(1000);
    p_sav_acc->withdraw(500);
    delete p_sav_acc;

    cout << "\n=================================" << endl;

    cout << endl;
    return 0;
}