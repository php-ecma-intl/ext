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

#ifndef ECMA_INTL_PHP_CLASSES_LOCALE_H
#define ECMA_INTL_PHP_CLASSES_LOCALE_H

#include "php/php_common.h"

typedef struct ecma_IntlLocale ecma_IntlLocale;

struct ecma_IntlLocale {
  char *original;
  char *tag;
  zend_object std;
};

static inline ecma_IntlLocale *ecma_IntlLocaleFromObj(zend_object *obj) {
  return (ecma_IntlLocale *)((char *)(obj)-XtOffsetOf(ecma_IntlLocale, std));
}

#define ECMA_LOCALE_P(zv) ecma_IntlLocaleFromObj(Z_OBJ_P(zv))

extern zend_class_entry *ecma_ce_IntlLocale;
extern zend_object_handlers ecma_handlers_IntlLocale;

void registerEcmaIntlLocale(void);
zend_object *ecma_createIntlLocale(zend_class_entry *classEntry);

#endif /* ECMA_INTL_PHP_CLASSES_LOCALE_H */
