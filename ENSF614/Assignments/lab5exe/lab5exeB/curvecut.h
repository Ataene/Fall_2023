/*
* File Name: lab5Exe_B.cpp
* Assignment: ENSF 614 Lab 5, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "circle.h"
#include "rectangle.h"
#pragma once

/**
 * The CurveCut class represents a shape created by cutting a circular section from a rectangle.
 * It inherits properties from both the Circle and Rectangle classes.
 */

class CurveCut : public Circle, public Rectangle{
protected:
    double width;

public:
/**
     * Constructor to create a CurveCut object.
     *
     * @param x The x-coordinate of the CurveCut's position.
     * @param y The y-coordinate of the CurveCut's position.
     * @param a The length of one side of the rectangle (sideA).
     * @param width The width of the rectangular section.
     * @param radius The radius of the circular section.
     * @param name The name of the CurveCut.
     */

    CurveCut(double x, double y, double a, double width, double radius, const char *name);
    double area() const;
    double perimeter() const;

    /**
     * Display information about the CurveCut, including its name, position, side length (sideA), width, area, and perimeter.
     */
    void display() const;
};