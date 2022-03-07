#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int num{255};
    cout << "\n=======================" << endl;
    cout << std::dec << num << endl;
    cout << std::hex << num << endl;
    cout << std::oct << num << endl;

    cout << "\n=======================" << endl;
    cout << std::showbase;
    cout << std::dec << num << endl;
    cout << std::hex << num << endl;
    cout << std::oct << num << endl;

    cout << "\n=======================" << endl;
    cout << std::showbase << std::uppercase;
    cout << std::hex << num << endl;

    cout << "\n=======================" << endl;
    cout << std::showpos;
    cout << std::dec << num << endl;
    cout << std::hex << num << endl;
    cout << std::oct << num << endl;

    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase);
    std::cout.setf(std::ios::showpos);

    std::cout << std::resetiosflags(std::ios::basefield);
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::uppercase);
    std::cout << std::resetiosflags(std::ios::showpos);

    cout << "\n=======================" << endl;
    cout << "Enter an integer: ";
    cin >> num;

    cout << "Decimal default: " << num << endl;
    cout << "Hexadecimal : " << hex << uppercase << num << endl;
    cout << "Hexadecimal : " << hex << num << endl;
    cout << "Hexadecimal : " << hex << nouppercase << num << endl;

    cout << "Octal : " << oct << num << endl;
    cout << "Hexadecimal : " << hex << showbase << num << endl;
    cout << "Octal : " << oct << num << endl;

    cout << endl;
    return 0;
};