#include <iostream>
#include "time.h"

Time::Time(unsigned int hours, unsigned int minutes)
{
    set_hours(hours);
    set_minutes(minutes);
}

Time::Time(unsigned int minutes)
{
    set_hours(minutes%60);
    set_minutes(minutes/60);
}

void Time::set_hours(unsigned int hours)
{
    this->hours = hours%24;
}

void Time::set_minutes(unsigned int minutes)
{
    this->minutes = minutes%60; //остатъка може да отива в часовете
}

void Time::print()
{
    std::cout << hours << ":" << minutes << std::endl;
}
