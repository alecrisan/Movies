//
//  main.cpp
//  cpp
//
//  Created by Crisan Alexandra on 25/03/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//
#include <iostream>
#include "Movie.hpp"
#include "UI.hpp"
#include "Tests.hpp"
#include "Exception.hpp"
#include "CSVWatchList.hpp"
#include "HTMLWatchList.hpp"

using namespace std;

int main()
{
    try
    {
        //Tests::testAll();
        Repo repo{};
        repo.loadFromFile();
        MovieValidator val{};
        string choice;
        cout<<"Where do you want to store your watchlist? csv/html?"<<endl;
        getline(cin, choice);
        if (choice == "csv")
        {
            FileWatchList* w = new CSVWatchList{"WatchList.csv"};
            Controller ctrl{repo, w, val};
            UI ui{ctrl};
            ui.start();
            delete w;
        }
        else if (choice == "html")
        {
            FileWatchList* w = new HTMLWatchList{"WatchList.html"};
            Controller ctrl{repo, w, val};
            UI ui{ctrl};
            ui.start();
            delete w;
        }
        else
        {
            cout<<"Not a valid option"<<endl;
            return 0;
        }
    }
    catch(Exception& e)
    {
        cout<<e.what()<<endl;
    }
    return 0;
}
