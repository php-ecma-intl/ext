#include "src/ecma402/util.h"
#include "tests/criterion/test.h"

#define TEST_SUITE ecma402Util

Test(TEST_SUITE, sortsAndRemovesDuplicateValues) {
  const char *values[] = {
      "standard", "standard", "stroke", "PINYIN",   "trad",    "ReFormed",
      "unihan",   "DICT",     "zhuyin", "phonetic", "pinyin",  "reformed",
      "comPAT",   "Eor",      "direct", "search",   "Dict",    "searchjl",
      "big5han",  "compat",   "dict",   "GB2312",   "stroke",  "direct",
      "ducet",    "eor",      "Trad",   "gb2312",   "phonebk", "emoji",
  };

  const char *expected[] = {
      "big5han", "compat",   "dict",   "direct",   "ducet",
      "emoji",   "eor",      "gb2312", "phonebk",  "phonetic",
      "pinyin",  "reformed", "search", "searchjl", "standard",
      "stroke",  "trad",     "unihan", "zhuyin",
  };

  int i, newLength, originalLength = 30, expectedLength = 19;

  const char **items;
  items = malloc(sizeof(char *) * originalLength);
  for (i = 0; i < originalLength; i++) {
    items[i] = malloc(sizeof(char) * (strlen(values[i]) + 1));
    strcpy((char *)items[i], values[i]);
  }

  newLength = sortAndRemoveDuplicates((char **)items, originalLength);

  cr_expect(eq(i8, newLength, expectedLength));

  for (i = 0; i < expectedLength; ++i) {
    cr_expect(eq(str, (char *)items[i], (char *)expected[i]));
  }

  free(items);
}
