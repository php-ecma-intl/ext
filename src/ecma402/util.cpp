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

#include "ecma402/util.h"

#include <cstdlib>
#include <cstring>

namespace {
int compareStrings(const void *left, const void *right);
int removeEmpty(char **array, int length);
void sort(char **array, int length);
void strArrayWalk(char **array, int length, char *(*callback)(char *));
unsigned char toAsciiLowerUnchecked(unsigned char character);
} // namespace

int ecma402_removeDuplicates(char **array, int length, char *(*callback)(char *)) {
	int i, j, k;
	int const originalLength = length;

	if (callback != nullptr) {
		strArrayWalk(array, length, (*callback));
	}

	for (i = 0; i < length; i++) {
		for (j = i + 1; j < length; j++) {
			if (strcmp(array[i], array[j]) == 0) {
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
			array[i] = nullptr;
		}
	}

	return length;
}

int ecma402_sortAndRemoveDuplicates(char **array, int length, char *(*callback)(char *)) {
	if (callback != nullptr) {
		strArrayWalk(array, length, (*callback));
	}

	sort(array, length);
	length = removeEmpty(array, length);

	return ecma402_removeDuplicates(array, length, nullptr);
}

char *ecma402_strToLower(char *string) {
	for (char *p = string; *p != 0; p++) {
		*p = ecma402::util::toAsciiLower(*p);
	}

	return string;
}

char *ecma402_strToUpper(char *string) {
	for (char *p = string; *p != 0; p++) {
		*p = ecma402::util::toAsciiUpper(*p);
	}

	return string;
}

bool ecma402::util::isAscii(unsigned char character) { return (character & ~0x7F) == 0; }

bool ecma402::util::isAsciiAlnum(unsigned char character) { return isAsciiDigit(character) || isAsciiAlpha(character); }

bool ecma402::util::isAsciiAlpha(unsigned char character) { return isAsciiLower(toAsciiLowerUnchecked(character)); }

bool ecma402::util::isAsciiDigit(unsigned char character) { return character >= '0' && character <= '9'; }

bool ecma402::util::isAsciiLower(unsigned char character) { return character >= 'a' && character <= 'z'; }

bool ecma402::util::isAsciiUpper(unsigned char character) { return character >= 'A' && character <= 'Z'; }

std::vector<std::string> ecma402::util::split(const std::string &string, const std::string &delimiter) {
	size_t startPosition = 0, endPosition, delimiterLength = delimiter.length();
	std::string token;
	std::vector<std::string> result;

	while ((endPosition = string.find(delimiter, startPosition)) != std::string::npos) {
		token = string.substr(startPosition, endPosition - startPosition);
		startPosition = endPosition + delimiterLength;
		result.push_back(token);
	}

	result.push_back(string.substr(startPosition));

	return result;
}

unsigned char ecma402::util::toAsciiLower(unsigned char character) {
	return character | (static_cast<int>(isAsciiUpper(character)) << 5);
}

unsigned char ecma402::util::toAsciiUpper(unsigned char character) {
	return character & ~(static_cast<int>(isAsciiLower(character)) << 5);
}

namespace {

int compareStrings(const void *left, const void *right) { return strcmp(*(const char **)left, *(const char **)right); }

int removeEmpty(char **array, int length) {
	int i, j;
	int const originalLength = length;

	for (i = 0; i < length; i++) {
		if (strcmp(array[i], "") == 0) {
			for (j = i; j < length - 1; j++) {
				array[j] = array[j + 1];
			}
			length--;
			i--;
		}
	}

	if ((originalLength - length) > 0) {
		for (i = length; i < originalLength; i++) {
			array[i] = nullptr;
		}
	}

	return length;
}

void sort(char **array, int length) { qsort(array, length, sizeof(const char *), compareStrings); }

void strArrayWalk(char **array, int length, char *(*callback)(char *)) {
	for (int i = 0; i < length; i++) {
		array[i] = (*callback)(array[i]);
	}
}

unsigned char toAsciiLowerUnchecked(unsigned char character) { return character | 0x20; }

} // namespace
