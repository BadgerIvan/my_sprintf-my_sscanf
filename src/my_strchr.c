#include "my_string.h"

char *my_strchr(const char *str, int c) {
  char *res = my_NULL;
  if (str != my_NULL) {
    my_size_t i = 0;

    while ((str[i] != (char)c) && (str[i] != '\0')) {
      i++;
    }
    if (str[i] == (char)c) {
      res = (char *)&str[i];
    }
  }

  return res;
}