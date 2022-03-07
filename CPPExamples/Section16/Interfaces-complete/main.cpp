#include <iostream>
#include <vector>

using namespace std;

class I_Printable
{
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);

public:
    virtual void print(std::ostream &os) const = 0;
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
    obj.print(os);
    return os;
}

class Account : public I_Printable
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Account display";
    }
    virtual ~Account() {}
};

class Checking : public Account
{
public:
    virtual void withdraw(double amount) override
    {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Checking display";
    }
    virtual ~Checking() {}
};

class Savings : public Account
{
public:
    virtual void withdraw(double amount) override
    {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Saving display";
    }
    virtual ~Savings() {}
};

class Trust : public Account
{
public:
    virtual void withdraw(double amount) override
    {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Trust display";
    }
    virtual ~Trust() { std::cout << "Trust::destructor" << std::endl; }
};

void do_withdraw(Account &account, double amount)
{
    account.withdraw(amount);
}

class Dog : public I_Printable
{
public:
    virtual void print(std::ostream &os) const override
    {
        os << "Woof woof";
    }
};

void print(const I_Printable &obj)
{
    std::cout << obj << std::endl;
}

int main()
{
    Dog *dog = new Dog();
    cout << *dog << endl;

    print(*dog);

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