//
// Created by LENOVO on 8. 05. 2022.
//

#include "Date.h"

std::string Date::toString() const{
    return std::to_string(day)+ "." + std::to_string(month)
           + "." + std::to_string(year);
}

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    this->year = year;
    this->month = month;
    this->day = day;
}
void Date::setDay(unsigned int day){
    this->day=day;
}
void Date::setMonth(unsigned int month){
    this->month=month;
}
void Date::setYear(unsigned int year){
    this->year=year;
}

std::ostream &operator<<(std::ostream &out, const Date &date) {
    out<<date.toString();
    return out;
}

bool Date::operator==(const Date &other) const {
    if (this == &other)
        return true;
    if ((this->day == other.day) && (this->month == other.month) && (this->year==other.year))
        return true;
    return false;
}

Date &Date::operator++() {
    if(this->monthsSize()){
        this->day++;
    }
    return *this;
}

Date &Date::operator++(int dummy) {
    if (this->monthsSize()){
        this->day+=1;
    }
    return *this;
}

bool Date::monthsSize() const {
    unsigned int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(months[this->month-1]>=this->day){
        return false;
    }
    return true;
}
/*
//prefix operator++
Complex& Complex::operator++() {
    this->real++;
    return *this;
}
//postfix operator++
Complex& Complex::operator++(int dummy) {
    this->real += 10;
    return *this;
}
*/
