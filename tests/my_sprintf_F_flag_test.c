#include <check.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/my_string.h"

START_TEST(test_my_sprintf_single_float_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%F", 789.123),
                   sprintf(original, "%F", 789.123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_single_negative_float_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%F", -789.123),
                   sprintf(original, "%F", -789.123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_max_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%F", FLT_MAX),
                   sprintf(original, "%F", FLT_MAX));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_min_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%F", FLT_MIN),
                   sprintf(original, "%F", FLT_MIN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_zero_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%F", 0.0), sprintf(original, "%F", 0.0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_width_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%20F", 789.123),
                   sprintf(original, "%20F", 789.123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_left_align_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%-20F", 789.123),
                   sprintf(original, "%-20F", 789.123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_zero_fill_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%020F", 789.123),
                   sprintf(original, "%020F", 789.123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_precision_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%.4F", 789.123),
                   sprintf(original, "%.4F", 789.123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_precision_zero_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%.0F", 789.123),
                   sprintf(original, "%.0F", 789.123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_precision_large_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%.12F", 789.123),
                   sprintf(original, "%.12F", 789.123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_width_and_precision_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%20.4F", 789.123),
                   sprintf(original, "%20.4F", 789.123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_plus_flag_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%+F", 789.123),
                   sprintf(original, "%+F", 789.123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_space_flag_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "% F", 789.123),
                   sprintf(original, "% F", 789.123));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_hash_flag_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%#F", 789.0),
                   sprintf(original, "%#F", 789.0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_many_floats_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%FHello%Fworld%F", 4.4, 5.5, 6.6),
                   sprintf(original, "%FHello%Fworld%F", 4.4, 5.5, 6.6));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_nan_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%F", NAN), sprintf(original, "%F", NAN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_negative_nan_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%F", -NAN), sprintf(original, "%F", -NAN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_inf_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%F", INFINITY),
                   sprintf(original, "%F", INFINITY));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_negative_inf_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%F", -INFINITY),
                   sprintf(original, "%F", -INFINITY));
  ck_assert_str_eq(my, original);
}
END_TEST

Suite *my_sprintf_F_suite(void) {
  Suite *s = suite_create("my_sprintf_F");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_my_sprintf_single_float_upper);
  tcase_add_test(tc, test_my_sprintf_single_negative_float_upper);
  tcase_add_test(tc, test_my_sprintf_float_max_upper);
  tcase_add_test(tc, test_my_sprintf_float_min_upper);
  tcase_add_test(tc, test_my_sprintf_float_zero_upper);
  tcase_add_test(tc, test_my_sprintf_float_with_width_upper);
  tcase_add_test(tc, test_my_sprintf_float_with_left_align_upper);
  tcase_add_test(tc, test_my_sprintf_float_with_zero_fill_upper);
  tcase_add_test(tc, test_my_sprintf_float_with_precision_upper);
  tcase_add_test(tc, test_my_sprintf_float_with_precision_zero_upper);
  tcase_add_test(tc, test_my_sprintf_float_with_precision_large_upper);
  tcase_add_test(tc, test_my_sprintf_float_with_width_and_precision_upper);
  tcase_add_test(tc, test_my_sprintf_float_with_plus_flag_upper);
  tcase_add_test(tc, test_my_sprintf_float_with_space_flag_upper);
  tcase_add_test(tc, test_my_sprintf_float_with_hash_flag_upper);
  tcase_add_test(tc, test_my_sprintf_many_floats_upper);
  tcase_add_test(tc, test_my_sprintf_nan_upper);
  tcase_add_test(tc, test_my_sprintf_negative_nan_upper);
  tcase_add_test(tc, test_my_sprintf_inf_upper);
  tcase_add_test(tc, test_my_sprintf_negative_inf_upper);

  suite_add_tcase(s, tc);
  return s;
}