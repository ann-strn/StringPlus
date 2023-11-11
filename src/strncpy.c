// 8. Копирует до n символов из строки, на которую указывает src, в dest.

#include "string.h"

char *strncpy(char *dest, const char *src, size_t n) {
  size_t src_len = strlen(src);
  size_t copy_len = n <= src_len ? n : (src_len + 1);

  for (size_t i = 0; i < copy_len; i++) {
    dest[i] = src[i];
  }
  return dest;
}
