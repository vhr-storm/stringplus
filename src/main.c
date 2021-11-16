#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_errno.h"
#include "s21_string.h"
<<<<<<< HEAD
#include "token.h"
=======

<<<<<<< HEAD
<<<<<<< HEAD
int main() {
  char *p = to_upper("asndmasn");
  printf("%s \n", p);
  MAX(4,5);
=======
void reverse(char *s) {
  int i, j;
  char c;
  for (i = 0, j = s21_strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

char *convert(long unsigned int number, int base, int type) {
  static char rep[16] = "0123456789ABCDEF";
  static char rep2[16] = "0123456789abcdef";
  static char buf[500];
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

void itoa(long long int n, char *s) {
  long long int i = 0, sign = n;
  if (sign < 0) sign = -sign;
  do {
    s[i++] = n % 10 + '0';
    n /= 10;
  } while (n > 0);
  if (sign < 0) s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void ftoa(double n, char *str, int after_point) {
  // int i_part[255], i = 0;

  printf("%lld\n", (long long int)n);
  double j = 10.0, tmp = n / j;
  printf("%f\n", tmp);
  // while (i_part[i]!='.')
  // {
  //   tmp=n%10;
  //   i_part[i]=
  // }

  unsigned long long int i_part = (long long int)n;
  printf(" i_part %llu\n", i_part);
  long double f_part = n - (int)i_part;
  printf(" f_part %Lf\n", f_part);
  itoa(i_part, str);
  str += s21_strlen(str);
  if (after_point != 0) {
    *str = '.';
    str++;
    f_part = f_part * pow(10, after_point);
    itoa(f_part, str);
    str = str + s21_strlen(str);
  }
}

void notation(long double f, char *str, int type) {
  int temp = 0;
  char tmp[256] = "";
  if (f < 1) {
    while (f < 1) {
      f *= 10;
      temp++;
    }
    ftoa(f, tmp, 5);
    s21_strcat(str, tmp);
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
    while (f > 10) {
      f /= 10;
      temp++;
    }
    ftoa(f, tmp, 5);
    s21_strcat(str, tmp);
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
  s21_strcat(str, convert(temp, 10, 1));
  str = str + s21_strlen(str);
}
void specificator(char *str, va_list arg, const char *traverse) {
  int i, r = 0, *h;
  double d, n;
  float f;
  char *s, *m = str, tmp[256] = "", tmp2[256] = "";
  unsigned int h2;
  long unsigned *h1;
  int temp = 0;
  switch (*traverse) {
    case 'c':
      i = va_arg(arg, int);
      if (i < 0) break;
      *str = (char)i;
      str++;
      break;

    case 'd':
      i = va_arg(arg, int);
      if (i < 0) {
        i = -i;
        *str = '-';
        str++;
      }
      ftoa(i, str, 0);
      str = str + s21_strlen(str);
      break;

    case 's':
      s = va_arg(arg, char *);
      s21_strcat(str, s);
      str = str + s21_strlen(str);
      break;

    case 'f':
      f = va_arg(arg, double);
      if (f < 0) {
        f = -f;
        *str = '-';
        str++;
      }
      ftoa(f, tmp, 6);
      s21_strcat(str, tmp);
      str = str + s21_strlen(tmp);
      break;

    case 'i':
      i = va_arg(arg, int);
      if (i < 0) {
        i = -i;
        *str = '-';
        str++;
      }
      itoa(i, tmp);
      s21_strcat(str, tmp);
      str = str + s21_strlen(tmp);
      break;

    case 'o':
      i = va_arg(arg, int);
      s21_strcat(str, convert((unsigned)i, 8, 1));
      str = str + s21_strlen(str);
      break;

    case 'x':
      h2 = va_arg(arg, unsigned int);
      s21_strcat(str, convert(h2, 16, 2));
      str = str + s21_strlen(convert(h2, 16, 2));
      break;

    case 'X':
      h2 = va_arg(arg, unsigned int);
      s21_strcat(str, convert(h2, 16, 1));
      str = str + s21_strlen(convert(h2, 16, 1));
      break;

    case 'n':
      h = va_arg(arg, int *);
      *h = s21_strlen(m);
      break;

    case 'p':
      h1 = va_arg(arg, long unsigned int *);
      s21_strcat(str, "0x");
      str = str + s21_strlen("0x");
      s21_strcat(str, convert((long unsigned int)h1, 16, 2));
      str = str + s21_strlen(convert((long unsigned int)h1, 16, 2));
      break;

    case 'u':
      h2 = va_arg(arg, unsigned int);
      s21_strcat(str, convert(h2, 10, 1));
      str = str + s21_strlen(convert(h2, 10, 1));
      break;

    case 'e':
      f = va_arg(arg, double);
      notation(f, str, 1);
      str = str + s21_strlen(str);
      break;

    case 'E':
      f = va_arg(arg, double);
      notation(f, str, 2);
      str = str + s21_strlen(str);
      break;

    case 'g':
      d = va_arg(arg, double);
      if (d < 0) {
        d = -d;
        *str = '-';
        str++;
      }
      double k = d;
      notation((double)d, tmp, 1);
      ftoa((double)k, tmp2, 2);
      if (s21_strlen(tmp) > s21_strlen(tmp2)) {
        s21_strcat(str, tmp2);
      } else
        s21_strcat(str, tmp);
      str += s21_strlen(str);
      break;

    case 'G':
      d = va_arg(arg, double);
      if (d < 0) {
        d = -d;
        *str = '-';
        str++;
      }
      double z = d, m = d;
      int cntr = 0;
      notation((double)d, tmp, 2);
      while (m >= 1) {
        m = m / 10;
        cntr++;
      }
      if (cntr > 6) {
        int tch = cntr - 6;
        ftoa(z, tmp2, tch);
      } else if (cntr == 0) {
        int tch = 6;
        ftoa(z, tmp2, tch);
      } else {
        int tch = 6 - cntr;
        ftoa(z, tmp2, tch);
      }
      if (s21_strlen(tmp) - 3 >= s21_strlen(tmp2)) {
        s21_strncat(str, tmp2, 7);
      } else
        s21_strncat(str, tmp, 10);
      str += s21_strlen(str);
      break;

    case '%':
      s21_strcat(str, "%");
      str++;
      break;

    default:
      break;
  }
}
int s21_sprintf(char *str, const char *format, ...) {
  const char *traverse;
  int r = 0;
  *str = 0;
  va_list arg;
  va_start(arg, format);

  for (traverse = format; *traverse != '\0' && r < s21_strlen(format);
       traverse++, r++) {
    while (*traverse != '%' && r < s21_strlen(format)) {
      *str = *traverse;
      traverse++;
      str++;
      r++;
    }
    if (r >= s21_strlen(format)) {
      *str = '\0';
      break;
    }
    r++;
    traverse++;
    specificator(str, arg, traverse);
    str = str + s21_strlen(str);
  }
  *str = 0;
  va_end(arg);
  return 0;
}

// int *digit(double b) {
//   long long int a = (int)b;
//   int ch[255];
//   int pos = 0;
//   while (a != 0) {
//     ch[pos] = a % 10;
//     pos++;
//     a /= 10;
//   }
//   return ch;
// }
>>>>>>> df86ffd50ea77f70ff14bcf67b1b58647a5bab06

=======
>>>>>>> b052c4ac0fa8a62e933d9a911575f3bdec4b8442
int main() {
<<<<<<< HEAD
  char str1[100];
  char str2[100];
  s21_sprintf(str1, "asdfasdfasdf %.10f ", 12341234.1231231233);
  sprintf(str2, "asdfasdfasdf %.10f ", 12341234.1231231233);
  printf("HERE IS MY IMPLEMENTATION: <%s>\n", str1);
  printf("HERE IS C  IMPLEMENTATION: <%s>\n", str2);
=======
  // char str[255], str1[255];
  // double n = 1112.1232;
  // double n1 = 1231.1;
  // int a, b = 1234, ch[255];
  // printf("%s\n", s21_strchr(str, str1));
  double s = 12345612123412341234;
  int b = (int)s;
  int ch[255];
  for (long long j = 0; j < 255; j++) {
    ch[j] = b % 10;
    b /= 10;
  }
  for (long long j = 0; j < 255; j++) {
    printf("%lld ", ch[j]);
  }

  // s21_sprintf(str, "%G %f", 0.1341213241234341422, 0.1234);
  // sprintf(str1, "%G %f", 0.1341213241234341422, 0.1234);
  // printf("%s\n", str);
  // printf("%s\n", str1);
  char str[255], str1[255];
  double n = 1321313213121.1341213241234341422;
  double n1 = 1231.1;
  int a, b = 1234;
  // printf("%s\n", s21_strchr(str, str1));;
  s21_sprintf(str, "%f %f", 5511123131555553333333311.1341213241234341422,
              0.1234);
  sprintf(str1, "%f %f", 5511231312333333333333333333.1341213241234341422,
          0.1234);
  printf("%s\n", str);
  printf("%s\n", str1);
  int a, b;

  s21_sprintf(str, "%11114rteyrteyd");
  sprintf(str1, "%.7f", -11.123456789);
  printf("%s \n", str);
  printf("%s \n", str1);
>>>>>>> a44a0fc93ec931fb4e78a6f51b2d3882e6e05f89
>>>>>>> df86ffd50ea77f70ff14bcf67b1b58647a5bab06
  return 0;
}
