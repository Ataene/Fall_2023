#include "lab3Clock.h"

// Default constructor
Clock::Clock() {
    hour = 0;
    minute = 0;
    second = 0;
}

// Constructor with seconds argument
Clock::Clock(int seconds) {
    sec_to_hms(seconds);
}

// Constructor with hours, minutes, and seconds
Clock::Clock(int hours, int minutes, int seconds) {
    if (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59 && seconds >= 0 && seconds <= 59) {
        hour = hours;
        minute = minutes;
        second = seconds;
    } else {
        hour = 0;
        minute = 0;
        second = 0;
    }
}

// Getter functions
int Clock::get_hour() const {
    return hour;
}

int Clock::get_minute() const {
    return minute;
}

int Clock::get_second() const {
    return second;
}

// Setter functions
void Clock::set_hour(int hours) {
    if (hours >= 0 && hours <= 23) {
        hour = hours;
    }
}

void Clock::set_minute(int minutes) {
    if (minutes >= 0 && minutes <= 59) {
        minute = minutes;
    }
}

void Clock::set_second(int seconds) {
    if (seconds >= 0 && seconds <= 59) {
        second = seconds;
    }
}

// Additional functionalities
void Clock::increment() {
    if (hour == 23 && minute == 59 && second == 59) {
        hour = 0;
        minute = 0;
        second = 0;
    } else {
        add_seconds(1);
    }
}

void Clock::decrement() {
    if (hour == 0 && minute == 0 && second == 0) {
        hour = 23;
        minute = 59;
        second = 59;
    } else {
        add_seconds(-1);
    }
}

void Clock::add_seconds(int seconds) {
    int total_seconds = hms_to_sec() + seconds;
    sec_to_hms(total_seconds);
}

// Helper functions
int Clock::hms_to_sec() const {
    return hour * 3600 + minute * 60 + second;
}

void Clock::sec_to_hms(int total_seconds) {
    if (total_seconds >= 0 && total_seconds <= 86399) {
        hour = total_seconds / 3600;
        minute = (total_seconds % 3600) / 60;
        second = total_seconds % 60;
    } else {
        hour = 0;
        minute = 0;
        second = 0;
    }
}
