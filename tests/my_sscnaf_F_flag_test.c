#include <check.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/my_string.h"

START_TEST(test_my_sscanf_F_empty) {
  char *input = "";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%F", &a), sscanf(input, "%F", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_F_simple) {
  char *input = "123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%F", &a), sscanf(input, "%F", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_F_negative) {
  char *input = "-456.789";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%F", &a), sscanf(input, "%F", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_F_multiple) {
  char *input = "789.012 123.456 -345.678";
  float a1 = 0, a2 = 0, a3 = 0;
  float b1 = 0, b2 = 0, b3 = 0;
  ck_assert_int_eq(my_sscanf(input, "%F%F%F", &a1, &a2, &a3),
                   sscanf(input, "%F%F%F", &b1, &b2, &b3));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
}
END_TEST

START_TEST(test_my_sscanf_F_with_text) {
  char *input = "Value: 42.5, Next: 73.8";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  ck_assert_int_eq(my_sscanf(input, "Value: %F, Next: %F", &a1, &a2),
                   sscanf(input, "Value: %F, Next: %F", &b1, &b2));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_my_sscanf_F_leading_whitespace) {
  char *input = "    \t\n\r\v\f 123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%F", &a), sscanf(input, "%F", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_F_trailing_whitespace) {
  char *input = "456.789   \t\n\r\v\f";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%F", &a), sscanf(input, "%F", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_F_max_float) {
  char *input = "3.402823466E+38";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%F", &a), sscanf(input, "%F", &b));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a, FLT_MAX);
}
END_TEST

START_TEST(test_my_sscanf_F_min_float) {
  char *input = "-3.402823466E+38";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%F", &a), sscanf(input, "%F", &b));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a, -FLT_MAX);
}
END_TEST

START_TEST(test_my_sscanf_F_invalid_input) {
  char *input = "abc123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%F", &a), sscanf(input, "%F", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_F_mixed_input) {
  char *input = "123.456abc789.012";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  ck_assert_int_eq(my_sscanf(input, "%Fabc%F", &a1, &a2),
                   sscanf(input, "%Fabc%F", &b1, &b2));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_my_sscanf_F_zero) {
  char *input = "0.0";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%F", &a), sscanf(input, "%F", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_F_leading_zeros) {
  char *input = "000123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%F", &a), sscanf(input, "%F", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_F_leading_plus) {
  char *input = "+123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%F", &a), sscanf(input, "%F", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_F_width) {
  char *input = "123.456789";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%5F", &a), sscanf(input, "%5F", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_F_star) {
  char *input = "123.456 789.012";
  float a = 0;
  ck_assert_int_eq(my_sscanf(input, "%*F %F", &a), sscanf(input, "%*F %F", &a));
}
END_TEST

START_TEST(test_my_sscanf_F_scientific) {
  char *input = "1.23E+4";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%F", &a), sscanf(input, "%F", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_F_scientific_negative) {
  char *input = "-1.23E-4";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%F", &a), sscanf(input, "%F", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_F_inf) {
  char *input = "INF";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%F", &a), sscanf(input, "%F", &b));
  ck_assert(!!isinf(a) == !!isinf(b));
}
END_TEST

START_TEST(test_my_sscanf_F_nan) {
  char *input = "NAN";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%F", &a), sscanf(input, "%F", &b));
  ck_assert(!!isnan(a) == !!isnan(b));
}
END_TEST

START_TEST(test_my_sscanf_LF_simple) {
  char *input = "123.456789012345";
  long double a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%LF", &a), sscanf(input, "%LF", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_LF_large) {
  char *input = "1.7976931348623158E+308";
  long double a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%LF", &a), sscanf(input, "%LF", &b));
  ck_assert_double_eq(a, b);
  ck_assert_double_eq(a, DBL_MAX);
}
END_TEST

START_TEST(test_my_sscanf_F_star_no_output) {
  char *input = "123.456 789.012";
  ck_assert_int_eq(my_sscanf(input, "%*F %*F"), sscanf(input, "%*F %*F"));
}
END_TEST

Suite *my_sscanf_F_suite(void) {
  Suite *s = suite_create("my_sscanf_F");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_my_sscanf_F_empty);
  tcase_add_test(tc, test_my_sscanf_F_simple);
  tcase_add_test(tc, test_my_sscanf_F_negative);
  tcase_add_test(tc, test_my_sscanf_F_multiple);
  tcase_add_test(tc, test_my_sscanf_F_with_text);
  tcase_add_test(tc, test_my_sscanf_F_leading_whitespace);
  tcase_add_test(tc, test_my_sscanf_F_trailing_whitespace);
  tcase_add_test(tc, test_my_sscanf_F_max_float);
  tcase_add_test(tc, test_my_sscanf_F_min_float);
  tcase_add_test(tc, test_my_sscanf_F_invalid_input);
  tcase_add_test(tc, test_my_sscanf_F_mixed_input);
  tcase_add_test(tc, test_my_sscanf_F_zero);
  tcase_add_test(tc, test_my_sscanf_F_leading_zeros);
  tcase_add_test(tc, test_my_sscanf_F_leading_plus);
  tcase_add_test(tc, test_my_sscanf_F_width);
  tcase_add_test(tc, test_my_sscanf_F_star);
  tcase_add_test(tc, test_my_sscanf_F_scientific);
  tcase_add_test(tc, test_my_sscanf_F_scientific_negative);
  tcase_add_test(tc, test_my_sscanf_F_inf);
  tcase_add_test(tc, test_my_sscanf_F_nan);
  tcase_add_test(tc, test_my_sscanf_LF_simple);
  tcase_add_test(tc, test_my_sscanf_LF_large);
  tcase_add_test(tc, test_my_sscanf_F_star_no_output);

  suite_add_tcase(s, tc);
  return s;
}