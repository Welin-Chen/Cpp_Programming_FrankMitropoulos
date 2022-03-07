#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    char selection{};
    vector<int> numbers{};
    do
    {
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add numbers" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest numbers" << endl;
        cout << "L - Display the largest numbers" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";
        cin >> selection;

        if (selection == 'P' || selection == 'p')
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
        else if (selection == 'A' || selection == 'a')
        {
            double num{};
            cout << "Enter an integer to add to the list: ";
            cin >> num;
            numbers.push_back(num);
            cout << numbers.at(numbers.size() - 1) << " added" << endl;
        }
        else if (selection == 'M' || selection == 'm')
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
        else if (selection == 'S' || selection == 's')
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
        else if (selection == 'L' || selection == 'l')
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
        else if (selection == 'q' || selection == 'Q')
            cout << "Goodby..." << endl;
        else
            cout << "Unkonw selection, try again." << endl;

    } while (!(selection == 'q' || selection == 'Q'));
    cout << endl;
    return 0;
}