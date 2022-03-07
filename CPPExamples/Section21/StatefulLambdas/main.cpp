#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int global_x{1000};

void test1()
{
    cout << "\nTest1------------------------" << endl;

    int local_x{100};
    auto l = [local_x]()
    {
        cout << local_x << endl;
        cout << global_x << endl;
    };
    l();
};
void test2()
{
    cout << "\nTest2------------------------" << endl;

    int x{100};
    auto l = [x]() mutable
    {
        x += 100;
        cout << x << endl;
    };
    l();
    cout << x << endl;

    l();
    cout << x << endl;
};
void test3()
{
    cout << "\nTest3------------------------" << endl;

    int x{100};
    auto l = [&x]() mutable
    {
        x += 100;
        cout << x << endl;
    };

    l();
    cout << x << endl;
};

void test4()
{
    cout << "\nTest4------------------------" << endl;

    int x{100};
    int y{200};
    // int z{300};

    auto l = [=]() mutable
    {
        x += 100;
        y += 100;
        cout << x << endl;
        cout << y << endl;
    };
    l();

    cout << "\n";
    cout << x << endl;
    cout << y << endl;
};

void test5()
{
    cout << "\nTest5------------------------" << endl;

    int x{100};
    int y{200};
    int z{300};

    auto l = [&]()
    {
        x += 100;
        y += 100;
        z += 100;
        cout << x << endl;
        cout << y << endl;
        cout << z << endl;
    };
    l();

    cout << "\n";
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
};

void test6()
{
    cout << "\nTest6------------------------" << endl;

    int x{100};
    int y{200};
    int z{300};

    auto l = [=, &y]() mutable
    {
        x += 100;
        y += 100;
        z += 100;

        cout << x << endl;
        cout << y << endl;
        cout << z << endl;
    };
    l();

    cout << "\n";
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
};
void test7()
{
    cout << "\nTest7------------------------" << endl;

    int x{100};
    int y{200};
    int z{300};

    auto l = [&, x, z]() mutable
    {
        x += 100;
        y += 100;
        z += 100;

        cout << x << endl;
        cout << y << endl;
        cout << z << endl;
    };
    l();

    cout << "\n";
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
};

class Person
{
    friend ostream &operator<<(ostream &os, const Person &rhs);

private:
    string name;
    int age;

public:
    Person() = default;
    Person(string name, int age) : name{name}, age{age} {};
    Person(const Person &p) = default;
    ~Person() = default;

    string get_name() const { return name; };
    void set_name(string name) { this->name = name; };

    int get_age() const { return age; };
    void set_age(int age) { this->age = age; };

    auto change_person1()
    {
        return [this](string new_name, int new_age)
        {
            name = new_name;
            age = new_age;
        };
    };

    auto change_person2()
    {
        return [=](string new_name, int new_age)
        {
            name = new_name;
            age = new_age;
        };
    };

    auto change_person3()
    {
        return [&](string new_name, int new_age)
        {
            name = new_name;
            age = new_age;
        };
    };
};

ostream &operator<<(ostream &os, const Person &rhs)
{
    os << "[Person: " << rhs.name << ":" << rhs.age << "]";
    return os;
};

void test8()
{
    cout << "\nTest8------------------------" << endl;

    Person person("Larry", 18);
    cout << person << endl;

    auto change_person1 = person.change_person1();
    change_person1("Moe", 30);
    cout << person << endl;

    auto change_person2 = person.change_person2();
    change_person2("Curly", 25);
    cout << person << endl;

    auto change_person3 = person.change_person3();
    change_person3("Frank", 34);
    cout << person << endl;
};

class Lambda
{
private:
    int y;

public:
    Lambda(int y) : y{y} {};

    void operator()(int x) const { cout << x + y << endl; };
};

void test9()
{
    cout << "\nTest9------------------------" << endl;

    int y{100};

    Lambda lambda1(y);
    auto lambda2 = [y](int x)
    { cout << x + y << endl; };

    lambda1(200);
    lambda2(200);
};

class People
{
private:
    vector<Person> people;
    int max_people;

public:
    People(int max = 10) : max_people{max} {};
    People(const People &p) = default;
    void add(string name, int age) { people.emplace_back(name, age); };
    void set_max_people(int max) { max_people = max; };
    int get_max_people() const { return max_people; };

    vector<Person> get_people(int max_age)
    {
        vector<Person> result;
        int count{0};
        copy_if(people.begin(), people.end(), back_inserter(result),
                [this, &count, max_age](const Person &p)
                { return p.get_age() > max_age && ++count <= max_people; });
        return result;
    };
};

void test10()
{
    cout << "\nTest10------------------------" << endl;

    People friends;
    friends.add("Larry", 18);
    friends.add("Curly", 25);
    friends.add("Moe", 35);
    friends.add("Frank", 28);
    friends.add("James", 65);

    auto result = friends.get_people(17);

    cout << endl;
    for (const auto &p : result)
        cout << p << endl;

    friends.set_max_people(3);
    result = friends.get_people(17);

    cout << endl;
    for (const auto &p : result)
        cout << p << endl;

    result = friends.get_people(50);

    cout << endl;
    for (const auto &p : result)
        cout << p << endl;
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
    test8();
    test9();
    test10();
    return 0;
}