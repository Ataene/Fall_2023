/*
* File Name: lab4Exe_A.cpp
* Assignment: ENSF 614 Lab 5, exercise A
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#pragma once
#include "shape.h"

// Defining the Square class that inherit tfrom the shape
class Square : public Shape {
private:
    double side_a;

public:


//
/
const Point& getOrigin() const {
        return origin;
    }

    const char* getName() const {
        return shapeName;
    }

    double distance(const Shape& s1, const Shape& s2) {
        return Point::distance(s1.getOrigin(), s2.getOrigin());
    }

    double distance(const Shape& other) const {
        return Point::distance(origin, other.getOrigin());
    }
    ///



    // The constructor to create the object
    Square(double x, double y, double side_a, const char* name);
    double area() const; // The Area method 
    double perimeter() const;
    double getSideA() const; 
    void set_side_a(double side); // Getter method to retrieve the value of "side_a."
    void display() const; // Used to display and print
};
