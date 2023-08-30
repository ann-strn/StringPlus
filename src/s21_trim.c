// 5.4. Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src). В
// случае какой-либо ошибки следует вернуть значение NULL

#include "s21_string.h"

int find_mismatch(const char *src, const char *trim_chars, int i) {
  int position = -1;
  for (int j = 0; trim_chars[j]; j++) {
    if (src[i] == trim_chars[j]) {
      position = -1;
      break;
    } else
      position = i;
  }
  return position;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = s21_NULL;
  if (src != s21_NULL && trim_chars != s21_NULL) {
    int size = s21_strlen(src);
    int start = -1, end = -1;
    for (int i = 0; i < size; i++) {
      start = find_mismatch(src, trim_chars, i);
      if (start != -1) break;
    }
    for (int i = size - 1; i >= 0; i--) {
      end = find_mismatch(src, trim_chars, i);
      if (end != -1) break;
    }
    if (start > end)
      result = "";
    else if (start == -1 && end == -1) {
      result = (char *)calloc(size + 1, sizeof(char));
      if (result != s21_NULL) {
        for (int i = 0; i < size; i++) result[i] = src[i];
      }
    } else {
      result = (char *)calloc(end - start + 2, sizeof(char));
      if (result != s21_NULL) {
        for (int i = 0; start <= end; start++, i++) result[i] = src[start];
      }
    }
  }
  return result;
}