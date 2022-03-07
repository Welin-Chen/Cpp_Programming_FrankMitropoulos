#include <iostream>
#include "Movies.h"

// 無引數建構函數
Movies::Movies()
{
}

// 解構函數
Movies::~Movies() {}

bool Movies::add_movie(std::string name, std::string rating, int watched)
{
    for (const Movie &i : movies)
    {
        if (i.get_name() == name)
            return false;
    }
    Movie temp{name, rating, watched};
    movies.push_back(temp);
    return true;
}

bool Movies::increment_watched(std::string name)
{
    for (Movie &i : movies)
    {
        if (i.get_name() == name)
        {
            i.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display() const
{
    if (movies.size() == 0)
    {
        std::cout << "Sorry,no movies to display\n"
                  << std::endl;
    }
    else
    {
        std::cout << "\n===========================" << std::endl;

        for (const auto &i : movies)
        {
            i.display();
        }
        std::cout << "\n===========================" << std::endl;
    }
}
