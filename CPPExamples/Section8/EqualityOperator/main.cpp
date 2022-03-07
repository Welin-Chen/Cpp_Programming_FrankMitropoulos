#include <iostream>

using namespace std;

int main()
{
    bool equal_result{false};
    bool not_equal_result{false};

    // int num1{}, num2{};

    // cout << boolalpha;

    // cout << "Enter two intergers separated by a space:" << endl;
    // cin >> num1 >> num2;
    // equal_result = (num1 == num2);
    // not_equal_result = (num1 != num2);
    // cout << "Comparison result (equals): " << equal_result << endl;
    // cout << "Comparison result (not equals): " << not_equal_result << endl;

    char char1{}, char2{};

    cout << boolalpha;

    cout << "Enter two characters separated by a space:" << endl;
    cin >> char1 >> char2;
    equal_result = (char1 == char2);
    not_equal_result = (char1 != char2);
    cout << "Comparison result (equals): " << equal_result << endl;
    cout << "Comparison result (not equals): " << not_equal_result << endl;

    cout << endl;
    return 0;
}