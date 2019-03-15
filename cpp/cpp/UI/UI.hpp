//
//  UI.hpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 25/03/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef UI_hpp
#define UI_hpp

#include <stdio.h>
#include "Controller.hpp"

class UI
{
private:
    Controller ctrl;
    
public:
    /*
     Constructor for the UI
     Input: c - Controller
     */
    UI(const Controller& c) : ctrl(c) {}
    
    /*
     Starts the program
     Input: None
     Output: the applications starts
     */
    void start();
    
    /*
     Destructor for the UI
     */
    ~UI();
    
private:
    
    /*
     Prints out the options for the administrator
     */
    static void printAdminMenu();
    
    /*
     Prints out the options for the user
     */
    static void printUserMenu();
    
    /*
     Prints out all the movies from the repo
     */
    void displayAllMoviesRepo();
    
    /*
     Prints out all the movies from the repo with the duration less than a given number
     Input: duration - integer
     Output: None
     */
    void displayMoviesLessThan(int duration);
    
    /*
     Prints out all the movies from the watch list
     */
    void displayAllMoviesWatchList();
    
    
    
};

#endif /* UI_hpp */
