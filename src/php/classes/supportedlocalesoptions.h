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

#ifndef ECMA_INTL_PHP_CLASSES_SUPPORTEDLOCALESOPTIONS_H
#define ECMA_INTL_PHP_CLASSES_SUPPORTEDLOCALESOPTIONS_H

#include "php/php_common.h"

#define ECMA_SUPPORTED_LOCALES_OPTION_COUNT 1

typedef enum ecma_supportedLocalesOption {
  LOCALE_MATCHER = 1,
} ecma_supportedLocalesOption;

typedef struct ecma_IntlSupportedLocalesOptions {
  bool allNull;
  ecma_supportedLocalesOption iteratorCurrent;
  zend_object std;
} ecma_IntlSupportedLocalesOptions;

static inline ecma_IntlSupportedLocalesOptions *
ecma_IntlSupportedLocalesOptionsFromObj(zend_object *obj) {
  return (ecma_IntlSupportedLocalesOptions *)((char *)(obj)-XtOffsetOf(
      ecma_IntlSupportedLocalesOptions, std));
}

#define ECMA_SUPPORTED_LOCALES_OPTIONS_P(zv)                                   \
  ecma_IntlSupportedLocalesOptionsFromObj(Z_OBJ_P(zv))

extern zend_class_entry *ecma_ce_IntlSupportedLocalesOptions;
extern zend_object_handlers ecma_handlers_IntlSupportedLocalesOptions;

zend_object *
ecma_createIntlSupportedLocalesOptions(zend_class_entry *classEntry);

PHP_MINIT_FUNCTION(ecma_intl_supportedlocalesoptions);

#endif /* ECMA_INTL_PHP_CLASSES_SUPPORTEDLOCALESOPTIONS_H */
