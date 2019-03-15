//
//  Exception.cpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 20/04/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#include "Exception.hpp"

Exception::Exception(const string & mess) : message(mess)
{
}

const char* Exception::what()
{
    return message.c_str();
}
