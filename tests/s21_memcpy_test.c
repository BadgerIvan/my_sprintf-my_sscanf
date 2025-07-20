#include <check.h>

#include "../src/s21_string.h"

START_TEST(test_s21_memcpy_number) {
  int num = 250, *ptr1 = &num;
  int dest;
  int *ptr2 = &dest;
  ck_assert_ptr_eq(s21_memcpy(ptr2, ptr1, 4), memcpy(ptr2, ptr1, 4));
}
END_TEST

START_TEST(test_s21_memcpy_number_list) {
  int a[] = {123, 21321, 0};
  int b[3] = {0};
  ck_assert_ptr_eq(s21_memcpy(b, a, 12), memcpy(b, a, 12));
}
END_TEST

START_TEST(test_s21_memcpy_string) {
  char a[] = "qwerty";
  char b[7] = {0};
  ck_assert_ptr_eq(s21_memcpy(b, a, 7), memcpy(b, a, 7));
}
END_TEST

START_TEST(test_s21_memcpy_empty) {
  char a[7] = {0};
  char b[7] = {0};
  ck_assert_ptr_eq(s21_memcpy(b, a, 7), memcpy(b, a, 7));
}
END_TEST

START_TEST(test_s21_memcpy_matrix) {
  char a[2][7] = {"qwerty", "asdfgh"};
  char b[2][7] = {0};
  ck_assert_ptr_eq(s21_memcpy(b, a, 14), memcpy(b, a, 14));
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_memcpy_empty);
  tcase_add_test(tc, test_s21_memcpy_number);
  tcase_add_test(tc, test_s21_memcpy_number_list);
  tcase_add_test(tc, test_s21_memcpy_matrix);
  tcase_add_test(tc, test_s21_memcpy_string);

  suite_add_tcase(s, tc);
  return s;
}