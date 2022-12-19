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
