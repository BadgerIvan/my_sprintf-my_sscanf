#include "my_string.h"

void *my_memcpy(void *dest, const void *src, my_size_t n) {
  char *d = dest;
  const char *s = src;

  for (my_size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }

  return dest;
}