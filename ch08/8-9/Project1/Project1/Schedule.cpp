#include "Schedule.h"


Schedule::Schedule() {
    seat = new Seat[8];

    for (int i = 0; i < 8; i++) {
        seat[i].setSeats("---");
    }
}

void Schedule::setTime(string time) {
    this->time = time;
}

string Schedule::getTime() {
    return time;
}

Seat* Schedule::getSeat() {
    return seat;
}