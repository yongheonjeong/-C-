#pragma once
#ifndef SEAT_H
#define SEAT_H
#include <iostream>
using namespace std;

class AirlineBook;

class Seat {
    string seats;
public:
    Seat() {}
    void setSeats(string seats);
    string getSeats();
 
};


#endif