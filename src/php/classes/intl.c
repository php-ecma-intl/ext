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

#include "php/classes/intl.h"

#include "ecma402/category.h"
#include "ecma402/locale.h"
#include "php/classes/category.h"

#include <ext/spl/spl_iterators.h>
#include <unicode/uloc.h>

zend_class_entry *ecma_ce_Intl = NULL;

void registerEcmaIntl() { ecma_ce_Intl = register_class_Ecma_Intl(); }

PHP_METHOD(Ecma_Intl, __construct) { ZEND_PARSE_PARAMETERS_NONE(); }

PHP_METHOD(Ecma_Intl, getCanonicalLocales) {
  zval *localesArg, *loopItem;
  HashTable *localesHt;
  const char **locales;
  char **canonicalized;
  int i, canonicalizedLength, localesLength = 0;
  ecma402_errorStatus *errorStatus;

  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_ZVAL(localesArg)
  ZEND_PARSE_PARAMETERS_END();

  if (!isString(localesArg) && !isNull(localesArg) &&
      !isStringable(localesArg) && !isIterable(localesArg)) {
    zend_type_error(
        "Ecma\\Intl::getCanonicalLocales(): Argument #1 ($locales) must be of "
        "type iterable<Stringable|string>|Stringable|string|null, %s given",
        zend_zval_type_name(localesArg));
    RETURN_THROWS();
  }

  array_init(return_value);

  if (EXPECTED(Z_TYPE_P(localesArg) == IS_NULL)) {
    return;
  }

  ALLOC_HASHTABLE(localesHt);
  zend_hash_init(localesHt, 0, NULL, ZVAL_PTR_DTOR, 0);

  if (isString(localesArg)) {
    zval localeString;
    ZVAL_STR_COPY(&localeString, Z_STR_P(localesArg));
    zend_hash_next_index_insert(localesHt, &localeString);
  } else if (isStringable(localesArg)) {
    zval localeString;
    zend_std_cast_object_tostring(Z_OBJ_P(localesArg), &localeString,
                                  IS_STRING);
    zend_hash_next_index_insert(localesHt, &localeString);
  } else if (isArray(localesArg)) {
    zend_hash_copy(localesHt, Z_ARRVAL_P(localesArg),
                   (copy_ctor_func_t)zval_add_ref);
  } else {
    spl_iterator_apply(localesArg, iteratorToHashTable, (void *)localesHt);
  }

  locales = (const char **)emalloc(sizeof(char *) * ULOC_FULLNAME_CAPACITY);

  ZEND_HASH_FOREACH_VAL(localesHt, loopItem)

  if (isString(loopItem)) {
    locales[localesLength] = Z_STRVAL_P(loopItem);
    localesLength++;
  } else if (isStringable(loopItem)) {
    zval localeString;
    zend_std_cast_object_tostring(Z_OBJ_P(loopItem), &localeString, IS_STRING);
    locales[localesLength] = Z_STRVAL(localeString);
    localesLength++;
  } else {
    zend_type_error(
        "Ecma\\Intl::getCanonicalLocales(): Argument #1 ($locales) must be of "
        "type iterable<Stringable|string>|Stringable|string|null, %s given in "
        "iterable",
        zend_zval_type_name(loopItem));
  }

  ZEND_HASH_FOREACH_END();

  errorStatus = ecma402_initErrorStatus();

  if (locales) {
    canonicalized = (char **)emalloc(sizeof(char *) * ULOC_FULLNAME_CAPACITY);
    canonicalizedLength = ecma402_canonicalizeLocaleList(
        locales, localesLength, canonicalized, errorStatus);

    if (ecma402_hasError(errorStatus)) {
      zend_value_error("%s", errorStatus->errorMessage);
    } else {
      for (i = 0; i < canonicalizedLength; i++) {
        add_next_index_string(return_value, canonicalized[i]);
      }
    }

    if (canonicalized) {
      efree(canonicalized);
    }

    efree(locales);
  }

  ecma402_freeErrorStatus(errorStatus);

  zend_hash_destroy(localesHt);
  FREE_HASHTABLE(localesHt);

  if (EG(exception)) {
    RETURN_THROWS();
  }
}

PHP_METHOD(Ecma_Intl, supportedValuesOf) {
  zend_object *categoryCase;
  zval *categoryZval;
  const char **values = NULL;
  char *category;
  int valuesCount, capacity;

  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_OBJ_OF_CLASS(categoryCase, ecma_ce_IntlCategory)
  ZEND_PARSE_PARAMETERS_END();

  categoryZval = zend_enum_fetch_case_value(categoryCase);
  category = Z_STRVAL_P(categoryZval);

  capacity = ecma402_capacityForCategory(category);
  values = (const char **)emalloc(sizeof(const char *) * capacity);
  valuesCount = ecma402_supportedValuesForCategory(category, values);

  array_init_size(return_value, valuesCount);

  for (int i = 0; i < valuesCount; i++) {
    add_next_index_string(return_value, values[i]);
  }

  if (values) {
    efree(values);
  }
}
