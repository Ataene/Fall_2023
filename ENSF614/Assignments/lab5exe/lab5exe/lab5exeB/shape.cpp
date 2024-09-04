/*
* File Name: lab5Exe_B.cpp
* Assignment: ENSF 614 Lab 5, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "shape.h"
#include "point.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

// Constructor for the Shape class.
Shape::Shape(double x, double y, const char *sName) : origin(Point(x, y)){
    name = new char[strlen(sName) + 1];
    strcpy(this->name, sName);
}

// Destructor for the Shape class.
Shape::~Shape(){
    delete[] name;
    name = nullptr;
}

Shape::Shape(const Shape &s) : origin(Point(s.getO().getx(), s.getO().gety())){
    name = new char[strlen(s.getName()) + 1];
    strcpy(name, s.getName());
}

Shape &Shape::operator=(const Shape &h){
    if (this != &h)
    {
        delete[] name;

        origin = Point(h.getO().getx(), h.getO().gety());
        name = new char[strlen(h.getName()) + 1];
        strcpy(name, h.getName());
    }

    return *this;
}

void Shape::display() const {
    cout << "Name : " << getName() << endl;
    getO().display();
}

const Point &Shape::getO() const{
    return origin;
}

// Get the name of the shape.
const char *Shape::getName() const{
    return name;
}

double Shape::distance(Shape &s1) const{
    double dist = getO().distance(s1.getO());
    return dist;
}
// Calculate the distance between two shapes using their origins.
double Shape::distance(Shape &s1, Shape &s2){
    double dist = s1.getO().distance(s1.getO(), s2.getO());
    return dist;
}

// Move the shape by a specified amount in the X and Y directions.
void Shape::move(double moveX, double moveY){
    double valueX = getO().getx();
    double valueY = getO().gety();
    origin.setx(valueX + moveX);
    origin.sety(valueY + moveY);
}