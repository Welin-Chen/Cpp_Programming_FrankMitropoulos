#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double num1{123456789.987654321};
    double num2{1234.5678};
    double num3{1234.0};

    cout << "--Defaults----------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout << std::setprecision(2);
    cout << "--Precision 2----------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout << std::setprecision(5);
    cout << "--Precision 5----------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout << std::setprecision(9);
    cout << "--Precision 9----------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout << std::setprecision(3) << std::fixed;
    cout << "--Precision 3 - fixed----------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout << std::setprecision(3) << std::scientific;
    cout << "--Precision 3 - scientific----------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout << std::setprecision(3) << std::scientific << std::uppercase;
    cout << "--Precision 3 - scientific - uppercase----------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout << std::setprecision(3) << std::fixed << std::showpos;
    cout << "--Precision 3 - fixed - showpos----------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout.unsetf(std::ios::scientific | std::ios ::fixed);
    cout << std::resetiosflags(std::ios::showpos);

    cout << std::setprecision(10) << std::showpoint;
    cout << "--Precision 10 - showpoint----------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout.unsetf(std::ios::scientific | std::ios ::fixed);
    cout << std::setprecision(6);
    cout << resetiosflags(ios::showpos);
    cout << resetiosflags(ios::showpoint);

    cout << "--Back to defaults----------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout << endl;
    return 0;
};