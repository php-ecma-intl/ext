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

#ifndef ECMA_INTL_PHP_CLASSES_LOCALE_OPTIONS_H
#define ECMA_INTL_PHP_CLASSES_LOCALE_OPTIONS_H

#include "php/php_common.h"

#define ECMA_LOCALE_OPTION_COUNT 10

typedef enum ecma_localeOption {
  CALENDAR = 1,
  CASE_FIRST,
  COLLATION,
  CURRENCY,
  HOUR_CYCLE,
  LANGUAGE,
  NUMBERING_SYSTEM,
  NUMERIC,
  REGION,
  SCRIPT,
} ecma_localeOption;

typedef struct ecma_IntlLocaleOptions {
  bool allNull;
  ecma_localeOption iteratorCurrent;
  zend_object std;
} ecma_IntlLocaleOptions;

static inline ecma_IntlLocaleOptions *
ecma_IntlLocaleOptionsFromObj(zend_object *obj) {
  return (ecma_IntlLocaleOptions *)((char *)(obj)-XtOffsetOf(
      ecma_IntlLocaleOptions, std));
}

#define ECMA_LOCALE_OPTIONS_P(zv) ecma_IntlLocaleOptionsFromObj(Z_OBJ_P(zv))

extern zend_class_entry *ecma_ce_IntlLocaleOptions;
extern zend_object_handlers ecma_handlers_IntlLocaleOptions;

zend_object *ecma_createIntlLocaleOptions(zend_class_entry *classEntry);

PHP_MINIT_FUNCTION(ecma_intl_locale_options);

#endif /* ECMA_INTL_PHP_CLASSES_LOCALE_OPTIONS_H */
