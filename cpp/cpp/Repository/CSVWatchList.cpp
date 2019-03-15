//
//  CSVWatchList.cpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 01/05/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#include "CSVWatchList.hpp"
#include "Exception.hpp"

void CSVWatchList::writeToFile()
{
    ofstream g(this->filename);
    
    if (!g.is_open())
        throw Exception("The file could not be opened!");
    
    for (auto m : this->movs)
    {
        g << m;
    }
    
    g.close();
}

void CSVWatchList::displayWatchList() const
{
    system(("open "s + this->filename).c_str());
}
