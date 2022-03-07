#include <iostream>

using namespace std;

int main()
{
    int miles{};
    int gallons{};
    double miles_per_gallon{};

    cout << "Enter the miles: ";
    cin >> miles;
    cout << "Enter the gallons: ";
    cin >> gallons;

    // miles_per_gallon = miles / gallons;
    if (miles_per_gallon != 0)
    {
        miles_per_gallon = static_cast<double>(miles) / gallons;
        cout << "Result: " << miles_per_gallon << endl;
    }
    else
        cerr << "Sorry, can't divided by zero" << endl;

    cout << "Bye" << endl;
    cout << endl;
    return 0;
}