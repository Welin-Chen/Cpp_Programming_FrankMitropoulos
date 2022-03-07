#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Square_Functor
{
    void operator()(int x)
    {
        cout << x * x << " ";
    }
};

class Mutillier
{
private:
    int num{};

public:
    Mutillier(int n) : num{n} {}
    int operator()(int n) const { return num * n; }
};

template <typename T>
struct Displayer
{
    void operator()(const T &data)
    {
        cout << data << " ";
    }
};
int main()
{
    cout << "\nTest1==================" << endl;
    Square_Functor square;
    square(4);

    Displayer<int> d1;
    Displayer<string> d2;
    d1(100);
    d2("Frank");

    cout << "\nTest2==================" << endl;
    vector<int> vec1{1, 2, 3, 4, 5};
    vector<string> vec2{"Larry", "Moe", "Curly"};

    for_each(vec1.begin(), vec1.end(), square);
    cout << endl;

    for_each(vec1.begin(), vec1.end(), Displayer<int>());
    cout << endl;

    for_each(vec1.begin(), vec1.end(), d1);
    cout << endl;

    for_each(vec2.begin(), vec2.end(), Displayer<string>());
    cout << endl;

    for_each(vec2.begin(), vec2.end(), d2);
    cout << endl;

    cout << "\nTest3==================" << endl;
    for_each(vec1.begin(), vec1.end(), [](int x)
             { cout << x * x << " "; });
    cout << endl;

    for_each(vec1.begin(), vec1.end(), [](int x)
             { cout << x * 10 << " "; });
    cout << endl;

    for_each(vec1.begin(), vec1.end(), [](int x)
             { cout << x << " "; });
    cout << endl;

    for_each(vec2.begin(), vec2.end(), [](string s)
             { cout << s << " "; });
    cout << endl;

    cout << "\nTest4==================" << endl;
    Mutillier mult(100);
    vec1 = {1, 2, 3, 4};

    transform(vec1.begin(), vec1.end(), vec1.begin(), mult);
    for_each(vec1.begin(), vec1.end(), d1);
    cout << endl;

    vec1 = {1, 2, 3, 4};
    transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x)
              { return x * 100; });
    for_each(vec1.begin(), vec1.end(), [](int x)
             { cout << x << " "; });
    cout << endl;

    return 0;
}