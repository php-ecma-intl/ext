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

#include <unicode/uloc.h>

zend_class_entry *ecma_ce_Intl = NULL;

void registerEcmaIntl() { ecma_ce_Intl = register_class_Ecma_Intl(); }

PHP_METHOD(Ecma_Intl, __construct) { ZEND_PARSE_PARAMETERS_NONE(); }

PHP_METHOD(Ecma_Intl, getCanonicalLocales) {
  HashTable *localesInput;
  zend_string *localeInput;
  const char **locales;
  char **canonicalized;
  int i, canonicalizedLength, localesLength = 0;
  ecma402_errorStatus *errorStatus;

  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_ARRAY_HT_OR_STR(localesInput, localeInput)
  ZEND_PARSE_PARAMETERS_END();

  if (localesInput == NULL) {
    ALLOC_HASHTABLE(localesInput);
    zend_hash_init(localesInput, 1, NULL, ZVAL_PTR_DTOR, 0);

    zval localeString;
    ZVAL_STR_COPY(&localeString, localeInput);
    zend_hash_index_update(localesInput, 0, &localeString);
  }

  array_init(return_value);
  locales = (const char **)emalloc(sizeof(char *) * ULOC_FULLNAME_CAPACITY);

  zval *loopItem;
  ZEND_HASH_FOREACH_VAL(localesInput, loopItem)

  if (Z_TYPE_P(loopItem) != IS_STRING) {
    zend_type_error("The $locales argument must be of type string or an array "
                    "of type string");
  } else {
    locales[localesLength] = Z_STRVAL_P(loopItem);
    localesLength++;
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

  if (localeInput) {
    zend_hash_destroy(localesInput);
    FREE_HASHTABLE(localesInput);
  }

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
