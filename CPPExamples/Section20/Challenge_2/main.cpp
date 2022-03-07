// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

using namespace std;

class Song
{
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;

public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const
    {
        return name;
    }
    std::string get_artist() const
    {
        return artist;
    }
    int get_rating() const
    {
        return rating;
    }

    bool operator<(const Song &rhs) const
    {
        return this->name < rhs.name;
    }

    bool operator==(const Song &rhs) const
    {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s)
{
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
    return os;
}

void display_menu()
{
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song)
{
    cout << "Playing: " << endl;
    cout << song << endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song)
{
    for (const auto &song : playlist)
        cout << song << endl;
    cout << "Current song: " << endl;
    cout << current_song << endl;
}

int main()
{

    std::list<Song> playlist{
        {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Camila Cabello", 5},
        {"Pray For Me", "The Weekend and K. Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroone 5", 4},
        {"Whatever It Takes", "Imagine Dragons", 3}};

    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);

    char selection{};
    do
    {
        display_menu();
        cin >> selection;
        selection = toupper(selection);
        if (selection == 'F')
        {
            cout << "Playing first song" << endl;
            current_song = playlist.begin();
            play_current_song(*current_song);
        }
        else if (selection == 'N')
        {
            cout << "Playing next song" << endl;
            current_song++;
            if (current_song == playlist.end())
            {
                cout << "Wrapping to start of playlist" << endl;
                current_song = playlist.begin();
                play_current_song(*current_song);
            }
            else
                play_current_song(*current_song);
        }
        else if (selection == 'P')
        {
            cout << "Playing previous song" << endl;
            if (current_song == playlist.begin())
            {
                cout << "Wrapping to end of playlist" << endl;
                current_song = playlist.end();
            }
            current_song--;
            play_current_song(*current_song);
        }
        else if (selection == 'A')
        {
            string name, artist;
            int rating;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Adding and playing new song" << endl;
            cout << "Enter song name: ";
            getline(cin, name);
            cout << "Enter song artist: ";
            getline(cin, artist);
            cout << "Enter song rating (1-5): ";
            cin >> rating;
            playlist.insert(current_song, Song{name, artist, rating});
            current_song--;
            play_current_song(*current_song);
        }
        else if (selection == 'L')
        {
            cout << endl;
            display_playlist(playlist, *current_song);
        }
        else if (selection == 'Q')
            cout << "Quitting" << endl;
        else
            cout << "illegal choice, try again..." << endl;
    } while (selection != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}