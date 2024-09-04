//  main.cpp
//  Quiz1Pre
//  Created by Emmanuel Alafonye on 2023-09-20.

#include <iostream>
using namespace std;

int main(void) {
    char myChar = 'a';
    
    cout<<"The address of myChar is: "<< unsigned long int (&myChar);
    
    return 0;
}
