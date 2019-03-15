//
//  UI.cpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 25/03/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#include "UI.hpp"
#include "MovieValidator.hpp"
#include "Exception.hpp"

using namespace std;

void UI::printAdminMenu()
{
    cout<<" Admin options: "<<endl;
    cout<<"\t 1. List all movies"<<endl;
    cout<<"\t 2. Add a movie"<<endl;
    cout<<"\t 3. Delete a movie"<<endl;
    cout<<"\t 4. Update a movie"<<endl;
    cout<<"\t 5. List all movies with the duration less than a given number"<<endl;
    cout<<"\t 0. Back"<<endl;
}

void UI::printUserMenu()
{
    cout<<" User options: "<<endl;
    cout<<"\t 1. See all movies, one by one"<<endl;
    cout<<"\t 2. Add a movie to your watchlist"<<endl;
    cout<<"\t 3. Next movie"<<endl;
    cout<<"\t 4. Delete a movie from your watchlist"<<endl;
    cout<<"\t 5. See all your movies"<<endl;
    cout<<"\t 0. Back"<<endl;
}

void UI::displayAllMoviesRepo()
{
    vector<Movie> v = this->ctrl.getRepo().getMovies();
    
    if(v.empty())
        return;
    
    if (v.size() == 0)
    {
        cout << "There are no movies in the repository." << endl;
        return;
    }
    int i = 0;
    for (auto m : v)
    {
        i++;
        cout << i <<". Title: " << m.getTitle() << "; Genre: " << m.getGenre() << "; Year: " << m.getYearOfRelease() << "; Likes: " << m.getnrLikes() << "; Duration: " << m.getDuration()<<endl;
    }
}

void UI::displayMoviesLessThan(int duration)
{
    vector<Movie> v = this->ctrl.getRepo().getMovies();
    
    if(v.empty())
        return;
    
    if (v.size() == 0)
    {
        cout << "There are no movies in the repository." << endl;
        return;
    }
    for (auto m : v)
    {
        if (m < duration)
            cout <<"Title: " << m.getTitle() << "; Genre: " << m.getGenre() << "; Year: " << m.getYearOfRelease() << "; Likes: " << m.getnrLikes() << "; Duration: " << m.getDuration()<<endl;
    }
}

void UI::displayAllMoviesWatchList()
{
    vector<Movie> v = this->ctrl.getWatchList()->getMovs();
    
    if(v.empty())
        return;
    
    if (v.size() == 0)
    {
        cout << "There are no movies in your watchlist." << endl;
        return;
    }
    int i = 0;
    for (auto m : v)
    {
        i++;
        cout << i <<". Title: " << m.getTitle() << "; Genre: " << m.getGenre() << "; Year: " << m.getYearOfRelease() << "; Likes: " << m.getnrLikes() << "; Duration: " << m.getDuration()<<endl;
    }
}


void UI::start()
{
    while(true)
    {
        string choose;
        cout<<"Who are you, admin or user? (0 if you want to exit)"<<endl;
        getline(cin, choose);
        if (choose == "admin")
        {
            printAdminMenu();
            while(true)
            {
                int option;
                cout<<"Enter an option: ";
                cin>>option;
                cin.ignore();
        
                if (option == 1)
                    this->displayAllMoviesRepo();
            
                else if (option == 2)
                {
                    cout<<"You chose to add a new movie"<<endl;
            
                    cout<<"Enter the title: ";
                    string title;
                    getline(cin, title);
            
                    cout<<"Enter the genre: ";
                    string genre;
                    getline(cin, genre);
            
                    cout<<"Enter the year of release: ";
                    int yearOfRelease;
                    cin>>yearOfRelease;
                    cin.ignore();
            
                    cout<<"Enter the number of likes: ";
                    int nrLikes;
                    cin>>nrLikes;
                    cin.ignore();
            
                    cout<<"Enter the link for the trailer: ";
                    string trailer;
                    getline(cin, trailer);
                    
                    cout<<"Enter the duration: ";
                    int duration;
                    cin>>duration;

                    try
                    {
                        this->ctrl.addMovieToRepo(title, genre, yearOfRelease, nrLikes, trailer, duration);
                    }
                    catch (MovieException& me)
                    {
                        for(auto m : me.getErrorMsg())
                            cout<<m;
                    }
                    catch(Exception& e)
                    {
                        cout<<e.what()<<endl;
                    }
            
                }
            
                else if (option == 3)
                {
                    cout<<"You chose to delete a movie"<<endl;
            
                    cout<<"Enter the title: ";
                    string title;
                    getline(cin, title);
            
                    cout<<"Enter the year of release: ";
                    int yearOfRelease;
                    cin>>yearOfRelease;
            
                    try
                    {
                        this->ctrl.delMovieRepo(title, yearOfRelease);
                    }
                    catch(Exception& e)
                    {
                        cout<<e.what()<<endl;
                    }
                }
            
                else if (option == 4)
                {
                    cout<<"You chose to update a movie"<<endl;
                    
                    cout<<"With the title: ";
                    string title;
                    getline(cin, title);
            
                    cout<<"And the year of release: ";
                    int yearOfRelease;
                    cin>>yearOfRelease;
                    cin.ignore();
            
                    cout<<"Enter the new title: ";
                    string newtitle;
                    getline(cin, newtitle);
                
                    cout<<"Enter the new genre: ";
                    string newgenre;
                    getline(cin, newgenre);
                
                    cout<<"Enter the new year of release: ";
                    int newyearOfRelease;
                    cin>>newyearOfRelease;
                    cin.ignore();
                
                    cout<<"Enter the new number of likes: ";
                    int newnrLikes;
                    cin>>newnrLikes;
                    cin.ignore();
                
                    cout<<"Enter the new link for the trailer: ";
                    string newtrailer;
                    getline(cin, newtrailer);
                    
                    cout<<"Enter the new duration: ";
                    int newduration;
                    cin>>newduration;
                
                    Movie m{newtrailer, newgenre, newyearOfRelease, newnrLikes, newtrailer, newduration};
                    try
                    {
                        this->ctrl.updateMovieRepo(title, yearOfRelease, m);
                    }
                    catch(Exception& e)
                    {
                        cout<<e.what()<<endl;
                    }
                    catch(MovieException& me)
                    {
                        for(auto m : me.getErrorMsg())
                            cout<<m;
                    }
                }
                else if (option == 5)
                {
                    cout<<"Enter the duration: ";
                    int duration;
                    cin>>duration;
                    
                    this->displayMoviesLessThan(duration);
                }
                
                else if (option == 0)
                {
                    cout<<"Exited the program"<<endl;
                    break;
                }
                
                else
                    cout<<"Not a valid option"<<endl;
            
            }
        }
        else if (choose == "user")
        {
            printUserMenu();
            while (true)
            {
                int option;
                cout<<"Enter an option: ";
                cin>>option;
                cin.ignore();
                
                if (option == 1)
                {
                    string genre;
                    cout<<"Enter a genre: ";
                    getline(cin, genre);
                    
                    this->ctrl.filter(genre);
                    
                    this->ctrl.startWatchList();
                    Movie m = this->ctrl.getRepo().getCurrentMovie();
                    cout<<"Title: " << m.getTitle() << "; Genre: " << m.getGenre() << "; Year: " << m.getYearOfRelease() << "; Likes: " << m.getnrLikes() << "; Duration: " <<m.getDuration()<<endl;
                }
                else if (option == 2)
                {
                    Movie m = this->ctrl.getRepo().getCurrentMovie();
                    if (this->ctrl.addMovieToWatchList(m) == 1)
                        cout<<"Movie added"<<endl;
                    else
                        cout<<"Movie already in watchlist"<<endl;
                }
                else if (option == 3)
                {
                    this->ctrl.nextMovieWatchList();
                    Movie m = this->ctrl.getRepo().getCurrentMovie();
                    cout<<"Title: " << m.getTitle() << "; Genre: " << m.getGenre() << "; Year: " << m.getYearOfRelease() << "; Likes: " << m.getnrLikes() << "; Duration: " <<m.getDuration()<<endl;
                }
                else if (option == 4)
                {
                    cout<<"What movie from your watch list do you want to delete?"<<endl;
                    cout<<"Title: ";
                    string title;
                    getline(cin, title);
                    
                    cout<<"Year of release: ";
                    int yearOfRelease;
                    cin>>yearOfRelease;
                    cin.ignore();
                    
                    if (this->ctrl.delMovieFromWatchList(title, yearOfRelease) == 1)
                    {
                        cout<<"Movie deleted. Did you like it?"<<endl;
                        string answer;
                        getline(cin, answer);
                        
                        if (answer == "yes")
                        {
                            int poz = this->ctrl.getRepo().findPoz(title, yearOfRelease);
                            this->ctrl.getRepo().getMovies().at(poz).increaseLike();
                            cout<<"Number of likes: "<<this->ctrl.getRepo().getMovies()[poz].getnrLikes()<<endl;
                        }
                        else if (answer == "no")
                            cout<<"Sorry you didn't like it"<<endl;
                    }
                    else
                        cout<<"Movie not found"<<endl;
                    
                }
                else if (option == 5)
                {
                    cout<<"Your watchlist: "<<endl;
                    this->displayAllMoviesWatchList();
                    this->ctrl.openWatchList();
                }
                else if (option == 6)
                {
                    this->displayAllMoviesRepo();
                }
                else if (option == 0)
                    break;
            }
        }
        else if (choose == "0")
            break;
        
        else
            cout<<"Not a valid option"<<endl;
    }
}

UI::~UI()
{
    
}
