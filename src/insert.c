// 5.3. Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL

#include "string.h"

void *insert(const char *src, const char *str, size_t start_index) {
  char *result = NULL;
  if (str != NULL && src != NULL) {
    s21_size_t size = strlen(src) + strlen(str);
    s21_size_t end_index = start_index + strlen(str);
    result = (char *)calloc(size + 1, sizeof(char));
    if (result != NULL && start_index < strlen(src)) {
      for (s21_size_t i = 0; i < start_index; i++) result[i] = src[i];
      for (s21_size_t i = start_index, j = 0; i < end_index; i++, j++)
        result[i] = str[j];
      for (size_t i = end_index, j = start_index; i < size; i++, j++)
        result[i] = src[j];
    } else
      result = NULL;
  }
  return result;
  free(result);
}
