#include <check.h>
#include <stdarg.h>

#include "../src/s21_string.h"
#include "s21_sprintf_helpers.h"

START_TEST(test_parse_all_in_flag_full_format) {
  fmt_t fmt;
  init_fmt(&fmt);
  const char *full_fmt = "-+#05.10hd";

  va_list args;
  char *remaining = parse_all_in_flag(full_fmt, args, &fmt);

  ck_assert_int_eq(fmt.flags.left_alignment, 1);
  ck_assert_int_eq(fmt.flags.sign, 1);
  ck_assert_int_eq(fmt.flags.space, 0);
  ck_assert_int_eq(fmt.flags.base, 1);
  ck_assert_int_eq(fmt.flags.fill, 0);
  ck_assert_int_eq(fmt.width, 5);
  ck_assert_int_eq(fmt.precision, 10);
  ck_assert_int_eq(fmt.precision_set, 1);
  ck_assert_int_eq(fmt.length, 'h');
  ck_assert_int_eq(fmt.type, 'd');
  ck_assert_ptr_eq(remaining, full_fmt + s21_strlen(full_fmt));
}
END_TEST

START_TEST(test_parse_all_in_flag_minimal_format) {
  fmt_t fmt_min;
  init_fmt(&fmt_min);
  const char *min_fmt = "s";

  va_list args;
  char *remaining = parse_all_in_flag(min_fmt, args, &fmt_min);

  ck_assert_int_eq(fmt_min.type, 's');
  ck_assert_int_eq(fmt_min.width, 0);
  ck_assert_int_eq(fmt_min.precision, 0);
  ck_assert_int_eq(fmt_min.precision_set, 0);
  ck_assert_ptr_eq(remaining, min_fmt + 1);
}
END_TEST

START_TEST(test_parse_all_in_flag_no_precision) {
  fmt_t fmt_no_prec;
  init_fmt(&fmt_no_prec);
  const char *no_prec_fmt = "08lx";

  va_list args;
  char *remaining = parse_all_in_flag(no_prec_fmt, args, &fmt_no_prec);

  ck_assert_int_eq(fmt_no_prec.flags.fill, 1);
  ck_assert_int_eq(fmt_no_prec.width, 8);
  ck_assert_int_eq(fmt_no_prec.precision, 0);
  ck_assert_int_eq(fmt_no_prec.precision_set, 0);
  ck_assert_int_eq(fmt_no_prec.length, 'l');
  ck_assert_int_eq(fmt_no_prec.type, 'x');
  ck_assert_ptr_eq(remaining, no_prec_fmt + s21_strlen(no_prec_fmt));
}
END_TEST

START_TEST(test_parse_all_in_flag_invalid_format) {
  fmt_t fmt_invalid;
  init_fmt(&fmt_invalid);
  const char *invalid_fmt = "abc";
  va_list args;

  char *remaining = parse_all_in_flag(invalid_fmt, args, &fmt_invalid);

  ck_assert_int_eq(fmt_invalid.type, 'a');
  ck_assert_ptr_eq(remaining, invalid_fmt + 1);
}
END_TEST

Suite *format_parsing_suite(void) {
  Suite *s = suite_create("Format Parsing");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_parse_all_in_flag_full_format);
  tcase_add_test(tc, test_parse_all_in_flag_minimal_format);
  tcase_add_test(tc, test_parse_all_in_flag_no_precision);
  tcase_add_test(tc, test_parse_all_in_flag_invalid_format);

  suite_add_tcase(s, tc);
  return s;
}