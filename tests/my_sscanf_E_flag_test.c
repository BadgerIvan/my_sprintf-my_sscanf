#include <check.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/my_string.h"

START_TEST(test_my_sscanf_E_empty) {
  char *input = "";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%E", &a), sscanf(input, "%E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_simple) {
  char *input = "123.456";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%E", &a), sscanf(input, "%E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_negative) {
  char *input = "-456.789";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%E", &a), sscanf(input, "%E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_scientific) {
  char *input = "1.23E+04";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%E", &a), sscanf(input, "%E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_scientific_negative_exp) {
  char *input = "6.78E-09";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%E", &a), sscanf(input, "%E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_multiple) {
  char *input = "1.2E3 4.5E-6 -7.8E+9";
  float a1 = 0, a2 = 0, a3 = 0;
  float b1 = 0, b2 = 0, b3 = 0;
  ck_assert_int_eq(my_sscanf(input, "%E%E%E", &a1, &a2, &a3),
                   sscanf(input, "%E%E%E", &b1, &b2, &b3));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
}
END_TEST

START_TEST(test_my_sscanf_E_with_text) {
  char *input = "Value: 3.14E+00, Next: 2.71E-01";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  ck_assert_int_eq(my_sscanf(input, "Value: %E, Next: %E", &a1, &a2),
                   sscanf(input, "Value: %E, Next: %E", &b1, &b2));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_my_sscanf_E_leading_whitespace) {
  char *input = "    \t\n\r\v\f 1.5E2";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%E", &a), sscanf(input, "%E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_trailing_whitespace) {
  char *input = "2.5E3   \t\n\r\v\f";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%E", &a), sscanf(input, "%E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_max_float) {
  char *input = "3.4028235E+38";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%E", &a), sscanf(input, "%E", &b));
  ck_assert_float_eq(a, b);
  ck_assert(a >= FLT_MAX || isinf(a));
}
END_TEST

START_TEST(test_my_sscanf_E_min_float) {
  char *input = "1.1754944E-38";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%E", &a), sscanf(input, "%E", &b));
  ck_assert_float_eq(a, b);
  ck_assert(a <= FLT_MIN && a > 0);
}
END_TEST

START_TEST(test_my_sscanf_E_invalid_input) {
  char *input = "abc1.23E4";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%E", &a), sscanf(input, "%E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_mixed_input) {
  char *input = "1.2E3abc4.5E6";
  float a1 = 0, a2 = 0;
  float b1 = 0, b2 = 0;
  ck_assert_int_eq(my_sscanf(input, "%Eabc%E", &a1, &a2),
                   sscanf(input, "%Eabc%E", &b1, &b2));
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
}
END_TEST

START_TEST(test_my_sscanf_E_zero) {
  char *input = "0.0E0";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%E", &a), sscanf(input, "%E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_leading_zeros) {
  char *input = "0001.23E004";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%E", &a), sscanf(input, "%E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_leading_plus) {
  char *input = "+1.23E+01";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%E", &a), sscanf(input, "%E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_width) {
  char *input = "1.23456E7";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%5E", &a), sscanf(input, "%5E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_star) {
  char *input = "1.2E3 4.5E6";
  float a = 0;
  ck_assert_int_eq(my_sscanf(input, "%*E %E", &a),
                   sscanf(input, "%*E %E", &a));
}
END_TEST

START_TEST(test_my_sscanf_E_width_3) {
  char *input = "1.2345E6";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%3E", &a), sscanf(input, "%3E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_width_5_overflow) {
  char *input = "1.23456789E9";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%5E", &a), sscanf(input, "%5E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_star_simple) {
  char *input = "1.2E3 4.5E6";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%*E %E", &a),
                   sscanf(input, "%*E %E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_star_multiple) {
  char *input = "1.0E1 2.0E2 3.0E3 4.0E4";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%*E %*E %E %*E", &a),
                   sscanf(input, "%*E %*E %E %*E", &b));
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_E_star_no_output) {
  char *input = "1.2E3 4.5E6";
  ck_assert_int_eq(my_sscanf(input, "%*E %*E"), sscanf(input, "%*E %*E"));
}
END_TEST

START_TEST(test_my_sscanf_E_inf) {
  char *input = "inf";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%E", &a), sscanf(input, "%E", &b));
  ck_assert(isinf(a) && isinf(b));
}
END_TEST

START_TEST(test_my_sscanf_E_nan) {
  char *input = "nan";
  float a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%E", &a), sscanf(input, "%E", &b));
  ck_assert(isnan(a) && isnan(b));
}
END_TEST

Suite *my_sscanf_E_suite(void) {
  Suite *s = suite_create("my_sscanf_E");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_my_sscanf_E_empty);
  tcase_add_test(tc, test_my_sscanf_E_simple);
  tcase_add_test(tc, test_my_sscanf_E_negative);
  tcase_add_test(tc, test_my_sscanf_E_scientific);
  tcase_add_test(tc, test_my_sscanf_E_scientific_negative_exp);
  tcase_add_test(tc, test_my_sscanf_E_multiple);
  tcase_add_test(tc, test_my_sscanf_E_with_text);
  tcase_add_test(tc, test_my_sscanf_E_leading_whitespace);
  tcase_add_test(tc, test_my_sscanf_E_trailing_whitespace);
  tcase_add_test(tc, test_my_sscanf_E_max_float);
  tcase_add_test(tc, test_my_sscanf_E_min_float);
  tcase_add_test(tc, test_my_sscanf_E_invalid_input);
  tcase_add_test(tc, test_my_sscanf_E_mixed_input);
  tcase_add_test(tc, test_my_sscanf_E_zero);
  tcase_add_test(tc, test_my_sscanf_E_leading_zeros);
  tcase_add_test(tc, test_my_sscanf_E_leading_plus);
  tcase_add_test(tc, test_my_sscanf_E_width);
  tcase_add_test(tc, test_my_sscanf_E_star);
  tcase_add_test(tc, test_my_sscanf_E_width_3);
  tcase_add_test(tc, test_my_sscanf_E_width_5_overflow);
  tcase_add_test(tc, test_my_sscanf_E_star_simple);
  tcase_add_test(tc, test_my_sscanf_E_star_multiple);
  tcase_add_test(tc, test_my_sscanf_E_star_no_output);
  tcase_add_test(tc, test_my_sscanf_E_inf);
  tcase_add_test(tc, test_my_sscanf_E_nan);

  suite_add_tcase(s, tc);
  return s;
}