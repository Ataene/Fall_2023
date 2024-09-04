#ifndef LAB3CLOCK_H
#define LAB3CLOCK_H


// Preprocessor directive that prevents multiple inclusions of this header file.
// If LAB3CLOCK_H is not defined, the code between #ifndef and #endif will be included.

class Clock {
public: // Public member function to get components
    Clock(); // Default constructor
    Clock(int seconds); // Constructor with seconds argument
    Clock(int hours, int minutes, int seconds); // Constructor with hours, minutes, and seconds

    int get_hour() const;
    int get_minute() const;
    int get_second() const;

    void set_hour(int hours);
    void set_minute(int minutes);
    void set_second(int seconds);

    void increment();
    void decrement();
    void add_seconds(int seconds);

private: // Private data to store components
    int hour;
    int minute;
    int second;

    int hms_to_sec() const;
    void sec_to_hms(int total_seconds);
};

#endif
