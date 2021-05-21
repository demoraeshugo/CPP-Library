#ifndef LIBRARY_H
#define LIBRARY_H

#include "./Book.hpp"

class Library 
{      
    private:
        const int SIZE_FACTOR = 4;
        Book *books[4]; // array-based implementation of the bag data structure
        int numBooks; // the number of books currently in the bag
    public:
        Library();
        virtual ~Library();

        void sortByNumber();
        void sortByDate();
        void grow();
        int find(Book book);
        void add(Book book);
        bool remove(Book book);
        bool checkOut(Book book);
        bool returns(Book book);
        bool isEmpty();
        void print();
        void printDefault();
        void printByDate();
        void printByNumber();
};

#endif