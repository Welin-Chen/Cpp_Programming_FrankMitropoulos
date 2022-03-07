// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream in_file("romeoandjuliet");
    ofstream out_file{"romeoandjuliet_out.txt"};
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

        int line_number{};
        string line;
        while (getline(in_file, line))
        {
            if (line == "" || line == "\r")
            {
                out_file << line;
            }
            else
            {
                line_number++;
                out_file << setw(8) << left << line_number << line << endl;
            }
        }
        cout << "File copyed" << endl;
    }
    in_file.close();
    out_file.close();

    return 0;
}
