// 15. Разбивает строку str на ряд токенов, разделенных delim

#include "string.h"

char *strtok(char *str, const char *delim) {
  static char *nextToken = NULL;
  static char *prevToken = NULL;

  if (str != NULL) {
    nextToken = str;
    prevToken = NULL;
  }

  if (nextToken == NULL || *nextToken == '\0') {
    return NULL;
  }

  char *tokenStart = nextToken;

  while (*tokenStart && strrchr(delim, *tokenStart) != NULL) {
    tokenStart++;
  }

  if (*tokenStart == '\0') {
    nextToken = NULL;
  } else {
    prevToken = tokenStart;
    nextToken = strpbrk(tokenStart, delim);
    if (nextToken != NULL) {
      *nextToken = '\0';
      nextToken++;
    }
  }

  return prevToken;
}
