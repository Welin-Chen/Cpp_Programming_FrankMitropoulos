#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream in_file("poem.txt");
    ofstream out_file{"poem_out.txt"};
    {
        if (!in_file.is_open())
        {
            cerr << "Error opening input file" << endl;
            return 1;
        }
        if (!out_file.is_open())
        {
            cerr << "Error opening output file" << endl;
            return 1;
        }

        string line;
        while (getline(in_file, line))
            out_file << line << endl;

        cout << "File copyed" << endl;
    }
    in_file.close();
    out_file.close();

    cout << endl;
    return 0;
};