// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int find_substring(string word_to_find, vector<string> lines)
{
    int match_count{};
    for (auto line : lines)
    {
        if (line.find(word_to_find) != string::npos)
        {
            match_count++;
            // cout << line << " ";
        }
    }
    return match_count;
}

int main()
{
    ifstream in_file;
    string line{};
    string word_to_find{};
    vector<string> lines;
    int match_count{};

    in_file.open("romeoandjuliet.txt");
    {
        if (!in_file.is_open())
        {
            cerr << "Problem opening file" << endl;
            return 1;
        }

        while (!in_file.eof())
        {
            in_file >> line;
            lines.push_back(line);
        }
    }
    in_file.close();

    while (true)
    {
        cout << "leave enter: q" << endl;
        cout << "Enter the substring to search for: ";

        cin >> word_to_find;
        if (word_to_find == "q" | word_to_find == "Q")
        {
            cout << "Bye" << endl;
            break;
        }

        match_count = find_substring(word_to_find, lines);

        cout << lines.size() << " words were searched..." << endl;
        cout << "The substring " << word_to_find << " was found " << match_count << " times" << endl;
        cout << endl;
    }

    return 0;
}
