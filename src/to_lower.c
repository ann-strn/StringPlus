// 5Возвращает копию строки (str), преобразованной в нижний регистр. В случае
// какой-либо ошибки следует вернуть значение NULL

#include "string.h"

void *to_lower(const char *str) {
  char *result = NULL;
  result = (char *)malloc((strlen(str) + 1) * sizeof(char));
  size_t i = 0;
  for (; i < strlen(str); i++) {
    if (str[i] <= 90 && str[i] >= 65)
      result[i] = str[i] + 32;
    else
      result[i] = str[i];
  }
  result[i] = '\0';
  return (void *)result;
}
