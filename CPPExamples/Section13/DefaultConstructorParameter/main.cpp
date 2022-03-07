#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
private:
    std::string name;
    int health;
    int xp;

public:
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
};

Player::Player(std::string name_val, int healt_val, int xp_val)
    : name{name_val}, health{healt_val}, xp{xp_val}
{
    cout << "Three-args constructor" << endl;
}

int main()
{
    Player empty;
    Player frank{"Frank"};
    Player hero{"Hero", 100};
    Player villain{"Villain", 100, 55};
    cout << endl;
    return 0;
}