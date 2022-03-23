#pragma once

#ifndef TIME_CLASS
#define TIME_CLASS

class Time
{
    unsigned int hours;
    unsigned int minutes;
public:
    Time(unsigned int hours = 0, unsigned int minutes = 0);
    Time(unsigned int minutes = 0);

    void set_hours(unsigned int hours);
    void set_minutes(unsigned int minutes);

    void print();
};

#endif // TIME_CLASS
