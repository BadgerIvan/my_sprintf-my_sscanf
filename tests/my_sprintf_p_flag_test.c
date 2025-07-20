
#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/my_string.h"

START_TEST(test_my_sprintf_single_pointer) {
  char original[100];
  char my[100];
  void *ptr = (void *)0x123;
  ck_assert_int_eq(my_sprintf(my, "%p", ptr), sprintf(original, "%p", ptr));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_null_pointer) {
  char original[100];
  char my[100];
  void *ptr = my_NULL;
  ck_assert_int_eq(my_sprintf(my, "%p", ptr), sprintf(original, "%p", ptr));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_pointer_with_width) {
  char original[100];
  char my[100];
  void *ptr = (void *)0x123;
  ck_assert_int_eq(my_sprintf(my, "%15p", ptr),
                   sprintf(original, "%15p", ptr));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_pointer_with_left_align) {
  char original[100];
  char my[100];
  void *ptr = (void *)0x123;
  ck_assert_int_eq(my_sprintf(my, "%-15p", ptr),
                   sprintf(original, "%-15p", ptr));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_multiple_pointers) {
  char original[100];
  char my[100];
  void *ptr1 = (void *)0x123;
  void *ptr2 = (void *)0x456;
  void *ptr3 = (void *)0x789;
  ck_assert_int_eq(my_sprintf(my, "%p %p %p", ptr1, ptr2, ptr3),
                   sprintf(original, "%p %p %p", ptr1, ptr2, ptr3));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_pointer_with_text) {
  char original[100];
  char my[100];
  void *ptr = (void *)0x123;
  ck_assert_int_eq(my_sprintf(my, "Address: %p, value: 42", ptr),
                   sprintf(original, "Address: %p, value: 42", ptr));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_pointer_max_value) {
  char original[100];
  char my[100];
  void *ptr = (void *)ULONG_MAX;
  ck_assert_int_eq(my_sprintf(my, "%p", ptr), sprintf(original, "%p", ptr));
  ck_assert_str_eq(my, original);
}
END_TEST

START_TEST(test_my_sprintf_hard_for_mac) {
  char original[100];
  char my[100];
  char *ptr = "NULL";
  ck_assert_int_eq(my_sprintf(my, "test -  %p - %p", my_NULL, ptr),
                   sprintf(original, "test -  %p - %p", my_NULL, ptr));
  ck_assert_pstr_eq(my, original);
}
END_TEST

Suite *my_sprintf_p_suite(void) {
  Suite *s = suite_create("my_sprintf_p");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_my_sprintf_single_pointer);
  tcase_add_test(tc, test_my_sprintf_null_pointer);
  tcase_add_test(tc, test_my_sprintf_pointer_with_width);
  tcase_add_test(tc, test_my_sprintf_pointer_with_left_align);
  tcase_add_test(tc, test_my_sprintf_multiple_pointers);
  tcase_add_test(tc, test_my_sprintf_pointer_with_text);
  tcase_add_test(tc, test_my_sprintf_pointer_max_value);
  tcase_add_test(tc, test_my_sprintf_hard_for_mac);

  suite_add_tcase(s, tc);
  return s;
}