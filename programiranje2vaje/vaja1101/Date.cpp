//
// Created by LENOVO on 24. 05. 2022.
//

#include <algorithm>
#include<sstream>
#include "Date.h"
#include"UnparseableDateException.h"

std::string Date::toString() const {
    return std::to_string(day) + "." + std::to_string(month)
           + "." + std::to_string(year);
}

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    this->year = year;
    this->month = month;
    this->day = day;
}

void Date::setDay(unsigned int day) {
    this->day = day;
}

void Date::setMonth(unsigned int month) {
    this->month = month;
}

void Date::setYear(unsigned int year) {
    this->year = year;
}

int Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}

int Date::getYear() {
    return year;
}

Date Date::GetDateFromString(std::string temp) {
    int count = 0;
    int day1=0, month1=0, year1=0;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == '.') {
            count += 1;
        }
    }
    bool allDigits = true;
    for (char const &c: temp) {
        if (std::isdigit(c) == 0 && c != '.') {
            allDigits = false;
        }
    }

    std::string temp2 = temp;
    if (count == 2 && allDigits) {
        for (char &i: temp2) {
            if (i == '.') i = ' ';
        }

        std::stringstream(temp2) >> day1 >> month1 >> year1;

        return Date(day1, month1, year1);


    } else {
        throw UnparseableDateException(temp);
    }
}


Date::Date() {

}


