/*
* File Name: lab5Exe_B.cpp
* Assignment: ENSF 614 Lab 5, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "rectangle.h"
#include "square.h"
#include "shape.h"
#include "point.h"
#include <iostream>
#include <iomanip>
using namespace std;


/**
 * The Rectangle class represents a rectangle with two different side lengths, position, and name.
 * It inherits from the Square class and adds a second side length (sideB) to create a rectangle.
 */

Rectangle::Rectangle(double x, double y, double a, double b, const char *name)
    : Shape(x, y, name), Square(x, y, a, name){
    setSideB(b);
}

double Rectangle::area() const{
    return (getSideA() * getSideB());
}
/**
 * Calculate the perimeter of the rectangle.
 *
 * @return The perimeter of the rectangle.
 */

double Rectangle::perimeter() const{
    return (2 * (getSideA() + getSideB()));
}

double Rectangle::getSideB() const{
    return sideB;
}

void Rectangle::setSideB(double side){
    sideB = side;
}
/**
 * Display information about the rectangle, including its name, position, side lengths (sideA and sideB), area, and perimeter.
 */
void Rectangle::display() const{
    cout << "Rectangle Name: " << getName() << endl;
    getO().display();
    cout << "Side A: " << getSideA() << endl;
    cout << "Side B: " << getSideB() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}
