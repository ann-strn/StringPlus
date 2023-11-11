// 3. Копирует n символов из src в dest

#include "string.h"

void *memcpy(void *dest, const void *src, size_t n) {
  unsigned char *cpy_dest = (unsigned char *)dest;
  const unsigned char *cpy_src = (unsigned char *)src;

  for (size_t i = 0; i < n; i++) {
    cpy_dest[i] = cpy_src[i];
  }
  return dest;
}
