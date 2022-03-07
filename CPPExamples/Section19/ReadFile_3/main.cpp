#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream in_file;

    in_file.open("poem.txt");
    if (!in_file)
    {
        cerr << "Problem opening file" << endl;
        return 1;
    }

    string line{};
    while (!in_file.eof())
    {
        getline(in_file, line);
        cout << line << endl;
    }

    in_file.close();
    return 0;
};