/*
   +----------------------------------------------------------------------+
   | ecma_intl extension for PHP                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) Ben Ramsey <ben@benramsey.com>                         |
   | This source file is subject to the MIT license that is bundled with  |
   | this package in the file LICENSE, and is available at the following  |
   | web address: https://opensource.org/license/mit/                     |
   +----------------------------------------------------------------------+
*/

#include "util.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static void sort(char **array, int length);
static int compareStrings(const void *left, const void *right);
static int removeDuplicates(char **array, int length);
static void toLower(char **array, int length);

int sortAndRemoveDuplicates(char **array, int length) {
  sort(array, length);
  toLower(array, length);
  return removeDuplicates(array, length);
}

static int removeDuplicates(char **array, int length) {
  int i, j, k, originalLength = length;

  for (i = 0; i < length; i++) {
    for (j = i + 1; j < length; j++) {
      if (strcasecmp(array[i], array[j]) == 0) {
        for (k = j; k < length - 1; k++) {
          array[k] = array[k + 1];
        }
        length--;
        j--;
      }
    }
  }

  if ((originalLength - length) > 0) {
    for (i = length; i < originalLength; i++) {
      array[i] = NULL;
    }
  }

  return length;
}

static void sort(char **array, int length) {
  qsort(array, length, sizeof(const char *), compareStrings);
}

static int compareStrings(const void *left, const void *right) {
  return strcasecmp(*(const char **)left, *(const char **)right);
}

static void toLower(char **array, int length) {
  int i, j;

  for (i = 0; i < length; i++) {
    size_t slen = strlen(array[i]);
    for (j = 0; j < slen; j++) {
      array[i][j] = tolower(array[i][j]);
    }
  }
}
