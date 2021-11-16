#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_errno.h"
#include "s21_string.h"
#include "token.h"

char s1[10], s2[10] = "abc", s3[10] = "\0", s4[10] = " ", s5[10] = "\t\t\t",
             s6[10] = "\n\n\n", s7[10] = "123", s8[10] = "ABC", s9[10] = "avcc";
int b = 10, c = 100, d = -4, f = 0;
long double md = -13213213.51231235553556, ld = 13213213.51231235553556,
            l = 0.512312355535561231312354353535;

START_TEST(test_sprintf_first) {
  char str_1[255] = "", str_2[255] = "";
  s21_sprintf(str_1, "%d %d %d %d %d %d %d", 1, 2, 3, 4, 5, 6, 7);
  sprintf(str_2, "%d %d %d %d %d %d %d", 1, 2, 3, 4, 5, 6, 7);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 1 TEST");
  s21_sprintf(str_1, "%x%x%x%x%x%x%x", -1, -2, -3, -4, -5, -6, -7);
  sprintf(str_2, "%x%x%x%x%x%x%x", -1, -2, -3, -4, -5, -6, -7);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 2 TEST");
  s21_sprintf(str_1, "%hd%ld%ld%ld%hd%hd%hd", -1, -2, -3, -4, -5, -6, -7);
  sprintf(str_2, "%hd%ld%ld%ld%hd%hd%hd", -1, -2, -3, -4, -5, -6, -7);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 3 TEST");
  ck_assert_str_eq(str_1, str_2);
  s21_sprintf(str_1, "%i%i%i%i%i%i%i", -1, -2, -3, -4, -5, -6, -7);
  sprintf(str_2, "%i%i%i%i%i%i%i", -1, -2, -3, -4, -5, -6, -7);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 4 TEST");
  s21_sprintf(str_1, "%o%o%o%o%o%o", -1, -1, -1, 0, 0, 123123);
  sprintf(str_2, "%o%o%o%o%o%o", -1, -1, -1, 0, 0, 123123);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 5 TEST");
  s21_sprintf(str_1, "%p%p%p%p%p%p", s1, s2, s3, s4, s5, s6);
  sprintf(str_2, "%p%p%p%p%p%p", s1, s2, s3, s4, s5, s6);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 6 TEST");
  s21_sprintf(str_1, "!@#$%%^&*()_+-='';<>,./%c%%%%%%%%%%%%", 'A');
  sprintf(str_2, "!@#$%%^&*()_+-='';<>,./%c%%%%%%%%%%%%", 'A');
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 7 TEST");
  ck_assert_str_eq(str_1, str_2);
  s21_sprintf(str_1, "asdzxc%dweqrwesdafkjdfkj%sqwerasdf%Xasdfasdf%usadf",
              -1234, "ABCDEFG", -1234, -1234);
  sprintf(str_2, "asdzxc%dweqrwesdafkjdfkj%sqwerasdf%Xasdfasdf%usadf", -1234,
          "ABCDEFG", -1234, -1234);
  ck_assert_msg(strncmp(str_1, str_2, 73) == 0, "FAIL 8 TEST");
  ck_assert_str_eq(str_1, str_2);
  s21_sprintf(str_1,
              "                       %p                                 ", b);
  sprintf(str_2, "                       %p                                 ",
          b);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 9 TEST");
  s21_sprintf(
      str_1,
      "alaksdfhakjlshdfuweyhrjkhsdkjfhalsjkdhf "
      "jashdfjkhasldkhfjaksdhfjkh djhfalkshdflahsdljfh asdhf "
      "lkjahsdkjfhasjdhfajshdlfkhasdjhruyweoiquyruehrkjhdlkjhalsiuyrejkh"
      "fadljkhflakjshdfuehakshdfalkjsdhflkaeuyrf");
  sprintf(str_2,
          "alaksdfhakjlshdfuweyhrjkhsdkjfhalsjkdhf jashdfjkhasldkhfjaksdhfjkh "
          "djhfalkshdflahsdljfh asdhf "
          "lkjahsdkjfhasjdhfajshdlfkhasdjhruyweoiquyruehrkjhdlkjhalsiuyrejkhfad"
          "ljkhflakjshdfuehakshdfalkjsdhflkaeuyrf");
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 10 TEST");
  s21_sprintf(str_1, "%f%f%f%f%f%f", 1.0000, 2.0000, 3.0000, 4.0000, 5.0000,
              6.0000, 7.0000);
  sprintf(str_2, "%f%f%f%f%f%f", 1.0000, 2.0000, 3.0000, 4.0000, 5.0000, 6.0000,
          7.0000);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 11 TEST");
  s21_sprintf(str_1,
              "%pqwer2134%p42134qerq%p234eq rqewrqwer%pwqr "
              "qewrqwer%p1234234234%pweqrweqwe",
              s1, s2, s3, s4, s5, s6);
  sprintf(str_2,
          "%pqwer2134%p42134qerq%p234eq rqewrqwer%pwqr "
          "qewrqwer%p1234234234%pweqrweqwe",
          s1, s2, s3, s4, s5, s6);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 12 TEST");
  s21_sprintf(str_1, "%ld %ld %ld %ld %ld %ld %ld", 1, 1, 1, 1, 1, 1, 1);
  sprintf(str_2, "%ld %ld %ld %ld %ld %ld %ld", 1, 1, 1, 1, 1, 1, 1);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 13 TEST");
  s21_sprintf(str_1, "%ld %ld %ld %ld ", -1, -1, -1, -1);
  sprintf(str_2, "%ld %ld %ld %ld ", -1, -1, -1, -1);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 14 TEST");
  s21_sprintf(str_1, "%f %f %f %f ", -1.2335, 0.56664, 765.12354, -765.12354);
  sprintf(str_2, "%f %f %f %f ", -1.2335, 0.56664, 765.12354, -765.12354);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 15 TEST");
  s21_sprintf(str_1, "%e %e %e %e ", -1.2335, 0.0000056664, 765.12354,
              -765.12354);
  sprintf(str_2, "%e %e %e %e ", -1.2335, 0.0000056664, 765.12354, -765.12354);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 16 TEST");
  s21_sprintf(str_1, "%E %E %E %E ", -1.2335, 0.0000056664, 765.12354,
              -765.12354);
  sprintf(str_2, "%E %E %E %E ", -1.2335, 0.0000056664, 765.12354, -765.12354);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 17 TEST");
}
END_TEST

START_TEST(test_sprintf_second) {
  char str_1[255] = "", str_2[255] = "";
  s21_sprintf(str_1, "%.9ga %.8g %.7g %g %.5g %.4g ",
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556);
  sprintf(str_2, "%.9ga %.8g %.7g %g %.5g %.4g ",
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 1 TEST");
  s21_sprintf(str_1, "%.9e %.8e %.7e %e %.5e %.4e ",
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556);
  sprintf(str_2, "%.9e %.8e %.7e %e %.5e %.4e ",
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 2 TEST");
  s21_sprintf(str_1, "%.9E %.8E %.7E %E %.5E %.4E ",
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556);
  sprintf(str_2, "%.9E %.8E %.7E %E %.5E %.4E ",
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 3 TEST");
  s21_sprintf(str_1, "%.9f %.8f %.7f %f %.5f %.4f ",
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556,
              12321132151515151511515151.51231235553556);
  sprintf(str_2, "%.9f %.8f %.7f %f %.5f %.4f ",
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556,
          12321132151515151511515151.51231235553556);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 4 TEST");
  s21_sprintf(str_1, "%.9Lf %.8Lf %.7Lf %Lf %.5Lf %.4Lf ", md, md, md, md, md,
              md);
  sprintf(str_2, "%.9Lf %.8Lf %.7Lf %Lf %.5Lf %.4Lf ", md, md, md, md, md, md);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 5 TEST");
  s21_sprintf(str_1, "%.9LE %.8LE %.7LE %LE %.5LE %.4LE ", md, md, md, md, md,
              md);
  sprintf(str_2, "%.9LE %.8LE %.7LE %LE %.5LE %.4LE ", md, md, md, md, md, md);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 6 TEST");
  s21_sprintf(str_1, "%.9Le %.8Le %.7Le %Le %.5Le %.4Le ", ld, ld, ld, ld, ld,
              ld);
  sprintf(str_2, "%.9Le %.8Le %.7Le %Le %.5Le %.4Le ", ld, ld, ld, ld, ld, ld);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 7 TEST");
  s21_sprintf(str_1, "%.9Lg %.8Lg %.7Lg %Lg %.5Lg %.4Lg ", ld, ld, ld, ld, ld,
              ld);
  sprintf(str_2, "%.9Lg %.8Lg %.7Lg %Lg %.5Lg %.4Lg ", ld, ld, ld, ld, ld, ld);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 8 TEST");
  s21_sprintf(str_1, "%.9LG %.8LG %.7LG %LG %.5LG %.4LG ", ld, ld, ld, ld, ld,
              ld);
  sprintf(str_2, "%.9LG %.8LG %.7LG %LG %.5LG %.4LG ", ld, ld, ld, ld, ld, ld);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 9 TEST");
  s21_sprintf(str_1, "%.LG %.Lg %.Le %.LE %.Lf ", ld, md, ld, md, ld);
  sprintf(str_2, "%.LG %.Lg %.Le %.LE %.Lf ", ld, md, ld, md, ld);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 10 TEST");
  s21_sprintf(str_1, "%.9LE %.8LE %.7LE %LE %.5LE %.4LE ", l, l, l, l, l, l);
  sprintf(str_2, "%.9LE %.8LE %.7LE %LE %.5LE %.4LE ", l, l, l, l, l, l);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 11 TEST");
  s21_sprintf(str_1, "%.9Le %.8Le %.7Le %Le %.5Le %.4Le ", l, l, l, l, l, l);
  sprintf(str_2, "%.9Le %.8Le %.7Le %Le %.5Le %.4Le ", l, l, l, l, l, l);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 12 TEST");
  s21_sprintf(
      str_1, "%.9e %.8e %.7e %e %.5e %.4e ", 0.512312355535561231312354353535,
      0.512312355535561231312354353535, 0.512312355535561231312354353535,
      0.512312355535561231312354353535, 0.512312355535561231312354353535,
      0.512312355535561231312354353535);
  sprintf(str_2, "%.9e %.8e %.7e %e %.5e %.4e ",
          0.512312355535561231312354353535, 0.512312355535561231312354353535,
          0.512312355535561231312354353535, 0.512312355535561231312354353535,
          0.512312355535561231312354353535, 0.512312355535561231312354353535);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 13 TEST");
  s21_sprintf(
      str_1, "%.9E %.8E %.7E %E %.5E %.4E ", 0.512312355535561231312354353535,
      0.512312355535561231312354353535, 0.512312355535561231312354353535,
      0.512312355535561231312354353535, 0.512312355535561231312354353535,
      0.512312355535561231312354353535);
  sprintf(str_2, "%.9E %.8E %.7E %E %.5E %.4E ",
          0.512312355535561231312354353535, 0.512312355535561231312354353535,
          0.512312355535561231312354353535, 0.512312355535561231312354353535,
          0.512312355535561231312354353535, 0.512312355535561231312354353535);
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 14 TEST");
  s21_sprintf(str_1, "%s %s %s %s|  PROVERKA", "HELLO1 ", "HELLO2 ", "HELLO3",
              "HELLO4 ");
  sprintf(str_2, "%s %s %s %s|  PROVERKA", "HELLO1 ", "HELLO2 ", "HELLO3",
          "HELLO4 ");
  ck_assert_msg(strcmp(str_1, str_2) == 0, "FAIL 15 TEST");
}
END_TEST

START_TEST(test_toupper) {
  ck_assert_msg(strcmp(s21_to_upper("qwe qwe"), "QWE QWE") == 0, "FAIL 1 TEST");
  ck_assert_msg(strcmp(s21_to_upper(s9), "AVCC") == 0, "FAIL 2 TEST");
  ck_assert_msg(strcmp(s21_to_upper(s8), s8) == 0, "FAIL 3 TEST");
}
END_TEST

START_TEST(test_tolower) {
  ck_assert_msg(strcmp(s21_to_lower("QWE QWE"), "qwe qwe") == 0, "FAIL 1 TEST");
  ck_assert_msg(strcmp(s21_to_lower("AVCC"), "avcc") == 0, "FAIL 2 TEST");
  ck_assert_msg(strcmp(s21_to_lower(s8), "abc") == 0, "FAIL 3 TEST");
}
END_TEST

START_TEST(test_insert) {
  ck_assert_msg(strcmp(s21_insert("abcd", "AAA", 0), "AAAabcd") == 0,
                "FAIL 1 TEST");
  ck_assert_msg(strcmp(s21_insert("abcd", "AAA", 2), "abAAAcd") == 0,
                "FAIL 2 TEST");
  ck_assert_msg(strcmp(s21_insert("asdhjfhakjsdfh", "AAAAAAAAAAAAAAA", 5),
                       "asdhjAAAAAAAAAAAAAAAfhakjsdfh") == 0,
                "FAIL 3 TEST");
}
END_TEST

START_TEST(test_trim) {
  ck_assert_msg(strcmp(s21_trim("ababababfffffababab", "ab"), "fffff") == 0,
                "FAIL 1 TEST");
  ck_assert_msg(strcmp(s21_trim("     ff fff     ", " "), "ff fff") == 0,
                "FAIL 2 TEST");
  ck_assert_msg(strcmp(s21_trim("ff fff     ", " "), "ff fff") == 0,
                "FAIL 3 TEST");
  ck_assert_msg(strcmp(s21_trim("    ff fff", " "), "ff fff") == 0,
                "FAIL 4 TEST");
}
END_TEST

START_TEST(test_strcat) {
  s21_strcat(s1, s2);
  ck_assert_msg(strcmp(s1, "abc") == 0, "FAIL 1 TEST");
  s21_strcat(s2, s4);
  ck_assert_msg(strcmp(s2, "abc ") == 0, "FAIL 2 TEST");
  s21_strcat(s2, s7);
  ck_assert_msg(strcmp(s2, "abc 123") == 0, "FAIL 3 TEST");
  s21_strcat(s2, "asdas");
  ck_assert_msg(strcmp(s2, "abc 123asdas") == 0, "FAIL 4 TEST");
}
END_TEST

START_TEST(test_strncat) {
  s21_strncat(s1, s2, b);
  ck_assert_msg(strcmp(s1, "abc") == 0, "FAIL 1 TEST");
  s21_strncat(s2, s4, b);
  ck_assert_msg(strcmp(s2, "abc ") == 0, "FAIL 2 TEST");
  s21_strncat(s2, s7, b);
  ck_assert_msg(strcmp(s2, "abc 123") == 0, "FAIL 3 TEST");
  s21_strncat(s2, "asdas", b);
  ck_assert_msg(strcmp(s2, "abc 123asdas") == 0, "FAIL 4 TEST");
}
END_TEST

START_TEST(test_memcmp) {
  ck_assert_msg(s21_memcmp(s1, s1, b) == 0, "FAIL 1 TEST");
  ck_assert_msg(s21_memcmp(s1, s2, b) < 0, "FAIL 2 TEST");
  ck_assert_msg(s21_memcmp(s2, s1, b) > 0, "FAIL 3 TEST");
  ck_assert_msg(s21_memcmp(s1, s1, f) == 0, "FAIL 4 TEST");
}
END_TEST

START_TEST(test_memcpy) {
  s21_memcpy(s1, s2, c);
  ck_assert_msg(strcmp(s1, "abc") == 0, "FAIL 1 TEST");
  s21_memcpy(s1, s2, f);
  ck_assert_msg(strcmp(s1, "abc") == 0, "FAIL 2 TEST");
  s21_memcpy(s2, s7, b);
  ck_assert_msg(strcmp(s2, "123") == 0, "FAIL 3 TEST");
  s21_memcpy(s1, s5, b);
  ck_assert_msg(strcmp(s1, s5) == 0, "FAIL 4 TEST");
}
END_TEST

START_TEST(test_strchr) {
  ck_assert_msg(strcmp(s21_strchr("abc", 'a'), strchr("abc", 'a')) == 0,
                "FAIL 1 TEST");
  ck_assert_msg(s21_strchr("abfdgf", 0) == S21_NULL, "FAIL 2 TEST");
  ck_assert_msg(s21_strchr("abfdgf", 143) == S21_NULL, "FAIL 3 TEST");
}
END_TEST

START_TEST(test_strcmp) {
  ck_assert_msg(s21_strcmp(s1, s1) == 0, "FAIL 1 TEST");
  ck_assert_msg(s21_strcmp(s1, s2) < 0, "FAIL 2 TEST");
  ck_assert_msg(s21_strcmp(s2, s1) > 0, "FAIL 3 TEST");
  ck_assert_msg(s21_strcmp(s4, s5) > 0, "FAIL 4 TEST");
  ck_assert_msg(s21_strcmp(s5, s6) < 0, "FAIL 5 TEST");
}
END_TEST

START_TEST(test_strncmp) {
  ck_assert_msg(s21_strncmp(s1, s1, f) == 0, "FAIL 1 TEST");
  ck_assert_msg(s21_strncmp(s1, s2, b) < 0, "FAIL 2 TEST");
  ck_assert_msg(s21_strncmp(s2, s1, d) > 0, "FAIL 3 TEST");
  ck_assert_msg(s21_strncmp(s4, s5, c) > 0, "FAIL 4 TEST");
  ck_assert_msg(s21_strncmp(s5, s6, c) < 0, "FAIL 5 TEST");
}
END_TEST

START_TEST(test_strpbrk) {
  ck_assert_msg(s21_strpbrk(s2, "mkl") == S21_NULL, "FAIL 1 TEST");
  ck_assert_msg(strcmp(s21_strpbrk(s2, s2), strpbrk(s2, s2)) == 0,
                "FAIL 2 TEST");
  ck_assert_msg(strcmp(s21_strpbrk(s7, "123"), strpbrk(s7, "123")) == 0,
                "FAIL 3 TEST");
  ck_assert_msg(strcmp(s21_strpbrk("est", "te"), strpbrk("est", "te")) == 0,
                "FAIL 4 TEST");
}
END_TEST

START_TEST(test_strrchr) {
  ck_assert_msg(s21_strrchr(s1, 'a') == strrchr(s1, 'a'), "FAIL 1 TEST");
  ck_assert_msg(s21_strrchr(s5, 13) == strrchr(s5, 13), "FAIL 2 TEST");
  ck_assert_msg(s21_strrchr(s7, d) == strrchr(s7, d), "FAIL 3 TEST");
  ck_assert_msg(s21_strrchr(s6, 13) == strrchr(s6, 13), "FAIL 4 TEST");
  ck_assert_msg(s21_strrchr(s2, 'a') == strrchr(s2, 'a'), "FAIL 5 TEST");
}
END_TEST

START_TEST(test_strlen) {
  ck_assert_msg(s21_strlen(s1) == 0, "FAIL 1 TEST");
  ck_assert_msg(s21_strlen(s2) == 3, "FAIL 2 TEST");
  ck_assert_msg(s21_strlen(s3) == 0, "FAIL 3 TEST");
  ck_assert_msg(s21_strlen(s4) == 1, "FAIL 4 TEST");
  ck_assert_msg(s21_strlen(s5) == 3, "FAIL 5 TEST");
}
END_TEST

START_TEST(test_strcpy) {
  s21_strcpy(s1, s2);
  ck_assert_msg(strcmp(s1, s2) == 0, "FAIL 1 TEST");
  s21_strcpy(s2, s7);
  ck_assert_msg(strcmp(s2, s7) == 0, "FAIL 2 TEST");
  s21_strcpy(s7, s9);
  ck_assert_msg(strcmp(s7, s9) == 0, "FAIL 3 TEST");
}
END_TEST

START_TEST(test_strncpy) {
  s21_strncpy(s1, s2, 1);
  ck_assert_msg(strcmp(s1, "a") == 0, "FAIL 1 TEST");
  s21_strncpy(s2, s7, f);
  ck_assert_msg(strcmp(s2, s2) == 0, "FAIL 2 TEST");
  s21_strncpy(s7, s9, c);
  ck_assert_msg(strcmp(s7, s9) == 0, "FAIL 3 TEST");
}
END_TEST

START_TEST(test_strspn) {
  ck_assert_msg(s21_strspn("abcd", "abcd") == 4, "FAIL 1 TEST");
  ck_assert_msg(s21_strspn("abcd", "abc") == 3, "FAIL 2 TEST");
  ck_assert_msg(s21_strspn(s1, "abcd") == 0, "FAIL 3 TEST");
  ck_assert_msg(s21_strspn("", "") == 0, "FAIL 4 TEST");
  ck_assert_msg(s21_strspn(s7, s1) == 0, "FAIL 5 TEST");
}
END_TEST

START_TEST(test_strcspn) {
  ck_assert_msg(s21_strcspn("abcd", "abcd") == 0, "FAIL 1 TEST");
  ck_assert_msg(s21_strcspn("abcd", "abc") == 0, "FAIL 2 TEST");
  ck_assert_msg(s21_strcspn(s1, "abcd") == 0, "FAIL 3 TEST");
  ck_assert_msg(s21_strcspn("", "") == 0, "FAIL 4 TEST");
  ck_assert_msg(s21_strcspn(s7, s1) == 3, "FAIL 5 TEST");
  ck_assert_msg(s21_strcspn(s2, "b") == 1, "FAIL 6 TEST");
}
END_TEST

START_TEST(test_strstr) {
  ck_assert_msg(strcmp(s21_strstr(s2, s3), s3), "FAIL 1 TEST");
  ck_assert_msg(s21_strstr(s2, s4) == S21_NULL, "FAIL 2 TEST");
  ck_assert_msg(s21_strstr(s2, s7) == S21_NULL, "FAIL 3 TEST");
  ck_assert_msg(strcmp(s21_strstr(s2, "a"), "a"), "FAIL 4 TEST");
}
END_TEST

START_TEST(test_memchr) {
  ck_assert_msg(s21_memchr(s1, 'a', c) == memchr(s1, 'a', c), "FAIL 1 TEST");
  ck_assert_msg(s21_memchr(s2, 'a', c) == memchr(s2, 'a', c), "FAIL 2 TEST");
  ck_assert_msg(s21_memchr(s3, 0, c) == memchr(s3, 0, c), "FAIL 3 TEST");
  ck_assert_msg(s21_memchr(s5, '1', c) == memchr(s5, '1', c), "FAIL 4 TEST");
  ck_assert_msg(s21_memchr(s5, '\0', c) == memchr(s5, '\0', c), "FAIL 5 TEST");
}
END_TEST

START_TEST(test_memmove) {
  ck_assert_msg(s21_memmove(s1, "abcd", 2) == memmove(s1, "abcd", 2),
                "FAIL 1 TEST");
  ck_assert_msg(s21_memmove(s2, "123", 2) == memmove(s2, "123", 2),
                "FAIL 2 TEST");
  ck_assert_msg(s21_memmove(s3, "0", 2) == memmove(s3, "0", 2), "FAIL 3 TEST");
}
END_TEST

START_TEST(test_memset) {
  ck_assert_msg(s21_memset(s1, f, 2) == memset(s1, f, 2), "FAIL 1 TEST");
  ck_assert_msg(s21_memset(s2, d, 2) == memset(s2, d, 2), "FAIL 2 TEST");
  ck_assert_msg(s21_memset(s3, 'a', 2) == memset(s3, 'a', 2), "FAIL 3 TEST");
}
END_TEST

START_TEST(test_strtok) {
  char ss1[200] = "testtesttest", ss2[200] = "te", tmp1[200] = "testtesttest",
       tmp2[200] = "te";
  ck_assert_msg(strcmp(s21_strtok(ss1, ss2), strtok(tmp1, tmp2)) == 0,
                "FAIL 1 TEST");
  ck_assert_msg(strcmp(s21_strtok(S21_NULL, ss2), strtok(S21_NULL, tmp2)) == 0,
                "FAIL 2 TEST");
  ck_assert_msg(strcmp(s21_strtok(S21_NULL, ss2), strtok(S21_NULL, tmp2)) == 0,
                "FAIL 2 TEST");
}
END_TEST

START_TEST(test_strerror) {
  ck_assert_msg(strcmp(s21_strerror(1), "Operation not permitted") == 0,
                "FAIL 1 TEST");
  ck_assert_msg(s21_strerror(-1) == S21_NULL, "FAIL 2 TEST");
  ck_assert_msg(s21_strerror(1000) == S21_NULL, "FAIL 3 TEST");
}
END_TEST

Suite *suit_create(void) {
  Suite *suite = suite_create("test's of s21_string.h");

  TCase *s21_sprintf = tcase_create("s21_sprintf test's");
  tcase_add_test(s21_sprintf, test_sprintf_first);
  suite_add_tcase(suite, s21_sprintf);

  TCase *s21_sprintf_2 = tcase_create("s21_sprintf test's");
  tcase_add_test(s21_sprintf_2, test_sprintf_second);
  suite_add_tcase(suite, s21_sprintf_2);

  TCase *toupper = tcase_create("s21_toupper test's");
  tcase_add_test(toupper, test_toupper);
  suite_add_tcase(suite, toupper);

  TCase *tolower = tcase_create("s21_tolower test's");
  tcase_add_test(tolower, test_tolower);
  suite_add_tcase(suite, tolower);

  TCase *insert = tcase_create("s21_insert test's");
  tcase_add_test(insert, test_insert);
  suite_add_tcase(suite, insert);

  TCase *trim = tcase_create("s21_trim test's");
  tcase_add_test(trim, test_trim);
  suite_add_tcase(suite, trim);

  TCase *strcat = tcase_create("s21_strcat test's");
  tcase_add_test(strcat, test_strcat);
  suite_add_tcase(suite, strcat);

  TCase *strncat = tcase_create("s21_strncat test's");
  tcase_add_test(strncat, test_strncat);
  suite_add_tcase(suite, strncat);

  TCase *memcmp = tcase_create("s21_memcmp test's");
  tcase_add_test(memcmp, test_memcmp);
  suite_add_tcase(suite, memcmp);

  TCase *memcpy = tcase_create("s21_memcpy test's");
  tcase_add_test(memcpy, test_memcpy);
  suite_add_tcase(suite, memcpy);

  TCase *strchr = tcase_create("strcmp(s21_strchr test's");
  tcase_add_test(strchr, test_strchr);
  suite_add_tcase(suite, strchr);

  TCase *strcmp = tcase_create("s21_strcmp test's");
  tcase_add_test(strcmp, test_strcmp);
  suite_add_tcase(suite, strcmp);

  TCase *strncmp = tcase_create("s21_strncmp test's");
  tcase_add_test(strncmp, test_strncmp);
  suite_add_tcase(suite, strncmp);

  TCase *strpbrk = tcase_create("s21_strpbrk test's");
  tcase_add_test(strpbrk, test_strpbrk);
  suite_add_tcase(suite, strpbrk);

  TCase *strrchr = tcase_create("s21_strrchr test's");
  tcase_add_test(strrchr, test_strrchr);
  suite_add_tcase(suite, strrchr);

  TCase *strlen = tcase_create("s21_strlen test's");
  tcase_add_test(strlen, test_strlen);
  suite_add_tcase(suite, strlen);

  TCase *strcpy = tcase_create("s21_strcpy test's");
  tcase_add_test(strcpy, test_strcpy);
  suite_add_tcase(suite, strcpy);

  TCase *strncpy = tcase_create("s21_strncpy test's");
  tcase_add_test(strncpy, test_strncpy);
  suite_add_tcase(suite, strncpy);

  TCase *strspn = tcase_create("s21_strspn test's");
  tcase_add_test(strspn, test_strspn);
  suite_add_tcase(suite, strspn);

  TCase *strcspn = tcase_create("s21_strcspn test's");
  tcase_add_test(strcspn, test_strcspn);
  suite_add_tcase(suite, strcspn);

  TCase *strstr = tcase_create("s21_strstr test's");
  tcase_add_test(strstr, test_strstr);
  suite_add_tcase(suite, strstr);

  TCase *memchr = tcase_create("s21_memchr test's");
  tcase_add_test(memchr, test_memchr);
  suite_add_tcase(suite, memchr);

  TCase *memmove = tcase_create("s21_memmove test's");
  tcase_add_test(memmove, test_memmove);
  suite_add_tcase(suite, memmove);

  TCase *memset = tcase_create("s21_memsettest's");
  tcase_add_test(memset, test_memset);
  suite_add_tcase(suite, memset);

  TCase *strtok = tcase_create("s21_strtok test's");
  tcase_add_test(strtok, test_strtok);
  suite_add_tcase(suite, strtok);

  TCase *strerror = tcase_create("s21_strerror test's");
  tcase_add_test(strerror, test_strerror);
  suite_add_tcase(suite, strerror);

  return suite;
}

int main(void) {
  Suite *suite = suit_create();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  srunner_free(suite_runner);

  if (srunner_ntests_failed(suite_runner) != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
