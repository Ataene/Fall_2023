/*
 *  File Name: lab2exe_E.cpp
 *  Assignment: ENSF 614 Lab 2, exercise E
 *  Created by Mahmood Moussavi
 *  Completed by: Emmanuel Alafonye
 *  Submission Date: Sept 27, 2023.
 */

#include "lab2exe_E.h"

cplx cplx_add(cplx z1, cplx z2){
  cplx result;

  result.real = z1.real + z2.real;
  result.imag = z1.imag + z2.imag;
  return result;
}

cplx cplx_subtract(cplx z1, cplx z2){ // Subtract two complex numbers
    cplx result;
    result.real = z1.real - z2.real;
    result.imag = z1.imag - z2.imag;
    return result;
}

cplx cplx_multiply(cplx z1, cplx z2){ // Multiply two complex numbers
    cplx result;
    result.real = (z1.real * z2.real) - (z1.imag * z2.imag);
    result.imag = (z1.real * z2.imag) + (z1.imag * z2.real);
    return result;
}

