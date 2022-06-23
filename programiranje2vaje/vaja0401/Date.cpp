//
// Created by LENOVO on 21. 03. 2022.
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
