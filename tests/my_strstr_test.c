#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/my_string.h"

START_TEST(test_my_strstr_normal_1) {
  char *arg = "string";
  ck_assert_ptr_eq(my_strstr(arg, "ring"), strstr(arg, "ring"));
}
END_TEST

START_TEST(test_my_strstr_normal_2) {
  char *arg = "string";
  ck_assert_ptr_eq(my_strstr(arg, "ri"), strstr(arg, "ri"));
}
END_TEST

START_TEST(test_my_strstr_from_first_symbol) {
  char *arg = "string";
  ck_assert_ptr_eq(my_strstr(arg, "st"), strstr(arg, "st"));
}
END_TEST

START_TEST(test_my_strstr_one_symbol) {
  char *arg = "string";
  ck_assert_ptr_eq(my_strstr(arg, "t"), strstr(arg, "t"));
}
END_TEST

START_TEST(test_my_strstr_last_symbol) {
  char *arg = "string";
  ck_assert_ptr_eq(my_strstr(arg, "g"), strstr(arg, "g"));
}
END_TEST

START_TEST(test_my_strstr_two_occurrences) {
  char *arg = "string string";
  ck_assert_ptr_eq(my_strstr(arg, "ing"), strstr(arg, "ing"));
}
END_TEST

START_TEST(test_my_strstr_three_occurrences) {
  char *arg = "string string string";
  ck_assert_ptr_eq(my_strstr(arg, "ing"), strstr(arg, "ing"));
}
END_TEST

START_TEST(test_my_strstr_zero_byte) {
  char *arg = "string string string";
  ck_assert_ptr_eq(my_strstr(arg, "\0"), strstr(arg, "\0"));
}
END_TEST

START_TEST(test_my_strstr_empty_second) {
  char *arg = "string string string";
  ck_assert_ptr_eq(my_strstr(arg, ""), strstr(arg, ""));
}
END_TEST

START_TEST(test_my_strstr_empty_first) {
  char *arg = "";
  ck_assert_ptr_eq(my_strstr(arg, "qw"), strstr(arg, "qw"));
}
END_TEST

START_TEST(test_my_strstr_empty_all) {
  char *arg = "";
  ck_assert_ptr_eq(my_strstr(arg, ""), strstr(arg, ""));
}
END_TEST

START_TEST(test_my_strstr_string_not_found) {
  char *arg = "string";
  ck_assert_ptr_eq(my_strstr(arg, "cheburek"), strstr(arg, "cheburek"));
}
END_TEST

Suite *my_strstr_suite(void) {
  Suite *s = suite_create("my_strstr");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_my_strstr_normal_1);
  tcase_add_test(tc, test_my_strstr_normal_2);
  tcase_add_test(tc, test_my_strstr_from_first_symbol);
  tcase_add_test(tc, test_my_strstr_one_symbol);
  tcase_add_test(tc, test_my_strstr_last_symbol);
  tcase_add_test(tc, test_my_strstr_two_occurrences);
  tcase_add_test(tc, test_my_strstr_three_occurrences);
  tcase_add_test(tc, test_my_strstr_zero_byte);
  tcase_add_test(tc, test_my_strstr_empty_second);
  tcase_add_test(tc, test_my_strstr_empty_first);
  tcase_add_test(tc, test_my_strstr_empty_all);
  tcase_add_test(tc, test_my_strstr_string_not_found);

  suite_add_tcase(s, tc);
  return s;
}