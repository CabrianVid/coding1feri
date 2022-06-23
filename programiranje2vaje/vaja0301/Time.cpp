//
// Created by LENOVO on 15. 03. 2022.
//

#include "Time.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int Time::maxHour = 24;
int Time::noonHour = 12;

std::string Time::toString() const {
    if (hour < 10) {
        return "0" + std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
    }
    if (minute < 10) {
        return std::to_string(hour) + ":0" + std::to_string(minute) + ":" + std::to_string(second);
    }
    if (second < 10) {
        return std::to_string(hour) + ":" + std::to_string(minute) + ":0" + std::to_string(second);
    } else {
        return std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
    }
}

std::string Time::toString12HoursFormat() const {
    int hourTo12 = hour;
    if (hourTo12 < noonHour) {
        return std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second) + "AM";
    } else {
        hourTo12 -= noonHour;
        return std::to_string(hourTo12) + ":" + std::to_string(minute) + ":" + std::to_string(second) + "PM";
    }
}

Time::Time() : hour(0), minute(0), second(0) {
}

Time::Time(unsigned int hour, unsigned int minute, unsigned int second) : hour(hour), minute(minute), second(second) {
    if (!isTimeValid(hour, minute, second)) {
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
    }
};

bool Time::isTimeValid(unsigned int hour, unsigned int minute, unsigned int second) {
    if (hour < maxHour && minute < 60 && second < 60) {
        return true;
    } else {
        return false;
    }
}

Time Time::parse(std::string time) {
    char temp[time.length() + 1];
    strcpy(temp, time.c_str());

    string hours = "";
    for (int i = 0; i < 2; i++) {
        hours = hours + temp[i];
    }

    string minutes = "";
    for (int i = 3; i < 5; i++) {
        minutes = minutes + temp[i];
    }

    string seconds = "";
    for (int i = 6; i <= 7; i++) {
        seconds = seconds + temp[i];
    }

    unsigned int myint1 = stoi(hours);
    unsigned int myint2 = stoi(minutes);
    unsigned int myint3 = stoi(seconds);

    return Time(myint1, myint2, myint3);
}

void Time::setHour(unsigned int hour) {
    this->hour = hour;
}

void Time::setMinute(unsigned int minute) {
    this->minute = minute;
}

void Time::setSecond(unsigned int second) {
    this->second = second;
}

int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

int Time::getSecond() const {
    return second;
}

int Time::diffSeconds(const Time *time1, const Time *time2) {
    int t1 = (time1->hour) * 3600 + (time1->minute) * 60 + (time1->second);
    int t2 = (time2->hour) * 3600 + (time2->minute) * 60 + (time2->second);
    if (t1 > t2) {
        return t1 - t2;
    }
    if (t2 > t1) {
        return t2 - t1;
    } else {
        return 0;
    }
}
