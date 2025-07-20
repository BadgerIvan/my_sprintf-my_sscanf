#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>

#include "s21_string.h"
#include "utils.h"

#define NUMBER_ASCII 128

#define ASSIGNMENT_h_l(value, length, type_orig, type_h, type_l) \
  if (length == 'h') {                                           \
    type_h *out = va_arg(args, type_h *);                        \
    *out = (type_h)value;                                        \
  } else if (length == 'l') {                                    \
    type_l *out = va_arg(args, type_l *);                        \
    *out = value;                                                \
  } else {                                                       \
    type_orig *out = va_arg(args, type_orig *);                  \
    *out = (type_orig)value;                                     \
  }

typedef struct {
  s21_size_t width;
  s21_size_t save;
  char length;
  char type;
} info_t;

typedef int (*process_func_t)(const char **, info_t *, va_list, const char *);

static void init_process_array(process_func_t *array_of_funcs) {
  for (int i = 0; i < NUMBER_ASCII; i++)
    array_of_funcs[i] = (process_func_t)S21_NULL;
}

static void register_process_func(process_func_t *funcs, char flag,
                                  process_func_t func) {
  funcs[(int)flag] = func;
}

static void init_info(info_t *info) {
  info->width = 0;
  info->save = 1;
  info->length = 0;
  info->type = 0;
}

static int skip_whitespace(const char **str) {
  while (isspace(**str)) {
    (*str)++;
  }
  return **str != '\0';
}

static int get_sign(const char **str, s21_size_t *width) {
  int sign = 1;
  if (**str == '-') {
    sign = -1;
    (*str)++;
    (*width)--;
  } else if (**str == '+') {
    (*str)++;
    (*width)--;
  }
  return sign;
}

static int get_digit(char hex_char) {
  if (hex_char >= '0' && hex_char <= '9')
    return hex_char - '0';
  else if (tolower(hex_char) >= 'a' && tolower(hex_char) <= 'z')
    return tolower(hex_char) - 'a' + 10;
  return 0;
}

static int parse_unsigned_long_with_base_and_width(const char **str,
                                                   s21_size_t width,
                                                   unsigned long *value,
                                                   int base) {
  int flag = 0;
  *value = 0;
  width = width ? width : (s21_size_t)-1;
  int zero_flag = 0;
  if (base == 16 && **str == '0' &&
      (*(*str + 1) == 'x' || *(*str + 1) == 'X')) {
    *str += 2;
    width -= 2;
  } else if (base == 8 && **str == '0') {
    *str += 1;
    width -= 1;
    zero_flag = 1;
  }
  while (width > 0 && isxdigit(**str)) {
    *value = *value * base + get_digit(**str);
    (*str)++;
    flag = 1;
    width--;
  }
  if (!flag && zero_flag) flag = 1;
  return flag;
}

static int parse_unsigned_long_with_width(const char **str, s21_size_t width,
                                          unsigned long *value) {
  int flag = 0;
  *value = 0;
  width = width ? width : (s21_size_t)-1;
  while (isdigit(**str) && width > 0) {
    *value = *value * 10 + get_digit(**str);
    (*str)++;
    flag = 1;
    width--;
  }
  return flag;
}

static int process_unsigned_int(const char **str, info_t *info_flag,
                                va_list args,
                                __attribute__((unused))
                                const char *original_str) {
  if (!skip_whitespace(str)) return 0;
  unsigned long value = 0;
  int flag = parse_unsigned_long_with_width(str, info_flag->width, &value);
  if (info_flag->save && flag) {
    ASSIGNMENT_h_l(value, info_flag->length, unsigned int, unsigned short,
                   unsigned long);
  }
  return flag;
}

static int process_octal(const char **str, info_t *info_flag, va_list args,
                         __attribute__((unused)) const char *original_str) {
  if (!skip_whitespace(str)) return 0;
  s21_size_t value = 0;
  int flag = 0;
  flag =
      parse_unsigned_long_with_base_and_width(str, info_flag->width, &value, 8);
  if (info_flag->save && flag) {
    ASSIGNMENT_h_l(value, info_flag->length, unsigned int, unsigned short,
                   unsigned long);
  }
  return flag;
}

static int process_hex(const char **str, info_t *info_flag, va_list args,
                       __attribute__((unused)) const char *original_str) {
  if (!skip_whitespace(str)) return 0;
  s21_size_t value = 0;
  int flag = 0;
  flag = parse_unsigned_long_with_base_and_width(str, info_flag->width, &value,
                                                 16);
  if (info_flag->save && flag) {
    ASSIGNMENT_h_l(value, info_flag->length, unsigned int, unsigned short,
                   unsigned long);
  }
  return flag;
}

static int parse_long_with_width(const char **str, s21_size_t width,
                                 long *value) {
  int flag = 0;
  *value = 0;
  width = width ? width : (s21_size_t)-1;
  int sign = get_sign(str, &width);
  while (isdigit(**str) && width > 0) {
    *value = *value * 10 + get_digit(**str);
    (*str)++;
    flag = 1;
    width--;
  }
  *value *= sign;
  return flag;
}

static int process_int(const char **str, info_t *info_flag, va_list args,
                       __attribute__((unused)) const char *original_str) {
  if (!skip_whitespace(str)) return 0;
  long value = 0;
  int flag = parse_long_with_width(str, info_flag->width, &value);
  if (info_flag->save && flag) {
    ASSIGNMENT_h_l(value, info_flag->length, int, short, long);
  }
  return flag;
}

static int process_int_auto(const char **str, info_t *info_flag, va_list args,
                            __attribute__((unused)) const char *original_str) {
  if (!skip_whitespace(str)) return 0;
  int flag = 0;
  if (**str == '0' && (*(*str + 1) == 'x' || *(*str + 1) == 'X')) {
    flag = process_hex(str, info_flag, args, original_str);
  } else if (**str == '0') {
    flag = process_octal(str, info_flag, args, original_str);
  } else
    flag = process_int(str, info_flag, args, original_str);
  return flag;
}

static int process_char(const char **str, info_t *info_flag, va_list args,
                        __attribute__((unused)) const char *original_str) {
  char *ch = 0;
  if (info_flag->save) ch = (char *)va_arg(args, int *);
  s21_size_t width = info_flag->width ? info_flag->width : 1;
  s21_size_t i;
  for (i = 0; i < width && **str != '\0'; i++) {
    if (info_flag->save) ch[i] = **str;
    (*str)++;
  }
  return i > 0;
}

static int process_string(const char **str, info_t *info_flag, va_list args,
                          __attribute__((unused)) const char *original_str) {
  if (!skip_whitespace(str)) return 0;
  char *string = 0;
  if (info_flag->save) string = (char *)va_arg(args, int *);
  s21_size_t width = info_flag->width ? info_flag->width : (s21_size_t)-1;
  s21_size_t i;
  for (i = 0; i < width && **str != '\0' && !isspace((unsigned char)**str);
       i++) {
    if (info_flag->save) string[i] = **str;
    (*str)++;
  }
  if (info_flag->save && i > 0) string[i] = '\0';
  return i > 0;
}

static int parse_nan_inf(const char **str, s21_size_t width, int sign,
                         long double *value) {
  int flag = 0;
  if (width >= 3) {
    if (tolower((int)**str) == 'n' && tolower((int)*(*str + 1)) == 'a' &&
        tolower((int)*(*str + 2)) == 'n') {
      *value = sign * NAN;
      flag = 1;
    } else if (tolower((int)**str) == 'i' && tolower((int)*(*str + 1)) == 'n' &&
               tolower((int)*(*str + 2)) == 'f') {
      *value = sign * INFINITY;
      flag = 1;
    }
    if (flag) {
      *str += 3;
    }
  }
  return flag;
}

static int parse_long_double_from_string(const char **str, s21_size_t width,
                                         long double *value) {
  int flag = 0;
  *value = 0;
  width = width ? width : (s21_size_t)-1;
  int sign = get_sign(str, &width);
  int flag_nan_or_inf = parse_nan_inf(str, width, sign, value);
  if (flag_nan_or_inf) flag = 1;
  while (isdigit(**str) && width > 0 && !flag_nan_or_inf) {
    *value = *value * 10 + get_digit(**str);
    (*str)++;
    flag = 1;
    width--;
  }
  if (**str == '.' && width > 0 && !flag_nan_or_inf) {
    (*str)++;
    width--;
    s21_size_t num = 1;
    while (isdigit(**str) && width > 0) {
      *value = *value + get_digit(**str) / pow(10, num);
      (*str)++;
      width--;
      flag = 1;
      num++;
    }
  }
  if ((**str == 'e' || **str == 'E') && width > 1 && !flag_nan_or_inf) {
    (*str)++;
    width--;
    long num = 0;
    if (parse_long_with_width(str, width, &num))
      *value *= powl(10.0L, (long double)num);
  }
  if (!flag_nan_or_inf) *value *= sign;
  return flag;
}

static int process_float(const char **str, info_t *info_flag, va_list args,
                         __attribute__((unused)) const char *original_str) {
  if (!skip_whitespace(str)) return 0;
  long double value = 0;
  int flag = parse_long_double_from_string(str, info_flag->width, &value);
  if (flag && info_flag->save) {
    if (info_flag->length == 'L')
      *va_arg(args, double long *) = value;
    else if (info_flag->length == 'l')
      *va_arg(args, double *) = (double)value;
    else
      *va_arg(args, float *) = (float)value;
  }
  return flag;
}

static int process_number(const char **str, info_t *info_flag, va_list args,
                          const char *original_str) {
  if (info_flag->save) {
    int *out = va_arg(args, int *);
    *out = *str - original_str;
  }
  return 1;
}

static int process_percent(const char **str,
                           __attribute__((unused)) info_t *info_flag,
                           __attribute__((unused)) va_list args,
                           __attribute__((unused)) const char *original_str) {
  if (!skip_whitespace(str)) return 0;
  if (**str != '%') return 0;
  (*str)++;
  return 1;
}

static int process_type(const char **str, va_list args, info_t *info_flag,
                        process_func_t *funcs, const char *original_str) {
  return funcs[(int)info_flag->type](str, info_flag, args, original_str);
}

static int check_type(char type) {
  return s21_strchr("cdieEfFgGosuxXpn%", type) != S21_NULL;
}

static const char *parse_save_flag(const char *format, info_t *info_flag) {
  if (*format == '*') {
    info_flag->save = 0;
    format++;
  }
  return format;
}

static const char *parse_width(const char *format, info_t *info_flag) {
  while (isdigit(*format)) {
    info_flag->width = info_flag->width * 10 + (*format - '0');
    format++;
  }
  return format;
}

static const char *parse_length(const char *format, info_t *info_flag) {
  if (*format == 'l' || *format == 'h' || *format == 'L') {
    info_flag->length = *format;
    format++;
  }
  return format;
}

static int parse_info(const char **format, info_t *info_flag) {
  int result = 1;
  (*format)++;  // skip '%'
  *format = parse_save_flag(*format, info_flag);
  *format = parse_width(*format, info_flag);
  *format = parse_length(*format, info_flag);
  info_flag->type = **format;
  result = check_type(info_flag->type);
  if (result) (*format)++;
  return result;
}

static int handle_flag(const char **str, const char **format, va_list args,
                       info_t *info_flag, process_func_t *funcs,
                       const char *original_str) {
  int result = 1;
  result = parse_info(format, info_flag);
  if (result) result = process_type(str, args, info_flag, funcs, original_str);
  return result;
}

static int handle_not_format_char(const char **str, const char **format) {
  if (**format != **str) return 0;
  (*str)++;
  (*format)++;
  return 1;
}

static s21_size_t handle_is_active_after_flag(int is_active, int save,
                                              s21_size_t count, char type) {
  if (is_active && save && type != 'n' && type != '%') return ++count;
  return count;
}

static void register_all_process_funcs(process_func_t *funcs) {
  register_process_func(funcs, 'd', process_int);
  register_process_func(funcs, 'x', process_hex);
  register_process_func(funcs, 'X', process_hex);
  register_process_func(funcs, 'o', process_octal);
  register_process_func(funcs, 'i', process_int_auto);
  register_process_func(funcs, 'u', process_unsigned_int);
  register_process_func(funcs, 'c', process_char);
  register_process_func(funcs, 's', process_string);
  register_process_func(funcs, 'f', process_float);
  register_process_func(funcs, 'F', process_float);
  register_process_func(funcs, 'e', process_float);
  register_process_func(funcs, 'E', process_float);
  register_process_func(funcs, 'g', process_float);
  register_process_func(funcs, 'G', process_float);
  register_process_func(funcs, 'n', process_number);
  register_process_func(funcs, '%', process_percent);
}

int s21_sscanf(const char *str, const char *format, ...) {
  if (str == S21_NULL || format == S21_NULL) return EOF;
  if (*str == '\0' && s21_strstr(format, "%n") == S21_NULL) return EOF;
  va_list args;
  va_start(args, format);
  process_func_t funcs[NUMBER_ASCII];
  init_process_array(funcs);
  register_all_process_funcs(funcs);
  s21_size_t count = 0;
  int is_active = 1;
  int eof_condition = 0;
  int any_successful = 0;
  const char *original_str = str;
  while (*str && *format && is_active) {
    if (*format == '%') {
      info_t info_flag;
      init_info(&info_flag);
      is_active =
          handle_flag(&str, &format, args, &info_flag, funcs, original_str);
      if (is_active) any_successful = 1;
      count = handle_is_active_after_flag(is_active, info_flag.save, count,
                                          info_flag.type);
      if (!is_active && *str == '\0' && !any_successful) eof_condition = 1;
    } else {
      is_active = handle_not_format_char(&str, &format);
    }
  }
  va_end(args);
  return eof_condition ? EOF : count;
}