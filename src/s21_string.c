#include "s21_string.h"

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_errno.h"

void *s21_to_upper(const char *str) {
  const char *p1 = str;
  char *p2 = S21_NULL;
  if (p1 != S21_NULL) {
    p2 = (char *)malloc(sizeof(char *) * s21_strlen(p1));
    s21_strcpy(p2, p1);
    for (int i = 0; i < s21_strlen(p1); i++) {
      if (p2[i] >= 'a' && p2[i] <= 'z') p2[i] = p2[i] - 32;
    }
    p2[s21_strlen(p1)] = '\0';
  }

  return p2;
}

void *s21_to_lower(const char *str) {
  const char *p1 = str;
  char *p2 = S21_NULL;
  if (p1 != S21_NULL) {
    p2 = (char *)malloc(sizeof(char *) * s21_strlen(p1));
    s21_strcpy(p2, p1);
    for (int i = 0; i < s21_strlen(p1); i++) {
      if (p2[i] >= 'A' && p2[i] <= 'Z') p2[i] = p2[i] + 32;
    }
    p2[s21_strlen(p1)] = '\0';
  }
  return p2;
}

void *s21_trim(const char *src, const char *trim_chars) {
  const char *p1 = src, *p2;
  char *p3 = S21_NULL;
  if (trim_chars != S21_NULL) {
    p2 = trim_chars;
  } else {
    p2 = " ";
  }
  if (p1 != S21_NULL) {
    s21_size_t start_index = 0, end_index = s21_strlen(p1) - 1, i = 0;
    for (; p1[start_index] != '\0'; start_index++) {
      int counter = 0;
      for (s21_size_t j = 0; p2[j] != '\0'; j++) {
        if (p1[start_index] != p2[j]) {
          counter++;
        }
      }
      if (counter == s21_strlen(p2)) {
        break;
      }
    }
    for (; p1[end_index] != p1[start_index]; end_index--) {
      int counter = 0;
      for (s21_size_t j = 0; p2[j] != '\0'; j++) {
        if (p1[end_index] != p2[j]) {
          counter++;
        }
      }
      if (counter == s21_strlen(p2)) {
        break;
      }
    }
    p3 = (char *)malloc(sizeof(char *) * (end_index));
    while (start_index != end_index + 1) {
      p3[i] = p1[start_index];
      start_index++;
      i++;
    }
  }

  return p3;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  const char *p1 = src, *p2;
  char *p3 = S21_NULL;
  if (p1 != S21_NULL) {
    if (str == S21_NULL) {
      p2 = "";
    } else {
      p2 = str;
    }
    p3 = (char *)malloc(sizeof(char *) * (s21_strlen(p1) + s21_strlen(p2)));
    s21_size_t j = 0;
    s21_strcpy(p3, p1);
    for (; p2[j] != '\0'; j++) {
      p3[start_index + j] = p2[j];
    }
    s21_size_t i = start_index;
    for (; p1[i] != '\0'; i++) {
      p3[i + j] = p1[i];
    }
    p3[s21_strlen(p1) + s21_strlen(p2)] = '\0';
  }

  return p3 != S21_NULL && (start_index < s21_strlen(p1)) ? p3 : S21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *p1 = str1, *p2 = str2;
  int ans = 0;
  while (n--) {
    if (*p1 != *p2) {
      ans = *p1 - *p2;
      break;
    } else {
      p1++;
      p2++;
    }
  }
  return ans;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  const char *p1 = src;
  char *p2 = dest;
  while (n--) {
    *p2 = *p1;
    p1++;
    p2++;
  }
  return dest;
}

char *s21_strchr(const char *str, int c) {
  const char *p1 = str;
  for (; *p1 != '\0'; p1++) {
    if ((int)*p1 == c) {
      break;
    }
  }

  return *p1 != '\0' ? (char *)p1 : S21_NULL;
}

char *s21_strcat(char *dest, const char *src) {
  int i = 0, j = 0;
  i = s21_strlen(dest);
  while (src[j] != '\0') {
    dest[i + j] = src[j];
    j++;
  }
  dest[i + j] = '\0';
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  int i = 0, j = 0;
  i = s21_strlen(dest);
  while (src[j] != '\0' || j < n) {
    dest[i + j] = src[j];
    j++;
  }
  dest[i + n + 1] = '\0';
  return dest;
}

int s21_strcmp(const char *str1, const char *str2) {
  const char *p1 = str1, *p2 = str2;
  for (; *p1 != '\0' && *p2 != '\0'; p1++, p2++) {
    if (*p1 != *p2) {
      break;
    }
  }
  return *p1 - *p2;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *p1 = str1, *p2 = str2;
  while (*p1 != '\0') {
    if (s21_strchr(p2, *p1) != 0) {
      break;
    }
    p1++;
  }
  return *p1 != '\0' ? (char *)p1 : 0;
}
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  const char *p1 = str1, *p2 = str2;
  for (s21_size_t i = 0; (*p1 != '\0' && *p2 != '\0') || (i != n);
       p1++, p2++, i++) {
    if (*p1 != *p2) {
      break;
    }
  }
  return *p1 - *p2;
}

char *s21_strrchr(const char *str, int c) {
  const char *p1 = str;
  int flag = 0;
  s21_size_t n = s21_strlen(str) - 1;
  for (; (int)n >= 0; n--) {
    if (*(p1 + n) == c) {
      flag = 1;
      break;
    }
  }
  return flag == 1 ? (char *)(p1 + n) : S21_NULL;
}

char *s21_strcpy(char *dest, const char *src) {
  char *p1 = dest;
  const char *p2 = src;
  while (*p2 != '\0') {
    *p1 = *p2;
    p1++;
    p2++;
  }
  *p1 = '\0';
  return p1;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *p1 = dest;
  const char *p2 = src;
  s21_size_t i = 0;
  while (*p2 != '\0') {
    if (i == n) break;
    *p1 = *p2;
    p1++;
    p2++;
    i++;
  }
  return p1;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *p = (unsigned char *)str;
  unsigned char *result = S21_NULL;
  while (n--) {
    if (*p != (unsigned char)c) {
      p++;
    } else {
      result = p;
      break;
    }
  }
  return result;
}

char *s21_strerror(int errnum) {
  char *errlist[108];
  MACROLST;
  return (errnum <= 0 || errnum >= 107) ? S21_NULL : errlist[errnum];
}

s21_size_t s21_strlen(const char *str) {
  int i = 0;
  while (*str++ != '\0') i++;
  return i;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  const char *n;
  for (; *str1 != '\0'; str1++, i++) {
    for (n = str2; *n != '\0' && *n != *str1; n++) {
    }
    if (*n == '\0') break;
  }
  return i;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  const char *n;
  for (; *str1 != '\0'; str1++, i++) {
    for (n = str2; *n != '\0' && *n != *str1; n++) {
    }
    if (*n != '\0') break;
  }
  return i;
}

char *s21_strstr(const char *haystack, const char *needle) {
  const char *p1 = haystack, *p2 = needle;
  s21_size_t n = s21_strlen(p2);
  int flag = 0;
  for (; *p1 != '\0'; p1++) {
    if (s21_memcmp(p1, p2, n) == 0) {
      flag = 1;
      break;
    }
  }
  return flag == 1 ? (char *)p1 : S21_NULL;
}

char *s21_strtok(char *str, const char *delim) {
  static char *src, *ret = 0;
  char *p;
  int flag = 1;
  if (str != S21_NULL) src = str;
  if ((src == S21_NULL) || (*src == '\0')) flag = 0;
  if (flag == 1) {
    p = s21_strpbrk(src, delim);
    *p = 0;
    ret = src;
    src = ++p;
    while ((s21_strcmp("", ret) == 0)) {
      s21_strtok(src, delim);
    }
  }
  return flag == 1 ? ret : 0;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *p = (char *)dest;
  const char *pSrc = (const char *)src;
  char *tmp = (char *)malloc(sizeof(char *) * n);
  unsigned int i = 0;
  for (i = 0; i < n; ++i) {
    *(tmp + i) = *(pSrc + i);
  }
  for (i = 0; i < n; ++i) {
    *(p + i) = *(tmp + i);
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *p = str;
  while (n--) {
    *p++ = (unsigned char)c;
  }
  return str;
}
