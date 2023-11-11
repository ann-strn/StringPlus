// 4. Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
//  указывает аргумент str

#include "string.h"

void *memset(void *str, int c, size_t n) {
  for (size_t i = 0; i < n; i++) {
    *((char *)str + i) = c;
  }
  return str;
}
