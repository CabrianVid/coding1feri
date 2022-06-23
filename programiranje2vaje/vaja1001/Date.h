//
// Created by LENOVO on 18. 05. 2022.
//

#ifndef VAJA1001_DATE_H
#define VAJA1001_DATE_H


#include<string>

class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
public:
    Date() = default;

    Date(unsigned int day, unsigned int month, unsigned int year);

    std::string toString() const;

    void setMonth(unsigned int month);

    void setYear(unsigned int year);

    void setDay(unsigned int day);
};


#endif //VAJA1001_DATE_H
