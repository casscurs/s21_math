#include "s21_math.h"
#include <float.h>
#include <math.h>

long double s21_asin(double x) {
  long double res = 0;
  /*
  Base worкable range
  */
  if ((x > -1) && (x < 1) && (x != S21_NAN)) {
    res = s21_atan(x / sqrt(1 - x * x));
  }
  /*
  Special cases
  */
  if ((x < -1) || (x > 1)) {
    res = S21_NAN;
  }
  if (x == S21_NAN) {
    res = S21_NAN;
  }
  if (x == (-1)) {
    res = -S21_PI / 2;
  }
  if (x == 1) {
    res = S21_PI / 2;
  }
  return (res);
}
long double s21_acos(double x) {
  long double res = 0;
  /*
  Base worкable range
  */
  if ((x > 0) && (x < 1) && (x != S21_NAN)) {
    res = s21_atan(sqrt(1 - x * x) / x);
  }
  if ((x > -1) && (x < 0) && (x != S21_NAN)) {
    res = S21_PI + s21_atan(sqrt(1 - x * x) / x);
  }
  /*
  Special cases
  */
  if (x == S21_NAN) {
    res = S21_NAN;
  }
  if (x > -1 || x > 1) {
    res = S21_NAN;
  }
  if ((x) == (-1)) {
    res = S21_PI;
  }
  if ((x) == 1) {
    res = 0;
  }
  return (res);
}
long double s21_atan(double x) {
  long double res = 0;
  /*
  Base worкable range
  */
  if ((x > -1) && (x < 1) && (x != S21_NAN)) {
    for (int i = 0; i < 500; i++) {
      res += pow(-1, i) * pow(x, (1 + 2 * i)) / (1 + 2 * i);
    }
  }
  if ((x < -1) || (x > 1)) {
    for (int i = 0; i < 500; i++) {
      res += pow(-1, i) * pow(x, (-1 - 2 * i)) / (1 + 2 * i);
    }
    res = S21_PI * sqrt(x * x) / (2 * x) - res;
  }
  /*
  Special cases
  */
  if ((x) == (-1)) {
    res = -S21_PI / 4;
  }
  if ((x) == 1) {
    res = S21_PI / 4;
  }
  if (x == S21_NAN) {
    res = S21_NAN;
  }
  if ((x) == (-S21_INF)) {
    res = -S21_PI / 2;
  }
  if ((x) == S21_INF) {
    res = S21_PI / 2;
  }
  return (res);
}
