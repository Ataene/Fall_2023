/*
* iterator.cpp
* File Name: lab6Exe_A.cpp
* Assignment: ENSF 614 Lab 6, exercise A
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* ENSF 614 - Fall 2023 - Lab 6, Ex A
* Submission Date: 10 November, 2023.
*/


#include <iostream>
#include <algorithm> // Usde for sorting
#include <assert.h>
#include "mystring2.h" // Imported for Mystring

using namespace std;

// Define a template class Vector that can create vectors of different data types.

template <typename T>
class Vector
{
public:
// Nested class VectIter to represent an iterator for the Vector.
  class VectIter
  {
    friend class Vector;

  private:
    Vector *v; //Pointer to the parent object
    int index; // Represent the subscript number of the vectors

  public:
    // Constrcutor of the VectorIter
    VectIter(Vector &x) : v(&x), index(0) {}

    T operator++()
    {
      if (++index == v->size)
        index = 0;
      return v->array[index];
    }

    T operator++(int)
    {
      T temp = v->array[index++];
      if (index == v->size)
        index = 0;
      return temp;
    }

    T operator--()
    {
      if (index == 0)
        index = v->size - 1;
      else
        index--;
      return v->array[index];
    }

    T operator--(int)
    {
      T temp = v->array[index];
      if (index == 0)
        index = v->size - 1;
      else
        index--;
      return temp;
    }

    T operator*()
    {
      return v->array[index];
    }
  };
   // Constructor for Vector class.
  Vector(int sz) : size(sz)
  {
    array = new T[sz];
  }
  // Destructor for Vector class.
  ~Vector()
  {
    delete[] array;
  }
  // Overload the subscript operator ([]).
  T &operator[](int i)
  {
    return array[i];
  }

  // Sort the vector's elements in ascending order using the STL sort function.
  void ascending_sort()
  {
    sort(array, array + size);
  }

private:
  T *array; // Pointer to the first element of the array 
  int size; // Array size
};

// Main entry of the program
int main()
{
  Vector<int> x(3);
  x[0] = 999;
  x[1] = -77;
  x[2] = 88;
  // Creates and iterator for the integer Vector
  Vector<int>::VectIter iter(x);

  cout << "Testing an <int> Vector:" << endl;
  cout << "Testing sort" << endl;
  x.ascending_sort();

  for (int i = 0; i < 3; i++)
    cout << iter++ << endl;

  cout << "Testing Prefix --:" << endl;
  for (int i = 0; i < 3; i++)
    cout << --iter << endl;

  cout << "Testing Prefix ++:" << endl;
  for (int i = 0; i < 3; i++)
    cout << ++iter << endl;

  cout << "Testing Postfix --:" << endl;
  for (int i = 0; i < 3; i++)
    cout << iter-- << endl;

  cout << "Program Terminated Successfully." << endl;

  return 0;
}
