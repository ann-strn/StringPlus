// 9. Вычисляет длину начального сегмента str1, который полностью состоит из
// символов, не входящих в str2.

#include "string.h"

size_t strcspn(const char *str1, const char *str2) {
  size_t i = 0;
  for (; i < strlen(str1); i++)
    if (strchr(str2, str1[i])) break;
  return i;
}
