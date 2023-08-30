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

#ifndef ECMA_INTL_PHP_CLASSES_LOCALE_H
#define ECMA_INTL_PHP_CLASSES_LOCALE_H

#include "php/php_common.h"

#include "ecma402/locale.h"

typedef struct ecma_IntlLocale {
  ecma402_locale *locale;
  zend_object std;
} ecma_IntlLocale;

static inline ecma_IntlLocale *ecma_IntlLocaleFromObj(zend_object *obj) {
  return (ecma_IntlLocale *)((char *)(obj)-XtOffsetOf(ecma_IntlLocale, std));
}

#define ECMA_LOCALE_P(zv) ecma_IntlLocaleFromObj(Z_OBJ_P(zv))

extern zend_class_entry *ecma_ce_IntlLocale;
extern zend_object_handlers ecma_handlers_IntlLocale;

zend_object *ecma_createIntlLocale(zend_class_entry *classEntry);

PHP_MINIT_FUNCTION(ecma_intl_locale);

#endif /* ECMA_INTL_PHP_CLASSES_LOCALE_H */
