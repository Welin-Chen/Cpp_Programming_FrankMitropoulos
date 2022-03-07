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

    try
    {
        if (gallons == 0)
            throw 0;
        miles_per_gallon = static_cast<double>(miles) / gallons;
        cout << "Result: " << miles_per_gallon << endl;
    }

    catch (int &ex)
    {
        cerr << "Sorry, can't divided by zero: " << ex << endl;
    }
    cout << "Bye" << endl;
    cout << endl;
    return 0;
}