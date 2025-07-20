#include <check.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/my_string.h"

START_TEST(test_my_sprintf_single_upper_G) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%G", 123.456),
                   sprintf(original, "%G", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_single_negative_upper_G) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%G", -123.456),
                   sprintf(original, "%G", -123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_max) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%G", FLT_MAX),
                   sprintf(original, "%G", FLT_MAX));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_min) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%G", FLT_MIN),
                   sprintf(original, "%G", FLT_MIN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%G", 0.0), sprintf(original, "%G", 0.0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_small) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%G", 0.0000123456),
                   sprintf(original, "%G", 0.0000123456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_large) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%G", 123456789.0),
                   sprintf(original, "%G", 123456789.0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_with_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%15G", 123.456),
                   sprintf(original, "%15G", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_with_left_align) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%-15G", 123.456),
                   sprintf(original, "%-15G", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_with_zero_fill) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%015G", 123.456),
                   sprintf(original, "%015G", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_with_precision) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%.3G", 123.456),
                   sprintf(original, "%.3G", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_with_precision_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%.0G", 123.456),
                   sprintf(original, "%.0G", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_with_precision_large) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%.10G", 123.456),
                   sprintf(original, "%.10G", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_with_width_and_precision) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%15.3G", 123.456),
                   sprintf(original, "%15.3G", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_with_plus_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%+G", 123.456),
                   sprintf(original, "%+G", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_with_space_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "% G", 123.456),
                   sprintf(original, "% G", 123.456));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_with_hash_flag) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%#G", 123.0),
                   sprintf(original, "%#G", 123.0));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_many_upper_Gs) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%GHello%Gworld%G", 1.1, 2.2, 3.3),
                   sprintf(original, "%GHello%Gworld%G", 1.1, 2.2, 3.3));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_nan) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%G", NAN), sprintf(original, "%G", NAN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_negative_nan) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%G", -NAN), sprintf(original, "%G", -NAN));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_inf) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%G", INFINITY),
                   sprintf(original, "%G", INFINITY));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_upper_G_negative_inf) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%G", -INFINITY),
                   sprintf(original, "%G", -INFINITY));
  ck_assert_str_eq(my, original);
}
END_TEST

Suite *my_sprintf_G_suite(void) {
  Suite *s = suite_create("my_sprintf_upper_G");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_my_sprintf_single_upper_G);
  tcase_add_test(tc, test_my_sprintf_single_negative_upper_G);
  tcase_add_test(tc, test_my_sprintf_upper_G_max);
  tcase_add_test(tc, test_my_sprintf_upper_G_min);
  tcase_add_test(tc, test_my_sprintf_upper_G_zero);
  tcase_add_test(tc, test_my_sprintf_upper_G_small);
  tcase_add_test(tc, test_my_sprintf_upper_G_large);
  tcase_add_test(tc, test_my_sprintf_upper_G_with_width);
  tcase_add_test(tc, test_my_sprintf_upper_G_with_left_align);
  tcase_add_test(tc, test_my_sprintf_upper_G_with_zero_fill);
  tcase_add_test(tc, test_my_sprintf_upper_G_with_precision);
  tcase_add_test(tc, test_my_sprintf_upper_G_with_precision_zero);
  tcase_add_test(tc, test_my_sprintf_upper_G_with_precision_large);
  tcase_add_test(tc, test_my_sprintf_upper_G_with_width_and_precision);
  tcase_add_test(tc, test_my_sprintf_upper_G_with_plus_flag);
  tcase_add_test(tc, test_my_sprintf_upper_G_with_space_flag);
  tcase_add_test(tc, test_my_sprintf_upper_G_with_hash_flag);
  tcase_add_test(tc, test_my_sprintf_many_upper_Gs);
  tcase_add_test(tc, test_my_sprintf_upper_G_nan);
  tcase_add_test(tc, test_my_sprintf_upper_G_negative_nan);
  tcase_add_test(tc, test_my_sprintf_upper_G_inf);
  tcase_add_test(tc, test_my_sprintf_upper_G_negative_inf);

  suite_add_tcase(s, tc);
  return s;
}