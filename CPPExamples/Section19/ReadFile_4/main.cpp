#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream in_file;

    in_file.open("poem.txt");
    if (!in_file.is_open())
    {
        cerr << "Problem opening file" << endl;
        return 1;
    }

    char c{};
    while (!in_file.eof())
    {
        in_file.get(c);
        cout << c;
    }
    cout << endl;

    in_file.close();
    return 0;
};