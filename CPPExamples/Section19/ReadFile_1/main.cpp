#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in_file;
    string line;
    int num;
    double total;

    in_file.open("test.txt");
    if (!in_file)
    {
        cerr << "Problem opening file" << endl;
        return 1;
    }

    in_file >> line >> num >> total;
    cout << line << endl;
    cout << num << endl;
    cout << total << endl;

    in_file.close();

    cout << endl;
    return 0;
};