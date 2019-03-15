//
//  Tests.cpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 28/03/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#include "Tests.hpp"
#include <assert.h>
#include "Movie.hpp"
#include "DynamicArray.hpp"
#include "AdminDatabase.hpp"
#include "Controller.hpp"
#include "ComparatorAscendingByTitle2.hpp"
#include "ComparatorDescendingByDuration.hpp"
#include <vector>
#include "CSVWatchList.hpp"


void Tests::testsMovie()
{
    Movie m{"Black Panther", "Science fiction", 2018, 500, "https://www.youtube.com/watch?v=xjDjIWPwcPU", 120};

    assert (m.getTitle() == "Black Panther");
    assert (m.getGenre() == "Science fiction");
    assert (m.getYearOfRelease() == 2018);
    assert (m.getnrLikes() == 500);
    assert (m.getTrailer() == "https://www.youtube.com/watch?v=xjDjIWPwcPU");
    assert (m.getDuration() == 120);

    Movie m1{"Black Panther", "Science fiction", 2018, 500, "https://www.youtube.com/watch?v=xjDjIWPwcPU", 120};

    assert(m == m1);

    assert(m < 200);

    m.increaseLike();
    assert(m.getnrLikes() == 501);

    m.playTrailer();
}

void Tests::testsDA()
{
    DynamicArray<Movie> v1{ 2 };
    Movie m{"Black Panther", "Science fiction", 2018, 500, "https://www.youtube.com/watch?v=xjDjIWPwcPU", 150};
    Movie m2{ "It", "Thriller", 2017, 2000, "https://www.youtube.com/watch?v=FnCdOQsX5kc", 100};
    Movie m3{ "Beauty and the Beast", "Fantasy", 2017, 350, "https://www.youtube.com/watch?v=e3Nl_TCQXuw", 90};
    Movie m4{ "The maze runner", "Science fiction", 2014, 400, "https://www.youtube.com/watch?v=64-iSYVmMVY", 120};

    v1.add(m);
    v1.add(m2);
    assert(v1.getLen() == 2);
    assert(v1[0].getTitle() == "Black Panther");
    v1.add(m3);
    assert(v1.getLen() == 3);

    DynamicArray<Movie> v2 = v1;
    assert(v2.getLen() == 3);

    DynamicArray<Movie> v3;
    v3 = v1;
    assert(v3[0].getTitle() == "Black Panther");

    v1.del(1);
    assert(v1.getLen() == 2);
    assert(v1[1].getTitle() == "Beauty and the Beast");

    v1.del(10);

    v2.update(2, m4);
    assert(v2[2].getTitle() == "The maze runner");

    DynamicArray<Movie> a{};
    Movie mov{"lala", "da", 1200, 34, "www", 10};
    a = a + mov;

    assert(a.getLen() == 1);
    assert(a[0] == mov);

    a = a + m;
    assert(a.getLen() == 2);

    a = a - mov;
    assert(a.getLen() == 1);
    assert(a[0] == m);

    ComparatorAscendingByTitle c = ComparatorAscendingByTitle();
    v1.sort(c);

    assert(v1.getAllElems()[0].getTitle() == "Beauty and the Beast");

    DynamicArray<Movie> arr{};
    Movie mov1{"Black Panther", "Science fiction", 2018, 500, "https://www.youtube.com/watch?v=xjDjIWPwcPU", 100};
    Movie mov2{ "It", "Thriller", 2017, 2000, "https://www.youtube.com/watch?v=FnCdOQsX5kc", 150};
    ComparatorDescendingByDuration c2 = ComparatorDescendingByDuration();
    v2.sort(c2);

    assert(v2.getAllElems()[0].getTitle() == "It");

}

void Tests::testsDA2()
{
    DynamicArray<int> v1{ 2 };
    v1.add(10);
    v1.add(20);
    assert(v1.getLen() == 2);
    assert(v1[1] == 20);
    v1.add(30);
    assert(v1.getLen() == 3);

    DynamicArray<int> v2 = v1;
    assert(v2.getLen() == 3);

    DynamicArray<int> v3;
    v3 = v1;
    assert(v3[0] == 10);
}

void Tests::testsRepo()
{
    Repo repo{};
    Movie m{"Black Panther", "Science fiction", 2018, 500, "https://www.youtube.com/watch?v=xjDjIWPwcPU", 120};
    Movie m2{ "It", "Thriller", 2017, 2000, "https://www.youtube.com/watch?v=FnCdOQsX5kc", 100};
    //add a movie
    repo.addMovie(m);
    Movie result = repo.findByTitleAndYear("Black Panther", 2018);
    assert(result.getTitle() == m.getTitle() && result.getYearOfRelease() == m.getYearOfRelease());
    result = repo.findByTitleAndYear("Black Panther", 2);
    assert(result.getTitle() == "");


    vector<Movie> arr = repo.getMovies();
    assert(arr.size() == 1);

    repo.addMovie(m2);
    vector<Movie> arr2 = repo.getMovies();
    assert(arr2.size() == 2);

    //delete a movie
    int poz = repo.findPoz("Black Panther", 2018);
    repo.delMovie(poz);
    vector<Movie> arr3 = repo.getMovies();
    assert(arr3.size() == 1);
    assert(arr3[0].getTitle() == "It");

    //update a movie
    repo.updateMovie(0, m);
    vector<Movie> arr4 = repo.getMovies();
    assert(arr4[0].getTitle() == "Black Panther");

    repo.addMovie(m2);
    repo.filterByGenre("Thriller");
    vector<Movie> arr5 = repo.getMovies();
    assert(arr5.size() == 1);
    assert(arr5[0].getGenre() == "Thriller");


}

void Tests::testsWatchlist()
{
    WatchList wlist{};
    Movie m{"Black Panther", "Science fiction", 2018, 500, "https://www.youtube.com/watch?v=xjDjIWPwcPU", 120};
    Movie m2{ "It", "Thriller", 2017, 2000, "https://www.youtube.com/watch?v=FnCdOQsX5kc", 100};

    int p = wlist.findPoz("da", 3);
    assert(wlist.getMovs().size() == 0);
    assert(p == -1);

    //add a movie
    wlist.add(m);
    vector<Movie> arr = wlist.getMovs();
    assert(arr.size() == 1);

    int poz = wlist.findPoz("Black Panther", 2018);
    assert(poz == 0);

    int poz2 = wlist.findPoz("affs", 2);
    assert(poz2 == -1);

    //delete a movie

    wlist.del("Black Panther", 2018);
    assert(wlist.getMovs().size() == 0);

}

void Tests::testsControllerRepo()
{
    Repo repo{};
    MovieValidator val{};
    FileWatchList* w = new CSVWatchList{"testWatchList.csv"};
    Controller ctrl{repo, w, val};

    ctrl.startWatchList();
    ctrl.nextMovieWatchList();

    //add movies to repo
    try
    {
        ctrl.addMovieToRepo("Step Up", "Drama", 2006, 155, "https://www.youtube.com/watch?v=ZgnmCqA25-o", 120);
        ctrl.addMovieToRepo("It", "Thriller", 2017, 2000, "https://www.youtube.com/watch?v=FnCdOQsX5kc", 100);
        ctrl.addMovieToRepo("It", "Thriller", 2017, 2000, "https://www.youtube.com/watch?v=FnCdOQsX5kc", 100); // again

        assert(ctrl.getRepo().getMovies().size() == 2);
        vector<Movie> arr = ctrl.getRepo().getMovies();
        assert(arr[0].getTitle() == "Step Up");
        assert(arr[1].getTitle() == "It");

        //deleting a movie from repo
        ctrl.delMovieRepo("Step Up", 2006);
        ctrl.delMovieRepo("dasj", 3); // not in repo
        assert(ctrl.getRepo().getMovies().size() == 1);
        vector<Movie> arr2 = ctrl.getRepo().getMovies();
        assert(arr2[0].getTitle() == "It");

        //updating a movie from repo
        Movie m{ "Beauty and the Beast", "Fantasy", 2017, 350, "https://www.youtube.com/watch?v=e3Nl_TCQXuw", 90};
        ctrl.updateMovieRepo("It", 2017, m);
        ctrl.updateMovieRepo("fsd", 45, m); // not found
        assert(ctrl.getRepo().getMovies().size() == 1);
        vector<Movie> arr3 = ctrl.getRepo().getMovies();
        assert(arr3[0].getTitle() == "Beauty and the Beast");

        ctrl.filter("Comedy");
        ctrl.filter("null");

        Repo repo2{};
        MovieValidator val2{};
        Controller ctrl2{repo2, w, val2};
        ctrl2.addMovieToRepo("Step Up", "Drama", 2006, 155, "https://www.youtube.com/watch?v=ZgnmCqA25-o", 90);
        ctrl2.startWatchList();
        ctrl2.nextMovieWatchList();


        Repo repo3{};
        MovieValidator val3{};
        Controller ctrl3{repo3, w, val3};
        ctrl3.initRepo();
        ctrl3.startWatchList();
        ctrl3.nextMovieWatchList();
        delete w;
    }
    catch(...)
    {

    }



}

void Tests::testsControllerWatchList()
{
    Repo repo{};
    MovieValidator val{};
    FileWatchList* w = new CSVWatchList{"testWatchList.csv"};
    Controller ctrl{repo, w, val};
    Movie m{"Black Panther", "Science fiction", 2018, 500, "https://www.youtube.com/watch?v=xjDjIWPwcPU", 120};
    Movie m2{ "It", "Thriller", 2017, 2000, "https://www.youtube.com/watch?v=FnCdOQsX5kc", 100};
    //add movies to watchlist

    ctrl.addMovieToWatchList(m);
    ctrl.addMovieToWatchList(m); // already there
    assert(ctrl.getWatchList()->getMovs().size() == 1);

    //delete movies from watchlist

    ctrl.delMovieFromWatchList("Black Panther", 2018);
    ctrl.delMovieFromWatchList("fda", 3); // not found
    assert(ctrl.getWatchList()->getMovs().size() == 0);
    
    delete w;


}

void Tests::testAll()
{
    testsMovie();
    testsDA();
    testsDA2();
    testsRepo();
    testsWatchlist();
    testsControllerRepo();
    testsControllerWatchList();
}
