#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(const int array[], int size);
int *apply_all(const int arr1[], int size1, const int arr2[], int size2);

void print(const int array[], int size)
{
    cout << "[ ";
    for (auto i{0}; i < size; i++)
        cout << array[i] << " ";
    cout << "]" << endl;
}

int *apply_all(const int arr1[], int size1, const int arr2[], int size2)
{
    int *new_array{};
    new_array = new int[size1 * size2];

    int position{0};
    for (auto i{0}; i < size2; i++)
        for (auto j{0}; j < size1; j++)
        {
            new_array[position] = arr2[i] * arr1[j];
            position++;
        }
    return new_array;
}

int main()
{
    const size_t array1_size{5};
    const size_t array2_size{3};

    int array1[]{1, 2, 3, 4, 5};
    int array2[]{10, 20, 30};

    cout << "Array1: ";
    print(array1, array1_size);

    cout << "Array2: ";
    print(array2, array2_size);

    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t result_size = (array1_size * array2_size);
    cout << "Result= " << results << endl;
    cout << "*Result= " << *results << endl;

    cout << "\nResult: ";
    print(results, result_size);
    delete[] results;
    cout << "Result= " << results << endl;
    cout << "*Result= " << *(results + 1) << endl;

    cout << endl;
    return 0;
}