//  ENSF 614 - Fall 2023  Lab4 - exercise A
// lab4ExA.cpp

/*
* File Name: lab4Exe_A.cpp
* Assignment: ENSF 614 Lab 4, exercise A
* Created by Mahmood Moussavi
* Completed by: Emmanuel Alafonye
* Submission Date: October 18, 2023.
*/

#include<vector>
#include<string>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

typedef vector<string> String_Vector;

String_Vector transpose(const String_Vector& sv);
// REQUIRES:
//    sv.size() >= 1
//    All the strings in sv are the same length, and that length is >= 1.
// PROMISES:
//    Return value is the "transpose" of sv, as defined in the Exercise B
//    instructions.

int main() {
    
    const int ROWS = 5;
    const int COLS = 4;
    
    char c = 'A';
    String_Vector sv;
    sv.resize(ROWS);
    
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++) {
            sv.at(i).push_back(c);
            c++;
            if(c == 'Z' + 1)
                c = 'a';
            else if (c == 'z' + 1)
                c = 'A';
        }
    
    
    for(int i = 0; i < ROWS; i++) {
        cout<< sv.at(i);
        cout << endl;
    }
    
    String_Vector vs = transpose(sv);
    for(int i = 0; i < (int)vs.size(); i++)
        cout << vs.at(i) << endl;
    
    return 0;
}

String_Vector transpose (const String_Vector& sv) {
    
    // STUDENTS MUST COMPLETE THE DEFINITION OF THIS FUNCTION.
    if (sv.empty()){ // Check if the input vector is empty
        return String_Vector();
     }
     const int numRows = sv.size();
     const int numCols = sv[0].size();

    //Initialize the transposed vector.
     String_Vector vs(numCols, std::string(numRows, ' '));

     for (int i = 0; i < numRows; i++){ // Loop and transpose original matrix.
        for (int j = 0; j < numCols; j++)
        {
           vs[j][i] = sv[i][j];
        }
        
     }
    return vs;
}
