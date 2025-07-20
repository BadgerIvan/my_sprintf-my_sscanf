#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/utils.h"

START_TEST(test_my_size_t_to_string_base10_zero) {
  char str[100];
  char expected[] = "0";
  my_size_t_to_string_with_base(str, 0, 10);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_my_size_t_to_string_base10_small) {
  char str[100];
  char expected[] = "123";
  my_size_t_to_string_with_base(str, 123, 10);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_my_size_t_to_string_base10_large) {
  char str[100];
  char expected[] = "18446744073709551615";
  my_size_t_to_string_with_base(str, ULLONG_MAX, 10);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_my_size_t_to_string_base2_small) {
  char str[100];
  char expected[] = "1101";
  my_size_t_to_string_with_base(str, 13, 2);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_my_size_t_to_string_base2_large) {
  char str[100];
  char expected[] =
      "1111111111111111111111111111111111111111111111111111111111111111";
  my_size_t_to_string_with_base(str, ULLONG_MAX, 2);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_my_size_t_to_string_base8_small) {
  char str[100];
  char expected[] = "755";
  my_size_t_to_string_with_base(str, 493, 8);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_my_size_t_to_string_base8_large) {
  char str[100];
  char expected[] = "1777777777777777777777";
  my_size_t_to_string_with_base(str, ULLONG_MAX, 8);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_my_size_t_to_string_base16_small) {
  char str[100];
  char expected[] = "1af";
  my_size_t_to_string_with_base(str, 431, 16);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_my_size_t_to_string_base16_large) {
  char str[100];
  char expected[] = "ffffffffffffffff";
  my_size_t_to_string_with_base(str, ULLONG_MAX, 16);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_my_size_t_to_string_custom_base) {
  char str[100];
  char expected[] = "400";
  my_size_t_to_string_with_base(str, 100, 5);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_my_size_t_to_string_max_base) {
  char str[100];
  char expected[] = "10";
  my_size_t_to_string_with_base(str, 36, 36);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_my_size_t_to_string_power_of_two) {
  char str[100];
  char expected[] = "1000000000000000000000000";
  my_size_t_to_string_with_base(str, 16777216, 2);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_my_size_t_to_string_power_of_base) {
  char str[100];
  char expected[] = "100";
  my_size_t_to_string_with_base(str, 256, 16);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_my_size_t_to_string_single_digit) {
  char str[100];
  char expected[] = "5";
  my_size_t_to_string_with_base(str, 5, 10);
  ck_assert_str_eq(str, expected);
}
END_TEST

Suite *my_size_t_to_string_suite(void) {
  Suite *s = suite_create("my_size_t_to_string_with_base");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_my_size_t_to_string_base10_zero);
  tcase_add_test(tc, test_my_size_t_to_string_base10_small);
  tcase_add_test(tc, test_my_size_t_to_string_base10_large);
  tcase_add_test(tc, test_my_size_t_to_string_base2_small);
  tcase_add_test(tc, test_my_size_t_to_string_base2_large);
  tcase_add_test(tc, test_my_size_t_to_string_base8_small);
  tcase_add_test(tc, test_my_size_t_to_string_base8_large);
  tcase_add_test(tc, test_my_size_t_to_string_base16_small);
  tcase_add_test(tc, test_my_size_t_to_string_base16_large);
  tcase_add_test(tc, test_my_size_t_to_string_custom_base);
  tcase_add_test(tc, test_my_size_t_to_string_max_base);
  tcase_add_test(tc, test_my_size_t_to_string_power_of_two);
  tcase_add_test(tc, test_my_size_t_to_string_power_of_base);
  tcase_add_test(tc, test_my_size_t_to_string_single_digit);

  suite_add_tcase(s, tc);
  return s;
}