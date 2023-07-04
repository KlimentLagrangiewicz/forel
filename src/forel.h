#ifndef FOREL_H_
#define FOREL_H_

#include <stdlib.h>
#include <string.h>
#include <math.h>

double distEv(const double *x, const double *c, const int m);
double getAvDist(const double *x, const int n, const int m);
void autoscaling(double *x, const int n, const int m, double *eps);
char equal(const double* const x, const double* const y, const int n);
char calcCentrum(const double* const x, double *c, const int* const y, const int n, const int m, const int marker);
void markingNeighbors(const double* x, const double* c, int* const y, const int n, const int m, const double r, const int marker);
void forel(const double* const X, int* const y, const int n, const int m, const double inR);

#endif
