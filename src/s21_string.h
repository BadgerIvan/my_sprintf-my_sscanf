#ifndef S21_STRING_H_
#define S21_STRING_H_

#define S21_NULL ((void *)0)

typedef long unsigned s21_size_t;

void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strstr(const char *haystack, const char *needle);

int s21_sscanf(const char *str, const char *format, ...);
int s21_sprintf(char *str, const char *format, ...);

#endif