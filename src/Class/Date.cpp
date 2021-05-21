#include "../Header/Date.hpp"
#include "../Util/string_util.cpp"

#include <string>
#include <ctime>

Date::Date(std::string date) 
{
    const char DELIMITER = '/';
    vector<string> tokens = split(date, DELIMITER);

    this->month = stoi(tokens[0]);
    this->day = stoi(tokens[1]);
    this->year = stoi(tokens[2]);
}

Date::Date() 
{
    time_t ttime = time(0); 
    tm *local_time = localtime(&ttime);

    this->month = local_time->tm_mon + 1; // zero based
    this->day = local_time->tm_mday;
    this->year = local_time->tm_year + 1900; // years since 1900
}

Date::~Date() {}

int Date::getYear() 
{
    return year;
}

int Date::getMonth() 
{
    return month;
}

int Date::getDay() 
{
    return day;
}

int Date::getFebruaryDays() 
{
    const int QUADRENNIAL = 4;
    const int CENTENNIAL = 100;
    const int QUADRICENTENNIAL = 400;
    const int FEB_DAYS_LEAP_YEAR = 29;
    const int FEB_DAYS_NON_LEAP_YEAR = 28;

    if (((year % QUADRENNIAL == 0) & !(year % CENTENNIAL == 0)) || (year % QUADRICENTENNIAL == 0)) {
        return FEB_DAYS_LEAP_YEAR;
    } else {
        return FEB_DAYS_NON_LEAP_YEAR;
    }
}

int Date::getDaysInMonth() 
{
    const int DAYS_IN_30DAY_MONTH = 30;
    const int DAYS_IN_31DAY_MONTH = 31;
    const int INDEX_OF_MONTH = month;
    int result;

    switch (INDEX_OF_MONTH) {
        case JANUARY:
        case MARCH:
        case MAY:
        case JULY:
        case AUGUST:
        case OCTOBER:
        case DECEMBER:
            result = DAYS_IN_31DAY_MONTH;
        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            result = DAYS_IN_30DAY_MONTH;
        case FEBRUARY: 
            result = getFebruaryDays();
        default:
            result = -1;
    }

    return result;
}

bool Date::isValidYear() 
{
    Date today = Date();
    int yearLeftBound = 1900;
    int yearRightBound = today.year;

    return (year >= yearLeftBound && year < yearRightBound)
            || (year == yearRightBound && month < today.month)
            || (year == yearRightBound && month == today.month && day <= today.day);
}

bool Date::isValidMonth() 
{
    int MAX_MONTH_NUM = 12;
    int MIN_MONTH_NUM = 1;
    return month >= MIN_MONTH_NUM && month <= MAX_MONTH_NUM;
}

bool Date::isValidDay() 
{
    return day <= getDaysInMonth() && day > 0;
}

bool Date::isValid() 
{
    return isValidYear() && isValidMonth() && isValidDay();
}

std::string Date::toString() 
{
    return std::to_string(month) 
            + "/" 
            + std::to_string(day) 
            + "/" 
            + std::to_string(year);
}