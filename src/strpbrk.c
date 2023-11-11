// 12. Находит первый символ в строке str1, который соответствует любому
// символу, указанному в str2.

#include "string.h"

char *strpbrk(const char *str1, const char *str2) {
  char *res = NULL;
  for (; *str1 != '\0'; str1++) {
    if (strchr(str2, *str1)) {
      res = (char *)str1;
      break;
    }
  }
  return res;
}
