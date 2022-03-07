#include <iostream>

using namespace std;

class DividedByZeroException
{
};
class NegativeValueException
{
};

double caculate_mpg(int miles, int gallons)
{
    if (gallons == 0)
        throw DividedByZeroException();
    if (miles < 0 || gallons < 0)
        throw NegativeValueException();

    return static_cast<double>(miles) / gallons;
}
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
        miles_per_gallon = caculate_mpg(miles, gallons);
        cout << "Result: " << miles_per_gallon << endl;
    }

    catch (const DividedByZeroException &ex)
    {
        cerr << "Sorry, you can't divide by zero" << endl;
    }

    catch (const NegativeValueException &ex)
    {
        cerr << "Sorry, one of your parameters is negative" << endl;
    }

    cout << "Bye" << endl;

    cout << endl;
    return 0;
}