#include <iostream>

using namespace std;

class Test
{
private:
    int data;

public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data{data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

void my_deleter(Test *ptr)
{
    std::cout << "\tUsing my costum function deleter" << std::endl;
    delete ptr;
}

int main()
{
    {
        std::shared_ptr<Test> ptr1{new Test{100}, my_deleter};
    }
    cout << "==================" << endl;
    {
        std::shared_ptr<Test> ptr2(new Test{1000}, [](Test *ptr)
                                   {
                                       cout << "\tUsing my custom lamdba deleter" << endl;
                                       delete ptr;
                                   });
    }
    cout << endl;
    return 0;
}