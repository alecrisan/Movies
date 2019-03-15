//
//  FileWatchList.hpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 01/05/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef FileWatchList_hpp
#define FileWatchList_hpp

#include <stdio.h>
#include "WatchList.hpp"

class FileWatchList : public WatchList
{
protected:
    string filename;

public:
    /*
     Constructor with parameters for a FileWatchList
     */
    FileWatchList(const string& filename)
    {
        this->filename = filename;
    }
    
    /*
     Virtual destructor for a FileWatchList
     */
    virtual ~FileWatchList() {}
    
    /*
     Virtual function that writes to a file
     */
    virtual void writeToFile() = 0;
    
    /*
     Virtual function that displays the watchlist
     */
    virtual void displayWatchList() const = 0;
};

#endif /* FileWatchList_hpp */
