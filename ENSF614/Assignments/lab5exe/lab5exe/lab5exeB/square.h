/*
* File Name: lab5Exe_B.cpp
* Assignment: ENSF 614 Lab 5, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "shape.h"
#include "point.h"
#pragma once

class Square : virtual public Shape{
protected:
    double sideA;

public:
    // The constructor to create the object
    Square(double x, double y, double side, const char *sName);
    double area() const;
    double perimeter() const;
    double getSideA() const;
    void setSideA(double side); // Getter method to retrieve the value of "sideA."
    void display() const; // Used to display and print
};