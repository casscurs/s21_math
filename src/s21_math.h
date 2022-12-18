#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define S21_E 2.71828182845904
#define S21_PI 3.14159265358979
#define S21_INF LDBL_MAX * 1e100
#define S21_NAN S21_INF - S21_INF

long double s21_factorial(int n);

long double s21_exp(double x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_log(double x);

#endif  // SRC_S21_MATH_H_
