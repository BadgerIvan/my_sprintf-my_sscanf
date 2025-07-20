#include "my_string.h"

char *my_strstr(const char *haystack, const char *needle) {
  char *res = my_NULL;
  if (needle == my_NULL) {
    res = (char *)haystack;
  } else if (haystack != my_NULL) {
    my_size_t i = 0;
    my_size_t count_matches = 0;
    my_size_t len_str1 = my_strlen(haystack);
    my_size_t len_str2 = my_strlen(needle);
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