//
//  Comparator2.hpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 05/04/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef Comparator2_hpp
#define Comparator2_hpp

#include <stdio.h>

template <typename T>

class Comparator
{
public:
    /*
     Constructor for a Comparator
     */
    Comparator() {}
    
    /*
     Function that compares two entities
     Input : t1, t2
     Output: True or False
     */
    virtual bool compare(const T& t1, const T& t2) = 0;
    
    /*
     Destructor for a Comparator
     */
    ~Comparator() {}
};

#endif /* Comparator2_hpp */
