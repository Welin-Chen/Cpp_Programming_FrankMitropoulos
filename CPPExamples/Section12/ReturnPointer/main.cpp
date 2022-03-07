#include <iostream>
#include <string>
#include <vector>

using namespace std;

int *create_array(size_t size, int init_value = 0)
{
    int *new_storage{nullptr};
    new_storage = new int[size];
    for (size_t i{0}; i < size; i++)
    {
        *(new_storage + i) = init_value;
    }
    return new_storage;
}

void display(int *array, size_t size)
{
    for (size_t i{0}; i < size; i++)
    {
        // cout << *(array + i) << " ";
        cout << array[i] << " ";
    }
    cout << endl;
}
int main()
{
    int *my_array{nullptr};
    size_t size;
    int init_value{};

    cout << "How many integers would you like to allocate? ";
    cin >> size;
    cout << "What value would you like them initialized to? ";
    cin >> init_value;

    my_array = create_array(size, init_value);
    cout << "\n------------------" << endl;

    display(my_array, size);

    cout << endl;
    return 0;
}