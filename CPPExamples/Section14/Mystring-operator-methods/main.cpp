#include <iostream>
// #include <string>
// #include <vector>
#include "Mystring.h"

using namespace std;

int main()
{
    cout << boolalpha << endl;

    Mystring larry{"Larry"};
    Mystring moe{"Moe"};

    Mystring stooge = larry;
    larry.display();
    moe.display();

    cout << (larry == moe) << endl;
    cout << (larry == stooge) << endl;

    larry.display();
    Mystring larry2 = -larry;
    larry2.display();

    Mystring stooges = larry + "Moe";
    // Mystring stooges = "Moe" + larry;

    Mystring two_stooges = moe + " " + "larry";
    two_stooges.display();

    Mystring three_stooges = moe + " " + larry + " " + "Curly";
    three_stooges.display();

    cout << endl;
    return 0;
}