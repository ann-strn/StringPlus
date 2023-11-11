// 13. Выполняет поиск последнего вхождения символа c (беззнаковый тип) в
// строке, на которую указывает аргумент str.

#include "string.h"

char *strrchr(const char *str, int c) {
  const char *res = NULL;
  int len = 0;
  while (*str != '\0') {
    str++;
    len++;
  }
  while (len >= 0) {
    if (*str == c) {
      res = str;
      break;
    }
    str--;
    len--;
  }
  return (char *)res;
}
