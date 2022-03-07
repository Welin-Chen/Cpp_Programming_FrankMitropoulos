#include <iostream>

using namespace std;

class Base
{
    // Note friends of Base have access to all
public:
    int a{0};
    void display() { std::cout << a << ", " << b << ", " << c << endl; }

protected:
    int b{0};

private:
    int c{0};
};

class Derived : public Base
{
    // Note friends of Derived have access to only what Derived hass access to

    // a will be public
    // b will be protected
    // c will not be accessible
public:
    void access_base_members()
    {
        a = 100; //ok
        b = 200; //ok
        // c = 300; //not accessible
    }
};
int main()
{
    cout << "===Base member access from base objects===" << endl;
    Base base;
    base.a = 100; //OK
    // base.b = 200; //Compiler error
    // base.c = 300; //Compiler error

    cout << "===Base member access from derived objects===" << endl;
    Derived d;
    d.a = 100; //Ok
    // d.b = 200; //error
    // d.c = 300; //error
    cout << endl;
    return 0;
}