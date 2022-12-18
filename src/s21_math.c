#include "s21_math.h"

#include <float.h>

long double s21_factorial(int n) {
  long double res;
  if (n == 0 || n == 1) {
    res = 1.;
  } else if (n < 0) {
    res = 0.;
  } else {
    res = n * s21_factorial(n - 1);
  }
  return (res);
}

long double s21_exp(double x) {
  long double res;
  res = 0.L;
  if (x > DBL_MAX) {
    res = S21_INF;
  } else if (x < -20) {
    res = 0;
    // } else if (x == S21_NAN) {
    //   res = S21_NAN;
  } else {
    for (int i = 0; i < 500; i += 1) {
      res += s21_pow(x, i) / s21_factorial(i);
    }
    if (res > DBL_MAX) {
      res = S21_INF;
    }
  }
  return res;
}

long double s21_cos(double x) {
  long double res;
  res = 0.L;
  if (s21_fabs(x) > DBL_MAX || x == S21_NAN) {
    res = S21_NAN;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    for (int i = 0; i < 500; i += 1) {
      res += s21_pow(-1, i) * s21_pow(x, 2 * i) / s21_factorial(2 * i);
    }
  }
  return res;
}

long double s21_sin(double x) {
  long double res;
  res = 0.L;
  if (s21_fabs(x) > DBL_MAX || x == S21_NAN) {
    res = S21_NAN;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    for (int i = 0; i < 500; i += 1) {
      res += s21_pow(-1, i) * s21_pow(x, 2 * i + 1) / s21_factorial(2 * i + 1);
    }
  }
  return res;
}

long double s21_tan(double x) {
  long double res;
  res = 0.L;
  if (s21_fabs(x) > DBL_MAX || x == S21_NAN) {
    res = S21_NAN;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    long double cosx = s21_cos(x);
    if (s21_fabs(cosx) >= LDBL_MIN) {
      res = s21_sin(x) / cosx;
    } else {
      res = S21_NAN;
    }
  }
  return res;
}

long double s21_log(double x) {
  long double res;
  res = 0.L;
  if (x < 0 || x == S21_NAN) {
    res = S21_NAN;
  } else if (x > DBL_MAX) {
    res = S21_INF;
  } else if (x < DBL_MIN) {
    res = -S21_INF;
  } else {
    long double tmp = 0.;
    while (x > S21_E) {
      x = x / S21_E;
      tmp += 1.;
    }
    long double y = (x - 1) / (x + 1);
    for (int i = 0; i < 500; i += 1) {
      res += s21_pow(y, 2 * i) / (2 * i + 1);
    }
    res = res * 2 * y;
    res += tmp;
    if (res > DBL_MAX) {
      res = S21_INF;
    }
  }
  return res;
}
