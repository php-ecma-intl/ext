#include "../test.h"

#include "ecma402/util.h"

#define TEST_SUITE ecma402Util

// NOLINTBEGIN(cert-err58-cpp, misc-const-correctness,
//             misc-use-anonymous-namespace)

using string =
    std::basic_string<char, std::char_traits<char>, criterion::allocator<char>>;

Test(TEST_SUITE, removeDuplicatesWithoutCallback) {
  const char *values[] = {
      "standard", "standard", "stroke", "PINYIN",   "trad",    "ReFormed",
      "unihan",   "DICT",     "zhuyin", "phonetic", "pinyin",  "reformed",
      "comPAT",   "Eor",      "direct", "search",   "Dict",    "searchjl",
      "big5han",  "compat",   "dict",   "GB2312",   "stroke",  "direct",
      "ducet",    "eor",      "Trad",   "gb2312",   "phonebk", "emoji",
  };

  const char *expected[] = {
      "standard", "stroke",  "PINYIN",   "trad",   "ReFormed", "unihan",
      "DICT",     "zhuyin",  "phonetic", "pinyin", "reformed", "comPAT",
      "Eor",      "direct",  "search",   "Dict",   "searchjl", "big5han",
      "compat",   "dict",    "GB2312",   "ducet",  "eor",      "Trad",
      "gb2312",   "phonebk", "emoji",
  };

  const int originalCount = 30, expectedCount = 27;
  int i, newCount;

  const char **items;
  items = (const char **)malloc(sizeof(char *) * originalCount);
  for (i = 0; i < originalCount; i++) {
    items[i] = (const char *)malloc(sizeof(char) * (strlen(values[i]) + 1));
    strcpy((char *)items[i], values[i]);
  }

  newCount = ecma402_removeDuplicates((char **)items, originalCount, NULL);

  cr_expect(eq(i8, newCount, expectedCount));

  for (i = 0; i < expectedCount; ++i) {
    cr_expect(eq(str, (char *)items[i], (char *)expected[i]));
  }

  free(items);
}

Test(TEST_SUITE, removeDuplicatesWithStrToLowerCallback) {
  const char *values[] = {
      "standard", "standard", "stroke", "PINYIN",   "trad",    "ReFormed",
      "unihan",   "DICT",     "zhuyin", "phonetic", "pinyin",  "reformed",
      "comPAT",   "Eor",      "direct", "search",   "Dict",    "searchjl",
      "big5han",  "compat",   "dict",   "GB2312",   "stroke",  "direct",
      "ducet",    "eor",      "Trad",   "gb2312",   "phonebk", "emoji",
  };

  const char *expected[] = {
      "standard", "stroke", "pinyin",  "trad",     "reformed",
      "unihan",   "dict",   "zhuyin",  "phonetic", "compat",
      "eor",      "direct", "search",  "searchjl", "big5han",
      "gb2312",   "ducet",  "phonebk", "emoji",
  };

  const int originalCount = 30, expectedCount = 19;
  int i, newCount;

  const char **items;
  items = (const char **)malloc(sizeof(char *) * originalCount);
  for (i = 0; i < originalCount; i++) {
    items[i] = (const char *)malloc(sizeof(char) * (strlen(values[i]) + 1));
    strcpy((char *)items[i], values[i]);
  }

  newCount = ecma402_removeDuplicates((char **)items, originalCount,
                                      ecma402_strToLower);

  cr_expect(eq(i8, newCount, expectedCount));

  for (i = 0; i < expectedCount; ++i) {
    cr_expect(eq(str, (char *)items[i], (char *)expected[i]));
  }

  free(items);
}

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
  items = (const char **)malloc(sizeof(char *) * originalCount);
  for (i = 0; i < originalCount; i++) {
    items[i] = (const char *)malloc(sizeof(char) * (strlen(values[i]) + 1));
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
  items = (const char **)malloc(sizeof(char *) * originalCount);
  for (i = 0; i < originalCount; i++) {
    items[i] = (const char *)malloc(sizeof(char) * (strlen(values[i]) + 1));
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
  items = (const char **)malloc(sizeof(char *) * originalCount);
  for (i = 0; i < originalCount; i++) {
    items[i] = (const char *)malloc(sizeof(char) * (strlen(values[i]) + 1));
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

ParameterizedTestParameters(TEST_SUITE, isAsciiDigitReturnsTrue) {
  static criterion::parameters<string> tests;

  char c;

  // Test for ASCII characters 0 - 9.
  for (c = '0'; c <= '9'; c++) {
    string s;
    s.assign(&c, 1);
    tests.emplace_back(s);
  }

  return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isAsciiDigitReturnsTrue) {
  cr_expect(eq(i8, ecma402::util::isAsciiDigit(*test->c_str()), true),
            "Expected true for \"%s\"; received false", test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isAsciiDigitReturnsFalse) {
  static criterion::parameters<string> tests;

  wchar_t c;

  // For each printable ASCII character...
  for (c = 32; c <= 126; c++) {
    // Don't include ASCII characters 0 - 9 in these tests.
    if (c >= '0' && c <= '9') {
      continue;
    }
    string s;
    s.assign(reinterpret_cast<const char *>(&c), 1);
    tests.emplace_back(s);
  }

  // For each printable Latin-1 supplement character...
  for (c = 160; c <= 255; c++) {
    string s;
    s.assign(reinterpret_cast<const char *>(&c), 1);
    tests.emplace_back(s);
  }

  return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isAsciiDigitReturnsFalse) {
  cr_expect(eq(i8, ecma402::util::isAsciiDigit(*test->c_str()), false),
            "Expected false for \"%s\"; received true", test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isAsciiAlphaReturnsTrue) {
  static criterion::parameters<string> tests;

  char c;

  // Test for ASCII characters A - Z.
  for (c = 'A'; c <= 'Z'; c++) {
    string s;
    s.assign(&c, 1);
    tests.emplace_back(s);
  }

  // Test for ASCII characters a - z.
  for (c = 'a'; c <= 'z'; c++) {
    string s;
    s.assign(&c, 1);
    tests.emplace_back(s);
  }

  return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isAsciiAlphaReturnsTrue) {
  cr_expect(eq(i8, ecma402::util::isAsciiAlpha(*test->c_str()), true),
            "Expected true for \"%s\"; received false", test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isAsciiAlphaReturnsFalse) {
  static criterion::parameters<string> tests;

  wchar_t c;

  // For each printable ASCII character...
  for (c = 32; c <= 126; c++) {
    // Don't include ASCII characters A - Z or a - z in these tests.
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      continue;
    }
    string s;
    s.assign(reinterpret_cast<const char *>(&c), 1);
    tests.emplace_back(s);
  }

  // For each printable Latin-1 supplement character...
  for (c = 160; c <= 255; c++) {
    string s;
    s.assign(reinterpret_cast<const char *>(&c), 1);
    tests.emplace_back(s);
  }

  return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isAsciiAlphaReturnsFalse) {
  cr_expect(eq(i8, ecma402::util::isAsciiAlpha(*test->c_str()), false),
            "Expected false for \"%s\"; received true", test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isAsciiAlnumReturnsTrue) {
  static criterion::parameters<string> tests;

  char c;

  // Test for ASCII characters 0 - 9.
  for (c = '0'; c <= '9'; c++) {
    string s;
    s.assign(&c, 1);
    tests.emplace_back(s);
  }

  // Test for ASCII characters A - Z.
  for (c = 'A'; c <= 'Z'; c++) {
    string s;
    s.assign(&c, 1);
    tests.emplace_back(s);
  }

  // Test for ASCII characters a - z.
  for (c = 'a'; c <= 'z'; c++) {
    string s;
    s.assign(&c, 1);
    tests.emplace_back(s);
  }

  return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isAsciiAlnumReturnsTrue) {
  cr_expect(eq(i8, ecma402::util::isAsciiAlnum(*test->c_str()), true),
            "Expected true for \"%s\"; received false", test->c_str());
}

ParameterizedTestParameters(TEST_SUITE, isAsciiAlnumReturnsFalse) {
  static criterion::parameters<string> tests;

  wchar_t c;

  // For each printable ASCII character...
  for (c = 32; c <= 126; c++) {
    // Don't include ASCII characters 0 - 9, A - Z, or a - z in these tests.
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z')) {
      continue;
    }
    string s;
    s.assign(reinterpret_cast<const char *>(&c), 1);
    tests.emplace_back(s);
  }

  // For each printable Latin-1 supplement character...
  for (c = 160; c <= 255; c++) {
    string s;
    s.assign(reinterpret_cast<const char *>(&c), 1);
    tests.emplace_back(s);
  }

  return tests;
}

ParameterizedTest(string *test, TEST_SUITE, isAsciiAlnumReturnsFalse) {
  cr_expect(eq(i8, ecma402::util::isAsciiAlnum(*test->c_str()), false),
            "Expected false for \"%s\"; received true", test->c_str());
}

// NOLINTEND(cert-err58-cpp, misc-const-correctness,
//           misc-use-anonymous-namespace)
