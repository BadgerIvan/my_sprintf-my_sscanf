#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/utils.h"

START_TEST(test_parse_my_size_t_from_str_valid) {
  my_size_t result = 0;
  const char *test_str = "12345abc";
  char *remaining = parse_my_size_t_from_str(test_str, &result);

  ck_assert_int_eq(result, 12345);
  ck_assert_ptr_eq(remaining, test_str + 5);
}
END_TEST

START_TEST(test_parse_my_size_t_from_str_null_checks) {
  my_size_t result = 0;
  const char *test_str = "123";

  ck_assert_ptr_eq(parse_my_size_t_from_str(my_NULL, &result), my_NULL);
  ck_assert_ptr_eq(parse_my_size_t_from_str(test_str, my_NULL), my_NULL);
}
END_TEST

START_TEST(test_parse_my_size_t_from_str_empty) {
  my_size_t result = 0;
  const char *empty_str = "";
  char *remaining = parse_my_size_t_from_str(empty_str, &result);

  ck_assert_int_eq(result, 0);
  ck_assert_ptr_eq(remaining, empty_str);
}
END_TEST

START_TEST(test_parse_my_size_t_from_str_no_digits) {
  my_size_t result = 0;
  const char *no_digits_str = "abc123";
  char *remaining = parse_my_size_t_from_str(no_digits_str, &result);

  ck_assert_int_eq(result, 0);
  ck_assert_ptr_eq(remaining, no_digits_str);
}
END_TEST

Suite *numeric_parsing_suite(void) {
  Suite *s = suite_create("Numeric Parsing");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_parse_my_size_t_from_str_valid);
  tcase_add_test(tc, test_parse_my_size_t_from_str_null_checks);
  tcase_add_test(tc, test_parse_my_size_t_from_str_empty);
  tcase_add_test(tc, test_parse_my_size_t_from_str_no_digits);

  suite_add_tcase(s, tc);
  return s;
}