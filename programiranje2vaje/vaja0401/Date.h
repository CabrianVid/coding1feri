//
// Created by LENOVO on 21. 03. 2022.
//

#ifndef VAJA0401_DATE_H
#define VAJA0401_DATE_H

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


#endif //VAJA0401_DATE_H
