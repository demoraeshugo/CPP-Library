#ifndef DATE_H
#define DATE_H

#include <string>

class Date 
{      
    private:
        int year;
        int month;
        int day;

        enum Months {
            JANUARY,
            FEBRUARY,
            MARCH,
            APRIL,
            MAY,
            JUNE,
            JULY,
            AUGUST,
            SEPTEMBER,
            OCTOBER,
            NOVEMBER,
            DECEMBER
        };

        int getFebruaryDays();
        int getDaysInMonth();
        bool isValidYear();
        bool isValidMonth();
        bool isValidDay();

    public:
        Date(std::string date);
        Date();
        virtual ~Date();

        int getYear();
        int getMonth();
        int getDay();
        bool isValid();
        std::string toString();
};

#endif