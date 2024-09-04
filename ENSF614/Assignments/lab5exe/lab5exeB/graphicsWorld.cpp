/*
* File Name: lab5Exe_B.cpp
* Assignment: ENSF 614 Lab 5, exercise B
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 23, 2023.
*/

#include "graphicsWorld.h"
#include "curvecut.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include "shape.h"
#include "point.h"
#include <iostream>

using namespace std;

void GraphicsWorld::run()
{
    Point m(6, 8);
    Point n(6, 8);
    n.setx(9);
    cout << "\nExpected to display the distance between m and n is: 3";
    cout << "\nThe distance between m and n is: " << m.distance(n);
    cout << "\nExpected second version of the distance function also print: 3";
    cout << "\nThe distance between m and n is again: " << Point::distance(m, n);

    cout << "\n\nTesting Functions in class Square:" << endl;
    Square s(5, 7, 12, "SQUARE - S");
    s.display();
    cout << "\nTesting Functions in class Rectangle:" << endl;
    Rectangle a(5, 7, 12, 15, "RECTANGLE A");
    a.display();

    Rectangle b(16, 7, 8, 9, "RECTANGLE B");
    b.display();

    double d = a.distance(b);
    cout << "\nDistance between square a, and b is: " << d << endl;
    Rectangle rec1 = a;
    rec1.display();
    cout << "\nTesting assignment operator in class Rectangle:" << endl;
    Rectangle rec2(3, 4, 11, 7, "RECTANGLE rec2");
    rec2.display();
    rec2 = a;
    a.setSideB(200);
    a.setSideA(100);
    cout << "\nExpected to display the following values for objec rec2: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n"
         << "X-coordinate: 5\n"
         << "Y-coordinate: 7\n"
         << "Side a: 12\n"
         << "Side b: 15\n"
         << "Area: 180\n"
         << "Perimeter: 54\n";
    cout << "\nIf it doesn't there is a problem with your assignment operator.\n"
         << endl;
    rec2.display();

    cout << "\nTesting copy constructor in class Rectangle:" << endl;
    Rectangle rec3(a);
    rec3.display();
    a.setSideB(300);
    a.setSideA(400);
    cout << "\nExpected to display the following values for objec rec2: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n"
         << "X-coordinate: 5\n"
         << "Y-coordinate: 7\n"
         << "Side a: 100\n"
         << "Side b: 200\n"
         << "Area: 20000\n"
         << "Perimeter: 600\n";
    cout << "\nIf it doesn't there is a problem with your assignment operator.\n"
         << endl;
    rec3.display();
    cout << "\nTesting array of pointers and polymorphism:" << endl;
    Shape *sh[4];
    sh[0] = &s;
    sh[1] = &b;
    sh[2] = &rec1;
    sh[3] = &rec3;
    sh[0]->display();
    sh[1]->display();
    sh[2]->display();
    sh[3]->display();
    cout << "\nTesting Functions in class Circle:" << endl;
    Circle c(3, 5, 9, "CIRCLE C");
    c.display();
    cout << "the area of " << c.getName() << " is: " << c.area() << endl;
    cout << "the perimeter of " << c.getName() << " is: " << c.perimeter() << endl;
    d = a.distance(c);
    cout << "\nThe distance between rectangle a and circle c is: " << d << endl;

    CurveCut rc(6, 5, 10, 12, 9, "CurveCut rc");
    rc.display();
    cout << "the area of " << rc.getName() << " is: " << rc.area() << endl;
    cout << "the perimeter of " << rc.getName() << " is: " << rc.perimeter();
    d = rc.distance(c);
    cout << "\nThe distance between rc and c is: " << d << endl;
    sh[0] = &s;
    sh[1] = &a;
    sh[2] = &c;
    sh[3] = &rc;
    sh[0]->display();
    cout << "The area of " << sh[0]->getName() << " is: " << sh[0]->area();
    cout << "\nthe perimeter of " << sh[0]->getName() << " is: " << sh[0]->perimeter() << endl << endl;
    sh[1]->display();
    cout << "\nThe area of " << sh[1]->getName() << " is: " << sh[1]->area();
    cout << "\nthe perimeter of " << sh[0]->getName() << " is: " << sh[1]->perimeter() << endl << endl;
    sh[2]->display();
    cout << "\nThe area of " << sh[2]->getName() << " is: " << sh[2]->area();
    cout << "\nthe circumference of " << sh[2]->getName() << " is: " << sh[2]->perimeter() << endl << endl;
    sh[3]->display();
    cout << "\nThe area of " << sh[3]->getName() << " is: " << sh[3]->area();
    cout << "\nthe perimeter of " << sh[3]->getName() << " is: " << sh[3]->perimeter() << endl << endl;
    cout << "\nTesting copy constructor in class CurveCut:" << endl;
    CurveCut cc = rc;
    cc.display();
    cout << "\nTesting assignment operator in class CurveCut:" << endl;
    CurveCut cc2(2, 5, 100, 12, 9, "CurveCut cc2");
    cc2.display();
    cc2 = cc;
    cc2.display();
}

int main(){
    GraphicsWorld functionRun;
    functionRun.run();
    return 0;
}