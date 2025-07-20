#include <check.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/my_string.h"

START_TEST(test_my_sscanf_e_empty) {
  char *input = "";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%e", &a), sscanf(input, "%e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_e_simple) {
  char *input = "123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%e", &a), sscanf(input, "%e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_e_negative) {
  char *input = "-456.789";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%e", &a), sscanf(input, "%e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_e_exponent_upper) {
  char *input = "1.23E+10";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%e", &a), sscanf(input, "%e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_e_exponent_lower) {
  char *input = "1.23e-5";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%e", &a), sscanf(input, "%e", &b));
  ck_assert_float_eq_tol(a, b, 1e-7);
}
END_TEST

START_TEST(test_my_sscanf_e_multiple) {
  char *input = "7.89e1 0.12e2 -3.45e3";
  float a1 = 0, a2 = 0, a3 = 0;
  float b1 = 0, b2 = 0, b3 = 0;
  ck_assert_int_eq(my_sscanf(input, "%e%e%e", &a1, &a2, &a3),
                   sscanf(input, "%e%e%e", &b1, &b2, &b3));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
}
END_TEST

START_TEST(test_my_sscanf_e_with_text) {
  char *input = "Value: 4.2e1, Next: 7.3e0";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  ck_assert_int_eq(my_sscanf(input, "Value: %e, Next: %e", &a1, &a2),
                   sscanf(input, "Value: %e, Next: %e", &b1, &b2));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_my_sscanf_e_leading_whitespace) {
  char *input = "    \t\n\r\v\f 1.23e1";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%e", &a), sscanf(input, "%e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_e_trailing_whitespace) {
  char *input = "4.56e2   \t\n\r\v\f";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%e", &a), sscanf(input, "%e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_e_max_float) {
  char *input = "3.4028235e38";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%e", &a), sscanf(input, "%e", &b));
  ck_assert_float_eq(a, b);
  ck_assert(a == FLT_MAX || isnan(b));
}
END_TEST

START_TEST(test_my_sscanf_e_min_float) {
  char *input = "1.1754944e-38";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%e", &a), sscanf(input, "%e", &b));
  ck_assert_float_eq(a, b);
  ck_assert(a == FLT_MIN || isnan(b));
}
END_TEST

START_TEST(test_my_sscanf_e_invalid_input) {
  char *input = "abc1.23e1";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%e", &a), sscanf(input, "%e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_e_mixed_input) {
  char *input = "1.23e1abc4.56e2";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  ck_assert_int_eq(my_sscanf(input, "%eabc%e", &a1, &a2),
                   sscanf(input, "%eabc%e", &b1, &b2));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_my_sscanf_e_zero) {
  char *input = "0.0";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%e", &a), sscanf(input, "%e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_e_leading_zeros) {
  char *input = "0001.23e1";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%e", &a), sscanf(input, "%e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_e_leading_plus) {
  char *input = "+1.23e1";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%e", &a), sscanf(input, "%e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_e_width) {
  char *input = "1.23456e5";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%4e", &a), sscanf(input, "%4e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_e_star) {
  char *input = "1.23e1 4.56e2";
  float a = 0;
  ck_assert_int_eq(my_sscanf(input, "%*e %e", &a), sscanf(input, "%*e %e", &a));
}
END_TEST

START_TEST(test_my_sscanf_e_width_3) {
  char *input = "1.23456e5";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%3e", &a), sscanf(input, "%3e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_e_star_simple) {
  char *input = "1.23e1 4.56e2";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%*e %e", &a), sscanf(input, "%*e %e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_e_star_multiple) {
  char *input = "1.0e1 2.0e2 3.0e3 4.0e4";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%*e %*e %e %*e", &a),
                   sscanf(input, "%*e %*e %e %*e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_le_simple) {
  char *input = "1.23e10";
  double a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%le", &a), sscanf(input, "%le", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_le_large) {
  char *input = "1.7976931348623157e308";
  double a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%le", &a), sscanf(input, "%le", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_e_width_star) {
  char *input = "1.2345e1 6.7890e2";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%3e %*e %*e", &a),
                   sscanf(input, "%3e %*e %*e", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_e_star_no_output) {
  char *input = "1.23e1 4.56e2";
  ck_assert_int_eq(my_sscanf(input, "%*e %*e"), sscanf(input, "%*e %*e"));
}
END_TEST

START_TEST(test_my_sscanf_e_inf) {
  char *input = "inf";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%e", &a), sscanf(input, "%e", &b));
  ck_assert(isinf(a) && isinf(b));
}
END_TEST

START_TEST(test_my_sscanf_e_nan) {
  char *input = "nan";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%e", &a), sscanf(input, "%e", &b));
  ck_assert(isnan(a) && isnan(b));
}
END_TEST

Suite *my_sscanf_e_suite(void) {
  Suite *s = suite_create("my_sscanf_e");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_my_sscanf_e_empty);
  tcase_add_test(tc, test_my_sscanf_e_simple);
  tcase_add_test(tc, test_my_sscanf_e_negative);
  tcase_add_test(tc, test_my_sscanf_e_exponent_upper);
  tcase_add_test(tc, test_my_sscanf_e_exponent_lower);
  tcase_add_test(tc, test_my_sscanf_e_multiple);
  tcase_add_test(tc, test_my_sscanf_e_with_text);
  tcase_add_test(tc, test_my_sscanf_e_leading_whitespace);
  tcase_add_test(tc, test_my_sscanf_e_trailing_whitespace);
  tcase_add_test(tc, test_my_sscanf_e_max_float);
  tcase_add_test(tc, test_my_sscanf_e_min_float);
  tcase_add_test(tc, test_my_sscanf_e_invalid_input);
  tcase_add_test(tc, test_my_sscanf_e_mixed_input);
  tcase_add_test(tc, test_my_sscanf_e_zero);
  tcase_add_test(tc, test_my_sscanf_e_leading_zeros);
  tcase_add_test(tc, test_my_sscanf_e_leading_plus);
  tcase_add_test(tc, test_my_sscanf_e_width);
  tcase_add_test(tc, test_my_sscanf_e_star);
  tcase_add_test(tc, test_my_sscanf_e_width_3);
  tcase_add_test(tc, test_my_sscanf_e_star_simple);
  tcase_add_test(tc, test_my_sscanf_e_star_multiple);
  tcase_add_test(tc, test_my_sscanf_e_star_no_output);
  tcase_add_test(tc, test_my_sscanf_le_simple);
  tcase_add_test(tc, test_my_sscanf_le_large);
  tcase_add_test(tc, test_my_sscanf_e_width_star);
  tcase_add_test(tc, test_my_sscanf_e_inf);
  tcase_add_test(tc, test_my_sscanf_e_nan);

  suite_add_tcase(s, tc);
  return s;
}