#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = S21_NULL;
  if (needle == S21_NULL) {
    res = (char *)haystack;
  } else if (haystack != S21_NULL) {
    s21_size_t i = 0;
    s21_size_t count_matches = 0;
    s21_size_t len_str1 = s21_strlen(haystack);
    s21_size_t len_str2 = s21_strlen(needle);
    while ((count_matches != len_str2) && (i != len_str1)) {
      if (haystack[i] == needle[count_matches]) {
        count_matches++;
      } else {
        count_matches = 0;
      }
      i++;
    }
    if (count_matches == len_str2) {
      res = (char *)&haystack[i - len_str2];
    }
  }

  return res;
}