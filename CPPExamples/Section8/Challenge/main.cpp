#include <iostream>

using namespace std;

int main()
{
    int change_amount{0};
    cout << "\nEnter an amount in cents : ";
    cin >> change_amount;

    const int dollar_value{100};
    const int quarter_value{25};
    const int dime_value{10};
    const int nickel_value{5};

    int balance{0};

    int dollar{0};
    dollar = change_amount / dollar_value;
    balance = change_amount % dollar_value;

    int quarter{0};
    quarter = balance / quarter_value;
    balance %= quarter_value;

    int dime{0};
    dime = balance / dime_value;
    balance %= dime_value;

    int nickel{0};
    nickel = balance / nickel_value;
    balance %= nickel_value;

    int penny{0};
    penny = balance;

    cout << "dollars  : " << dollar << endl;
    cout << "quarters : " << quarter << endl;
    cout << "dimes    : " << dime << endl;
    cout << "nickels  : " << nickel << endl;
    cout << "pennys   : " << penny << endl;

    cout << endl;
    return 0;
}