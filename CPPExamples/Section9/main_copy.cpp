#include <iostream>
#include <vector>
using namespace std;
class NODE
{
public:
    char symbol;
    int count;
};
int main()
{
    NODE temp;
    vector<NODE> gem_list;

    temp.symbol = 'a';
    temp.count = 0;
    gem_list.push_back(temp);

    temp.symbol = 'b';
    temp.count = 1;
    gem_list.push_back(temp);

    // .. 經過幾次push_back

    for (int i = 0; i < gem_list.size(); i++)
        cout << gem_list[i].symbol << " " << gem_list[i].count << endl;

    return 0;
}