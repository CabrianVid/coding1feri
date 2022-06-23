#include <iostream>
#include <string>

#include "Time.h"

using namespace std;

int main() {
    Time wakeUp(12, 55, 33);
    Time schoolStart, lunchTime, workoutTime, sleepTime;

    cout << wakeUp.toString() << "\n";
    cout << wakeUp.toString12HoursFormat() << "\n";
    cout << wakeUp.isTimeValid(15, 22, 1100) << "\n";
    sleepTime.parse("21:23:45");

    schoolStart.setHour(12);
    schoolStart.setMinute(25);
    schoolStart.setSecond(45);
    lunchTime.setHour(13);
    lunchTime.setMinute(24);
    lunchTime.setSecond(40);

    cout << "\n\n" << workoutTime.diffSeconds(&lunchTime, &schoolStart);

    return 0;
}
