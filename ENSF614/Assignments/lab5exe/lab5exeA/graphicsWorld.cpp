/*
 * File Name: lab4Exe_A.cpp
 * Assignment: ENSF 614 Lab 5, exercise A
 * Created by Mahmood Moussavi
 * Completed by: Emmanuel Alafonye
 * Submission Date: October 23, 2023.
 */

#include <iostream>
#include "graphicsWorld.h"
using namespace std;

void GraphicsWorld::run()
{

  // Testing the Point class
  Point m(6, 8);
  Point n(6, 8);
  n.setX(9);
  cout << "\nExpected to display the distance between m and n is: 3";
  cout << "\nThe distance between m and n is: " << m.distance(n);
  cout << "\nExpected second version of the distance function also prints: 3";
  cout << "\nThe distance between m and n is again: "
       << Point::distance(m, n);

  // Testing the Square class
  cout << "\n\nTesting Functions in class Square:" << endl;
  Square s(5, 7, 12, "SQUARE - S");
  s.display();

  // Testing the Rectangle class
  cout << "\nTesting Functions in class Rectangle:" << endl;
  Rectangle a(5, 7, 12, 15, "RECTANGLE A");
  a.display();
  Rectangle b(16, 7, 8, 9, "RECTANGLE B");
  b.display();
  double d = a.distance(b);
  cout << "\nDistance between rectangle a and b is: " << d << endl;
  Rectangle rec1 = a;
  rec1.display();

  // Testing assignment operator in class Rectangle
  cout << "\nTesting assignment operator in class Rectangle:" << endl;
  Rectangle rec2(3, 4, 11, 7, "RECTANGLE rec2");
  rec2.display();
  rec2 = a;
  a.set_side_b(200);
  a.set_side_a(100);
  cout << "\nExpected to display the following values for object rec2: " << endl;
  cout << "Rectangle Name: RECTANGLE A\n"
       << "X-coordinate: 5\n"
       << "Y-coordinate: 7\n"
       << "Side a: 12\n"
       << "Side b: 15\n"
       << "Area: 180\n"
       << "Perimeter: 54\n";
  cout << "\nIf it doesn't, there is a problem with your assignment operator." << std::endl;
  rec2.display();

  // Testing copy constructor in class Rectangle
  cout << "\nTesting copy constructor in class Rectangle:" << std::endl;
  Rectangle rec3(a);
  rec3.display();
  a.set_side_b(300);
  a.set_side_a(400);
  cout << "\nExpected to display the following values for object rec3: " << endl;
  cout << "Rectangle Name: RECTANGLE A\n"
       << "X-coordinate: 5\n"
       << "Y-coordinate: 7\n"
       << "Side a: 100\n"
       << "Side b: 200\n"
       << "Area: 20000\n"
       << "Perimeter: 600\n";
  cout << "\nIf it doesn't, there is a problem with your copy constructor." << endl;
  rec3.display();

  // Testing array of pointers and polymorphism
  cout << "\nTesting array of pointers and polymorphism:" << endl;
  Shape *sh[4];
  sh[0] = &s;
  sh[1] = &b;
  sh[2] = &rec1;
  sh[3] = &rec3;

  for (int i = 0; i < 4; i++)
  {
    sh[i]->display();
  }

  // Testing Functions in class Circle
  cout << "\nTesting Functions in class Circle:" << endl;
  Circle c(3, 5, 9, "CIRCLE C");
  c.display();
  cout << "the area of " << c.getName() << " is: " << c.area() << endl;
  cout << "the perimeter of " << c.getName() << " is: " << c.perimeter() << endl;
  d = a.distance(c);
  cout << "\nThe distance between rectangle a and circle c is: " << d;

  // Testing Functions in class CurveCut
  cout << "\nTesting Functions in class CurveCut:" << endl;
  CurveCut rc(6, 5, 10, 12, 9, "CurveCut rc");
  rc.display();
  
  cout << "the area of " << rc.getName() << " is: " << rc.area() << endl;
  cout << "the perimeter of " << rc.getName() << " is: " << rc.perimeter() << endl;
  d = rc.distance(c);
  cout << "\nThe distance between rc and c is: " << d;

  // Testing copy constructor in class CurveCut
  cout << "\nTesting copy constructor in class CurveCut:" << endl;
  CurveCut cc = rc;
  cc.display();

  // Testing assignment operator in class CurveCut
  cout << "\nTesting assignment operator in class CurveCut:" << endl;
  CurveCut cc2(2, 5, 100, 12, 9, "CurveCut cc2");
  cc2.display();
  cc2 = cc;
  cc2.display();
}
