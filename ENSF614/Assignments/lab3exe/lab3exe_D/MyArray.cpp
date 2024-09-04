/*
 * File Name: lab3exe_D.cpp
 * Assignment: ENSF 614 Lab 3, exercise D
 * Created by Mahmood Moussavi
 * Completed by: Emmanuel Alafonye
 * Submission Date: October 13, 2023.
 */

#include "MyArray.h"

MyArray::MyArray()
{

    sizeM = 0; // Creating the empty array.

    storageM = new EType[0]; // set the size
}

// Constructor for the object array.
MyArray::MyArray(const EType *builtin, int sizeA){
    sizeM = sizeA;
    storageM = new EType[sizeM];

    for (int i = 0; i < sizeM; i++){

        storageM[i] = builtin[i];
    }
}
// Copy constructor for the myArray class
MyArray::MyArray(const MyArray &source){
    sizeM = source.sizeM;
    storageM = new EType[sizeM];
    for (int i = 0; i < sizeM; i++)
    {
        storageM[i] = source.storageM[i];
    }
}

MyArray &MyArray::operator=(const MyArray &rhs){

    if (this == &rhs){

        return *this; // Handle self-assignment
    }

    delete[] storageM;

    sizeM = rhs.sizeM;

    storageM = new EType[sizeM];

    for (int i = 0; i < sizeM; i++)
    {

        storageM[i] = rhs.storageM[i];
    }

    return *this;
}

// Destructor
MyArray::~MyArray(){

    delete[] storageM;
}

int MyArray::size() const{

    return sizeM;
}
// Returns the element of specified index.
EType MyArray::at(int i) const{

    if (i >= 0 && i < sizeM)
    {
        return storageM[i];
    }
    else
    {
        return 0;
    }
}

void MyArray::set(int i, EType new_value)
{

    if (i >= 0 && i < sizeM)
    {
        storageM[i] = new_value;
    }
}

// Resizes the array to a new size
void MyArray::resize(int new_size){
    if (new_size < 0)
    {
        return;
    }

    EType *newStorage = new EType[new_size];

    int copySize = (new_size < sizeM) ? new_size : sizeM;

    for (int i = 0; i < copySize; i++)
    {
        newStorage[i] = storageM[i];
    }

    delete[] storageM;

    storageM = newStorage;

    sizeM = new_size;
}
