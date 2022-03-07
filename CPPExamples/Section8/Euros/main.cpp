#include <iostream>

using namespace std;

int main()
{
    const double usd_per_eur{1.19};
    cout << "Welcom to the EUR to USD converter" << endl;
    cout << "Enter the value in EUR:" << endl;

    double euros{0};
    double dollars{0};
    cin >> euros;
    dollars = euros * usd_per_eur;

    cout << euros << " euros is equal to " << dollars << " dollars" << endl;

    cout << endl;
    return 0;
}