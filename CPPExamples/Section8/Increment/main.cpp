#include <iostream>

using namespace std;

int main()
{
    int counter{10};
    int result{0};

    counter = 10;
    result = 0;
    // ex2
    // cout << "Counter: " << counter << endl;

    // result = ++counter;
    // cout << "Counter: " << counter << endl;
    // cout << "Result: " << result << endl;

    // ex3
    // cout << "Counter: " << counter << endl;

    // result = counter++;
    // cout << "Counter: " << counter << endl;
    // cout << "Result: " << result << endl;

    // ex4
    // cout << "Counter: " << counter << endl;

    // result = ++counter + 10;
    // cout << "Counter: " << counter << endl;
    // cout << "Result: " << result << endl;
    // cout << endl;

    // ex5
    cout << "Counter: " << counter << endl;

    result = counter++ + 10;
    cout << "Counter: " << counter << endl;
    cout << "Result: " << result << endl;
    cout << endl;

    return 0;
}