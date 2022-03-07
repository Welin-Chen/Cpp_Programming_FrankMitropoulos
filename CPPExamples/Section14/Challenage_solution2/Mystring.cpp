#include <cstring>
#include <cctype>
#include <iostream>
#include "Mystring.h"

//no args constructor
Mystring::Mystring()
    : str(nullptr)
{
    str = new char[1];
    *str = '\0';
}

//Overloaded constructor
Mystring::Mystring(const char *s)
    : str(nullptr)
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

//Copy constructor
Mystring::Mystring(const Mystring &source)
    : str{nullptr}
{
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
    // std::cout << "Copy constructor used" << std::endl;
}

// Move constructor
Mystring::Mystring(Mystring &&source)
    : str{source.str}
{
    source.str = nullptr;
    // std::cout << "Move constructor used" << std::endl;
}

//Destructor
Mystring::~Mystring()
{
    // if (str == nullptr)
    //     std::cout << "Calling destructor for Mystring : nullptr" << std::endl;
    // else
    //     std::cout << "Calling destructor for Mystring : " << str << std::endl;

    delete[] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
    // std::cout << "Copy assignment" << std::endl;

    if (this == &rhs)
        return *this;
    delete[] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
    // std::cout << "Using move assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Equality
bool operator==(const Mystring &lhs, const Mystring &rhs)
{
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

// Not euality
bool operator!=(const Mystring &lhs, const Mystring &rhs)
{
    return !(std::strcmp(lhs.str, rhs.str) == 0);
}

// < less than
bool operator<(const Mystring &lhs, const Mystring &rhs)
{
    // return (std::strcmp(str, rhs.str) < 0);
    return (lhs.str < rhs.str);
}

// > greater than
bool operator>(const Mystring &lhs, const Mystring &rhs)
{
    // return (std::strcmp(str, rhs.str) > 0);
    return (lhs.str > rhs.str);
}

// - lowercase
Mystring operator-(Mystring &obj)
{
    char *buff = new char[std::strlen(obj.str) + 1];
    strcpy(buff, obj.str);
    for (auto i{0}; i < strlen(obj.str); i++)
    {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// + concatenation
Mystring operator+(const Mystring &lhs, const Mystring &rhs)
{
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    strcpy(buff, lhs.str);
    strcat(buff, rhs.str);
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// +=
Mystring &operator+=(Mystring &lhs, const Mystring &rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

// * repeat
Mystring operator*(const Mystring &lhs, int n)
{
    Mystring temp;
    for (auto i{0}; i < n; i++)
    {
        temp = temp + lhs;
    }
    return temp;
    // char *buff = new char[std::strlen(str) * n + 1];
    // for (auto i{0}; i < n; i++)
    // {
    //     strcat(buff, str);
    // }
    // Mystring temp{buff};
    // delete[] buff;
    // return temp;
}

// *= repeat and assign
Mystring &operator*=(Mystring &lhs, int n)
{
    lhs = lhs * n;
    return lhs;
}

// ++s pre-increment - make uppercase

Mystring &operator++(Mystring &obj)
{
    for (auto i{0}; i < strlen(obj.str); i++)
    {
        obj.str[i] = std::toupper(obj.str[i]);
    }
    return obj;
}

// s++ post-increment - make uppercase
Mystring operator++(Mystring &lhs, int)
{
    Mystring temp{lhs};
    ++lhs;
    return temp;
}

//Display method
void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
int Mystring::get_length() const
{
    return std::strlen(str);
}

// string getter
const char *Mystring::get_str() const
{
    return str;
}

// Overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
    os << rhs.str;
    return os;
}

// Overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs)
{
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete[] buff;
    return in;
}
