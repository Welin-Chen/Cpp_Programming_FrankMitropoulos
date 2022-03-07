// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int field_1_width{15};
int field_2_width{30};

void print_header()
{
    cout << setw(field_1_width) << left << "Student"
         << setw(field_1_width) << right << "Score" << endl;
    cout << setw(field_2_width) << setfill('-') << "" << endl;
    cout << setfill(' ');
}

int process_response(string answer, string response)
{
    int score{};
    for (auto i = 0; i < answer.length(); i++)
        if (answer.at(i) == response.at(i))
            score++;
    return score;
}

void print_student(string name, int score)
{
    cout << setw(field_1_width) << left << name
         << setw(field_1_width) << right << score << endl;
}

void print_footer(double avaerage_score)
{
    cout << setw(field_2_width) << setfill('-') << "" << endl;
    cout << setfill(' ');
    cout << setw(field_1_width) << left << "Average score"
         << setw(field_1_width) << right << avaerage_score << endl;
}

int main()
{
    ifstream in_file;
    string answer{};
    string name{};
    string response{};
    int score_total{};
    int total_students{};
    double avaerage_score{};

    in_file.open("responses.txt");
    {

        if (!in_file.is_open())
        {
            cerr << "Problem opening file" << endl;
            return 1;
        }

        print_header();
        {
            in_file >> answer;
            while (!in_file.eof())
            {
                in_file >> name >> response;
                int score = process_response(answer, response);
                score_total += score;
                total_students++;
                print_student(name, score);
            }
            if (total_students != 0)
                avaerage_score = static_cast<double>(score_total) / total_students;
        }
        print_footer(avaerage_score);
    }
    in_file.close();

    return 0;
}
