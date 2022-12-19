#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <check.h>
#include <ctype.h>
#include <stdint.h>

// Abs, fabs, ceil, floor, fmod functions

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);

// Pow and sqrt functions
long double s21_sqrt(double sqrt);
long double s21_pow(double base, double exp);