/*
* File Name: lab4Exe_A.cpp
* Assignment: ENSF 614 Lab 5, exercise A
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#pragma once

/**
 * @brief A class representing a 2D point with X and Y coordinates.
 */

class Point {
    
private:
    double x;
    double y;
    static int pointCount;
    int id;

public:
 /**
     * @brief Constructor to create a Point object.
     *
     * @param x The X-coordinate of the point.
     * @param y The Y-coordinate of the point.
     */
    Point(double x, double y);
    void display() const;
    static double distance(const Point& p1, const Point& p2);
    double distance(const Point& other) const;
    double getX() const;
    double getY() const;
    void setX(double x); // set the X-coordinate
    void setY(double y); // set the Y-coordinate
    static int counter();
};
