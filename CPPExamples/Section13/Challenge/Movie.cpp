#include <iostream>
#include "Movie.h"

// Implementaion for constructor
Movie::Movie(std::string name, std::string rating, int watched)
    : name(name), rating(rating), watched(watched)
{
}

// Implementaion for copy constructor
Movie::Movie(const Movie &source)
    : Movie{source.name, source.rating, source.watched}
{
}

// Implementaion for destructor
Movie::~Movie() {}

// void Movie::display() const
// {
//     std::cout << name << " , " << rating << " , " << watched << std::endl;
// }