// 2. Сравнивает первые n байтов str1 и str2.

#include "string.h"

int memcmp(const void *str1, const void *str2, size_t n) {
  int result = 0;
  for (size_t i = 0; i < n; i++) {
    if (*((char *)str1 + i) != *((char *)str2 + i)) {
      result = *((char *)str1 + i) - *((char *)str2 + i);
      break;
    }
  }
  return result;
}
