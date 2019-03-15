//
//  CSVWatchList.hpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 01/05/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef CSVWatchList_hpp
#define CSVWatchList_hpp

#include <stdio.h>
#include "FileWatchList.hpp"

class CSVWatchList : public FileWatchList
{
public:
    /*
     Constructor with parameters for a CSVWatchList
     */
    CSVWatchList(const string& filename) : FileWatchList{ filename } {}
    
    /*
     Writes the watchlist to file.
     Throws an Exception if it can't write
     */
    void writeToFile() override;
    
    /*
     Displays the watchlist using a text editor
     */
    void displayWatchList() const override;
};

#endif /* CSVWatchList_hpp */
