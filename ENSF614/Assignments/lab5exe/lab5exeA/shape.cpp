/*
* File Name: lab4Exe_A.cpp
* Assignment: ENSF 614 Lab 5, exercise A
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "shape.h"
#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

/**
 * @brief A class representing a shape with an origin point and a name.
 */
Shape::Shape(double x, double y, const char* name) : origin(x, y), shapeName(nullptr) {
    try {
        shapeName = new char[strlen(name) + 1];
        strcpy(shapeName, name);
    } catch (const std::bad_alloc& e) {
        // Handle memory allocation failure
        std::cerr << "Memory allocation error: " << e.what() << std::endl;
        shapeName = nullptr; // Ensure shapeName is set to nullptr
    }
}

Shape::~Shape() {
    delete[] shapeName;
}

const Point& Shape::getOrigin() const {
    return origin;
}

const char* Shape::getName() const {
    return shapeName;
}

void Shape::display() const {
    cout << "Shape Name: " << shapeName << std::endl;
    cout << "X-coordinate: " << origin.getX() << std::endl;
    cout << "Y-coordinate: " << origin.getY() << std::endl;
}

double Shape::distance(const Shape& s1, const Shape& s2) {
    return Point::distance(s1.getOrigin(), s2.getOrigin());
}

double Shape::distance(const Shape& other) const {
    return Point::distance(origin, other.getOrigin());
}

/**
     * @brief Move the shape by a specified amount in both the X and Y directions.
     *
     * @param dx The amount to move in the X direction.
     * @param dy The amount to move in the Y direction.
     */
void Shape::move(double dx, double dy) {
    origin = Point(origin.getX() + dx, origin.getY() + dy);
}
