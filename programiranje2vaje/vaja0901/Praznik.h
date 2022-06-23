//
// Created by LENOVO on 10. 05. 2022.
//

#ifndef VAJA0901_PRAZNIK_H
#define VAJA0901_PRAZNIK_H


#include <string>

class Praznik {
    friend std::ostream& operator<<(std::ostream &out, const Praznik &praznik);
private:
    unsigned int day;
    unsigned int month;
public:
    Praznik(unsigned int day, unsigned int month);
    std::string toString() const;
    void setMonth(unsigned int month);
    void setDay(unsigned int day);
    Praznik& operator--();          // prefix operator--
    Praznik operator--(int dummy);// postfix operator --

};


#endif //VAJA0901_PRAZNIK_H
