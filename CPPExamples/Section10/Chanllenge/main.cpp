#include <iostream>
#include <string>
using namespace std;

int main()
{
    string alphabet{" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key{"[ZXCVBNMASDFGHJKLQWERTYUIOPzxcvbnmasdfghjklqwertyuiop"};

    string secret_message{};
    cout << "\nEnter your secret message: ";
    getline(cin, secret_message);

    string encry_message{};
    cout << "\nEncrypting message..." << endl;

    for (char c : secret_message)
    {
        size_t position = alphabet.find(c);
        if (position != string::npos)
            encry_message += key[position];
        else
            encry_message += c;
    }

    cout << "\nEncrypted message: " << encry_message << endl;

    string decry_message{};
    cout << "\nDecrypting message..." << endl;

    for (char c : encry_message)
    {
        size_t position = key.find(c);
        if (position != string::npos)
            decry_message += alphabet[position];
        else
            decry_message += c;
    }

    cout << "\nDecrypted message: " << decry_message << endl;

    cout << endl;
    return 0;
}