#ifndef TOKEN_H
#define TOKEN_H
#include <stdarg.h>

typedef struct tok {
  char flag;
  int width;
  char extra_width_arg;  // если ширина это *
  int precision;
  char extra_precision_arg;  // если точность это .*
  char length;
  char specifier;
  int written_chars;
} Token;

void reverse(char *s);
// char *convert(long unsigned int number, int base, int type);
void itoa(long long int n, char *s);
void ftoa(long double n, char *str, Token *token);
void notation(long double f, char *str, int type, Token *token);
void specificator(char *str, Token *token, va_list arg);
int contains(const char *arr, char elem);
void _def_init_token(Token *token);
int fill_token(const char *format, Token *token);
void fill_addition(char *dest, Token *token, va_list arg);
void s21_sprintf(char *str, const char *format, ...);
void change(Token *t, int a);


#endif