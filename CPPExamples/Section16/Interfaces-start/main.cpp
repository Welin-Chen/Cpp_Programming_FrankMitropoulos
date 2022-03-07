#include <iostream>
#include <vector>

using namespace std;

class Account
{
    friend std::ostream &operator<<(std::ostream &os, const Account &acc);

public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() {}
};

std::ostream &operator<<(std::ostream &os, const Account &acc)
{
    os << "Account display";
    return os;
}

class Checking : public Account
{
    friend std::ostream &operator<<(std::ostream &os, const Checking &acc);

public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Checking::withdraw" << std::endl;
    }

    virtual ~Checking() {}
};

std::ostream &operator<<(std::ostream &os, const Checking &acc)
{
    os << "Checking display";
    return os;
}

class Savings : public Account
{
    friend std::ostream &operator<<(std::ostream &os, const Savings &acc);

public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {}
};
std::ostream &operator<<(std::ostream &os, const Savings &acc)
{
    os << "Savings display";
    return os;
}

class Trust : public Account
{
    friend std::ostream &operator<<(std::ostream &os, const Trust &acc);

public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() { std::cout << "Trust::destructor" << std::endl; }
};
std::ostream &operator<<(std::ostream &os, const Trust &acc)
{
    os << "Trust display";
    return os;
}
void do_withdraw(Account &account, double amount)
{
    account.withdraw(amount);
}

int main()
{
    Account *p1 = new Account();
    cout << *p1 << endl;

    Account *p2 = new Checking();
    cout << *p2 << endl;

    // Account a;
    // cout << a << endl;

    // Checking c;
    // cout << c << endl;

    // Savings s;
    // cout << s << endl;

    // Trust t;
    // cout << t << endl;

    cout << endl;
    return 0;
}