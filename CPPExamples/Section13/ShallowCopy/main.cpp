#include <iostream>

using namespace std;

class Shallow
{
private:
    int *data;

public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }

    Shallow(int d);                 // Contructor建構子(建立物件object)
    Shallow(const Shallow &source); // Copy contructor複製建構子
    ~Shallow();                     //Destructor解構子
};

Shallow::Shallow(int d) // Contructor建構子(建立物件object)
{
    data = new int;
    *data = d;
}

Shallow::Shallow(const Shallow &source) // Copy contructor複製建構子
    : data(source.data)
{
    cout << "Copy constructor - shallow copy" << endl;
}

Shallow::~Shallow() //Destructor解構子
{
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_shallow(Shallow s)
{
    cout << s.get_data_value() << endl;
}

int main()
{
    Shallow obj1{100};
    display_shallow(obj1);

    Shallow obj2{obj1};
    obj2.set_data_value(1000);

    cout << endl;
    return 0;
}