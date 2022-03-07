#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs);
    friend bool operator<(const Mystring &lhs, const Mystring &rhs);
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator-(Mystring &obj);
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
    friend Mystring &operator+=(Mystring &lhs, const Mystring &rhs);
    friend Mystring operator*(const Mystring &lhs, int n);
    friend Mystring &operator*=(Mystring &lhs, int n);
    friend Mystring &operator++(Mystring &obj);     //pre-increment ++s1
    friend Mystring operator++(Mystring &lhs, int); //post-increment s1++

    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str; //pointer to a char[] that hold a C-style string
public:
    Mystring();                       // no args constructor
    Mystring(const char *s);          //Overloaded constructor
    Mystring(const Mystring &source); //Copy constructor
    Mystring(Mystring &&source);      //Move constructor
    ~Mystring();                      //Desturctor

    Mystring &operator=(const Mystring &rhs); //Copy assignment
    Mystring &operator=(Mystring &&rhs);      //Move assignment

    void display() const;

    int get_length() const;
    const char *get_str() const;
};
#endif // _MYSTRING_H_