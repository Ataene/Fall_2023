/*
 *  File Name: lab2exe_E.cpp
 *  Assignment: ENSF 614 Lab 2, exercise E
 *  Created by Mahmood Moussavi
 *  Completed by: Emmanuel Alafonye
 *  Submission Date: Sept 27, 2023.
 */

#ifndef CPLX_H
#define CPLX_H

struct cplx {
  double real;
  double imag;
};

/*  NOTES:
 *    The following set of function prototypes make for a good
 *    exercise in programming with structs but constitute a BAD module
 *    interface design.  A good interface would use the same pattern
 *    for all four function prototypes.
 *
 *    cplx_add probably has the most convenient interface, because it
 *    lets you write things like
 *
 *       w = cplx_add( z1, cplx_add(z2, z3) );
 *
 *    On the other hand, cplx_multiply probably has the most efficient
 *    interface, because it eliminates any copying of structs.
 */

// cplx cplx_add(cplx z1, cplx z2);
cplx cplx_add(cplx z1, cplx z2)
{
  cplx result;

  result.real = z1.real + z2.real;
  result.imag = z1.imag + z2.imag;
  return result;
}
/* PROMISES: Return value is complex sum of z1 and z2. */

void cplx_subtract(cplx z1, cplx z2,  cplx *difference);
/*
 * REQUIRES
 *   difference points to a variable.
 * PROMISES
 *   *difference contains complex difference obtained
 *   by subtracting z2 from z1.
 */
// w = 1.5 + j 0.75, and z = -2.5 - j 0.5
void cplx_multiply(const cplx *pz1,
              const cplx *pz2,
              cplx *product);
/*
 * REQUIRES
 *   pz1, pz2 and product point to variables.
 *   pz1 != product && pz2 != product.
 * PROMISES
 *   *product contains complex product of *pz1 and *pz2.
 */
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

#endif /* ifndef CPLX_H */
