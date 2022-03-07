#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

char display_menu();
void Print(const vector<int> &numbers);
void Add(vector<int> &numbers);
void Mean(const vector<int> &numbers);
void Smallest(const vector<int> &numbers);
void Largest(const vector<int> &numbers);
void Find(const vector<int> &numbers);

int main()
{
    char selection{};
    vector<int> numbers{};
    do
    {
        selection = display_menu();
        switch (selection)
        {
        case 'P':
            Print(numbers);
            break;
        case 'A':
            Add(numbers);
            break;
        case 'M':
            Mean(numbers);
            break;
        case 'S':
            Smallest(numbers);
            break;
        case 'L':
            Largest(numbers);
            break;
        case 'F':
            Find(numbers);
            break;
        case 'Q':
            cout << "Goodby..." << endl;
            break;
        default:
            cout << "Unkonw selection, try again." << endl;
        }

    } while (selection != 'Q');
    cout << endl;
    return 0;
}

char display_menu()
{
    char s;
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add numbers" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest numbers" << endl;
    cout << "L - Display the largest numbers" << endl;
    cout << "F - Find the number" << endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice: ";
    cin >> s;
    return toupper(s);
}

void Print(const vector<int> &numbers)
{
    if (numbers.empty())
        cout << "[] - the list is empty" << endl;
    else
    {
        cout << "[ ";
        for (auto val : numbers)
            cout << val << " ";
        cout << "]" << endl;
    }
}

void Add(vector<int> &numbers)
{
    double num{};
    cout << "Enter an integer to add to the list: ";
    cin >> num;
    numbers.push_back(num);
    cout << numbers.at(numbers.size() - 1) << " added" << endl;
}

void Mean(const vector<int> &numbers)
{
    if (numbers.empty())
        cout << "The numbers is empty" << endl;
    else
    {
        double mean{};
        double total{};
        for (auto val : numbers)
        {
            total += val;
        }
        mean = total / numbers.size();
        cout << fixed << setprecision(1);
        cout << "The mean is : " << mean << endl;
    }
}

void Smallest(const vector<int> &numbers)
{
    if (!numbers.empty())
    {
        int min{};
        min = *min_element(numbers.begin(), numbers.end());
        cout << "The smallest number is: " << min << endl;
    }
    else
        cout << "The numbers is empty" << endl;
}

void Largest(const vector<int> &numbers)
{
    if (!numbers.empty())
    {
        int max{};
        max = *max_element(numbers.begin(), numbers.end());
        cout << "The largest number is: " << max << endl;
    }
    else
        cout << "The numbers is empty" << endl;
}

void Find(const vector<int> &numbers)
{
    int target;
    bool ans{false};
    cout << "Enter the number to find: ";
    cin >> target;
    for (auto i : numbers)
    {
        if (i == target)
            ans = true;
    }
    if (ans)
        cout << target << " was found" << endl;
    else
        cout << target << " was not found" << endl;
}