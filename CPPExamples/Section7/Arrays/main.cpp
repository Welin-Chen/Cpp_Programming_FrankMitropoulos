#include <iostream>

using namespace std;

int main()
{
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    cout << "\nThe first vowel is: " << vowels[0] << endl;
    cout << "The last vowel is: " << vowels[4] << endl;

    double hi_temp[] = {90.1, 89.8, 77.5, 91.6};
    cout << "\nThe first high temperature is: " << hi_temp[0] << endl;
    hi_temp[0] = 100.7;
    cout << "The first high temperature is: " << hi_temp[0] << endl;

    int test_score[5] = {100, 90, 80, 70, 60};
    cout << "\nFirst score at index 0: " << test_score[0] << endl;
    cout << "Second score at index 1: " << test_score[1] << endl;
    cout << "Third score at index 2: " << test_score[2] << endl;
    cout << "Fourth score at index 3: " << test_score[3] << endl;
    cout << "Fifth score at index 4: " << test_score[4] << endl;

    cout << "\nEnter 5 test scores: ";
    cin >> test_score[0];
    cin >> test_score[1];
    cin >> test_score[2];
    cin >> test_score[3];
    cin >> test_score[4];

    cout << "\nThe updated array is:" << endl;
    cout << "First score at index 0: " << test_score[0] << endl;
    cout << "Second score at index 1: " << test_score[1] << endl;
    cout << "Third score at index 2: " << test_score[2] << endl;
    cout << "Fourth score at index 3: " << test_score[3] << endl;
    cout << "Fifth score at index 4: " << test_score[4] << endl;

    cout << "\nNotice what the value of the array name is: " << test_score << endl;

    cout << endl;
    return 0;
}
