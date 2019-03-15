//
//  WatchList.hpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 29/03/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef WatchList_hpp
#define WatchList_hpp

#include <stdio.h>
#include "Movie.hpp"
#include <vector>

class WatchList
{
  
protected:
    vector<Movie> movs;
    int current;
    
public:
    
    /*
     Default constructor for a WatchList
     */
    WatchList();
    
    /*
     Adds a song to the user's watchlist
     Input: m - a movie
     Output: the movie is added
     */
    void add(const Movie& m);
    
    
    /*
     Deletes a song from the user's watchlist
     Input: title - string
            yearOfRelease - integer
     Output: the movie is deleted
     */
    void del(const string& title, int yearOfRelease);
    
    
    /*
     Finds the position of a movie in the watchlist
     Input: title - string
            yearOfRelease - integer
     Output: the position, an integer, or -1 if the movie wasn't found
     */
    int findPoz(const string& title, int yearOfRelease);

    
    /*
     Gets the movies from the watchlist
     */
    vector<Movie> getMovs() const { return movs; }
    
    /*
     Destructor for a watchlist
     */
    ~WatchList();
};

#endif /* WatchList_hpp */
