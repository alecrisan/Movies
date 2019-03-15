//
//  ComparatorAscendingByTitle2.cpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 05/04/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#include "ComparatorAscendingByTitle2.hpp"


bool ComparatorAscendingByTitle::compare(const Movie& m1, const Movie& m2)
{
    return m1.getTitle().compare(m2.getTitle()) < 0;
}

