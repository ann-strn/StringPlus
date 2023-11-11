// 6. Выполняет поиск первого вхождения символа c(беззнаковый тип) в строке,
//     на которую указывает аргумент str.

#include "string.h"

char *strchr(const char *str, int c) {
  char *res = (char *)NULL;
  for (size_t i = 0; i < strlen(str) + 1; i++) {
    if (*((char *)str + i) == c) {
      res = (char *)str + i;
      break;
    }
  }
  return res;
}
