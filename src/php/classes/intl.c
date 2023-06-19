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

#include "intl.h"

#include "collation.h"
#include "src/ecma402/category.h"
#include "src/php/classes/category.h"

#include <Zend/zend_exceptions.h>
#include <stdbool.h>

static zend_object *getCaseForCategoryValue(char *category, const char *value);

zend_class_entry *ecma_ce_Intl = NULL;

void registerEcmaIntl() { ecma_ce_Intl = register_class_Ecma_Intl(); }

PHP_METHOD(Ecma_Intl, __construct) { ZEND_PARSE_PARAMETERS_NONE(); }

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

  capacity = getCapacityForCategory(category);
  values = (const char **)emalloc(sizeof(const char *) * capacity);
  valuesCount = getSupportedValuesForCategory(category, values);

  array_init_size(return_value, valuesCount);

  for (int i = 0; i < valuesCount; i++) {
    zend_object *valueCase = getCaseForCategoryValue(category, values[i]);
    add_next_index_object(return_value, valueCase);
  }

  if (values) {
    efree(values);
  }

  if (EG(exception)) {
    RETURN_THROWS();
  }
}

static zend_object *getCaseForCategoryValue(char *category, const char *value) {
  zend_object *valueCase = NULL;
  zend_string *valueZstr;
  zend_result result;

  valueZstr = zend_string_init(value, strlen(value), false);

  if (strcmp(CATEGORY_COLLATION, category) == 0) {
    result = zend_enum_get_case_by_value(&valueCase, ecma_ce_IntlCollation, 0,
                                         valueZstr, true);
  }

  zend_string_release(valueZstr);

  // This should never happen, but just in case we don't find a case for the
  // value in the given enum, we'll throw an Error.
  if (valueCase == NULL || result == FAILURE) {
    zend_throw_error(
        zend_ce_error,
        "Unable to find enum case for value \"%s\" in category \"%s\"", value,
        category);
  }

  return valueCase;
}
