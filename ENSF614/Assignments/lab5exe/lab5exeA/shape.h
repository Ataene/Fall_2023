/*
* File Name: lab4Exe_A.cpp
* Assignment: ENSF 614 Lab 5, exercise A
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#pragma once
#include "point.h"

/**
 * Represents a geometric shape with an origin point and a name.
 */

class Shape {
private:
    Point origin;
    char* shapeName;

public:
    /**
     * Constructor to create a new Shape with the given coordinates and name.
     *
     * @param x The x-coordinate of the origin point.
     * @param y The y-coordinate of the origin point.
     * @param name The name of the shape.
     */
    Shape(double x, double y, const char* name);
    ~Shape();
    const Point& getOrigin() const;
    const char* getName() const;
    void display() const;
    /**
     * Calculate the distance between two Shape objects.
     *
     * @param s1 The first Shape for distance calculation.
     * @param s2 The second Shape for distance calculation.
     * @return The distance between s1 and s2 as a double.
     */
    static double distance(const Shape& s1, const Shape& s2);
    double distance(const Shape& other) const;
     /**
     * Move the shape by specified distances in the x and y directions.
     *
     * @param dx The distance to move the shape in the x-direction.
     * @param dy The distance to move the shape in the y-direction.
     */
    void move(double dx, double dy);
};
