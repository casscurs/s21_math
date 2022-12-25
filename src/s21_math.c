#include "s21_math.h"
#include <float.h>

// Abs, fabs, ceil, floor, fmod functions
int s21_abs(int x) { return (x > 0) ? x : -x; }

long double s21_fabs(double x) { return (x > 0) ? x : -x; }

long double s21_ceil(double x) {
  return ((x - (int)x) && x > 0.) ? (long double)((int)x + 1)
                                  : (long double)(int)x;
}

long double s21_floor(double x) {
  return ((x - (int)x) && x < 0.) ? (long double)((int)x - 1)
                                  : (long double)(int)x;
}

long double s21_fmod(double x, double y) {
  long double res = s21_fabs(x);
  y = s21_fabs(y);
  int i = 1;
  while (res >= y) {
    res = s21_fabs(x) - y * i;
    i++;
  }
  return x < 0 ? -res : res;
}

// Pow and sqrt functions

long double s21_pow(double base, double ex) {
  long double ans = 0.0;
  if (ex == (int)ex) {
    if (ex < 0) {
      base = 1 / base;
      ex = -ex;
    }
    ans = 1.;
    for (int i = 0; i < ex; i++) {
      ans *= base;
    }
  } else {
    ans = s21_exp(ex * s21_log(base));
  }
  return ans;
}

long double s21_sqrt(double x) { return s21_pow(x, 0.5); }

// Exp sin cos tan log and factorial functions

long double s21_factorial(int n) {
  long double res = 0.;
  if (n == 0 || n == 1) {
    res = 1.;
  } else if (n > 1) {
    res = n * s21_factorial(n - 1);
  }
  return (res);
}

long double s21_exp(double x) {
  long double res = 0.L;
  int is_x_negative = 0;
  if (x > DBL_MAX) {
    res = S21_INF;
  } else if (x < -DBL_MAX) {
    res = 0;
  } else {
    if (x < 0) {
      is_x_negative = 1;
      x = -x;
    }
    for (int i = 0; i < 500; i += 1) {
      res += s21_pow(x, i) / s21_factorial(i);
    }
    if (is_x_negative) {
      res = 1 / res;
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
  int is_small = 0;
  res = 0.L;
  if (x < 0 || x == S21_NAN) {
    res = S21_NAN;
  } else if (x > DBL_MAX) {
    res = S21_INF;
  } else if (x < DBL_MIN) {
    res = -S21_INF;
  } else {
    long double tmp = 0.;
    if (x < 0.01) {
      x = 1 / x;
      is_small = 1;
    }
    while (x > S21_E) {
      x = x / S21_E;
      tmp += 1.;
    }
    long double y = (x - 1) / (x + 1);
    for (int i = 0; i < 2000; i += 1) {
      res += s21_pow(y, 2 * i) / (2 * i + 1);
    }
    res = res * 2 * y;
    res += tmp;
    if (is_small) {
      res = - res;
    }
  }
  return res;
}

// asin acos atan functions

long double s21_asin(double x) {
  long double res = 0;
  /*
  Base worкable range
  */
  if ((x > -1) && (x < 1) && (x != S21_NAN)) {
    res = s21_atan(x / s21_sqrt(1 - x * x));
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
    res = s21_atan(s21_sqrt(1 - x * x) / x);
  }
  if ((x > -1) && (x < 0) && (x != S21_NAN)) {
    res = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
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
      res += s21_pow(-1, i) * s21_pow(x, (1 + 2 * i)) / (1 + 2 * i);
    }
  }
  if ((x < -1) || (x > 1)) {
    for (int i = 0; i < 500; i++) {
      res += s21_pow(-1, i) * s21_pow(x, (-1 - 2 * i)) / (1 + 2 * i);
    }
    res = S21_PI * s21_sqrt(x * x) / (2 * x) - res;
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
