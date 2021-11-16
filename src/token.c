#include "token.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_errno.h"
#include "s21_string.h"

void _def_init_token(Token *token) {
  token->flag = 'r';
  token->width = 0;
  token->extra_width_arg = 0;
  token->precision = 6;
  token->extra_precision_arg = 0;
  token->length = '\0';
  token->specifier = '\0';
  token->written_chars = 0;
}
const char specifiers[17] = {'i', 'd', 'g', 'G', 'n', 'e', 'E', 'x', 'X',
                             'c', 'u', 'o', 'p', 's', '%', 'f', '\0'};

const char length_modifiers[4] = {'L', 'l', 'h', '\0'};

const char flags[6] = {'-', '+', ' ', '#', '0', '\0'};

const char precision_modifiers[4] = {'L', 'l', 'h', '\0'};

const char numbers[11] = "0123456789";
void clean(char *arr) {
  for (; *arr != '\0'; arr++) {
    *arr = 0;
  }
}
char *p(long unsigned int num, int base) {
  static char rep2[16] = "0123456789abcdef";
  static char buf[50];
  char *ptr;
  ptr = &buf[49];
  *ptr = '\0';
  do {
    *--ptr = rep2[num % base];
    num /= base;
  } while (num != 0);
  return ptr;
}

char *convert(unsigned int number, int base, int type, Token *token) {
  static char rep[16] = "0123456789ABCDEF";
  static char rep2[16] = "0123456789abcdef";
  static char buf[50];
  if (token->length == 'h') number = (unsigned short int)number;
  if (token->length == 'l')
    number = (unsigned long int)number;
  else
    number = (int)number;
  char *ptr;
  ptr = &buf[49];
  *ptr = '\0';
  do {
    if (type == 1)
      *--ptr = rep[number % base];
    else if (type == 2)
      *--ptr = rep2[number % base];
    number /= base;
  } while (number != 0);
  return ptr;
}

void notation(long double f, char *str, int type, Token *token) {
  int temp = 0, afterpoint = token->precision, addr_point, sign, flag = 0;
  char *fcvt_;
  if (f < 0) {
    f = -f;
    s21_strcat(str, "-");
    str += s21_strlen(str);
  }
  if (f < 1 && f != 0) {
    while (f < 1) {
      f *= 10;
      temp++;
    }
    if (afterpoint == 0) {
      fcvt_ = fcvt(f, afterpoint, &addr_point, &sign);
      s21_strcat(str, fcvt_);
      str += s21_strlen(str);
    } else {
      fcvt_ = fcvt(f, afterpoint, &addr_point, &sign);
      fcvt_ = s21_insert(fcvt_, ".", addr_point);
      s21_strcat(str, fcvt_);
      flag = 1;
    }
    if (temp >= 10 && type == 1) {
      s21_strcat(str, "e-");
    } else if (temp < 10 && type == 1) {
      s21_strcat(str, "e-0");
    } else if (temp >= 10 && type == 2) {
      s21_strcat(str, "E-");
    } else if (temp < 10 && type == 2) {
      s21_strcat(str, "E-0");
    }
  } else if (f >= 1) {
    while (f >= 10) {
      f /= 10;
      temp++;
    }
    if (afterpoint == 0) {
      fcvt_ = fcvt(f, afterpoint, &addr_point, &sign);
      s21_strcat(str, fcvt_);
      str += s21_strlen(str);
    } else {
      fcvt_ = fcvt(f, afterpoint, &addr_point, &sign);
      fcvt_ = s21_insert(fcvt_, ".", addr_point);
      s21_strcat(str, fcvt_);
      flag = 1;
    }
    if (temp >= 10 && type == 1) {
      s21_strcat(str, "e+");
    } else if (temp < 10 && type == 1) {
      s21_strcat(str, "e+0");
    } else if (temp >= 10 && type == 2) {
      s21_strcat(str, "E+");
    } else if (temp < 10 && type == 2) {
      s21_strcat(str, "E+0");
    }
  }
  if (flag == 1) {
    free(fcvt_);
  }

  s21_strcat(str, convert(temp, 10, 1, token));
  str = str + s21_strlen(str);
}
void nullAfterpointNotation(char *src) {
  if (contains(src, '.')) {
    char tmp[255] = {0};
    int start_index = -1, end_index = -1, index = s21_strlen(src);
    while (src[index] != 'E' && src[index] != 'e') {
      index--;
    }
    index--;
    if (src[index] == '0') {
      end_index = index;
      while (src[index] == '0') {
        start_index = index;
        index--;
      }
      for (int m = 0, n = 0; src[m] != 0; m++) {
        if (m >= start_index && m <= end_index) continue;
        tmp[n++] = src[m];
      }
      s21_strcpy(src, tmp);
    }
  }
}
void nullAfterpointDouble(char *src, int addrpoint) {
  char tmp[255] = {0};
  int index = s21_strlen(src) - 1;
  while (src[index] == '0' && index >= addrpoint - 1) {
    index--;
  }
  index++;
  s21_strncpy(tmp, src, index);
  clean(src);
  s21_strcpy(src, tmp);
}
void notationG(long double d, char *str, int type, Token *token) {
  int afterpoint = token->precision, addr_point, sign, temp;
  char tmp[256] = {0}, tmp2[256] = "", *fcvt_;
  if (token->precision - 1 < 0) {
    token->precision = 0;
  } else {
    token->precision -= 1;
  }
  notation((double)d, tmp, type, token);
  nullAfterpointNotation(tmp);
  fcvt_ = fcvt(d, afterpoint, &addr_point, &sign);
  afterpoint -= addr_point;
  fcvt_ = fcvt(d, afterpoint, &temp, &sign);
  while (addr_point < 0) {
    char *tmp = s21_insert(fcvt_, "0", 0);
    clean(fcvt_);
    s21_strcpy(fcvt_, tmp);
    free(tmp);
    addr_point++;
  }

  if (afterpoint <= 0) {
    s21_strcat(tmp2, fcvt_);
  } else {
    if (d != (int)d) {
      fcvt_ = s21_insert(fcvt_, ".", addr_point);
      nullAfterpointDouble(fcvt_, addr_point);
      s21_strncat(tmp2, fcvt_, addr_point + afterpoint);
      free(fcvt_);
    } else {
      nullAfterpointDouble(fcvt_, addr_point);
      s21_strncat(tmp2, fcvt_, addr_point + afterpoint);
    }
  }
  if (s21_strlen(tmp) - 4 <= s21_strlen(tmp2) && (afterpoint < 0) ||
      (afterpoint > 13)) {
    s21_strcat(str, tmp);
  } else {
    if (d < 1) {
      s21_strcat(str, "0");
      str++;
    }
    s21_strcat(str, tmp2);
  }
  str += s21_strlen(str);
}

void specificator(char *str, Token *token, va_list arg) {
  int *h, afterpoint = token->precision, addr_point, sign;
  long int i = 0;
  long double d = 0;
  char *s, *fcvt_;
  long unsigned *h1;
  if (token->extra_precision_arg) {
    afterpoint = va_arg(arg, int);
    token->precision = afterpoint;
  }
  switch (token->specifier) {
    case 'c':
      i = va_arg(arg, int);
      if (i < 0) break;
      *str = (char)i;
      str++;
      break;

    case 'd':
      i = va_arg(arg, int);
      if (token->length != 'l') {
        if (i < 0) {
          i = -i;
          *str = '-';
          str++;
        }
      }
      s21_strcat(str, convert(i, 10, 2, token));
      str += s21_strlen(str);
      break;

    case 's':
      s = va_arg(arg, char *);
      s21_strcat(str, s);
      str += s21_strlen(str);
      break;

    case 'f':
      if (token->length == 'L') {
        d = va_arg(arg, long double);
        d = (long double)d;
      } else {
        d = va_arg(arg, double);
      }
      if (d < 0) {
        d = -d;
        *str = '-';
        str++;
      }
      if (d < 1) {
        s21_strcat(str, "0");
        str++;
      }
      if (afterpoint == 0) {
        fcvt_ = fcvt(d, afterpoint, &addr_point, &sign);
        s21_strcat(str, fcvt_);
        str += s21_strlen(str);
      } else {
        fcvt_ = fcvt(d, afterpoint, &addr_point, &sign);
        fcvt_ = s21_insert(fcvt_, ".", addr_point);
        s21_strcat(str, fcvt_);
        str += s21_strlen(str);
        free(fcvt_);
      }
      break;

    case 'i':
      i = va_arg(arg, int);
      if (token->length != 'l') {
        if (i < 0) {
          i = -i;
          *str = '-';
          str++;
        }
      }
      s21_strcat(str, convert(i, 10, 2, token));
      str = str + s21_strlen(str);
      break;

    case 'o':
      i = va_arg(arg, int);
      s21_strcat(str, convert(i, 8, 1, token));
      str = str + s21_strlen(str);
      break;

    case 'x':
      i = va_arg(arg, int);
      s21_strcat(str, convert(i, 16, 2, token));
      str = str + s21_strlen(str);
      break;

    case 'X':
      i = va_arg(arg, int);
      s21_strcat(str, convert(i, 16, 1, token));
      str = str + s21_strlen(convert(i, 16, 1, token));
      break;

    case 'n':
      h = va_arg(arg, int *);
      int length = token->written_chars;
      *h = length;
      break;

    case 'p':
      h1 = va_arg(arg, long unsigned int *);
      s21_strcat(str, "0x");
      str = str + s21_strlen(str);
      s21_strcat(str, p((long unsigned int)h1, 16));
      str = str + s21_strlen(str);
      break;

    case 'u':
      if (token->length == 'h') {
        i = va_arg(arg, int);
        i = (short unsigned int)i;
      } else if (token->length == 'l') {
        i = va_arg(arg, long unsigned int);
      } else {
        i = va_arg(arg, unsigned int);
      }
      s21_strcat(str, convert(i, 10, 1, token));
      str = str + s21_strlen(convert(i, 10, 1, token));
      break;

    case 'e':
      if (token->length == 'L') {
        d = va_arg(arg, long double);
      } else {
        d = va_arg(arg, double);
      }
      notation(d, str, 1, token);
      str = str + s21_strlen(str);
      break;

    case 'E':
      if (token->length == 'L') {
        d = va_arg(arg, long double);
      } else {
        d = va_arg(arg, double);
      }
      notation(d, str, 2, token);
      str = str + s21_strlen(str);
      break;

    case 'g':
      if (token->length == 'L') {
        d = va_arg(arg, long double);
      } else {
        d = va_arg(arg, double);
      }
      if (d < 0) {
        d = -d;
        *str = '-';
        str++;
      }
      notationG(d, str, 1, token);
      break;

    case 'G':
      if (token->length == 'L') {
        d = va_arg(arg, long double);
      } else {
        d = va_arg(arg, double);
      }
      if (d < 0) {
        d = -d;
        *str = '-';
        str++;
      }
      notationG(d, str, 2, token);
      break;

    case '%':
      s21_strcat(str, "%");
      str++;
      break;

    default:
      break;
  }
}

int contains(const char *arr, char elem) {
  for (; *arr != '\0'; arr++) {
    if (*arr == elem) {
      break;
    }
  }
  return *arr ? 1 : 0;
}

int fill_token(const char *format, Token *token) {
  const char *p = format;
  int maxPos = 0, current = 0;
  for (; !contains(specifiers, *(p + maxPos)); maxPos++) {
    if (*(p + maxPos) == '\0') return -1;
  }
  token->specifier = *(p + maxPos);
  if ((maxPos - current) && contains(flags, *(p + current))) {
    token->flag = *(p + current);
    current++;
  }
  char string_for_width[100] = {0};
  int width_cursor = 0;
  if ((maxPos - current) && *(p + current) == '*') {
    token->extra_width_arg = 1;
    current++;
  } else {
    while ((maxPos - current) && contains(numbers, *(p + current))) {
      *(string_for_width + width_cursor) = *(p + current);
      current++;
      width_cursor++;
    }
    token->width = atoi(string_for_width);
    clean(string_for_width);
    width_cursor = 0;
  }
  if ((maxPos - current) && *(p + current) == '.') {
    current++;
    if ((maxPos - current) && *(p + current) == '*') {
      token->extra_precision_arg = 1;
      current++;
    } else {
      while ((maxPos - current) && contains(numbers, *(p + current))) {
        *(string_for_width + width_cursor) = *(p + current);
        current++;
        width_cursor++;
      }
      token->precision = atoi(string_for_width);
    }
  }
  if ((maxPos - current) && contains(length_modifiers, *(p + current))) {
    token->length = *(p + current);
    current++;
  }
  return maxPos;
}

void fill_addition(char *dest, Token *token, va_list arg) {
  char str_before_mod[200] = {0};
  int width = token->width;
  if (token->extra_width_arg) {
    width = va_arg(arg, int);
  }
  specificator(str_before_mod, token, arg);
  char str_after_mod[200] = {0};
  char *before_str = str_before_mod;
  char *after_str = str_after_mod;

  if (width > s21_strlen(str_before_mod)) {
    int dif = width - s21_strlen(str_before_mod);
    switch (token->flag) {
      case 'r':
        s21_memset(str_after_mod, ' ', dif);
        s21_strcat(str_after_mod, str_before_mod);
        break;

      case '-':
        s21_strcat(str_after_mod, str_before_mod);
        s21_memset(str_after_mod + s21_strlen(str_before_mod), ' ', dif);
        break;

      case '+':
        if ((token->specifier == 'd' || token->specifier == 'i') &&
            str_before_mod[0] != '-') {
          s21_memset(after_str, ' ', dif - 1);
          after_str[dif - 1] = '+';
          after_str += dif;
        } else {
          s21_memset(after_str, ' ', dif);
        }
        s21_strcat(str_after_mod, str_before_mod);
        break;

      case ' ':
        if ((token->specifier == 'd' || token->specifier == 'i') &&
            str_before_mod[0] != '-') {
          s21_memset(after_str, ' ', dif - 1);
          after_str[dif - 1] = ' ';
          after_str += dif;
        } else {
          s21_memset(after_str, ' ', dif);
        }
        s21_strcat(str_after_mod, str_before_mod);
        break;

      case '0':
        if ((token->specifier == 'd' || token->specifier == 'i') &&
            str_before_mod[0] == '-') {
          *after_str++ = '-';
          before_str++;
        }
        s21_memset(after_str, '0', dif);
        s21_strcat(after_str, before_str);
        break;
    }
  } else {
    if ((token->specifier == 'd' || token->specifier == 'i') &&
        str_before_mod[0] != '-' && token->flag == '+') {
      *after_str++ = '+';
    }

    if ((token->specifier == 'd' || token->specifier == 'i') &&
        str_before_mod[0] != '-' && token->flag == ' ') {
      *after_str++ = ' ';
    }

    s21_strcat(str_after_mod, str_before_mod);
  }
  s21_strcpy(dest, str_after_mod);
}

void s21_sprintf(char *str, const char *format, ...) {
  clean(str);
  char tmp[5000] = {0};
  char *start_of_str = tmp, *str_fill = tmp;
  char addition[200] = {0};
  const char *cursor = format;
  va_list arg;
  va_start(arg, format);
  for (; *cursor != '\0'; cursor++) {
    if (*cursor != '%') {
      *str_fill = *cursor;
      str_fill++;
    } else {
      Token token;
      _def_init_token(&token);
      token.written_chars = s21_strlen(start_of_str);
      cursor++;
      int shift = fill_token(cursor, &token);
      if (shift == -1) {
        *str_fill = '%';
        str_fill++;
        *str_fill = *cursor;
        str_fill++;
      } else {
        clean(addition);
        fill_addition(addition, &token, arg);
        cursor += shift;
        s21_strcat(str_fill, addition);
        str_fill += s21_strlen(str_fill);
      }
    }
  }
  *str_fill = 0;
  s21_strcpy(str, start_of_str);
  va_end(arg);
}

// int main(void) {
//   char str_1[300];
//   char str_2[300];
//   char *str_3, *str3 = ".";
//   int a, b;
//   long double md = -13213213.51231235553556, ld = 13213213.51231235553556,
//               l = 0.512312355535561231312354353535;
//   s21_sprintf(str_1, "%g|  PROVERKA", 750000000.15000);
//   sprintf(str_2, "%g|  PROVERKA", 750000000.15000);
//   printf("HERE IS MY IMPLEMENTATION: <%s>\n", str_1);
//   printf("HERE IS C  IMPLEMENTATION: <%s>\n", str_2);
//   return 0;
// }
