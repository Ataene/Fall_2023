/*
* File Name: lab4Exe_A.cpp
* Assignment: ENSF 614 Lab 5, exercise A
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "point.h"
#include <iostream>
#include <cmath>

using namespace std;

int Point::pointCount = 0;

/**
 * @brief Constructor to create a Point object with specified coordinates.
 *
 * @param x The X-coordinate of the point.
 * @param y The Y-coordinate of the point.
 */

Point::Point(double x, double y) : x(x), y(y), id(1000 + pointCount) {
    pointCount++;
}

void Point::display() const {
    cout << "X-coordinate: " << x <<endl;
    cout << "Y-coordinate: " << y <<endl;
}

/**
 * @brief Calculate the Euclidean distance between this point and another point using their coordinates.
 *
 * @param other The other point.
 * @return The Euclidean distance between this point and the other point.
 */

double Point::distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double Point::distance(const Point& other) const {
    return distance(*this, other);
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

/**
 * @brief Get the total number of Point objects created.
 *
 * @return The total number of Point objects created.
 */

int Point::counter() {
    return pointCount;
}
