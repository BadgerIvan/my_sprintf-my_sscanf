#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/my_string.h"

START_TEST(test_my_sscanf_o_empty) {
  char *input = "";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%o", &a), sscanf(input, "%o", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_o_simple) {
  char *input = "123";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%o", &a), sscanf(input, "%o", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_o_with_prefix) {
  char *input = "0123";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%o", &a), sscanf(input, "%o", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_o_multiple) {
  char *input = "123 456 777";
  unsigned int a1 = 0, a2 = 0, a3 = 0;
  unsigned int b1 = 0, b2 = 0, b3 = 0;
  ck_assert_int_eq(my_sscanf(input, "%o%o%o", &a1, &a2, &a3),
                   sscanf(input, "%o%o%o", &b1, &b2, &b3));
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
}
END_TEST

START_TEST(test_my_sscanf_o_with_text) {
  char *input = "Oct: 123, Next: 456";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  ck_assert_int_eq(my_sscanf(input, "Oct: %o, Next: %o", &a1, &a2),
                   sscanf(input, "Oct: %o, Next: %o", &b1, &b2));
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
}
END_TEST

START_TEST(test_my_sscanf_o_leading_whitespace) {
  char *input = "   \t\n\r\v\f 123";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%o", &a), sscanf(input, "%o", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_o_trailing_whitespace) {
  char *input = "123   \t\n\r\v\f";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%o", &a), sscanf(input, "%o", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_o_max_uint) {
  char *input = "37777777777";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%o", &a), sscanf(input, "%o", &b));
  ck_assert_uint_eq(a, b);
  ck_assert_uint_eq(a, UINT_MAX);
}
END_TEST

START_TEST(test_my_sscanf_o_invalid_input) {
  char *input = "xyz123";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%o", &a), sscanf(input, "%o", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_o_mixed_input) {
  char *input = "123xyz456";
  unsigned int a1 = 0, a2 = 0;
  unsigned int b1 = 0, b2 = 0;
  ck_assert_int_eq(my_sscanf(input, "%oxyz%o", &a1, &a2),
                   sscanf(input, "%oxyz%o", &b1, &b2));
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
}
END_TEST

START_TEST(test_my_sscanf_o_zero) {
  char *input = "0";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%o", &a), sscanf(input, "%o", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_o_leading_zeros) {
  char *input = "000123";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%o", &a), sscanf(input, "%o", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_o_width) {
  char *input = "123456";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%3o", &a), sscanf(input, "%3o", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_o_star) {
  char *input = "123 456";
  unsigned int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%*o %o", &a),
                   sscanf(input, "%*o %o", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_ho_simple) {
  char *input = "123";
  unsigned short a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%ho", &a), sscanf(input, "%ho", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_lo_simple) {
  char *input = "12345670";
  unsigned long a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%lo", &a), sscanf(input, "%lo", &b));
  ck_assert_uint_eq(a, b);
}
END_TEST

Suite *my_sscanf_o_suite(void) {
  Suite *s = suite_create("my_sscanf_o");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_my_sscanf_o_empty);
  tcase_add_test(tc, test_my_sscanf_o_simple);
  tcase_add_test(tc, test_my_sscanf_o_with_prefix);
  tcase_add_test(tc, test_my_sscanf_o_multiple);
  tcase_add_test(tc, test_my_sscanf_o_with_text);
  tcase_add_test(tc, test_my_sscanf_o_leading_whitespace);
  tcase_add_test(tc, test_my_sscanf_o_trailing_whitespace);
  tcase_add_test(tc, test_my_sscanf_o_max_uint);
  tcase_add_test(tc, test_my_sscanf_o_invalid_input);
  tcase_add_test(tc, test_my_sscanf_o_mixed_input);
  tcase_add_test(tc, test_my_sscanf_o_zero);
  tcase_add_test(tc, test_my_sscanf_o_leading_zeros);
  tcase_add_test(tc, test_my_sscanf_o_width);
  tcase_add_test(tc, test_my_sscanf_o_star);
  tcase_add_test(tc, test_my_sscanf_ho_simple);
  tcase_add_test(tc, test_my_sscanf_lo_simple);

  suite_add_tcase(s, tc);
  return s;
}