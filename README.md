# Custom Math Library: s21_math

## Introduction

Implementation of your own version of the math.h library.  

This is a team project developed in collaboration with Cupcakep, Takakoka, Mathildc
and Jesicahi also students of School 21 in Moscow.

## Chapter I: Information

### Overview

The C programming language offers a range of mathematical functions through the standard library `math.h`. These functions cater to various mathematical computations involving floating-point numbers, often utilizing radians as the unit of angle.

### Functions to Implement

We aim to implement a subset of functions similar to those found in `math.h`, focusing on basic mathematical operations. Here's an overview of the functions to be included:

| No. | Function | Description |
| --- | -------- | ----------- |
| 1   | `int s21_abs(int x)`           | Computes the absolute value of an integer. |
| 2   | `long double s21_acos(double x)`  | Computes the arc cosine. |
| 3   | `long double s21_asin(double x)`  | Computes the arc sine. |
| 4   | `long double s21_atan(double x)`  | Computes the arc tangent. |
| 5   | `long double s21_ceil(double x)`  | Returns the nearest integer not less than the given value. |
| 6   | `long double s21_cos(double x)`   | Computes cosine. |
| 7   | `long double s21_exp(double x)`   | Returns `e` raised to the power of the given value. |
| 8   | `long double s21_fabs(double x)`  | Computes the absolute value of a floating-point number. |
| 9   | `long double s21_floor(double x)` | Returns the nearest integer not greater than the given value. |
| 10  | `long double s21_fmod(double x, double y)` | Computes the remainder of the division operation. |
| 11  | `long double s21_log(double x)`   | Computes the natural logarithm. |
| 12  | `long double s21_pow(double base, double exp)` | Raises a number to the given power. |
| 13  | `long double s21_sin(double x)`   | Computes sine. |
| 14  | `long double s21_sqrt(double x)`  | Computes square root. |
| 15  | `long double s21_tan(double x)`   | Computes tangent. |

## Chapter II: Implementation

### Part 1: Implementing the s21_math library functions

The following guidelines outline the implementation of the math library:

- Development in C language adhering to C11 standard using gcc compiler.
- Code organization within the src folder on the develop branch.
- Adherence to modern language constructs and POSIX.1-2017 standard, avoiding legacy constructions and library functions.
- Adherence to Google style guide for code writing.
- Creation of a static library with the header file s21_math.h.
- Structured programming principles should be followed, minimizing code duplication.
- Use of the s21_ prefix for each function.
- Comprehensive unit tests using the Check library to ensure accuracy and reliability.
- Unit tests must achieve at least 80% coverage for each function using gcov.
- Provision of a Makefile for building the library and tests, with targets for all necessary operations including building, cleaning, testing, generating coverage reports, etc.
- Prohibition of copying implementation from the standard math.h library, except for usage within unit tests.
- Emphasis on mimicking the logic and behavior of the standard library, particularly regarding error handling and memory management.
- Verification of results with a total accuracy of 16 significant digits and fractional part accuracy up to 6 decimal places.
