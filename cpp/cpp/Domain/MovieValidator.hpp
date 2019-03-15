//
//  MovieValidator.hpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 17/04/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef MovieValidator_hpp
#define MovieValidator_hpp

#include <stdio.h>
#include "Movie.hpp"

class MovieException
{
private:
    vector<string> messages;

public:
    
    /*
     Constructor with parameters for a MovieException
     */
    MovieException(vector<string> _messages);

    /*
     Gets the error messages
     Returns a vector of strings
     */
    vector<string> getErrorMsg() const {return this->messages; }

};

class MovieValidator
{
  
public:
    
    /*
     Default constructor for a MovieValidator
     */
    MovieValidator() {}
    
    /*
     Checks whether the movie is valid or not
     */
    static void validate(const Movie& m);
    
};


#endif /* MovieValidator_hpp */
