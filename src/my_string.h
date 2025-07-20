#ifndef my_STRING_H_
#define my_STRING_H_

#define my_NULL ((void *)0)

typedef long unsigned my_size_t;

void *my_memcpy(void *dest, const void *src, my_size_t n);
void *my_memset(void *str, int c, my_size_t n);
char *my_strchr(const char *str, int c);
char *my_strncpy(char *dest, const char *src, my_size_t n);
my_size_t my_strlen(const char *str);
char *my_strstr(const char *haystack, const char *needle);

int my_sscanf(const char *str, const char *format, ...);
int my_sprintf(char *str, const char *format, ...);

#endif