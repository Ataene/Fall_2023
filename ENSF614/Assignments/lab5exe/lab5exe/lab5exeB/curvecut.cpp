/*
* File Name: lab5Exe_B.cpp
* Assignment: ENSF 614 Lab 5, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "curvecut.h"
#include "circle.h"
#include "shape.h"
#include "point.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


/**
 * Constructor to create a CurveCut object by specifying its position, width, length, cut radius, and name.
 *
 * @param x The x-coordinate of the CurveCut's position.
 * @param y The y-coordinate of the CurveCut's position.
 * @param width The width of the rectangular section.
 * @param length The length of one side of the rectangle.
 * @param cutRadius The radius of the circular cut.
 * @param name The name of the CurveCut.
 */

CurveCut::CurveCut(double x, double y, double width, double length, double cutRadius, const char *name)
    : Shape(x, y, name), Circle(x, y, cutRadius, name), Rectangle(x, y, width, length, name){
    double minLength = width < length ? width : length;

    if (cutRadius > minLength)
    {
        cerr << "\n. Error: Cut radius is too large for the given dimensions.\n";
        exit(1);
    }
}

double CurveCut::area() const{
    return (Rectangle::area() - (Circle::area() / 4));
}

double CurveCut::perimeter() const{
    return Rectangle::perimeter() - (2 * getRad()) + (Circle::perimeter() / 4);
}

/**
 * Display information about the CurveCut, including its name, position, width, length, and cut radius.
 */

void CurveCut::display() const{
    cout << "CurveCut Name: " << getName() << endl;
    getO().display();
    cout << "Width: " << getSideA() << endl;
    cout << "Length: " << getSideB() << endl;
    cout << "Radius of the cut: " << getRad() << endl;
}
