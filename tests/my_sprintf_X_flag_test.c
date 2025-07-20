#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/my_string.h"

START_TEST(test_my_sprintf_single_hex_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%X", 0x123u),
                   sprintf(original, "%X", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_short_positive_hex_upper) {
  char original[100];
  char my[100];
  unsigned short int num = 0x1234u;
  ck_assert_int_eq(my_sprintf(my, "%hX", num), sprintf(original, "%hX", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_short_max_hex_upper) {
  char original[100];
  char my[100];
  unsigned short int num = USHRT_MAX;
  ck_assert_int_eq(my_sprintf(my, "%hX", num), sprintf(original, "%hX", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_long_positive_hex_upper) {
  char original[100];
  char my[100];
  unsigned long int num = 0x12345678UL;
  ck_assert_int_eq(my_sprintf(my, "%lX", num), sprintf(original, "%lX", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_long_max_hex_upper) {
  char original[100];
  char my[100];
  unsigned long int num = ULONG_MAX;
  ck_assert_int_eq(my_sprintf(my, "%lX", num), sprintf(original, "%lX", num));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_many_hex_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(
      my_sprintf(my, "%XHello,world@%X %X55656%X", 0x1u, 0x2u, 0x3u, 0x4u),
      sprintf(original, "%XHello,world@%X %X55656%X", 0x1u, 0x2u, 0x3u, 0x4u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_single_hex_upper_with_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%10X", 0x123u),
                   sprintf(original, "%10X", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_single_hex_upper_with_width_and_left_align) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%-10X", 0x123u),
                   sprintf(original, "%-10X", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_single_hex_upper_with_width_and_fill) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%010X", 0x123u),
                   sprintf(original, "%010X", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_hex_upper_with_width) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%10X", 0x123u),
                   sprintf(original, "%10X", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_hex_upper_with_zero_fill) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%010X", 0x123u),
                   sprintf(original, "%010X", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_hex_upper_with_all_flags) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%-15X", 0x123u),
                   sprintf(original, "%-15X", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_zero_value_with_flags_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%05X", 0u), sprintf(original, "%05X", 0u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_precision_hex_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%.5X", 0x42u),
                   sprintf(original, "%.5X", 0x42u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_precision_hex_upper_zero) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%.3X", 0u), sprintf(original, "%.3X", 0u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_precision_width_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%10.5X", 0x123u),
                   sprintf(original, "%10.5X", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_precision_minus_flag_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%-10.5X", 0x123u),
                   sprintf(original, "%-10.5X", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_precision_zero_and_num_zero_upper) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%.0X", 0u), sprintf(original, "%.0X", 0u));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_hex_upper_alternate_form) {
  char original[100];
  char my[100];
  ck_assert_int_eq(my_sprintf(my, "%#X", 0x123u),
                   sprintf(original, "%#X", 0x123u));
  ck_assert_str_eq(my, original);
}
END_TEST

Suite *my_sprintf_X_suite(void) {
  Suite *s = suite_create("my_sprintf_X");
  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, test_my_sprintf_single_hex_upper);
  tcase_add_test(tc, test_my_sprintf_short_positive_hex_upper);
  tcase_add_test(tc, test_my_sprintf_short_max_hex_upper);
  tcase_add_test(tc, test_my_sprintf_long_positive_hex_upper);
  tcase_add_test(tc, test_my_sprintf_long_max_hex_upper);
  tcase_add_test(tc, test_my_sprintf_many_hex_upper);
  tcase_add_test(tc, test_my_sprintf_single_hex_upper_with_width);
  tcase_add_test(tc,
                 test_my_sprintf_single_hex_upper_with_width_and_left_align);
  tcase_add_test(tc, test_my_sprintf_single_hex_upper_with_width_and_fill);
  tcase_add_test(tc, test_my_sprintf_hex_upper_with_width);
  tcase_add_test(tc, test_my_sprintf_hex_upper_with_zero_fill);
  tcase_add_test(tc, test_my_sprintf_hex_upper_with_all_flags);
  tcase_add_test(tc, test_my_sprintf_zero_value_with_flags_upper);
  tcase_add_test(tc, test_my_sprintf_precision_hex_upper);
  tcase_add_test(tc, test_my_sprintf_precision_hex_upper_zero);
  tcase_add_test(tc, test_my_sprintf_precision_width_upper);
  tcase_add_test(tc, test_my_sprintf_precision_minus_flag_upper);
  tcase_add_test(tc, test_my_sprintf_precision_zero_and_num_zero_upper);
  tcase_add_test(tc, test_my_sprintf_hex_upper_alternate_form);
  suite_add_tcase(s, tc);
  return s;
}