#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/my_string.h"

START_TEST(test_my_sscanf_s_empty) {
  char *input = "";
  char a[10] = {0}, b[10] = {0};
  ck_assert_int_eq(my_sscanf(input, "%s", a), sscanf(input, "%s", b));
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_s_basic) {
  char *input = "Hello";
  char a[10] = {0}, b[10] = {0};
  ck_assert_int_eq(my_sscanf(input, "%s", a), sscanf(input, "%s", b));
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_s_with_spaces) {
  char *input = "Hello world";
  char a[10] = {0}, b[10] = {0};
  ck_assert_int_eq(my_sscanf(input, "%s", a), sscanf(input, "%s", b));
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_s_width) {
  char *input = "Hello";
  char a[10] = {0}, b[10] = {0};
  ck_assert_int_eq(my_sscanf(input, "%3s", a), sscanf(input, "%3s", b));
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_s_no_assign) {
  char *input = "Hello";
  ck_assert_int_eq(my_sscanf(input, "%*s"), sscanf(input, "%*s"));
}
END_TEST

START_TEST(test_my_sscanf_s_multiple) {
  char *input = "Hello world";
  char a1[10] = {0}, a2[10] = {0};
  char b1[10] = {0}, b2[10] = {0};
  ck_assert_int_eq(my_sscanf(input, "%s %s", a1, a2),
                   sscanf(input, "%s %s", b1, b2));
  ck_assert_str_eq(a1, b1);
  ck_assert_str_eq(a2, b2);
}
END_TEST

START_TEST(test_my_sscanf_s_special_chars) {
  char *input = "H3ll0_w0rld!";
  char a[20] = {0}, b[20] = {0};
  ck_assert_int_eq(my_sscanf(input, "%s", a), sscanf(input, "%s", b));
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_s_long_string) {
  char *input = "This_is_a_very_long_string_that_should_be_truncated";
  char a[60] = {0}, b[60] = {0};
  ck_assert_int_eq(my_sscanf(input, "%s", a), sscanf(input, "%s", b));
  ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(test_my_sscanf_s_only_spaces) {
  char *input = "                    ";
  char a[20] = {0}, b[20] = {0};
  ck_assert_int_eq(my_sscanf(input, "%s", a), sscanf(input, "%s", b));
  ck_assert_str_eq(a, b);
}

Suite *my_sscanf_s_suite(void) {
  Suite *s = suite_create("my_sscanf_s");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_my_sscanf_s_empty);
  tcase_add_test(tc, test_my_sscanf_s_basic);
  tcase_add_test(tc, test_my_sscanf_s_with_spaces);
  tcase_add_test(tc, test_my_sscanf_s_width);
  tcase_add_test(tc, test_my_sscanf_s_no_assign);
  tcase_add_test(tc, test_my_sscanf_s_multiple);
  tcase_add_test(tc, test_my_sscanf_s_special_chars);
  tcase_add_test(tc, test_my_sscanf_s_long_string);
  tcase_add_test(tc, test_my_sscanf_s_only_spaces);

  suite_add_tcase(s, tc);
  return s;
}