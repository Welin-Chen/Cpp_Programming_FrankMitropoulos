#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

void display(const array<int, 5> &arr)
{
    cout << "[ ";
    for (auto &i : arr)
        cout << i << " ";
    cout << "]" << endl;
}
void test1()
{
    cout << "\nTest1======================" << endl;
    array<int, 5> arr1{1, 2, 3, 4, 5};
    array<int, 5> arr2;

    display(arr1);
    display(arr2);

    arr2 = {10, 20, 30, 40, 50};

    display(arr1);
    display(arr2);

    cout << "Size of arr1 is: " << size(arr1) << endl;
    cout << "Size of arr2 is: " << size(arr2) << endl;

    arr1[0] = 1000;
    arr1.at(1) = 2000;
    display(arr1);

    cout << "Front of arr2: " << arr2.front() << endl;
    cout << "Back of arr2: " << arr2.back() << endl;
};

void test2()
{
    cout << "\nTest2======================" << endl;
    array<int, 5> arr1{1, 2, 3, 4, 5};
    array<int, 5> arr2{10, 20, 30, 40, 50};

    display(arr1);
    display(arr2);

    arr1.fill(0);

    display(arr1);
    display(arr2);

    arr1.swap(arr2);

    display(arr1);
    display(arr2);
};

void test3()
{
    cout << "\nTest3======================" << endl;
    array<int, 5> arr1{1, 2, 3, 4, 5};

    int *ptr = arr1.data();
    cout << ptr << endl;

    *ptr = 1000;
    display(arr1);
};

void test4()
{
    cout << "\nTest4======================" << endl;

    array<int, 5> arr1{2, 1, 4, 5, 3};
    display(arr1);

    sort(arr1.begin(), arr1.end());
    display(arr1);
};

void test5()
{
    cout << "\nTest5======================" << endl;

    array<int, 5> arr1{2, 1, 4, 5, 3};

    array<int, 5>::iterator min_mum = min_element(arr1.begin(), arr1.end());
    auto max_mum = max_element(arr1.begin(), arr1.end());
    cout << "min: " << *min_mum << " ,max: " << *max_mum << endl;
};

void test6()
{
    cout << "\nTest6======================" << endl;

    array<int, 5> arr1{2, 1, 3, 3, 5};

    auto adjacent = adjacent_find(arr1.begin(), arr1.end());
    if (adjacent != arr1.end())
        cout << "Adjacent element found with value: " << *adjacent << endl;
    else
        cout << "No adjacent element found " << endl;
};

void test7()
{
    cout << "\nTest7======================" << endl;

    array<int, 5> arr1{1, 2, 3, 4, 5};

    // acuumulate is from #include<numeric>
    int sum = accumulate(arr1.begin(), arr1.end(), 0);
    cout << "Sum of the elements in arr1 is: " << sum << endl;
};

void test8()
{
    cout << "\nTest8======================" << endl;

    array<int, 10> arr1{1, 2, 3, 1, 2, 3, 3, 3, 3};

    int count = std::count(arr1.begin(), arr1.end(), 3);
    cout << "Found 3: " << count << " times" << endl;
};

void test9()
{
    cout << "\nTest9======================" << endl;

    array<int, 10> arr1{1, 2, 3, 50, 60, 70, 80, 200, 300, 400};

    int count = std::count_if(arr1.begin(), arr1.end(), [](int x)
                              { return x > 10 && x < 200; });
    cout << "Found: " << count << " matches" << endl;
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

    return 0;
}