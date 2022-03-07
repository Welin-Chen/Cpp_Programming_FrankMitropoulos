#include <iostream>
#include "Account.h"
#include "Saving_Account.h"

using namespace std;

int main()
{
    cout << "\n=====Account class===============" << endl;
    Account a1{1000};
    cout << a1 << endl;

    a1.deposit(500);
    cout << a1 << endl;

    a1.withdraw(1000);
    cout << a1 << endl;

    a1.withdraw(5000);
    cout << a1 << endl;

    cout << "\n=====Saving Account===============" << endl;
    Saving_Account s1{1000, 5};
    cout << s1 << endl;

    s1.deposit(1000);
    cout << s1 << endl;

    s1.withdraw(2000);
    cout << s1 << endl;

    s1.withdraw(1000);
    cout << s1 << endl;

    cout << "\n=================================" << endl;

    cout << endl;
    return 0;
}