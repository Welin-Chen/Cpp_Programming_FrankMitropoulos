#include <iostream>
#include <string>

using namespace std;

int main()
{
    string letter;
    cout << "Enter string: ";
    getline(cin, letter);

    cout << "string :" << letter << endl;

    int count{};
    count = letter.length();
    cout << "count: " << count << endl;

    for (int i{1}; i <= count; i++)
    {
        for (int j{1}; j <= (count - i); j++)
        {
            cout << " ";
        }
        for (auto j{0}; j < i; j++)
        {
            cout << letter[j];
        }
        for (auto j{i - 2}; j >= 0; j--)
        {
            cout << letter[j];
        }
        for (int j{1}; j <= (count - i); j++)
        {
            cout << " ";
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}