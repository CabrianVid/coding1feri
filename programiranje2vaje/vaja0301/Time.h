//
// Created by LENOVO on 15. 03. 2022.
//

#ifndef VAJA0301A_TIME_H
#define VAJA0301A_TIME_H
#include <string>






class Time {
private:

    unsigned int hour;
    unsigned int minute;
    unsigned int second;

    static int maxHour;
    static int noonHour;

public:
    Time();
    Time(unsigned int hour, unsigned int minute, unsigned int second);
    std::string toString() const;
    std::string toString12HoursFormat()const;
    static bool isTimeValid(unsigned int hour, unsigned int minute, unsigned int second) ;
    static Time  parse(std::string time);
    void setHour(unsigned int hour);
    void setMinute(unsigned int minute);
    void setSecond(unsigned int second);
    int getHour() const;
    int getMinute() const;
    int getSecond()const;
    static int diffSeconds(const Time* time1, const Time* time2);


};



#endif //VAJA0301A_TIME_H
