#include "curvecut.h"
#include "circle.h"
#include "shape.h"
#include "point.h"

#include <iostream>
#include <cmath>
using namespace std;

CurveCut::CurveCut(double x, double y, double width, double length, double radius, const char* name)
    : Rectangle(x, y, width, length, name), Circle(x, y, radius, name) {
    if (2 * radius > width || 2 * radius > length) {
        std::cerr << "Error: The radius of the cut is too large for the given dimensions." << std::endl;
        exit(1); // Terminate the program
    }
}

double CurveCut::area() const {
    double curveArea = Rectangle::area();
    double circleArea = Circle::area();
    return curveArea - circleArea;
}

double CurveCut::perimeter() const {
    double curvePerimeter = Rectangle::perimeter();
    double circlePerimeter = Circle::perimeter();
    return curvePerimeter + circlePerimeter;
}

void CurveCut::display() const {
    cout << "CurveCut Name: " << Rectangle::getName() << endl;
    cout << "X-coordinate: " << Rectangle::getOrigin().getX() << endl;
    cout << "Y-coordinate: " << Rectangle::getOrigin().getY() << endl;
    cout << "Width: " << Rectangle::getWidth() << endl; // Changes
    cout << "Length: " << Rectangle::getLength() << endl; // Changes
    cout << "Radius of the cut: " << Circle::getRadius() << endl;
}

