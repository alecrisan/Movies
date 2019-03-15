//
//  ComparatorAscendingByTitle2.hpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 05/04/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef ComparatorAscendingByTitle2_hpp
#define ComparatorAscendingByTitle2_hpp

#include <stdio.h>
#include "Movie.hpp"
#include "Comparator2.hpp"

class ComparatorAscendingByTitle: public Comparator<Movie>
{
public:
    /*
     Constructor for a ComparatorAscendingByTitle
     */
    ComparatorAscendingByTitle() {}
    
    /*
     Overrides the compare function from the Comparator
     */
    bool compare(const Movie& m1, const Movie& m2) override;
    
    /*
     Destructor for a ComparatorAscendingByTitle
     */
    ~ComparatorAscendingByTitle() {}
};

#endif /* ComparatorAscendingByTitle2_hpp */
