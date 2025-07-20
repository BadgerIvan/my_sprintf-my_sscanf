#include <check.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/my_string.h"

START_TEST(test_my_sscanf_f_empty) {
  char *input = "";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_simple) {
  char *input = "123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_negative) {
  char *input = "-456.789";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_multiple) {
  char *input = "789.012 345.678 -901.234";
  float a1 = 0, a2 = 0, a3 = 0;
  float b1 = 0, b2 = 0, b3 = 0;
  ck_assert_int_eq(my_sscanf(input, "%f%f%f", &a1, &a2, &a3),
                   sscanf(input, "%f%f%f", &b1, &b2, &b3));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
}
END_TEST

START_TEST(test_my_sscanf_f_with_text) {
  char *input = "Value: 42.5, Next: 73.8";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  ck_assert_int_eq(my_sscanf(input, "Value: %f, Next: %f", &a1, &a2),
                   sscanf(input, "Value: %f, Next: %f", &b1, &b2));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_my_sscanf_f_leading_whitespace) {
  char *input = "    \t\n\r\v\f 123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_trailing_whitespace) {
  char *input = "456.789   \t\n\r\v\f";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_max_float) {
  char *input = "3.402823466e+38";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_min_float) {
  char *input = "-3.402823466e+38";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_invalid_input) {
  char *input = "abc123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_mixed_input) {
  char *input = "123.456abc789.012";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  ck_assert_int_eq(my_sscanf(input, "%fabc%f", &a1, &a2),
                   sscanf(input, "%fabc%f", &b1, &b2));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_my_sscanf_f_zero) {
  char *input = "0.0";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_leading_zeros) {
  char *input = "000123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_leading_plus) {
  char *input = "+123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_width) {
  char *input = "123.456789";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%5f", &a), sscanf(input, "%5f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_star) {
  char *input = "123.456 789.012";
  float a = 0;
  ck_assert_int_eq(my_sscanf(input, "%*f %f", &a), sscanf(input, "%*f %f", &a));
}
END_TEST

START_TEST(test_my_sscanf_f_scientific) {
  char *input = "1.23e+4";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_scientific_negative) {
  char *input = "-1.23e-4";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_scientific_upper) {
  char *input = "1.23E+4";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_no_fraction) {
  char *input = "123.";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_no_integer) {
  char *input = ".456";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_inf) {
  char *input = "inf";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert(!!isinf(a) == !!isinf(b));
}
END_TEST

START_TEST(test_my_sscanf_f_inf_negative) {
  char *input = "-inf";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert(!!isinf(a) == !!isinf(b));
}
END_TEST

START_TEST(test_my_sscanf_f_nan) {
  char *input = "nan";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert(!!isnan(a) == !!isnan(b));
}
END_TEST

START_TEST(test_my_sscanf_f_nan_negative) {
  char *input = "-nan";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert(!!isnan(a) == !!isnan(b));
}
END_TEST

START_TEST(test_my_sscanf_f_long) {
  char *input = "1234567890.1234567890";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%f", &a), sscanf(input, "%f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_width_star) {
  char *input = "123.456 789.012 345.678";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%*f %5f %*f", &a),
                   sscanf(input, "%*f %5f %*f", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_f_star_no_output) {
  char *input = "123.456 789.012";
  ck_assert_int_eq(my_sscanf(input, "%*f %*f"), sscanf(input, "%*f %*f"));
}
END_TEST

START_TEST(test_my_sscanf_lf_simple) {
  char *input = "123.456";
  double a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%lf", &a), sscanf(input, "%lf", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_lf_large) {
  char *input = "1.7976931348623158e+308";
  double a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%lf", &a), sscanf(input, "%lf", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_lf_small) {
  char *input = "2.2250738585072014e-308";
  double a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%lf", &a), sscanf(input, "%lf", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_Lf_simple) {
  char *input = "123.456";
  long double a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%Lf", &a), sscanf(input, "%Lf", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_Lf_large) {
  char *input = "1.189731495357231765e+4932";
  long double a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%Lf", &a), sscanf(input, "%Lf", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

Suite *my_sscanf_f_suite(void) {
  Suite *s = suite_create("my_sscanf_f");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_my_sscanf_f_empty);
  tcase_add_test(tc, test_my_sscanf_f_simple);
  tcase_add_test(tc, test_my_sscanf_f_negative);
  tcase_add_test(tc, test_my_sscanf_f_multiple);
  tcase_add_test(tc, test_my_sscanf_f_with_text);
  tcase_add_test(tc, test_my_sscanf_f_leading_whitespace);
  tcase_add_test(tc, test_my_sscanf_f_trailing_whitespace);
  tcase_add_test(tc, test_my_sscanf_f_max_float);
  tcase_add_test(tc, test_my_sscanf_f_min_float);
  tcase_add_test(tc, test_my_sscanf_f_invalid_input);
  tcase_add_test(tc, test_my_sscanf_f_mixed_input);
  tcase_add_test(tc, test_my_sscanf_f_zero);
  tcase_add_test(tc, test_my_sscanf_f_leading_zeros);
  tcase_add_test(tc, test_my_sscanf_f_leading_plus);
  tcase_add_test(tc, test_my_sscanf_f_width);
  tcase_add_test(tc, test_my_sscanf_f_star);
  tcase_add_test(tc, test_my_sscanf_f_scientific);
  tcase_add_test(tc, test_my_sscanf_f_scientific_negative);
  tcase_add_test(tc, test_my_sscanf_f_scientific_upper);
  tcase_add_test(tc, test_my_sscanf_f_no_fraction);
  tcase_add_test(tc, test_my_sscanf_f_no_integer);
  tcase_add_test(tc, test_my_sscanf_f_inf);
  tcase_add_test(tc, test_my_sscanf_f_inf_negative);
  tcase_add_test(tc, test_my_sscanf_f_nan);
  tcase_add_test(tc, test_my_sscanf_f_nan_negative);
  tcase_add_test(tc, test_my_sscanf_f_long);
  tcase_add_test(tc, test_my_sscanf_f_width_star);
  tcase_add_test(tc, test_my_sscanf_f_star_no_output);
  tcase_add_test(tc, test_my_sscanf_lf_simple);
  tcase_add_test(tc, test_my_sscanf_lf_large);
  tcase_add_test(tc, test_my_sscanf_lf_small);
  tcase_add_test(tc, test_my_sscanf_Lf_simple);
  tcase_add_test(tc, test_my_sscanf_Lf_large);

  suite_add_tcase(s, tc);
  return s;
}