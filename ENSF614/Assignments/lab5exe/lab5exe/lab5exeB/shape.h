/*
* File Name: lab5Exe_B.cpp
* Assignment: ENSF 614 Lab 5, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "point.h"
#pragma once

class Shape
{
protected:
    Point origin;
    char *name;

public:
    Shape(double x, double y, const char *sName);
    virtual ~Shape();

    Shape(const Shape &s);

    Shape& operator=(const Shape &h);

    const Point &getO() const;

    const char *getName() const;

    virtual void display() const;

    virtual double distance(Shape &S) const;

    static double distance(Shape &s1, Shape &s2);
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    void move (double dx, double dy);
};
