// 5. Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов.

#include "string.h"

char *strncat(char *dest, const char *src, size_t n) {
  size_t dest_len = strlen(dest);
  for (size_t i = 0; i < n && i < strlen(src); i++, dest_len++) {
    dest[dest_len] = src[i];
  }
  dest[dest_len] = '\0';

  return dest;
}
