#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int scores[]{100, 95, 89};
    cout << "Value of scores: " << scores << endl;

    int *scores_ptr{scores};
    cout << "Value of scores_ptr: " << scores_ptr << endl;

    cout << "\nArray subscript notion----------------- " << endl;
    cout << scores[0] << endl;
    cout << scores[1] << endl;
    cout << scores[2] << endl;

    cout << "\nPointer subscript notion----------------- " << endl;
    cout << scores_ptr[0] << endl;
    cout << scores_ptr[1] << endl;
    cout << scores_ptr[2] << endl;

    cout << "\nPointer offset notion----------------- " << endl;
    cout << *scores_ptr << endl;
    cout << *(scores_ptr + 1) << endl;
    cout << *(scores_ptr + 2) << endl;

    cout << "\nArray offset notion----------------- " << endl;
    cout << *scores << endl;
    cout << *(scores + 1) << endl;
    cout << *(scores + 2) << endl;

    cout << endl;
    return 0;
}