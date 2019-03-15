//
//  Exception.hpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 20/04/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef Exception_hpp
#define Exception_hpp

#include <stdio.h>
#include <string>
#include <exception>

using namespace std;

class Exception: public exception
{
private:
    string message;
    
public:
    /*
     Constructor for an Exception
     */
    Exception(const string &mess);
    
    virtual const char* what();
    
};

#endif /* Exception_hpp */
