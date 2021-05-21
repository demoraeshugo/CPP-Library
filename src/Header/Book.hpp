#ifndef BOOK_H
#define BOOK_H

#include "./Date.hpp"
#include <string>

class Book 
{      
    private:
        std::string number;
        std::string name;
        bool isCheckedOut;
        Date datePublished;
        static int currentSerialNumber;

    public:
        Book(std::string name, Date datePublished);
        Book(std::string name);
        virtual ~Book();

        std::string getBookNumber();
        Date getDatePublished();
        bool getCheckedOut();
        static std::string getCurrentSerialNumber();

        int compareByNumber(Book book);
        int compareByDate(Book book);
        bool equals(Book book);
        std::string toString();
        void checkOut();
        void checkIn();
};

#endif