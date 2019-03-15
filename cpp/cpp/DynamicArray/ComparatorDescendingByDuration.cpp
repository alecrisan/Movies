//
//  ComparatorDescendingByDuration.cpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 05/04/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#include "ComparatorDescendingByDuration.hpp"

bool ComparatorDescendingByDuration::compare(const Movie& m1, const Movie& m2)
{
    return m1.getDuration() < m2.getDuration();
}
