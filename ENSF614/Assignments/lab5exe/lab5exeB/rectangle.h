/*
* File Name: lab5Exe_B.cpp
* Assignment: ENSF 614 Lab 5, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "square.h"
#pragma once

/**
 * The Rectangle class represents a rectangle with two different side lengths, position, and name.
 * It inherits from the Square class and adds a second side length (sideB) to create a rectangle.
 */

class Rectangle : public Square{
protected:
    double sideB;

public:
 /**
     * Constructor to create a Rectangle object.
     *
     * @param x         The x-coordinate of the rectangle's position.
     * @param y         The y-coordinate of the rectangle's position.
     * @param a         The length of one side of the rectangle (sideA).
     * @param b         The length of the second side of the rectangle (sideB).
     * @param sName     The name of the rectangle.
     */
    Rectangle(double x, double y, double a, double b, const char *sName);
    double area() const;
    double perimeter() const;
    /**
     * Get the length of the second side of the rectangle.
     *
     * @return The length of the second side of the rectangle (sideB).
     */
    double getSideB() const;
    void setSideB(double side);
      /**
     * Display information about the rectangle, including its name, position, side lengths (sideA and sideB), area, and perimeter.
     */
    void display() const;
};
