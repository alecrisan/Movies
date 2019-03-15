//
//  Controller.cpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 25/03/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#include "Controller.hpp"
#include "Exception.hpp"
#include "MovieValidator.hpp"

int Controller::addMovieToWatchList(const Movie& m)
{
//    if (this->watchlist == nullptr)
//        return;
    int poz = this->watchlist->findPoz(m.getTitle(), m.getYearOfRelease());
    if (poz != -1)
        return 0;
    this->watchlist->add(m);
    this->watchlist->writeToFile();
    return 1;
}

int Controller::delMovieFromWatchList(const string& title, int yearOfRelease)
{
    int poz = this->watchlist->findPoz(title, yearOfRelease);
    if (poz == -1)
        return 0;
    this->watchlist->del(title, yearOfRelease);
    this->watchlist->writeToFile();
    return 1;
}

void Controller::addMovieToRepo(const string& title, const string& genre, int yearOfRelease, int nrLikes, const string& trailer, int duration)
{
    int poz = this->repo.findPoz(title, yearOfRelease);
    if (poz != -1)
        throw Exception("Movie already exists");
    Movie m{ title, genre, yearOfRelease, nrLikes, trailer, duration};
    this->validator.validate(m);
    this->repo.addMovie(m);
}

void Controller::delMovieRepo(const string& title, int yearOfRelease)
{
    int poz = this->repo.findPoz(title, yearOfRelease);
    if (poz == -1)
        throw Exception("The movie you're trying to delete doesn't exist");
    this->repo.delMovie(poz);
}

void Controller::updateMovieRepo(const string& title, int yearOfRelease, Movie& newM)
{
    int poz = this->repo.findPoz(title, yearOfRelease);
    if (poz == -1)
        throw Exception("The movie you're trying to update doesn't exist");
    this->validator.validate(newM);
    this->repo.updateMovie(poz, newM);
}


void Controller::filter(const string& genre)
{
    this->repo.filterByGenre(genre);
}

void Controller::startWatchList()
{
    this->repo.play();
}

void Controller::nextMovieWatchList()
{
    this->repo.next();
}

void Controller::openWatchList()
{
    this->watchlist->displayWatchList();
}

void Controller::initRepo()
{
    Movie m1{ "Step Up", "Drama", 2006, 155, "https://www.youtube.com/watch?v=ZgnmCqA25-o", 120};
    Movie m2{ "It", "Thriller", 2017, 2000, "https://www.youtube.com/watch?v=FnCdOQsX5kc", 100};
    Movie m3{ "Beauty and the Beast", "Fantasy", 2017, 350, "https://www.youtube.com/watch?v=e3Nl_TCQXuw", 90};
    Movie m4{ "The maze runner", "Science fiction", 2014, 400, "https://www.youtube.com/watch?v=64-iSYVmMVY", 120};
    Movie m5{ "Now you see me", "Mystery", 2013, 500, "https://www.youtube.com/watch?v=4OtM9j2lcUA", 110};
    Movie m6{ "We're the millers", "Comedy", 2013, 450, "https://www.youtube.com/watch?v=0Vsy5KzsieQ", 100};
    Movie m7{ "Love, Rosie", "Romance", 2014, 1000, "https://www.youtube.com/watch?v=SqSE6Kzuht0", 180};
    Movie m8{ "Kingsman: The secret service", "Science fiction", 2014, 1200, "https://www.youtube.com/watch?v=kl8F-8tR8to&t=7s", 80};
    Movie m9{ "Project X", "Comedy", 2012, 700, "https://www.youtube.com/watch?v=3BEIhA8CcY0", 115};
    Movie m10{ "Shutter Island", "Thriller", 2010, 800, "https://www.youtube.com/watch?v=5iaYLCiq5RM", 120};
    
    this->repo.addMovie(m1);
    this->repo.addMovie(m2);
    this->repo.addMovie(m3);
    this->repo.addMovie(m4);
    this->repo.addMovie(m5);
    this->repo.addMovie(m6);
    this->repo.addMovie(m7);
    this->repo.addMovie(m8);
    this->repo.addMovie(m9);
    this->repo.addMovie(m10);
}

Controller::~Controller()
{
    
}

