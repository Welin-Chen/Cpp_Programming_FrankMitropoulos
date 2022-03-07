// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>

using namespace std;

template <typename T>
void display(const deque<T> &d)
{
    cout << "[ ";
    for (const auto i : d)
        cout << i;
    cout << " ]" << endl;
}

template <typename T>
void display(stack<T> s)
{
    cout << "[ ";
    while (!s.empty())
    {
        T i = s.top();
        s.pop();
        cout << i << " ";
    }
    cout << "]" << endl;
}

template <typename T>
void display(queue<T> q)
{
    cout << "[ ";
    while (!q.empty())
    {
        T i = q.front();
        q.pop();
        cout << i << " ";
    }
    cout << "]" << endl;
}

bool operator==(stack<char> stk, queue<char> q)
{
    while (!stk.empty())
    {
        if (stk.top() != q.front())
            return false;
        stk.pop();
        q.pop();
    }
    return true;
}

bool operator==(queue<char> q, stack<char> stk)
{
    while (!q.empty())
    {
        if (q.front() != stk.top())
            return false;
        q.pop();
        stk.pop();
    }
    return true;
}

bool is_palindrome(const std::string &s)
{
    stack<char> stk;
    queue<char> q;

    for (auto c : s)
    {
        if (isalpha(c))
        {
            stk.push(toupper(c));
            q.push(toupper(c));
        }
    }
    // display(stk);
    // display(q);

    return (stk == q);
    // return (q == stk);
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