#include "../test.h"

#include "ecma402/util.h"

#define TEST_SUITE ecma402Util

Test(TEST_SUITE, sortAndRemoveDuplicatesWithStrToLowerCallback) {
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

  const int originalCount = 30, expectedCount = 19;
  int i, newCount;

  const char **items;
  items = malloc(sizeof(char *) * originalCount);
  for (i = 0; i < originalCount; i++) {
    items[i] = malloc(sizeof(char) * (strlen(values[i]) + 1));
    strcpy((char *)items[i], values[i]);
  }

  newCount = ecma402_sortAndRemoveDuplicates((char **)items, originalCount,
                                             ecma402_strToLower);

  cr_expect(eq(i8, newCount, expectedCount));

  for (i = 0; i < expectedCount; ++i) {
    cr_expect(eq(str, (char *)items[i], (char *)expected[i]));
  }

  free(items);
}

Test(TEST_SUITE, sortAndRemoveDuplicatesWithStrToUpperCallback) {
  const char *values[] = {
      "standard", "standard", "stroke", "PINYIN",   "trad",    "ReFormed",
      "unihan",   "DICT",     "zhuyin", "phonetic", "pinyin",  "reformed",
      "comPAT",   "Eor",      "direct", "search",   "Dict",    "searchjl",
      "big5han",  "compat",   "dict",   "GB2312",   "stroke",  "direct",
      "ducet",    "eor",      "Trad",   "gb2312",   "phonebk", "emoji",
  };

  const char *expected[] = {
      "BIG5HAN", "COMPAT",   "DICT",   "DIRECT",   "DUCET",
      "EMOJI",   "EOR",      "GB2312", "PHONEBK",  "PHONETIC",
      "PINYIN",  "REFORMED", "SEARCH", "SEARCHJL", "STANDARD",
      "STROKE",  "TRAD",     "UNIHAN", "ZHUYIN",
  };

  const int originalCount = 30, expectedCount = 19;
  int i, newCount;

  const char **items;
  items = malloc(sizeof(char *) * originalCount);
  for (i = 0; i < originalCount; i++) {
    items[i] = malloc(sizeof(char) * (strlen(values[i]) + 1));
    strcpy((char *)items[i], values[i]);
  }

  newCount = ecma402_sortAndRemoveDuplicates((char **)items, originalCount,
                                             ecma402_strToUpper);

  cr_expect(eq(i8, newCount, expectedCount));

  for (i = 0; i < expectedCount; ++i) {
    cr_expect(eq(str, (char *)items[i], (char *)expected[i]));
  }

  free(items);
}

Test(TEST_SUITE, sortAndRemoveDuplicatesWithNoCallback) {
  const char *values[] = {
      "standard", "standard", "stroke", "PINYIN",   "trad",    "ReFormed",
      "unihan",   "DICT",     "zhuyin", "phonetic", "pinyin",  "reformed",
      "comPAT",   "Eor",      "direct", "search",   "Dict",    "searchjl",
      "big5han",  "compat",   "dict",   "GB2312",   "stroke",  "direct",
      "ducet",    "eor",      "Trad",   "gb2312",   "phonebk", "emoji",
  };

  const char *expected[] = {
      "DICT",   "Dict",     "Eor",    "GB2312",   "PINYIN",   "ReFormed",
      "Trad",   "big5han",  "comPAT", "compat",   "dict",     "direct",
      "ducet",  "emoji",    "eor",    "gb2312",   "phonebk",  "phonetic",
      "pinyin", "reformed", "search", "searchjl", "standard", "stroke",
      "trad",   "unihan",   "zhuyin",
  };

  const int originalCount = 30, expectedCount = 27;
  int i, newCount;

  const char **items;
  items = malloc(sizeof(char *) * originalCount);
  for (i = 0; i < originalCount; i++) {
    items[i] = malloc(sizeof(char) * (strlen(values[i]) + 1));
    strcpy((char *)items[i], values[i]);
  }

  newCount =
      ecma402_sortAndRemoveDuplicates((char **)items, originalCount, NULL);

  cr_expect(eq(i8, newCount, expectedCount));

  for (i = 0; i < expectedCount; ++i) {
    cr_expect(eq(str, (char *)items[i], (char *)expected[i]));
  }

  free(items);
}

Test(TEST_SUITE, strToLower) {
  char value[] = "Foo, Bar, Baz, Qux!";
  char expected[] = "foo, bar, baz, qux!";

  ecma402_strToLower(value);

  cr_expect(eq(str, value, expected));
}

Test(TEST_SUITE, strToUpper) {
  char value[] = "Foo, Bar, Baz, Qux!";
  char expected[] = "FOO, BAR, BAZ, QUX!";

  ecma402_strToUpper(value);

  cr_expect(eq(str, value, expected));
}
