// 5.1. Возвращает копию строки(str), преобразованной в верхний регистр.В случае
// какой-либо ошибки следует вернуть значение NULL

#include "string.h"

void *to_upper(const char *str) {
  char *result = NULL;
  result = (char *)malloc((strlen(str) + 1) * sizeof(char));
  size_t i = 0;
  for (; i < strlen(str); i++) {
    if (str[i] >= 97 && str[i] <= 122)
      result[i] = str[i] - 32;
    else
      result[i] = str[i];
  }
  result[i] = '\0';
  return (void *)result;
}
