/*
* File Name: lab4Exe_A.cpp
* Assignment: ENSF 614 Lab 5, exercise A
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "square.h"
#include <iostream>
using namespace std;

// Constructor for the Square class, initializing the position, side length, and name.
Square::Square(double x, double y, double side_a, const char* name) : Shape(x, y, name), side_a(side_a) {}

double Square::area() const {
    return side_a * side_a;
}

double Square::perimeter() const { 
    return 4 * side_a;
}

double Square::getSideA() const { // Get method to get the side_a
    return side_a;
}

void Square::set_side_a(double side) {
    side_a = side;
}

void Square::display() const { 
    Shape::display(); // Display method for the base class
    cout << "Side a: " << side_a <<endl;
    cout << "Area: " << area() <<endl;
    cout << "Perimeter: " << perimeter() <<endl; // Display the perimeter
}

Square(double x, double y, double side_a, const char *name)
{
}
