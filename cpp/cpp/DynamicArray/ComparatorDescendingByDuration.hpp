//
//  ComparatorDescendingByDuration.hpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 05/04/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef ComparatorDescendingByDuration_hpp
#define ComparatorDescendingByDuration_hpp

#include <stdio.h>
#include "Movie.hpp"
#include "Comparator2.hpp"

class ComparatorDescendingByDuration: public Comparator<Movie>
{
public:
    /*
     Constructor for a ComparatorDescendingByDuration
     */
    ComparatorDescendingByDuration() {}
    
    /*
     Overrides the compare function from the Comparator
     */
    bool compare(const Movie& m1, const Movie& m2) override;
    
    
    /*
     Destructor for a ComparatorDescendingByDuration
     */
    ~ComparatorDescendingByDuration() {}
};


#endif /* ComparatorDescendingByDuration_hpp */
