//
// Created by LENOVO on 8. 05. 2022.
//

#ifndef VAJA0901_DATE_H
#define VAJA0901_DATE_H


#include<string>

class Date {
    friend std::ostream& operator<<(std::ostream &out, const Date &date);
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:
    Date(unsigned int day, unsigned int month, unsigned int year);
    std::string toString() const;
    void setMonth(unsigned int month);
    void setYear(unsigned int year);
    void setDay(unsigned int day);
    bool operator==(const Date& other) const;
    Date& operator++();          // prefix operator++
    Date& operator++(int dummy); //postfix operator++
    bool monthsSize() const;
};


#endif //VAJA0901_DATE_H
