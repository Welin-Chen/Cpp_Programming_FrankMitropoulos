#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class Person
{
    friend ostream &operator<<(ostream &os, const Person &rhs);

private:
    string name;
    int age;

public:
    Person(string name, int age) : name{name}, age{age} {};
    Person(const Person &p) : name{p.name}, age{p.age} {};
    ~Person() = default;

    string get_name() const { return name; };
    void set_name(string name) { this->name = name; };

    int get_age() const { return age; };
    void set_age(int age) { this->age = age; };
};

ostream &operator<<(ostream &os, const Person &rhs)
{
    os << "[Person: " << rhs.name << ":" << rhs.age << "]";
    return os;
}

void test1()
{
    cout << "\nTest1---------------------------" << endl;

    []()
    { cout << "Hi" << endl; }();

    [](int x)
    { cout << x << endl; }(100);

    [](int x, int y)
    { cout << x + y << endl; }(100, 200);
};

void test2()
{
    cout << "\nTest2---------------------------" << endl;

    auto l1 = []()
    { cout << "Hi" << endl; };
    l1();

    int num1{100};
    int num2{100};

    auto l2 = [](int x, int y)
    { cout << x + y << endl; };
    l2(10, 20);
    l2(num1, num2);

    auto l3 = [](int &x, int y)
    {
        cout << "x: " << x << " y: " << y << endl;
        x = 1000;
        y = 2000;
    };

    l3(num1, num2);
    cout << "num1: " << num1 << " num2: " << num2 << endl;
};

void test3()
{
    cout << "\nTest3---------------------------" << endl;
    Person stooge{"Larry", 18};
    cout << stooge << endl;

    auto l4 = [](Person p)
    { cout << p << endl; };
    l4(stooge);

    auto l5 = [](const Person &p)
    { cout << p << endl; };
    l5(stooge);

    auto l6 = [](Person &p)
    {
        p.set_name("Frank");
        p.set_age(25);
        cout << p << endl;
    };
    l6(stooge);

    cout << stooge << endl;
}

void filter_vector(const vector<int> &vec, function<bool(int)> func)
{
    cout << "[ ";
    for (int i : vec)
    {
        if (func(i))
            cout << i << " ";
    }
    cout << "]" << endl;
};

void test4()
{
    cout << "\nTest4---------------------------" << endl;
    vector<int> nums{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    filter_vector(nums, [](int x)
                  { return x > 50; });

    filter_vector(nums, [](int x)
                  { return x <= 30; });

    filter_vector(nums, [](int x)
                  { return x >= 30 && x <= 60; });
};

auto make_lambda()
{
    return []()
    { cout << "This lambda was made using the make_lambda function!"; };
}

void test5()
{
    cout << "\nTest5---------------------------" << endl;

    auto l5 = make_lambda();

    l5();
};

void test6()
{
    cout << "\nTest6---------------------------" << endl;
    auto l6 = [](auto x, auto y)
    { cout << "x: " << x << " y: " << y << endl; };

    l6(10, 20);
    l6(100.3, 200);
    l6(12.5, 15.54);

    l6(Person("Larry", 18), Person("Curly", 22));
};

void test7()
{
    cout << "\nTest7---------------------------" << endl;

    vector<Person> stooges{
        {"Larry", 18},
        {"Moe", 30},
        {"Curly", 25}};

    sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2)
         { return p1.get_name() < p2.get_name(); });

    for_each(stooges.begin(), stooges.end(), [](const Person &p)
             { cout << p << endl; });

    cout << endl;

    sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2)
         { return p1.get_age() < p2.get_age(); });

    for_each(stooges.begin(), stooges.end(), [](const Person &p)
             { cout << p << endl; });
};

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    cout << endl;
    return 0;
}