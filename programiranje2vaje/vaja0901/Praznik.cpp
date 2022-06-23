//
// Created by LENOVO on 10. 05. 2022.
//

#include "Praznik.h"

std::string Praznik::toString() const{
    return std::to_string(day)+ "." + std::to_string(month);
}

Praznik::Praznik(unsigned int day, unsigned int month) {
    this->month = month;
    this->day = day;
}
void Praznik::setDay(unsigned int day){
    this->day=day;
}
void Praznik::setMonth(unsigned int month){
    this->month=month;
}

std::ostream &operator<<(std::ostream &out, const Praznik &date) {
    out<<date.toString();
    return out;
}

//prefix operator--
Praznik& Praznik::operator--() {
    this->day--;
    this->month--;
    return *this;
}
//postfix operator--
Praznik Praznik::operator--(int dummy) {
    Praznik temp=*this;
    --*this;
    return temp;
}
