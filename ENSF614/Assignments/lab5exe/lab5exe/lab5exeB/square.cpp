/*
* File Name: lab5Exe_B.cpp
* Assignment: ENSF 614 Lab 5, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "square.h"
#include "shape.h"
#include "point.h"
#include <iostream>
#include <iomanip>  

using namespace std;

/**
 * The Square class represents a square with a side length, position, and name.
 */

Square::Square(double x, double y, double side, const char *name) : Shape(x, y, name){
    setSideA(side);
}

double Square::area() const{
    return getSideA() * getSideA();
}

double Square::perimeter() const{
    return getSideA() * 4;
}

double Square::getSideA() const{
    return sideA;
}

void Square::setSideA(double side){
    sideA = side;
}

void Square::display() const{
    cout << "Name: " << getName() << endl;
    getO().display();

    /**
     * Display information about the square, including its name, position, side length, area, and perimeter.
     */
    
    cout << "Side a: " << getSideA() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}
