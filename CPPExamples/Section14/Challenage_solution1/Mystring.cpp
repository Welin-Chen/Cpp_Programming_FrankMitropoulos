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
bool Mystring ::operator==(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) == 0);
}

// Not euality
bool Mystring ::operator!=(const Mystring &rhs) const
{
    return !(std::strcmp(str, rhs.str) == 0);
}

// < less than
bool Mystring ::operator<(const Mystring &rhs) const
{
    // return (std::strcmp(str, rhs.str) < 0);
    return (str < rhs.str);
}

// > greater than
bool Mystring ::operator>(const Mystring &rhs) const
{
    // return (std::strcmp(str, rhs.str) > 0);
    return (str > rhs.str);
}

// - lowercase
Mystring Mystring ::operator-() const
{
    char *buff = new char[std::strlen(str) + 1];
    strcpy(buff, str);
    for (auto i{0}; i < strlen(str); i++)
    {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// + concatenation
Mystring Mystring ::operator+(const Mystring &rhs) const
{
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    strcpy(buff, str);
    strcat(buff, rhs.str);
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// +=
Mystring &Mystring::operator+=(const Mystring &rhs)
{
    *this = *this + rhs;
    return *this;
}

// * repeat
Mystring Mystring::operator*(int n) const
{
    Mystring temp;
    for (auto i{0}; i < n; i++)
    {
        temp = temp + *this;
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
Mystring &Mystring::operator*=(int n)
{
    *this = *this * n;
    return *this;
}

// ++s pre-increment - make uppercase
Mystring &Mystring ::operator++()
{
    for (auto i{0}; i < strlen(str); i++)
    {
        str[i] = std::toupper(str[i]);
    }
    return *this;
}

// s++ post-increment - make uppercase
Mystring Mystring ::operator++(int)
{
    Mystring temp(*this);
    operator++();
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
