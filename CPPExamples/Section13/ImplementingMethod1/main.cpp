#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account
{
private:
    // attributes
    string name;
    double balance;

public:
    // methods
    // declare inline
    void set_balance(double bal) { balance = bal; }
    double get_balance() { return balance; }

    // methods will be declare outside the class declaration
    void set_name(string n);
    string get_name();

    bool deposit(double amount);
    bool withdraw(double amount);
};

void Account::set_name(string n)
{
    name = n;
}

string Account::get_name()
{
    return name;
}

bool Account::deposit(double amount)
{
    // if verify amount
    balance += amount;
    return true;
}

bool Account::withdraw(double amount)
{
    if ((balance - amount) >= 0)
    {
        balance -= amount;
        return true;
    }
    else
        return false;
}

int main()
{
    Account frank_account;
    frank_account.set_name("Frank's account");
    frank_account.set_balance(1000);

    if (frank_account.deposit(200))
        cout << "Deposit OK" << endl;
    else
        cout << "Deposit Not allowed" << endl;

    if (frank_account.withdraw(500))
        cout << "Withdraw OK" << endl;
    else
        cout << "Not sufficient funds" << endl;

    if (frank_account.withdraw(1500))
        cout << "Withdraw OK" << endl;
    else
        cout << "Not sufficient funds" << endl;

    cout << endl;
    return 0;
}