#include "s21_math.h"

// Abs, fabs, ceil, floor, fmod functions
int s21_abs(int x){
    return (x > 0) ? x : -x;
}

long double s21_fabs(double x){
    return (x > 0) ? x : -x;
}

long double s21_ceil(double x){
    return ((x - (int)x) && x > 0.) ? (long double)((int)x + 1) : (long double)(int)x;
}

long double s21_floor(double x){
    return ((x - (int)x) && x < 0.) ? (long double)((int)x - 1) : (long double)(int)x;
}

long double s21_fmod(double x, double y){
    long double res = s21_fabs(x);
    y = s21_fabs(y);
    int i = 1;
    while (res >= y){
        res = s21_fabs(x) - y * i;
        i++;
    }
    return x < 0 ? - res : res;
}
