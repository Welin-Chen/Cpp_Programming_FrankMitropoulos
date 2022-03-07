#include <iostream>
#include <string>
#include "Mystring.h"

using namespace std;

int main()
{
    Mystring empty;          //no args constructor
    Mystring larry("Larry"); //overloaded constructor
    Mystring stooge{larry};  //copy constructor

    empty.display();
    larry.display();
    stooge.display();

    cout << endl;
    return 0;
}