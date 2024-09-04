#include "circle.h"
#include "shape.h"
#include <iostream>
#include <cmath>

Circle::Circle(double x, double y, double radius, const char* name)
    : Shape(x, y, name), radius(radius) {
}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::display() const {
    Shape::display();
    std::cout << "Radius: " << radius << std::endl;
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double r) {
    radius = r;
}
