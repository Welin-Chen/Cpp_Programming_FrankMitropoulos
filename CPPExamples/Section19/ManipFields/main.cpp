#include <iostream>
#include <iomanip>

using namespace std;

void ruler()
{
    std::cout << "\n12345678901234567890123456789012345678901234567890" << endl;
}
int main()
{
    int num1{1234};
    double num2{1234.5678};
    string hello{"Hello"};

    cout << "\n--Default------------------" << endl;
    ruler();
    cout << num1 << num2 << hello << endl;

    cout << "\n--Default - one per line------------------" << endl;
    ruler();
    cout << num1 << endl;
    cout << num2 << endl;
    cout << hello << endl;

    cout << "\n--width 10 for num1------------------" << endl;
    ruler();
    cout << setw(10) << num1
         << num2
         << hello << endl;

    cout << "\n--width 10 for num1 and num2------------------" << endl;
    ruler();
    cout << setw(10) << num1
         << setw(10) << num2
         << hello << endl;

    cout << "\n--width 10 for num1 and num2 and hello------------------" << endl;
    ruler();
    cout << setw(10) << num1
         << setw(10) << num2
         << setw(10) << hello
         << endl;

    cout << "\n--width 10 for num1 and num2 and hello left for all------------------" << endl;
    ruler();
    cout << setw(10) << left << num1
         << setw(10) << left << num2
         << setw(10) << left << hello
         << endl;

    cout << "\n--width 10 for num1 and num2 and hello left for all setfill to dash------------------" << endl;
    ruler();
    cout << setfill('-');
    cout << setw(10) << left << num1
         << setw(10) << left << num2
         << setw(10) << left << hello
         << endl;

    cout << "\n--width 10 for num1 and num2 and hello left for all setfill varies------------------" << endl;
    ruler();

    cout << setw(10) << left << setfill('*') << num1
         << setw(10) << left << setfill('#') << num2
         << setw(10) << left << setfill('-') << hello
         << endl;

    cout << endl;
    return 0;
};