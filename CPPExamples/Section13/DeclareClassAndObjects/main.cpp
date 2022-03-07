#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
    // atributes
    string name{"Player"};
    int health{100};
    int xp{3};
    // methods
    void talk();
    void is_dead();
};

class Account
{
    // attributes
    string name{"Account"};
    double balanece{0.0};

    // methods
    bool deposit(double);
    bool withdraw(double);
};
int main()
{
    Account frank_account;
    Account jim_account;

    Player frank;
    Player hero;

    Player players[]{frank, hero};

    Player *enemy{nullptr};
    enemy = new Player;

    vector<Player> player_vec{frank};
    player_vec.push_back(hero);

    delete enemy;
    cout << endl;
    return 0;
}