/*
* File Name: lab4Exe_A.cpp
* Assignment: ENSF 614 Lab 5, exercise A
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(double x, double y, double side_a, double side_b, const char* name)
    : Square(x, y, side_a, name), side_b(side_b) {
    // Initialize a Rectangle object with provided parameters.
    }

double Rectangle::area() const {
    return getSideA() * side_b;
}

double Rectangle::perimeter() const {
    // Calculate and return the perimeter of the rectangle (2 * (length + width)).
    return 2 * (getSideA() + side_b);
}

double Rectangle::getSideB() const {
    return side_b;
}

void Rectangle::set_side_b(double side) {
    side_b = side;
}

void Rectangle::display() const {
    // Display information about the rectangle, including its name, coordinates, side lengths, area, and perimeter.
    Square::display();
    cout << "Side b: " << side_b <<endl;
    cout << "Area: " << area() <<endl;
    cout << "Perimeter: " << perimeter() <<endl;
}
