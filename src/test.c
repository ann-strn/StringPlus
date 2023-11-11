#include <check.h>
#include <string.h>

#include "string.h"

START_TEST(strlen_test) {
  int n = 6;
  char *str[] = {"qazxsw",      ";;;;;;;;;;;;;;;", "schooll 21",
                 "QQQQQQQQQQQ", "1234567890",      "lana annnnnna"};
  for (int i = 0; i < n; i++) {
    ck_assert_int_eq(strlen(str[i]), strlen(str[i]));
  }
  char str2[] = "\0";
  char str3[] = "     ";
  ck_assert_int_eq(strlen(str2), strlen(str2));
  ck_assert_int_eq(strlen(str3), strlen(str3));
}
END_TEST

START_TEST(strerror_test) {
  for (int i = -100; i < 250; i++) {
    ck_assert_str_eq(strerror(i), strerror(i));
  }
  char ch = '?';
  ck_assert_str_eq(strerror(ch), strerror(ch));
  ck_assert_str_eq(strerror(-1000), strerror(-1000));
  ck_assert_str_eq(strerror(0), strerror(0));
}
END_TEST

START_TEST(memchr_test) {
  char src[] = "01234567890";
  for (int i = 48; i <= 57; i++) {
    ck_assert_ptr_eq(memchr(src, (char)i, 10), memchr(src, (char)i, 10));
  }

  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 97; i <= 122; i++) {
    ck_assert_ptr_eq(memchr(alphabet, (char)i, 25),
                     memchr(alphabet, (char)i, 25));
  }

  char alphabet_upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i = 65; i <= 90; i++) {
    ck_assert_ptr_eq(memchr(alphabet_upper, (char)i, 25),
                     memchr(alphabet_upper, (char)i, 25));
  }

  char nan[] = "AAAAAAAA";
  ck_assert_ptr_eq(memchr(nan, 'a', 10), memchr(nan, 'a', 10));
  ck_assert_ptr_eq(memchr(nan, 'A', 10), memchr(nan, 'A', 10));
  ck_assert_ptr_eq(memchr(nan, 'B', 10), memchr(nan, 'B', 10));
}
END_TEST

START_TEST(memcpy_test) {
  char dest[100];
  char string[] = "01234567890123456789";
  for (size_t i = 2; i < 20; i++) {
    ck_assert_ptr_eq(memcpy(dest, string, i), memcpy(dest, string, i));
  }
}
END_TEST

START_TEST(strrchr_test) {
  char str[100] = "1234567890";
  for (int i = 48; i <= 57; i++) {
    char *ptr1 = strrchr(str, i);
    char *orig1 = strrchr(str, i);
    ck_assert_str_eq(ptr1, orig1);
  }

  char str1[100] = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 97; i <= 122; i++) {
    char *ptr1 = strrchr(str1, i);
    char *orig1 = strrchr(str1, i);
    ck_assert_str_eq(ptr1, orig1);
  }

  char str2[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i = 65; i <= 90; i++) {
    char *ptr1 = strrchr(str2, i);
    char *orig1 = strrchr(str2, i);
    ck_assert_str_eq(ptr1, orig1);
  }
}
END_TEST

START_TEST(strncmp_test) {
  char str1[] = "abcdefghijklmnopqrstuvwxyz";
  char str2[] = "abcdyfghijklmnopqrstuvwxyz";

  int my1 = strncmp(str1, str2, 3) > 0 ? 1 : -1;
  int orig1 = strncmp(str1, str2, 3) > 0 ? 1 : -1;
  ck_assert_int_eq(orig1, my1);

  int my2 = strncmp(str1, str2, 5) > 0 ? 1 : -1;
  int orig2 = strncmp(str1, str2, 5) > 0 ? 1 : -1;
  ck_assert_int_eq(orig2, my2);

  int my3 = strncmp(str1, str2, 20) > 0 ? 1 : -1;
  int orig3 = strncmp(str1, str2, 20) > 0 ? 1 : -1;
  ck_assert_int_eq(orig3, my3);

  int my4 = strncmp(str1, str2, 10) > 0 ? 1 : -1;
  int orig4 = strncmp(str1, str2, 10) > 0 ? 1 : -1;
  ck_assert_int_eq(orig4, my4);
}
END_TEST

START_TEST(strncat_test) {
  char syms[100] = "0123456789";
  char syms_reverse[100] = "9876543210";
  char string[100] = "01234567890123456789";
  char alphabet_upper[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char no_syms[100] = "";

  ck_assert_str_eq(strncat(syms, syms_reverse, 10),
                   strncat(syms, syms_reverse, 10));
  ck_assert_str_eq(strncat(string, alphabet_upper, 1),
                   strncat(string, alphabet_upper, 1));
  ck_assert_str_eq(strncat(syms, alphabet_upper, 5),
                   strncat(syms, alphabet_upper, 5));
  ck_assert_str_eq(strncat(no_syms, alphabet_upper, 3),
                   strncat(no_syms, alphabet_upper, 3));
}
END_TEST

START_TEST(strncpy_test) {
  char str1[100] = "abcdefghijklmnopqrstuvwxyz";
  char str1_cp[25] = {0};
  char str2[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char str2_cp[25] = {0};
  char str3[100] = "1234567890";
  char str3_cp[10] = "9876543210";

  ck_assert_str_eq(strncpy(str1_cp, str1, 3), strncpy(str1_cp, str1, 3));
  ck_assert_str_eq(strncpy(str1_cp, str1, 10), strncpy(str1_cp, str1, 10));
  ck_assert_str_eq(strncpy(str2_cp, str2, 5), strncpy(str2_cp, str2, 5));
  ck_assert_str_eq(strncpy(str2_cp, str2, 15), strncpy(str2_cp, str2, 15));
  ck_assert_str_eq(strncpy(str3_cp, str3, 1), strncpy(str3_cp, str3, 1));
  ck_assert_str_eq(strncpy(str3_cp, str3, 10), strncpy(str3_cp, str3, 10));
}
END_TEST

START_TEST(strcspn_test) {
  char str1[] = "0123456789";
  char str1_in[] = "987";

  char str2[] = "abced";
  char str2_in[] = "ecd";

  char str3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char str3_in[] = "XYZ";
  char str3_not[] = "abc";

  ck_assert_int_eq(strcspn(str1, str1_in), strcspn(str1, str1_in));
  ck_assert_int_eq(strcspn(str2, str2_in), strcspn(str2, str2_in));
  ck_assert_int_eq(strcspn(str3, str3_in), strcspn(str3, str3_in));
  ck_assert_int_eq(strcspn(str3, str3_not), strcspn(str3, str3_not));
}
END_TEST

START_TEST(strpbrk_test) {
  char str1[] = "0123456789";
  char str1_in[] = "987";

  char str2[] = "abced";
  char str2_in[] = "ecd";

  char str3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char str3_in[] = "XYZ";
  char str3_in2[] = "ZYX";

  ck_assert_str_eq(strpbrk(str1, str1_in), strpbrk(str1, str1_in));
  ck_assert_str_eq(strpbrk(str2, str2_in), strpbrk(str2, str2_in));
  ck_assert_str_eq(strpbrk(str3, str3_in), strpbrk(str3, str3_in));
  ck_assert_str_eq(strpbrk(str3, str3_in2), strpbrk(str3, str3_in2));
}
END_TEST

START_TEST(strstr_test) {
  char str1[] = "0123456789";
  char str1_in[] = "789";

  char str2[] = "abced";
  char str2_in[] = "d";

  char str3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char str3_in[] = "XYZ";

  char str4[] = "0123456789";
  char str4_in[] = "345";

  ck_assert_str_eq(strstr(str1, str1_in), strstr(str1, str1_in));
  ck_assert_str_eq(strstr(str2, str2_in), strstr(str2, str2_in));
  ck_assert_str_eq(strstr(str3, str3_in), strstr(str3, str3_in));
  ck_assert_str_eq(strstr(str4, str4_in), strstr(str4, str4_in));
}
END_TEST

START_TEST(to_upper_test) {
  char str1[] = "alexey, you are an idiot, ok?";

  char *str1_upper = to_upper(str1);

  if (str1_upper) {
    ck_assert_str_eq("ALEXEY, YOU ARE AN IDIOT, OK?", str1_upper);
  }
  free(str1_upper);
}
END_TEST

START_TEST(to_lower_test) {
  char str1[] = "ALEXEY, YOU ARE AN IDIOT, OK?";

  char *str1_lower = to_lower(str1);

  if (str1_lower) {
    ck_assert_str_eq("alexey, you are an idiot, ok?", str1_lower);
  }
  free(str1_lower);
}
END_TEST

START_TEST(memset_test) {
  char str1[] = "0123456789";

  for (size_t i = 65; i < 90; i++) {
    ck_assert_str_eq(memset(str1, i, strlen(str1)),
                     memset(str1, i, strlen(str1)));
  }

  char str2[] = "abcdefghijklmnopqrstuvwxyzABCABCABC";
  size_t j = 3;
  for (size_t i = 97; i < 122; i++) {
    ck_assert_str_eq(memset(str2, i, j), memset(str2, i, j));
    j++;
  }
}
END_TEST

START_TEST(strtok_test) {
  char str1[] = "kek@lol@arbidol";
  char str1_delim[] = "@";

  char str2[] = "alexey/dog/snoop";
  char str2_delim[] = "/";

  char str3[] = "i&love&school&21";
  char str3_delim[] = "&";

  char str4[] = "^_^i^_^hate^_^strtok^_^!^_^";
  char str4_delim[] = "^_^";

  char str5[] = ".A...A...A...A.";
  char str5_delim[] = ".";

  char str6[] = "12345";
  char str6_delim[] = "1234";

  char str7[] = "12345";
  char str7_delim[] = "\0";

  char str8[] = "12345";
  char str8_delim[] = "?";

  char str9[] = "a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z";
  char str9_delim[] = ",";
  char *parts = strtok(str9, str9_delim);
  while (parts) {
    ck_assert_str_eq(strtok(str9, str9_delim), strtok(str9, str9_delim));
    parts = strtok(NULL, str9_delim);
  }

  ck_assert_str_eq(strtok(str1, str1_delim), strtok(str1, str1_delim));
  ck_assert_str_eq(strtok(str2, str2_delim), strtok(str2, str2_delim));
  ck_assert_str_eq(strtok(str3, str3_delim), strtok(str3, str3_delim));
  ck_assert_str_eq(strtok(str4, str4_delim), strtok(str4, str4_delim));
  ck_assert_str_eq(strtok(str5, str5_delim), strtok(str5, str5_delim));
  ck_assert_str_eq(strtok(str6, str6_delim), strtok(str6, str6_delim));
  ck_assert_str_eq(strtok(str7, str7_delim), strtok(str7, str7_delim));
  ck_assert_str_eq(strtok(str8, str8_delim), strtok(str8, str8_delim));
}
END_TEST

START_TEST(memcmp_test) {
  char str1[] = "0123456789";
  char str1_cmp[] = "0123456789";

  char str2[] = "abAdefghijklmnopqrstuvwxyz";
  char str2_cmp[] = "abAdefghijklmnopqrstuvwxyz";

  char str3[] = "12345";
  char str3_cmp[] = "54321";

  char str4[] = "ABCDE";
  char str4_cmp[] = "EDCBA";

  int originalTest1 = memcmp(str1, str1_cmp, strlen(str1)) > 0 ? 1 : -1;
  int myTest1 = memcmp(str1, str1_cmp, strlen(str1)) > 0 ? 1 : -1;

  int originalTest2 = memcmp(str2, str2_cmp, strlen(str2)) > 0 ? 1 : -1;
  int myTest2 = memcmp(str2, str2_cmp, strlen(str2)) > 0 ? 1 : -1;

  int originalTest3 = memcmp(str3, str3_cmp, strlen(str3)) > 0 ? 1 : -1;
  int myTest3 = memcmp(str3, str3_cmp, strlen(str3)) > 0 ? 1 : -1;

  int originalTest4 = memcmp(str4, str4_cmp, strlen(str4)) > 0 ? 1 : -1;
  int myTest4 = memcmp(str4, str4_cmp, strlen(str4)) > 0 ? 1 : -1;

  ck_assert_int_eq(originalTest1, myTest1);
  ck_assert_int_eq(originalTest2, myTest2);
  ck_assert_int_eq(originalTest3, myTest3);
  ck_assert_int_eq(originalTest4, myTest4);
}
END_TEST

START_TEST(test_trim) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *s2 = trim(s1, s3);
  ck_assert_str_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_insert) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char s4[] = "hello, hELLO, WORLD!world!";
  size_t num = 7;
  char *s2 = insert(s1, s3, num);
  ck_assert_str_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(sprintf_test) {
  char str1[1000];
  char str2[1000];
  char format[] = "This is a simple value %d";
  int val = 69;
  sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_plus_width_int) {
  char str1[1000];
  char str2[1000];

  char *format = "%+12d";
  int val = 69;
  sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_padding_int) {
  char str1[1000];
  char str2[1000];

  char *format = "%+12d";
  int val = 69;
  sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_zero_precision_zero_int) {
  char str1[1000];
  char str2[1000];

  char *format = "%.0d";
  int val = 0;
  sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_space_flag_int) {
  char str1[1000];
  char str2[1000];

  char *format = "% d";
  int val = 0;
  sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val) {
  char str1[1000];
  char str2[1000];
  char *format = "%u";
  unsigned int val = 14140;
  sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_width) {
  char str1[1000];
  char str2[1000];
  char *format = "%15u";
  unsigned int val = 14140;
  sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_flags) {
  char str1[1000];
  char str2[1000];

  char *format = "%-16u";
  unsigned int val = 14140;
  sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_precision) {
  char str1[1000];
  char str2[1000];
  char *format = "%.51u";
  unsigned int val = 14140;
  sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many_flags) {
  char str1[1000];
  char str2[1000];
  char *format = "% 5.51u";
  unsigned int val = 14140;
  sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_short) {
  char str1[1000];
  char str2[1000];

  char *format = "%hu";
  unsigned short int val = 14140;
  sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_long) {
  char str1[1000];
  char str2[1000];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many) {
  char str1[1000];
  char str2[1000];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  sprintf(str1, format, val, 14, 1441, 14414, 9681);

  sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
          (unsigned)14414, (unsigned)9681);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_short) {
  char str1[1000];
  char str2[1000];

  char *format = "%hd";
  short int val = 14140;
  sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_zero) {
  char str1[1000];
  char str2[1000];

  char *format = "%u";
  sprintf(str1, format, 0);

  sprintf(str2, format, (unsigned)0);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string) {
  char str1[1000];
  char str2[1000];

  char *format = "%s";
  char *string = "denis classniy";
  sprintf(str1, format, string);
  sprintf(str2, format, string);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_precision) {
  char str1[1000];
  char str2[1000];

  char *format = "%.4s";
  char *string = "denis classniy";
  sprintf(str1, format, string);
  sprintf(str2, format, string);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string__width) {
  char str1[1000];
  char str2[1000];

  char *format = "%25s";
  char *string = "denis classniy";
  sprintf(str1, format, string);
  sprintf(str2, format, string);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_minus) {
  char str1[1000];
  char str2[1000];

  char *format = "%-25s";
  char *string = "denis classniy";
  sprintf(str1, format, string);
  sprintf(str2, format, string);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char) {
  char str1[1000];
  char str2[1000];

  char *format = "%c";
  char sym = '!';
  sprintf(str1, format, sym);
  sprintf(str2, format, sym);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char_width) {
  char str1[1000];
  char str2[1000];

  char *format = "%5c";
  char sym = '!';
  sprintf(str1, format, sym);
  sprintf(str2, format, sym);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char_minus) {
  char str1[1000];
  char str2[1000];

  char *format = "%-5c";
  char sym = '!';
  sprintf(str1, format, sym);
  sprintf(str2, format, sym);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprint_string_null) {
  char str1[1000];
  char str2[1000];

  char *format = "%s";
  char *string = NULL;
  sprintf(str1, format, string);
  sprintf(str2, format, string);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float) {
  char str1[1000];
  char str2[1000];

  char *format = "%f";
  double num = 1.9;
  sprintf(str1, format, num);
  sprintf(str2, format, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_zero) {
  char str1[1000];
  char str2[1000];

  char *format = "%f";
  double zero = 0;
  sprintf(str1, format, zero);
  sprintf(str2, format, zero);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_double_min) {
  char str1[1000];
  char str2[1000];

  char *format = "%lf";
  double num = 1E-12;
  sprintf(str1, format, num);
  sprintf(str2, format, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_double) {
  char str1[1000];
  char str2[1000];

  char *format = "%lf";
  double negative = -0.34834493943;
  sprintf(str1, format, negative);
  sprintf(str2, format, negative);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_double_negative) {
  char str1[1000];
  char str2[1000];

  char *format = "%lf";
  double num = -10.934;
  sprintf(str1, format, num);
  sprintf(str2, format, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_double_nan) {
  char str1[1000];
  char str2[1000];

  char *format = "%lf";
  double nan = NAN;
  sprintf(str1, format, nan);
  sprintf(str2, format, nan);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_percent) {
  char str1[1000];
  char str2[1000];

  char *format = "%%lf";
  long double num = 0;
  sprintf(str1, format, num);
  sprintf(str2, format, num);
  ck_assert_str_eq(str1, str2);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, strlen_test);
  tcase_add_test(tc1_1, strerror_test);
  tcase_add_test(tc1_1, memchr_test);
  tcase_add_test(tc1_1, memcpy_test);
  tcase_add_test(tc1_1, strrchr_test);
  tcase_add_test(tc1_1, strncmp_test);
  tcase_add_test(tc1_1, strncat_test);
  tcase_add_test(tc1_1, strncpy_test);
  tcase_add_test(tc1_1, strcspn_test);
  tcase_add_test(tc1_1, strpbrk_test);
  tcase_add_test(tc1_1, strstr_test);
  tcase_add_test(tc1_1, to_upper_test);
  tcase_add_test(tc1_1, to_lower_test);
  tcase_add_test(tc1_1, memset_test);
  tcase_add_test(tc1_1, strtok_test);
  tcase_add_test(tc1_1, memcmp_test);
  tcase_add_test(tc1_1, test_trim);
  tcase_add_test(tc1_1, test_insert);

  tcase_add_test(tc1_1, sprintf_test);
  tcase_add_test(tc1_1, sprintf_plus_width_int);
  tcase_add_test(tc1_1, sprintf_padding_int);
  tcase_add_test(tc1_1, sprintf_zero_precision_zero_int);
  tcase_add_test(tc1_1, sprintf_space_flag_int);
  tcase_add_test(tc1_1, sprintf_unsigned_val);
  tcase_add_test(tc1_1, sprintf_unsigned_val_width);
  tcase_add_test(tc1_1, sprintf_unsigned_val_flags);
  tcase_add_test(tc1_1, sprintf_unsigned_val_precision);
  tcase_add_test(tc1_1, sprintf_unsigned_val_many_flags);
  tcase_add_test(tc1_1, sprintf_unsigned_val_short);
  tcase_add_test(tc1_1, sprintf_unsigned_val_long);
  tcase_add_test(tc1_1, sprintf_unsigned_val_many);
  tcase_add_test(tc1_1, sprintf_octal_short);
  tcase_add_test(tc1_1, sprintf_unsigned_zero);
  tcase_add_test(tc1_1, sprintf_string);
  tcase_add_test(tc1_1, sprintf_string_precision);
  tcase_add_test(tc1_1, sprintf_string__width);
  tcase_add_test(tc1_1, sprintf_string_minus);
  tcase_add_test(tc1_1, sprintf_char);
  tcase_add_test(tc1_1, sprintf_char_width);
  tcase_add_test(tc1_1, sprintf_char_minus);
  tcase_add_test(tc1_1, sprint_string_null);
  tcase_add_test(tc1_1, sprintf_float);
  tcase_add_test(tc1_1, sprintf_float_zero);
  tcase_add_test(tc1_1, sprintf_double_min);
  tcase_add_test(tc1_1, sprintf_double);
  tcase_add_test(tc1_1, sprintf_double_negative);
  tcase_add_test(tc1_1, sprintf_double_nan);
  tcase_add_test(tc1_1, sprintf_percent);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
