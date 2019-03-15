//
//  DynamicArray.hpp
//  LocalMovieDatabase
//
//  Created by Crisan Alexandra on 25/03/2018.
//  Copyright © 2018 Crisan Alexandra. All rights reserved.
//

#ifndef DynamicArray_hpp
#define DynamicArray_hpp

#include <stdio.h>
#include "Comparator2.hpp"

template <typename T>

class DynamicArray
{
private:
    T* elems;
    int len;
    int capacity;
public:
    
    /*
    Default constructor for a DynamicArray
    */
    DynamicArray(int capacity = 10)
    {
        this->len = 0;
        this->capacity = capacity;
        this->elems = new T[capacity];
    }
    
    
    /*
    Copy constructor for a DynamicArray
    */
    DynamicArray(const DynamicArray& arr)
    {
        this->len = arr.len;
        this->capacity = arr.capacity;
        this->elems = new T[this->capacity];
        
        for (int i = 0; i < this->len; i++)
            this->elems[i] = arr.elems[i];
    }
    
    
    /*
    Overloads the assignment operator for a DynamicArray
    */
    DynamicArray& operator=(const DynamicArray& arr)
    {
        if (this == &arr)
            return *this;
        
        this->len = arr.len;
        this->capacity = arr.capacity;
        
        delete[] this->elems;
        this->elems = new T[this->capacity];
        
        for (int i = 0; i < this->len; i++)
            this->elems[i] = arr.elems[i];
        
        return *this;
    }
    
    
    /*
    Overloads the "-" operator for a DynamicArray
    */
    friend DynamicArray& operator-(DynamicArray& arr, const T& e)
    {
        int i = 0;
        
        for(int i = 0; i < arr.getLen(); i++)
        {
            if (e == arr.elems[i])
                break;
        }
        
        for (int j = i; j < arr.getLen() - 1; j++)
            arr.elems[j] = arr.elems[j + 1];
        
        arr.len--;
        
        return arr;
    }
    
    
    /*
    Overloads the "+" operator for a DynamicArray
    */
    DynamicArray& operator+(const T& e)
    {
        this->add(e);
        return *this;
    }
    
    
    /*
     Adds an element to the current DynamicArray
     Input: e - a T element
     Output: the element is added
     */
    void add(const T& e)
    {
        if (this->len == this->capacity)
            this->resize();
        
        this->elems[this->len] = e;
        
        this->len++;
    }
    
    
    /*
     Deletes an element from the array by its position
     Input: poz - an integer
     Output: the element is deleted
     */
    void del(int poz)
    {
        if(poz < 0 || poz >= getLen())
            return;
        
        for (int i = poz; i < getLen() - 1; i++)
            this->elems[i] = this->elems[i + 1];
        
        this->len--;
    }
    
    
    /*
     Updates an element from the array by its position
     Input: poz - an integer
            e - the new T element
     Output: the element is updated
     */
    void update(int poz, T& e)
    {
        this->del(poz);
        this->add(e);
    }
    
    /*
     Resizes the current DynamicArray, multiplying its capacity by a given factor
     Input: factor - real number
     Output: None
     */
    void resize(double factor = 2)
    {
        this->capacity *= factor;
        
        T* newelems = new T[this->capacity];
        
        for (int i = 0; i < this->len; i++)
            newelems[i] = this->elems[i];
        
        delete[] this->elems;
        
        this->elems = newelems;
    }
    
    /*
     Sorts the array using the function compare
     Input: c - comparator
     Output: the array is sorted
     */
    void sort(Comparator<T>& c)
    {
        for (int i = 0; i < this->len - 1; i++)
            for (int j = i + 1; j < this->len; j++)
                if (c.compare(this->elems[i], this->elems[j]) == false)
                    swap(this->elems[i], this->elems[j]);
    }
    
    /*
     Increases the number of likes of a movie
     Input: poz - an integer
     Output: None
     */
    void modifyLike(int poz)
    {
        this->elems[poz].increaseLike();
    }
    
    /*
     Gets the elements of the array
     */
    T* getAllElems() const
    {
        return this->elems;
    }
    
    
    /*
    Overloads the indexing operator for a DynamicArray
    */
    T& operator[](int pos)
    {
        return this->getAllElems()[pos];
    }
    
    /*
     Gets the length of the array
     Returns an integer
     */
    int getLen() const
    {
        return this->len;
    }
    
    /*
     Destructor for a DynamicArray
     */
    ~DynamicArray()
    {
        delete[] this->elems;
    }
    
};



#endif /* DynamicArray_hpp */
