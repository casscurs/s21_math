#include "s21_math.h"


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
        ans = exp(ex * log(base));
    }
    return ans;
}

long double s21_sqrt(double x) {
    return s21_pow(x, 0.5);
}