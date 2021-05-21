#include "../Header/Book.hpp"
#include "../Header/Date.hpp"

#include <string>

int Book::currentSerialNumber = 10001;

Book::Book(std::string name, Date getDatePublished)
{
    this->number = getCurrentSerialNumber();
    this->name = name;
    this->datePublished = datePublished;
}

Book::Book(std::string name)
{
    this->name = name;
}

std::string Book::getBookNumber() 
{
    return this->number;
}

Date Book::getDatePublished() 
{
    return this->datePublished;
}

int Book::compareByNumber(Book book) 
{
    const bool COMPARITOR_NUMBER_IS_LESS_THAN = stoi(this->getBookNumber()) > stoi(book.getBookNumber());
    const bool COMPARITOR_NUMBER_IS_EQUAL_TO = stoi(this->getBookNumber()) == stoi(book.getBookNumber());

    if (COMPARITOR_NUMBER_IS_LESS_THAN) {
        return 1;
    } else if (COMPARITOR_NUMBER_IS_EQUAL_TO) {
        return 0;
    } else {
        return -1;
    }
}

int Book::compareByDate(Book book)
{
    // first compare years
    const bool COMPARITOR_YEAR_IS_LESS_THAN = this->getDatePublished().getYear() > book.getDatePublished().getYear();
    const bool COMPARITOR_YEAR_IS_GREATER_THAN = this->getDatePublished().getYear() < book.getDatePublished().getYear();

    if (COMPARITOR_YEAR_IS_LESS_THAN) {              
        return -1;
    } else if (COMPARITOR_YEAR_IS_GREATER_THAN) {
        return 1;
    }

    // if years are equal, compare months 
    const bool COMPARITOR_MONTH_IS_GREATER_THAN = this->getDatePublished().getMonth() < book.getDatePublished().getMonth();
    const bool COMPARITOR_MONTH_IS_LESS_THAN = this->getDatePublished().getMonth() > book.getDatePublished().getMonth();

    if (COMPARITOR_MONTH_IS_LESS_THAN) {       
        return -1;
    } else if (COMPARITOR_MONTH_IS_GREATER_THAN) {
        return 1;
    }

    // if months are equal, compare days
    const bool COMPARITOR_DAY_IS_GREATER_THAN = this->getDatePublished().getDay() < book.getDatePublished().getDay();
    const bool COMPARITOR_DAY_IS_LESS_THAN = this->getDatePublished().getDay() > book.getDatePublished().getDay();

    if (COMPARITOR_DAY_IS_GREATER_THAN) {  
        return -1;
    } else if (COMPARITOR_DAY_IS_LESS_THAN) {
        return 1;
    }
    
    return 0;
}

bool Book::equals(Book book)
{
    if(this == &book) {
        return true;
    }

    return (book.number == this->number);
}

std::string Book::toString()
{
    std::string isAvailable;

    if (this->isCheckedOut) {    //first check if Book is checked out or not
        isAvailable = "is not available";
    } else {
        isAvailable = "is available";
    }

    // ex: Book#10007::Design Patterns::5/30/1996::is available.
    return "Book#" + number + "::" + name + "::" + datePublished.toString() + "::" + isAvailable;
}

std::string Book::getCurrentSerialNumber() 
{
    return std::to_string(currentSerialNumber++);
}

bool Book::getCheckedOut() 
{
    return this->isCheckedOut;
}

void Book::checkOut() {
    this->isCheckedOut = true;
}

/**
 * setter method for checkedOut boolean, sets checkedOut as false
 */
void Book::checkIn() {
    this->isCheckedOut = false;
}