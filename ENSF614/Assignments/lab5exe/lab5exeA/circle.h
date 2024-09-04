#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double x, double y, double radius, const char* name);
    double area() const;
    double perimeter() const;
    void display() const;
    double getRadius() const;
    void setRadius(double radius);
};

#endif
