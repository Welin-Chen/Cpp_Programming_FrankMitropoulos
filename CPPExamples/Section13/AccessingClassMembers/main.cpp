#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
public:
    // atributes
    string name;
    int health;
    int xp;
    // methods
    void talk(string text_to_say) { cout << name << " says " << text_to_say << endl; }
    void is_dead();
};

class Account
{
public:
    // attributes
    string name;
    double balance;

    // methods
    void deposit(double bal)
    {
        balance += bal;
        cout << name << endl;
        cout << "deposit: " << bal << endl;
        cout << "balance: " << balance << endl;
        cout << endl;
    }
    void withdraw(double bal)
    {
        balance -= bal;
        cout << name << endl;
        cout << "withdraw: " << bal << endl;
        cout << "balance: " << balance << endl;
        cout << endl;
    }
};
int main()
{
    Account frank_account;
    frank_account.name = "Frank's account";
    frank_account.balance = 5000;

    frank_account.deposit(1000);
    frank_account.withdraw(500);

    Account *mary_account = new Account;
    (*mary_account).name = "Frank's account";
    (*mary_account).balance = 10000;

    mary_account->deposit(1000);
    mary_account->withdraw(500);
    delete mary_account;

    Player frank;
    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;
    frank.talk("Hi there");

    Player *enemy = new Player;
    (*enemy).name = "Enemy";
    (*enemy).health = 100;
    enemy->xp = 15;
    enemy->talk("I will destroy you!");

    cout << endl;
    return 0;
}