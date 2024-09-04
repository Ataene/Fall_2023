/*
* File Name: lab5Exe_B.cpp
* Assignment: ENSF 614 Lab 5, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "circle.h"
#include "shape.h"
#include "point.h"
#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;

Circle::Circle(double x, double y, double radius, const char *name) : Shape(x, y, name){
    setRadius(radius);
}

double Circle::area() const{
    return M_PI * pow(getRad(), 2);
}

double Circle::perimeter() const{
    return 2 * M_PI * getRad();
}

double Circle::getRad() const{
    return rad;
}

void Circle::setRadius(double radius){
    rad = radius;
}

void Circle::display() const{
    getO().display();
    cout << "Radius: " << getRad() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}
