/*
* File Name: lab4Exe_A.cpp
* Assignment: ENSF 614 Lab 5, exercise A
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#pragma once
#include "square.h"

/**
 * @brief A class representing a rectangle, which is a type of quadrilateral shape.
 * 
 * This class inherits from the Square class and adds a second side (side_b) to create a rectangle.
 */
class Rectangle : public Square {
private:
    double side_b;

public:
 /**
     * @brief Constructor to create a Rectangle object.
     *
     * @param x The X-coordinate of the origin.
     * @param y The Y-coordinate of the origin.
     * @param side_a The length of one side of the rectangle.
     * @param side_b The length of the second side of the rectangle.
     * @param name The name of the rectangle.
     */
    Rectangle(double x, double y, double side_a, double side_b, const char* name);
    double area() const;
    double perimeter() const;
    double getSideB() const;
    void set_side_b(double side);
    /**
     * @brief Display information about the rectangle, including its name, coordinates, and side lengths.
     */
    void display() const;
};
