/*
* File Name: lab5Exe_B.cpp
* Assignment: ENSF 614 Lab 5, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "rectangle.h"
#include "shape.h"
#pragma once

/**
 * The Circle class represents a circle with a center point, radius, and name.
 */

class Circle : virtual public Shape{
protected:
    double rad;

public:
  /**
     * Constructor to create a Circle object.
     *
     * @param x     The x-coordinate of the center.
     * @param y     The y-coordinate of the center.
     * @param radius    The radius of the circle.
     * @param name  The name of the circle.
     */
    Circle(double x, double y, double r, const char *name);
    double area() const;
    double perimeter() const;
    double getRad() const;
    void setRadius(double radius);
    void display() const;
};