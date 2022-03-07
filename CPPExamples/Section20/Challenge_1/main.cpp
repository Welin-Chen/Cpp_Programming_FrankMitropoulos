// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

template <typename T>
void display(const deque<T> &d)
{
    cout << "[ ";
    for (const auto i : d)
        cout << i;
    cout << " ]" << endl;
}

bool is_palindrome(const std::string &s)
{
    deque<char> c1;
    deque<char> c2;

    for (const auto i : s)
    {
        // if (!ispunct(i) & (i != ' '))
        if (isalpha(i))
        {
            c1.push_back(toupper(i));
            c2.push_front(toupper(i));
        }
    }

    // display(c1);
    // display(c2);
    // cout << "比較結果: " << (d == d1) << endl;
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    return (c1 == c2);
}

int main()
{
    std::vector<std::string> test_strings{"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
                                          "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
                                          "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result"
              << "String" << std::endl;
    for (const auto &s : test_strings)
    {
        cout << setw(8) << ((is_palindrome(s) == true) ? "true" : "false") << s << endl;
    }
    std::cout << std::endl;
    return 0;
}