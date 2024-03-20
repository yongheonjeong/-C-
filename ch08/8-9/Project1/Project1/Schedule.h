#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H
#include "Seat.h"

class AirlineBook;

class Schedule {
    string time;
    Seat* seat;
public:
    Schedule();
    Seat* getSeat();
    void setTime(string time);
    string getTime();
 
};


#endif