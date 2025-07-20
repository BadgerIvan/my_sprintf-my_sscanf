#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/my_string.h"

START_TEST(test_my_strchr_existing_symbol) {
  char *arg = "string";
  ck_assert_ptr_eq(my_strchr(arg, 'r'), strchr(arg, 'r'));
  ck_assert_int_eq(*my_strchr(arg, 'r'), 'r');
}
END_TEST

START_TEST(test_my_strchr_not_existing_symbol) {
  char *arg = "string";
  ck_assert_ptr_eq(my_strchr(arg, 'm'), strchr(arg, 'm'));
}
END_TEST

START_TEST(test_my_strchr_first_symbol) {
  char *arg = "string rrrrrrrrr";
  ck_assert_ptr_eq(my_strchr(arg, 'r'), strchr(arg, 'r'));
  ck_assert_int_eq(*my_strchr(arg, 'r'), 'r');
}
END_TEST

START_TEST(test_my_strchr_zero_byte) {
  char *arg = "string";
  ck_assert_ptr_eq(my_strchr(arg, '\0'), strchr(arg, '\0'));
  ck_assert_int_eq(*my_strchr(arg, '\0'), '\0');
}
END_TEST

START_TEST(test_my_strchr_empty_string) {
  char *arg = "";
  ck_assert_ptr_eq(my_strchr(arg, 'o'), strchr(arg, 'o'));
}
END_TEST

START_TEST(test_my_strchr_zero_byte_in_empty_string) {
  char *arg = "";
  ck_assert_ptr_eq(my_strchr(arg, '\0'), strchr(arg, '\0'));
  ck_assert_int_eq(*my_strchr(arg, '\0'), '\0');
}
END_TEST

START_TEST(test_my_strchr_character_code) {
  char *arg = "warning";
  ck_assert_ptr_eq(my_strchr(arg, 119), strchr(arg, 119));
  ck_assert_int_eq(*my_strchr(arg, 119), 119);
}
END_TEST

Suite *my_strchr_suite(void) {
  Suite *s = suite_create("my_strchr");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_my_strchr_character_code);
  tcase_add_test(tc, test_my_strchr_empty_string);
  tcase_add_test(tc, test_my_strchr_existing_symbol);
  tcase_add_test(tc, test_my_strchr_first_symbol);
  tcase_add_test(tc, test_my_strchr_not_existing_symbol);
  tcase_add_test(tc, test_my_strchr_zero_byte);
  tcase_add_test(tc, test_my_strchr_zero_byte_in_empty_string);

  suite_add_tcase(s, tc);
  return s;
}