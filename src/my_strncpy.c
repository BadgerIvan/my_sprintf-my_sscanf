#include "my_string.h"

char *my_strncpy(char *dest, const char *src, my_size_t n) {
  my_size_t i = 0;
  for (; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  for (; i < n; i++) {
    dest[i] = '\0';
  }
  return dest;
}