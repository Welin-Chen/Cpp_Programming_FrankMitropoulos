#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void test1()
{
    cout << "\nTest1----------------------------" << endl;

    vector<int> nums{10, 20, 30, 40, 50};
    for_each(nums.begin(), nums.end(), [](int num)
             { cout << num << " "; });
};

void test2()
{
    cout << "\nTest2----------------------------" << endl;

    struct Point
    {
        int x;
        int y;
    };

    Point pt1{1, 2};
    Point pt2{4, 3};
    Point pt3{3, 5};
    Point pt4{3, 1};

    vector<Point> triangle1{pt1, pt2, pt3};
    vector<Point> triangle2{pt2, pt3, pt1};
    vector<Point> triangle3{pt1, pt2, pt4};

    if (is_permutation(triangle1.begin(), triangle1.end(), triangle2.begin(),
                       [](Point lhs, Point rhs)
                       { return (lhs.x == rhs.x && lhs.y == rhs.y); }))
        cout << "Triangle1 and Triangle2 are equivalent!" << endl;
    else
        cout << "Triangle1 and Triangle2 are not equivalent!" << endl;

    if (is_permutation(triangle1.begin(), triangle1.end(), triangle3.begin(),
                       [](Point lhs, Point rhs)
                       { return (lhs.x == rhs.x && lhs.y == rhs.y); }))
        cout << "Triangle1 and Triangle3 are equivalent!" << endl;
    else
        cout << "Triangle1 and Triangle3 are not equivalent!" << endl;
};
void test3()
{
    cout << "\nTest3----------------------------" << endl;

    vector<int> test_scores{93, 88, 75, 68, 65};
    int bonus_points{5};

    transform(test_scores.begin(), test_scores.end(), test_scores.begin(),
              [bonus_points](int score)
              { return score += bonus_points; });

    for (auto score : test_scores)
        cout << score << " ";
    cout << endl;
};

void test4()
{
    cout << "\nTest4----------------------------" << endl;

    vector<int> nums{1, 2, 3, 4, 5};

    nums.erase(remove_if(nums.begin(), nums.end(), [](int num)
                         { return num % 2 == 0; }),
               nums.end());
    for (auto num : nums)
        cout << num << " ";
    cout << endl;
};

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
    os << "[Person:" << rhs.get_name() << ":" << rhs.get_age() << "]";
    return os;
};

void test5()
{
    cout << "\nTest5----------------------------" << endl;

    Person person1{"Larry", 18};
    Person person2{"Moe", 30};
    Person person3{"Curly", 25};

    vector<Person> people{person1, person2, person3};

    sort(people.begin(), people.end(),
         [](Person lhs, Person rhs)
         { return lhs.get_name() < rhs.get_name(); });

    for (auto p : people)
        cout << p << endl;

    cout << endl;

    sort(people.begin(), people.end(),
         [](Person lhs, Person rhs)
         { return lhs.get_age() > rhs.get_age(); });

    for (auto p : people)
        cout << p << endl;
};

bool in_between(const vector<int> &nums, int start_value, int end_value)
{
    bool result{false};
    result = all_of(nums.begin(), nums.end(),
                    [start_value, end_value](int value)
                    { return value >= start_value && value <= end_value; });
    return result;
};

void test6()
{
    cout << "\nTest6----------------------------" << endl;

    cout << boolalpha;
    vector<int> nums(10);
    iota(nums.begin(), nums.end(), 1);

    for (auto i : nums)
        cout << i << " ";

    cout << endl;

    cout << in_between(nums, 50, 60) << endl;
    cout << in_between(nums, 1, 10) << endl;
    cout << in_between(nums, 5, 7) << endl;
};

class Password_Validator1
{
private:
    char restricted_symbol{'$'};

public:
    bool is_valid(string password)
    {
        return all_of(password.begin(), password.end(),
                      [this](char character)
                      { return character != restricted_symbol; });
    };
};

class Password_Validator2
{
private:
    vector<char> restricted_symbols{'!', '$', '+'};

public:
    bool is_valid(string password)
    {
        return all_of(password.begin(), password.end(),
                      [this](char character)
                      { return none_of(restricted_symbols.begin(), restricted_symbols.end(),
                                       [character](char symbol)
                                       { return character == symbol; }); });
    };
};

void test7()
{
    cout << "\nTest7----------------------------" << endl;

    string password{"holywood1$"};
    Password_Validator1 pv1;

    if (pv1.is_valid(password))
        cout << "The password: " << password << " is valid!" << endl;
    else
        cout << "The password: " << password << " is NOT valid!" << endl;

    password = "holywood1";
    if (pv1.is_valid(password))
        cout << "The password: " << password << " is valid!" << endl;
    else
        cout << "The password: " << password << " is NOT valid!" << endl;

    cout << "\n";

    // validator2
    password = "C++Rocks!";
    Password_Validator2 pv2;

    if (pv2.is_valid(password))
        cout << "The password: " << password << " is valid!" << endl;
    else
        cout << "The password: " << password << " is NOT valid!" << endl;

    password = "CPlusPlusRocks!";
    if (pv2.is_valid(password))
        cout << "The password: " << password << " is valid!" << endl;
    else
        cout << "The password: " << password << " is NOT valid!" << endl;

    password = "CPlusPlusRocks";
    if (pv2.is_valid(password))
        cout << "The password: " << password << " is valid!" << endl;
    else
        cout << "The password: " << password << " is NOT valid!" << endl;
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
    return 0;
}