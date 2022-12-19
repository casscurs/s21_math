#include "s21_math.h"

START_TEST(s21_abs_tests) {

  // test 1
  ck_assert_int_eq(s21_abs(4), abs(4));

  // test 2
  ck_assert_int_eq(s21_abs(0), abs(0));

  // test 3
  ck_assert_int_eq(s21_abs(-4), abs(-4));

  // test 4
  ck_assert_int_eq(s21_abs(-0), abs(-0));

  // test 5
  ck_assert_int_eq(s21_abs(-32767), abs(-32767));

}
END_TEST

START_TEST(s21_fabs_tests) {
  // test 1
  ck_assert_float_eq(s21_fabs(1.000000), fabs(1.000000));

  // test 2
  ck_assert_float_eq(s21_fabs(-1.000000), fabs(-1.000000));

  // test 3
  ck_assert_float_eq(s21_fabs(-1436.6789), fabs(-1436.6789));

  // test 4
  ck_assert_float_eq(s21_fabs(-0.5682), fabs(-0.5682));

  // test 5
  ck_assert_float_eq(s21_fabs(-0.0), fabs(-0.0));
    
  // test 6
  ck_assert_float_eq(s21_fabs(-574785475.758457), fabs(-574785475.758457));
    
  // test 7
  ck_assert_float_eq(s21_fabs(574785475.758457), fabs(574785475.758457));

}
END_TEST

START_TEST(s21_ceil_tests) {
    // test 1
    ck_assert_float_eq(s21_ceil(0.05), ceil(0.05));

    // test 2
    ck_assert_float_eq(s21_ceil(5.25), ceil(5.25));

    // test 3
    ck_assert_float_eq(s21_ceil(-5.25), ceil(-5.25));

    // test 4
    ck_assert_float_eq(s21_ceil(145894093.5838938), ceil(145894093.5838938));

    // test 5
    ck_assert_float_eq(s21_ceil(-145894093.5838938), ceil(-145894093.5838938));

    // test 6
    ck_assert_float_eq(s21_ceil(-3), ceil(-3));

    // test 7
    ck_assert_float_eq(s21_ceil(3), ceil(3));
      
    //test 8
    ck_assert_float_eq(s21_ceil(0), ceil(0));

  }
END_TEST

START_TEST(s21_floor_tests) {
  // test 1
  ck_assert_float_eq(s21_floor(0.05), floor(0.05));

  // test 2
  ck_assert_float_eq(s21_floor(5.25), floor(5.25));

  // test 3
  ck_assert_float_eq(s21_floor(-5.25), floor(-5.25));

  // test 4
  ck_assert_float_eq(s21_floor(145894093.5838938), floor(145894093.5838938));

  // test 5
  ck_assert_float_eq(s21_floor(-145894093.5838938), floor(-145894093.5838938));

  // test 6
  ck_assert_float_eq(s21_floor(-3), floor(-3));

  // test 7
  ck_assert_float_eq(s21_floor(3), floor(3));
    
  //test 8
  ck_assert_float_eq(s21_floor(0), floor(0));

}
END_TEST

START_TEST(s21_fmod_tests) {
  // test 1
  ck_assert_float_eq(s21_fmod(10., 2.), fmod(10., 2.));

  // test 2
  ck_assert_float_eq(s21_fmod(-10., 2.), fmod(-10., 2.));

  // test 3
  ck_assert_float_eq(s21_fmod(30., 0.5), fmod(30., 0.5));

  // test 4
    ck_assert_float_eq(s21_fmod(-30., 0.5), fmod(-30., 0.5));

  // test 5
  ck_assert_float_eq(s21_fmod(0., 2.), fmod(0., 2.));

  // test 6
  ck_assert_float_eq(s21_fmod(10.5, 5.), fmod(10.5, 5.));

  // test 7
  ck_assert_float_eq(s21_fmod(-10.5, 5.), fmod(-10.5, 5.));
    
  // test 8
  ck_assert_float_eq(s21_fmod(106545345.568859, 5.), fmod(106545345.568859, 5.));
    
  // test 9
  ck_assert_float_eq(s21_fmod(1000000., 5.543545), fmod(1000000., 5.543545));
}
END_TEST



START_TEST(s21_pow_tests) {
    // test 1
    ck_assert_float_eq(s21_pow(4,2), pow(4,2));
    
    // test 2
    ck_assert_float_eq(s21_pow(2,-2), pow(2,-2));
    
    // test 3
    ck_assert_float_eq(s21_pow(2,0), pow(2,0));
    
    // test 4
    ck_assert_float_eq(s21_pow(2.456787,1), pow(2.456787,1));
    
    // test 5
    ck_assert_float_nan(s21_pow(-4,0.5));
    ck_assert_float_nan(pow(-4,0.5));
    
    // test 6
    ck_assert_float_eq(s21_pow(-4,5), pow(-4,5));
    
    // test 7
    ck_assert_float_eq(s21_pow(4,20), pow(4,20));
    
    // test 8
    ck_assert_float_eq(s21_pow(4,-10), pow(4,-10));
}
END_TEST

START_TEST(s21_sqrt_tests) {
    // test 1
    ck_assert_float_eq(s21_sqrt(4), sqrt(4));
    
    // test 2
    ck_assert_float_eq(s21_sqrt(0), sqrt(0));
    
    // test 3
    ck_assert_float_nan(s21_sqrt(-1));
    ck_assert_float_nan(sqrt(-1));
    
    // test 4
    ck_assert_float_eq(s21_sqrt(0.00001), sqrt(0.00001));
    
    // test 5
    ck_assert_float_eq(s21_sqrt(1444444444444444), sqrt(1444444444444444));
    
    // test 6
    ck_assert_float_eq(s21_sqrt(0.067676), sqrt(0.067676));

}
END_TEST



START_TEST(s21_exp_tests) {
  // test 1
  ck_assert_float_eq(s21_exp(-S21_INF), exp(-S21_INF));

  // test 2
  ck_assert_float_eq(s21_exp(S21_INF), exp(S21_INF));

  // test 3
  ck_assert_float_nan(s21_exp(S21_NAN));

  // test 4
  ck_assert_float_eq_tol(s21_exp(-100), exp(-100), 1e-15);

  // test 5
  ck_assert_float_eq(s21_exp(0.0005), exp(0.0005));

  // test 6
  ck_assert_float_eq(s21_exp(3000), exp(3000));

}
END_TEST

START_TEST(s21_sin_tests) {
  // test 1
  ck_assert_float_nan(s21_sin(-S21_INF));

  // test 2
  ck_assert_float_nan(s21_sin(S21_INF));

  // test 3
  ck_assert_float_nan(s21_sin(S21_NAN));

  // test 4
  ck_assert_float_eq_tol(s21_sin(-1000), sin(-1000), 1e-15);

  // test 5
    for (double x = -0.1; x < 0.1; x += 0.01) {
        ck_assert_float_eq_tol(s21_sin(x), sin(x), 1e-15);
    }

  // test 6
    for (double x = 100; x < 1000; x += 100) {
        ck_assert_float_eq_tol(s21_sin(x), sin(x), 1e-15);
    }

}
END_TEST

START_TEST(s21_cos_tests) {
  // test 1
  ck_assert_float_nan(s21_cos(-S21_INF));

  // test 2
  ck_assert_float_nan(s21_cos(S21_INF));

  // test 3
  ck_assert_float_nan(s21_cos(S21_NAN));

  // test 4
  ck_assert_float_eq_tol(s21_cos(-1000), cos(-1000), 1e-15);

  // test 5
  for (double x = -0.1; x < 0.1; x += 0.01) {
      ck_assert_float_eq_tol(s21_cos(x), cos(x), 1e-15);
  }

  // test 6
  for (double x = 100; x < 1000; x += 100) {
      ck_assert_float_eq_tol(s21_cos(x), cos(x), 1e-15);
  }
  
}
END_TEST

START_TEST(s21_tan_tests) {
  // test 1
  ck_assert_float_nan(s21_tan(-S21_INF));

  // test 2
  ck_assert_float_nan(s21_tan(S21_INF));

  // test 3
  ck_assert_float_nan(s21_tan(S21_NAN));

  // test 4
  ck_assert_float_eq_tol(s21_tan(-1000), tan(-1000), 1e-15);

  // test 5
  for (double x = -S21_PI; x < S21_PI; x += 0.1) {
    ck_assert_float_eq_tol(s21_tan(x), tan(x), 1e-15);
  }

  // test 6
  for (double x = 100; x < 1000; x += 100) {
    ck_assert_float_eq_tol(s21_tan(x), tan(x), 1e-15);
  }

}
END_TEST

START_TEST(s21_log_tests) {
  // test 1
  ck_assert_float_nan(s21_log(-S21_INF));

  // test 2
  ck_assert_float_eq(s21_log(S21_INF), log(S21_INF));

  // test 3
  ck_assert_float_nan(s21_log(S21_NAN));

  // test 4
  ck_assert_float_nan(s21_log(-100));

  // test 5
  for (double x = 0; x < 1; x += 0.1) {
      ck_assert_float_eq(s21_log(x), log(x));
  }

  // test 6
  for (double x = 1000; x < 10000; x += 1000) {
      ck_assert_float_eq(s21_log(x), log(x));
  }
  
  // test 7
  ck_assert_float_eq(s21_log(DBL_MAX*2), log(DBL_MAX*2));

  // test 7
  ck_assert_float_eq(s21_log(LDBL_MAX), log(LDBL_MAX));

}
END_TEST

Suite *s21_math(void){
    Suite *s;
    TCase *tc_tests;
    
    s = suite_create("s21_math.h tests");
    tc_tests = tcase_create("Tests");
    
    tcase_add_test(tc_tests, s21_abs_tests);
    tcase_add_test(tc_tests, s21_fabs_tests);
    tcase_add_test(tc_tests, s21_ceil_tests);
    tcase_add_test(tc_tests, s21_floor_tests);
    tcase_add_test(tc_tests, s21_fmod_tests);
    tcase_add_test(tc_tests, s21_pow_tests);
    tcase_add_test(tc_tests, s21_sqrt_tests);
    tcase_add_test(tc_tests, s21_exp_tests);
    tcase_add_test(tc_tests, s21_sin_tests);
    tcase_add_test(tc_tests, s21_cos_tests);
    tcase_add_test(tc_tests, s21_tan_tests);
    tcase_add_test(tc_tests, s21_log_tests);
    
    suite_add_tcase(s, tc_tests);
    
    return s;
}

int main(void){
    Suite *s;
    SRunner *runner;
    
    s = s21_math();
    runner = srunner_create(s);
    
    srunner_run_all(runner, CK_VERBOSE);
    srunner_ntests_failed(runner);
    srunner_free(runner);
    
    return 0;
}
