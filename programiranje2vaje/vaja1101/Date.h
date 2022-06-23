//
// Created by LENOVO on 24. 05. 2022.
//

#ifndef VAJA1101_DATE_H
#define VAJA1101_DATE_H

#include<iostream>
#include<string>

class Date {
    friend std::ostream& operator<<(std::ostream &out, const Date &date);
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:
    Date(unsigned int day, unsigned int month, unsigned int year);
    Date();
    std::string toString() const;
    void setMonth(unsigned int month);
    void setYear(unsigned int year);
    void setDay(unsigned int day);
    int getMonth();
    int getDay();
    int getYear();
    static Date GetDateFromString ( std::string temp);

};




#endif //VAJA1101_DATE_H
