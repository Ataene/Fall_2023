/*
* File Name: lab5Exe_B.cpp
* Assignment: ENSF 614 Lab 5, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#pragma once

/**
 * The Point class represents a point in a two-dimensional space.
 */

class Point{
private:
    double x;
    double y;
    static int pointCount;
    int id;

public:
     /**
     * Constructor to create a Point object with specified coordinates.
     *
     * @param a The x-coordinate of the point.
     * @param b The y-coordinate of the point.
     */

    Point(double a, double b);
    ~Point();
    Point(const Point &other);
    Point &operator=(const Point &rhs);
    void display() const;
    double getx() const;
    double gety() const;
    void setx(double a);
    void sety(double b);
     /**
     * Calculate the distance between this point and another point.
     *
     * @param p3 The other Point object.
     * @return The distance between this point and the other point.
     */
    
    int counter() const;
    double distance(const Point &p3) const;
     /**
     * Calculate the distance between two points.
     *
     * @param p1 The first Point object.
     * @param p2 The second Point object.
     * @return The distance between the two points.
     */

    static double distance(const Point &p1, const Point &p2);

};
