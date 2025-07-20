#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/my_string.h"

START_TEST(test_my_sscanf_i_decimal) {
  char *input = "12345";
  int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_i_octal) {
  char *input = "01234";
  int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_i_hex_lower) {
  char *input = "0x1a3f";
  int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_i_hex_upper) {
  char *input = "0XABCD";
  int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_i_negative) {
  char *input = "-12345";
  int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_i_positive_sign) {
  char *input = "+12345";
  int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_i_zero) {
  char *input = "0";
  int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_i_octal_zero) {
  char *input = "00";
  int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_i_hex_zero) {
  char *input = "0x0";
  int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_i_max_int) {
  char input[20];
  sprintf(input, "%d", INT_MAX);
  int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_i_min_int) {
  char input[20];
  sprintf(input, "%d", INT_MIN);
  int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_i_multiple) {
  char *input = "10 012 0xA";
  int a1 = 0, a2 = 0, a3 = 0;
  int b1 = 0, b2 = 0, b3 = 0;
  ck_assert_int_eq(my_sscanf(input, "%i %i %i", &a1, &a2, &a3),
                   sscanf(input, "%i %i %i", &b1, &b2, &b3));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
}
END_TEST

START_TEST(test_my_sscanf_i_with_width) {
  char *input = "123456789";
  int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%5i", &a), sscanf(input, "%5i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_i_no_output) {
  char *input = "12345";
  ck_assert_int_eq(my_sscanf(input, "%*i"), sscanf(input, "%*i"));
}
END_TEST

START_TEST(test_my_sscanf_i_invalid) {
  char *input = "abc";
  int a = 0, b = 0;
  ck_assert_int_eq(my_sscanf(input, "%i", &a), sscanf(input, "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

Suite *my_sscanf_i_suite(void) {
  Suite *s = suite_create("my_sscanf_i");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_my_sscanf_i_decimal);
  tcase_add_test(tc_core, test_my_sscanf_i_octal);
  tcase_add_test(tc_core, test_my_sscanf_i_hex_lower);
  tcase_add_test(tc_core, test_my_sscanf_i_hex_upper);
  tcase_add_test(tc_core, test_my_sscanf_i_negative);
  tcase_add_test(tc_core, test_my_sscanf_i_positive_sign);
  tcase_add_test(tc_core, test_my_sscanf_i_zero);
  tcase_add_test(tc_core, test_my_sscanf_i_octal_zero);
  tcase_add_test(tc_core, test_my_sscanf_i_hex_zero);
  tcase_add_test(tc_core, test_my_sscanf_i_max_int);
  tcase_add_test(tc_core, test_my_sscanf_i_min_int);
  tcase_add_test(tc_core, test_my_sscanf_i_multiple);
  tcase_add_test(tc_core, test_my_sscanf_i_with_width);
  tcase_add_test(tc_core, test_my_sscanf_i_no_output);
  tcase_add_test(tc_core, test_my_sscanf_i_invalid);

  suite_add_tcase(s, tc_core);

  return s;
}