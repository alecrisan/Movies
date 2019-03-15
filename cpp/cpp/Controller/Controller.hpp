//
//  Controller.hpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 25/03/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <stdio.h>
#include "AdminDatabase.hpp"
#include "WatchList.hpp"
#include "MovieValidator.hpp"
#include "FileWatchList.hpp"

class Controller
{
private:
    Repo repo;
    FileWatchList* watchlist;
    MovieValidator validator;

public:
    /*
     Constructor for a controller
     Input: r - Repo
            val - MovieValidator
     */
    Controller(const Repo& r, FileWatchList* w, MovieValidator val) : repo{r}, watchlist{w}, validator{val}{}
    
    /*
     Gets the repo from the controller
     */
    Repo getRepo() const { return repo; }
    
    
    /*
     Gets the watchlist from the controller
     */
    WatchList* getWatchList() const {return watchlist;}
    
    
    /*
     Adds a movie to the user's watchlist
     Input: m - a movie
     Output: the movie is added
     */
    int addMovieToWatchList(const Movie& m);
    
    
    /*
     Deletes a movie from the user's watchlist
     Input: title - string
            yearOfRelease - integer
     Output: 1 if it was deleted successfully, 0 otherwise
     */
    int delMovieFromWatchList(const string& title, int yearOfRelease);
    
    
    /*
     Adds a movie with the given data to the repository
     Input: title - string
            genre - string
            yearOfRelease - integer
            nrLikes - integer
            trailer - string
     Output: Throws an Exception if the movie already exists
                    a MovieException is the movie is not valid
     */
    void addMovieToRepo(const string& title, const string& genre, int yearOfRelease, int nrLikes, const string& trailer, int duration);
    
    
    /*
     Deletes a movie from the repository
     Input: title - string
            yearOfRelease - integer
     Output: Throws an Exception if the movie doesn't exist
     */
    void delMovieRepo(const string& title, int yearOfRelease);
    
    
    /*
     Updates a movie from the repository
     Input: title - string
            yearOfRelease - integer
            newM - the new movie
     Output: Throws an Exception if the movie doesn't exist
                    a MovieException if the new movie is not valid
     */
    void updateMovieRepo(const string& title, int yearOfRelease, Movie& newM);
    
    /*
     Filters the movies by a given genre
     Input: genre - string
     Output: None
     */
    void filter(const string& genre);
    
    /*
     Starts viewing the movies one by one
     */
    void startWatchList();
    
    /*
     Moves to the next movie in the repo
     */
    void nextMovieWatchList();
    
    /*
     Opens the watchlist in a text editor
     */
    void openWatchList();
    
    /*
     Initializes the repository
     */
    void initRepo();

    /*
     Destructor for a controller
     */
    ~Controller();
};

#endif /* Controller_hpp */
