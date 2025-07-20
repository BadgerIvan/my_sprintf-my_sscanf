#include "my_string.h"

void *my_memset(void *str, int c, my_size_t n) {
  unsigned char *char_str = str;
  for (my_size_t i = 0; i < n; i++) {
    char_str[i] = (unsigned char)c;
  }
  return str;
}