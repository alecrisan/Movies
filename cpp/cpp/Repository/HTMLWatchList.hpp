//
//  HTMLWatchList.hpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 01/05/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef HTMLWatchList_hpp
#define HTMLWatchList_hpp

#include <stdio.h>
#include "FileWatchList.hpp"

class HTMLWatchList : public FileWatchList
{
public:
    /*
     Constructor with parameters for a HTMLWatchList
     */
    HTMLWatchList(const string& filename) : FileWatchList{ filename } {}
    
    /*
     Writes the watchlist to file.
     Throws an Exception if it can't write
     */
    void writeToFile() override;
    
    /*
     Displays the watchlist using a browser
     */
    void displayWatchList() const override;
};

#endif /* HTMLWatchList_hpp */
