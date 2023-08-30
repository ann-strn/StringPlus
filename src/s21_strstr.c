// 14. Находит первое вхождение всей строки needle (не включая завершающий
// нулевой символ), которая появляется в строке haystack.

#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') {
    return (char *)haystack;
  }
  while (*haystack) {
    const char *h = haystack;
    const char *n = needle;
    while (*h && *n && *h == *n) {
      h++;
      n++;
    }
    if (*n == '\0') {
      return (char *)haystack;
    }
    haystack++;
  }
  return s21_NULL;
}
