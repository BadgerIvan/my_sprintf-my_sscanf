#include <check.h>

#include "../src/s21_string.h"
#include "s21_sprintf_helpers.h"

START_TEST(test_init_flags) {
  flags_t flags;
  init_flags(&flags);

  ck_assert_int_eq(flags.base, 0);
  ck_assert_int_eq(flags.fill, 0);
  ck_assert_int_eq(flags.left_alignment, 0);
  ck_assert_int_eq(flags.sign, 0);
  ck_assert_int_eq(flags.space, 0);
}
END_TEST

START_TEST(test_init_fmt) {
  fmt_t fmt;
  init_fmt(&fmt);

  ck_assert_int_eq(fmt.precision, 0);
  ck_assert_int_eq(fmt.precision_set, 0);
  ck_assert_int_eq(fmt.length, 0);
  ck_assert_int_eq(fmt.type, 0);
  ck_assert_int_eq(fmt.width, 0);

  ck_assert_int_eq(fmt.flags.base, 0);
  ck_assert_int_eq(fmt.flags.fill, 0);
  ck_assert_int_eq(fmt.flags.left_alignment, 0);
  ck_assert_int_eq(fmt.flags.sign, 0);
  ck_assert_int_eq(fmt.flags.space, 0);
}
END_TEST

Suite *init_suite(void) {
  Suite *s = suite_create("Initialization");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_init_flags);
  tcase_add_test(tc, test_init_fmt);

  suite_add_tcase(s, tc);
  return s;
}