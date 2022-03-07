#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <string>
#include <vector>
#include "Movie.h"

class Movies
{
private:
    std::vector<Movie> movies;

public:
    Movies();  //建構子
    ~Movies(); //解構子

    bool add_movie(std::string name, std::string rating, int watched);

    bool increment_watched(std::string name);

    void display() const;
};

#endif // _MOVIES_H_
