#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Date {
    private:
        int day, month, year;
    public:
        Date(): day(0), month(0), year(0) {}
        Date(int day, int month, int year): day(day), month(month), year(year) {}
        Date(const Date& date): day(date.day), month(date.month), year(date.year) {}
        ~Date() {}
        void setDay(int day) {this->day = day;}
        void setMonth(int month) {this->month = month;}
        void setYear(int year) {this->year = year;}
        int getDay() const {return day;}
        int getMonth() const {return month;}
        int getYear() const {return year;}

        Date& operator= (const Date& date)
        {
            this->day = date.day;
            this->month = date.month;
            this->year = date.year;
            return *this;
        }

        friend istream& operator>> (istream&, Date&);
        friend ostream& operator<< (ostream&, const Date&);
};

istream& operator>> (istream& in, Date& date)
{
    in >> date.day >> date.month >> date.year;
    return in;
}

ostream& operator<< (ostream& out, const Date& date)
{
    out << date.day << ' ' << date.month << ' ' << date.year;
    return out;
}

#endif // DATE_H_INCLUDED
