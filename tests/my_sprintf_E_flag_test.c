#include <check.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/my_string.h"

START_TEST(test_my_sprintf_single_float_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%E", 123.456),
                   sprintf(original, "%E", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_single_negative_float_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%E", -123.456),
                   sprintf(original, "%E", -123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_max_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%E", FLT_MAX),
                   sprintf(original, "%E", FLT_MAX));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_min_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%E", FLT_MIN),
                   sprintf(original, "%E", FLT_MIN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_zero_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%E", 0.0), sprintf(original, "%E", 0.0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_width_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%15E", 123.456),
                   sprintf(original, "%15E", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_left_align_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%-15E", 123.456),
                   sprintf(original, "%-15E", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_zero_fill_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%015E", 123.456),
                   sprintf(original, "%015E", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_precision_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%.3E", 123.456),
                   sprintf(original, "%.3E", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_precision_zero_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%.0E", 123.456),
                   sprintf(original, "%.0E", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_precision_large_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%.10E", 123.456),
                   sprintf(original, "%.10E", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_width_and_precision_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%15.3E", 123.456),
                   sprintf(original, "%15.3E", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_plus_flag_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%+E", 123.456),
                   sprintf(original, "%+E", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_space_flag_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "% E", 123.456),
                   sprintf(original, "% E", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_float_with_hash_flag_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%#E", 123.0),
                   sprintf(original, "%#E", 123.0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_many_floats_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%EHello%Eworld%E", 1.1, 2.2, 3.3),
                   sprintf(original, "%EHello%Eworld%E", 1.1, 2.2, 3.3));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_nan_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%E", NAN), sprintf(original, "%E", NAN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_negative_nan_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%E", -NAN), sprintf(original, "%E", -NAN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_inf_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%E", INFINITY),
                   sprintf(original, "%E", INFINITY));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_negative_inf_E) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%E", -INFINITY),
                   sprintf(original, "%E", -INFINITY));
  ck_assert_str_eq(my, original);
}
END_TEST

Suite *my_sprintf_E_suite(void) {
  Suite *s = suite_create("my_sprintf_E");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_my_sprintf_single_float_E);
  tcase_add_test(tc, test_my_sprintf_single_negative_float_E);
  tcase_add_test(tc, test_my_sprintf_float_max_E);
  tcase_add_test(tc, test_my_sprintf_float_min_E);
  tcase_add_test(tc, test_my_sprintf_float_zero_E);
  tcase_add_test(tc, test_my_sprintf_float_with_width_E);
  tcase_add_test(tc, test_my_sprintf_float_with_left_align_E);
  tcase_add_test(tc, test_my_sprintf_float_with_zero_fill_E);
  tcase_add_test(tc, test_my_sprintf_float_with_precision_E);
  tcase_add_test(tc, test_my_sprintf_float_with_precision_zero_E);
  tcase_add_test(tc, test_my_sprintf_float_with_precision_large_E);
  tcase_add_test(tc, test_my_sprintf_float_with_width_and_precision_E);
  tcase_add_test(tc, test_my_sprintf_float_with_plus_flag_E);
  tcase_add_test(tc, test_my_sprintf_float_with_space_flag_E);
  tcase_add_test(tc, test_my_sprintf_float_with_hash_flag_E);
  tcase_add_test(tc, test_my_sprintf_many_floats_E);
  tcase_add_test(tc, test_my_sprintf_nan_E);
  tcase_add_test(tc, test_my_sprintf_negative_nan_E);
  tcase_add_test(tc, test_my_sprintf_inf_E);
  tcase_add_test(tc, test_my_sprintf_negative_inf_E);

  suite_add_tcase(s, tc);
  return s;
}