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
#include "php/classes/category.h"

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
