/*
* File Name: lab4Exe_B.cpp
* Assignment: ENSF 614 Lab 5, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "point.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int Point::pointCount = 0;

Point::Point(double x, double y){
    x = x;
    y = y;
    id = ++pointCount + 1000;
}

Point::Point(const Point &p2){
    x = p2.getx();
    y = p2.gety();
    id = ++pointCount + 1000;
}

Point &Point::operator=(const Point &h){
    if (this != &h){
        x = h.getx();
        y = h.gety();
        id = ++pointCount + 1000;
    }

    return *this;
}

Point::~Point(){
    --pointCount;
}

void Point::display() const {
    cout <<"X-coordinate: " << getx() << endl;
    cout <<"Y-coordinate: " << gety() << endl;
}

double Point::getx() const{
    return this->x;
}

double Point::gety() const{
    return y;
}

void Point::setx(double x){
    x = x;
}

void Point::sety(double y){
    y = y;
}

int Point::counter() const{
    return pointCount;
}

double Point::distance(const Point &p1) const{
    double valueX = pow((getx() - p1.getx()), 2);
    double valueY = pow((gety() - p1.gety()), 2);
    return sqrt(valueX + valueY);
}

double Point::distance(const Point &p1, const Point &p2){
    double valueX = pow((p1.getx() - p2.getx()), 2);
    double valueY = pow((p1.gety() - p2.gety()), 2);

    return sqrt(valueX + valueY);
}