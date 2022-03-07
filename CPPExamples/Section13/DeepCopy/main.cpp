#include <iostream>

using namespace std;

class Deep
{
private:
    int *data;

public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }

    Deep(int d);              // Contructor建構子(建立物件object)
    Deep(const Deep &source); // Copy contructor複製建構子
    ~Deep();                  //Destructor解構子
};

Deep::Deep(int d) // Contructor建構子(建立物件object)
{
    data = new int;
    *data = d;
}

Deep::Deep(const Deep &source) // Copy contructor複製建構子
    : Deep(*source.data)
{
    cout << "Copy constructor - Deep copy" << endl;
}

Deep::~Deep() //Destructor解構子
{
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_Deep(Deep s)
{
    cout << s.get_data_value() << endl;
}

int main()
{
    Deep obj1{100};
    display_Deep(obj1);

    Deep obj2{obj1};
    obj2.set_data_value(1000);

    cout << endl;
    return 0;
}