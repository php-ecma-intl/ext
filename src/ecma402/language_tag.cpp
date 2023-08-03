/**
 * Copyright (c) php-ecma-intl contributors.
 *
 * This source file is subject to the BSD-3-Clause license that is bundled with
 * this package in the file LICENSE and is available at the following web
 * address: https://opensource.org/license/bsd-3-clause/
 *
 * This source file may utilize copyrighted material from third-party open
 * source projects, the use of which is acknowledged in the NOTICE file bundled
 * with this package.
 */

#include "language_tag.h"

#include "util.h"

#include <algorithm>
#include <cassert>
#include <unicode/umachine.h>
#include <unordered_set>

namespace {

using LChar = unsigned char;
using VariantCode = uint64_t;

unsigned convertToUnicodeSingletonIndex(UChar singleton);
bool isPartValid(const std::string &string);
bool isUnicodeExtensionAttribute(const std::string &string);
bool isUnicodeExtensionKey(const std::string &string);
bool isUnicodeExtensionTypeComponent(const std::string &string);
bool isUnicodeOtherExtensionValue(const std::string &string);
bool isUnicodePrivateUseExtensionValue(const std::string &string);
bool isUnicodeTypeKey(const std::string &string);
bool isUnicodeTypeValueComponent(const std::string &string);
VariantCode parseVariantCode(const std::string &string);

} // namespace

bool ecma402_isStructurallyValidLanguageTag(const char *tag) {
  ecma402::LanguageTagParser parser(tag);
  return parser.parseUnicodeLocaleId();
}

bool ecma402_isUnicodeLanguageSubtag(const char *language) {
  return ecma402::isUnicodeLanguageSubtag(language);
}

bool ecma402_isUnicodeLocaleIdentifierType(const char *identifier) {
  std::string const delimiter = "-";
  std::string const s = identifier;
  std::string token;

  auto start = 0U;
  auto end = s.find(delimiter);

  while (end != std::string::npos) {
    token = s.substr(start, end - start);

    if (!isUnicodeTypeValueComponent(token)) {
      return false;
    }

    start = end + delimiter.length();
    end = s.find(delimiter, start);
  }

  return isUnicodeTypeValueComponent(s.substr(start, end));
}

bool ecma402_isUnicodeRegionSubtag(const char *region) {
  return ecma402::isUnicodeRegionSubtag(region);
}

bool ecma402_isUnicodeScriptSubtag(const char *script) {
  return ecma402::isUnicodeScriptSubtag(script);
}

bool ecma402::isUnicodeLanguageSubtag(const std::string &string) {
  auto length = string.length();
  return length >= 2 && length <= 8 && length != 4 &&
         std::all_of(string.cbegin(), string.cend(), util::isAsciiAlpha);
}

bool ecma402::isUnicodeRegionSubtag(const std::string &string) {
  auto length = string.length();
  return (length == 2 &&
          std::all_of(string.cbegin(), string.cend(), util::isAsciiAlpha)) ||
         (length == 3 &&
          std::all_of(string.cbegin(), string.cend(), util::isAsciiDigit));
}

bool ecma402::isUnicodeScriptSubtag(const std::string &string) {
  return string.length() == 4 &&
         std::all_of(string.cbegin(), string.cend(), util::isAsciiAlpha);
}

bool ecma402::isUnicodeVariantSubtag(const std::string &string) {
  auto length = string.length();

  if (length >= 5 && length <= 8) {
    return std::all_of(string.cbegin(), string.cend(), util::isAsciiAlnum);
  }

  return length == 4 && util::isAsciiDigit(string.at(0)) &&
         std::all_of(std::next(string.cbegin()), string.cend(),
                     util::isAsciiAlnum);
}

ecma402::LanguageTagParser::LanguageTagParser(const std::string &tag) {
  tagParts = util::split(tag, "-");
  partsCursor = tagParts.begin();
  assert(partsCursor != tagParts.end());
  currentPart = *partsCursor;
}

bool ecma402::LanguageTagParser::isEos() {
  return partsCursor == tagParts.end();
}

bool ecma402::LanguageTagParser::next() {
  if (isEos()) {
    return false;
  }

  ++partsCursor;

  if (isEos()) {
    currentPart = {};
    return false;
  }

  currentPart = *partsCursor;
  return true;
}

bool ecma402::LanguageTagParser::parseUnicodeLanguageId() {
  assert(!isEos());

  if (!isUnicodeLanguageSubtag(currentPart)) {
    return false;
  }

  if (!next()) {
    return true;
  }

  if (isUnicodeScriptSubtag(currentPart) && !next()) {
    return true;
  }

  if (isUnicodeRegionSubtag(currentPart) && !next()) {
    return true;
  }

  std::unordered_set<VariantCode> variantCodes;

  while (true) {
    if (!isUnicodeVariantSubtag(currentPart)) {
      return isPartValid(currentPart);
    }

    VariantCode const variantCode = parseVariantCode(currentPart);
    auto search = variantCodes.find(variantCode);

    if (search != variantCodes.end()) {
      // The subtag already exists.
      return false;
    }

    variantCodes.insert(variantCode);

    if (!next()) {
      return true;
    }
  }
}

bool ecma402::LanguageTagParser::parseUnicodeLocaleId() {
  assert(!isEos());

  if (!parseUnicodeLanguageId()) {
    return false;
  }

  if (isEos()) {
    return true;
  }

  if (!parseExtensionsAndPrivateUseExtensions()) {
    return false;
  }

  return true;
}

bool ecma402::LanguageTagParser::parseExtensionsAndPrivateUseExtensions() {
  assert(!isEos());

  std::unordered_set<unsigned> singletons{};

  while (true) {
    if (currentPart.length() != 1) {
      return false;
    }

    UChar const prefixCode = currentPart[0];

    if (!util::isAsciiAlnum(prefixCode)) {
      return false;
    }

    // https://tc39.es/ecma402/#sec-isstructurallyvalidlanguagetag
    // does not include duplicate singleton subtags.
    //
    // https://unicode.org/reports/tr35/#Unicode_locale_identifier
    // As is often the case, the complete syntactic constraints are not easily
    // captured by ABNF, so there is a further condition: There cannot be more
    // than one extension with the same singleton (-a-, …, -t-, -u-, …). Note
    // that the private use extension (-x-) must come after all other
    // extensions.
    if (singletons.find(convertToUnicodeSingletonIndex(prefixCode)) !=
        singletons.end()) {
      return false;
    }

    singletons.insert(convertToUnicodeSingletonIndex(prefixCode));

    switch (prefixCode) {

    case 'u':
    case 'U': {
      if (!next()) {
        return false;
      }

      if (!parseUnicodeExtensionAfterPrefix()) {
        return false;
      }

      if (isEos()) {
        return true;
      }

      break; // Next extension.
    }

    case 't':
    case 'T': {
      if (!next()) {
        return false;
      }

      if (!parseTransformedExtensionAfterPrefix()) {
        return false;
      }

      if (isEos()) {
        return true;
      }

      break; // Next extension.
    }

    case 'x':
    case 'X': {
      if (!next()) {
        return false;
      }

      if (!parsePrivateUseExtensionAfterPrefix()) {
        return false;
      }

      return true; // If pu_extensions appear, no extensions can follow after
                   // that. This must be the end of unicode_locale_id.
    }

    default: {
      if (!next()) {
        return false;
      }

      if (!parseOtherExtensionAfterPrefix()) {
        return false;
      }

      if (isEos()) {
        return true;
      }

      break; // Next extension.
    }
    } // switch(prefixCode)
  }
}

bool ecma402::LanguageTagParser::parseUnicodeExtensionAfterPrefix() {
  assert(!isEos());
  bool isAttributeOrKeyword = false;

  if (isUnicodeExtensionAttribute(currentPart)) {
    isAttributeOrKeyword = true;

    while (true) {
      if (!isUnicodeExtensionAttribute(currentPart)) {
        break;
      }

      if (!next()) {
        return true;
      }
    }
  }

  if (isUnicodeExtensionKey(currentPart)) {
    isAttributeOrKeyword = true;

    while (true) {
      if (!isUnicodeExtensionKey(currentPart)) {
        break;
      }

      if (!next()) {
        return true;
      }

      while (true) {
        if (!isUnicodeExtensionTypeComponent(currentPart)) {
          break;
        }

        if (!next()) {
          return true;
        }
      }
    }
  }

  if (!isAttributeOrKeyword) {
    return false;
  }

  return true;
}

bool ecma402::LanguageTagParser::parseTransformedExtensionAfterPrefix() {
  assert(!isEos());
  bool found = false;

  if (isUnicodeLanguageSubtag(currentPart)) {
    found = true;

    if (!parseUnicodeLanguageId()) {
      return false;
    }

    if (isEos()) {
      return true;
    }
  }

  if (isUnicodeTypeKey(currentPart)) {
    found = true;

    while (true) {
      if (!isUnicodeTypeKey(currentPart)) {
        break;
      }

      if (!next()) {
        return false;
      }

      if (!isUnicodeTypeValueComponent(currentPart)) {
        return false;
      }

      if (!next()) {
        return true;
      }

      while (true) {
        if (!isUnicodeTypeValueComponent(currentPart)) {
          break;
        }

        if (!next()) {
          return true;
        }
      }
    }
  }

  return found;
}

bool ecma402::LanguageTagParser::parsePrivateUseExtensionAfterPrefix() {
  assert(!isEos());

  if (!isUnicodePrivateUseExtensionValue(currentPart)) {
    return false;
  }

  if (!next()) {
    return true;
  }

  while (true) {
    if (!isUnicodePrivateUseExtensionValue(currentPart)) {
      return isPartValid(currentPart);
    }

    if (!next()) {
      return true;
    }
  }
}

bool ecma402::LanguageTagParser::parseOtherExtensionAfterPrefix() {
  assert(!isEos());

  if (!isUnicodeOtherExtensionValue(currentPart)) {
    return false;
  }

  if (!next()) {
    return true;
  }

  while (true) {
    if (!isUnicodeOtherExtensionValue(currentPart)) {
      return true;
    }

    if (!next()) {
      return true;
    }
  }
}

namespace {

using namespace ecma402::util;

unsigned convertToUnicodeSingletonIndex(UChar singleton) {
  assert(isAsciiAlnum(singleton));
  singleton = toAsciiLower(singleton);

  // 0 - 9 => numeric
  // 10 - 35 => alpha
  if (isAsciiDigit(singleton)) {
    return singleton - '0';
  }

  return (singleton - 'a') + 10;
}

bool isPartValid(const std::string &string) {
  return string.length() > 0 &&
         std::all_of(string.cbegin(), string.cend(), isAsciiAlnum);
}

bool isUnicodeExtensionAttribute(const std::string &string) {
  auto length = string.length();
  return length >= 3 && length <= 8 &&
         std::all_of(string.cbegin(), string.cend(), isAsciiAlnum);
}

bool isUnicodeExtensionKey(const std::string &string) {
  return string.length() == 2 && isAsciiAlnum(string[0]) &&
         isAsciiAlpha(string[1]);
}

bool isUnicodeExtensionTypeComponent(const std::string &string) {
  auto length = string.length();
  return length >= 3 && length <= 8 &&
         std::all_of(string.cbegin(), string.cend(), isAsciiAlnum);
}

bool isUnicodeOtherExtensionValue(const std::string &string) {
  auto length = string.length();
  return length >= 2 && length <= 8 &&
         std::all_of(string.cbegin(), string.cend(), isAsciiAlnum);
}

bool isUnicodePrivateUseExtensionValue(const std::string &string) {
  auto length = string.length();
  return length >= 1 && length <= 8 &&
         std::all_of(string.cbegin(), string.cend(), isAsciiAlnum);
}

bool isUnicodeTypeKey(const std::string &string) {
  return string.length() == 2 && isAsciiAlpha(string[0]) &&
         isAsciiDigit(string[1]);
}

bool isUnicodeTypeValueComponent(const std::string &string) {
  auto length = string.length();
  return length >= 3 && length <= 8 &&
         std::all_of(string.cbegin(), string.cend(), isAsciiAlnum);
}

VariantCode parseVariantCode(const std::string &string) {
  assert(ecma402::isUnicodeVariantSubtag(string));
  assert(std::all_of(string.cbegin(), string.cend(), isAscii));
  assert(string.length() <= 8);
  assert(string.length() >= 1);

  struct Code {
    std::array<LChar, 8> characters{};
  };

  static_assert(std::is_unsigned<LChar>::value, "must be unsigned");
  static_assert(sizeof(VariantCode) == sizeof(Code), "size must be equal");

  Code code{};
  for (unsigned index = 0; index < string.length(); ++index) {
    code.characters[index] = toAsciiLower(string[index]);
  }

  VariantCode const result = reinterpret_cast<VariantCode &>(code);

  assert(result);
  assert(result != static_cast<VariantCode>(-1));

  return result;
}

} // namespace
