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

#ifndef ECMA_INTL_PHP_CLASSES_COLLATOR_H
#define ECMA_INTL_PHP_CLASSES_COLLATOR_H

#include "php/php_common.h"

typedef struct ecma_IntlCollator {
	zend_object std;
} ecma_IntlCollator;

static inline ecma_IntlCollator *ecma_IntlCollatorFromObj(zend_object *obj)
{
	return (ecma_IntlCollator *)((char *)(obj)-XtOffsetOf(ecma_IntlCollator, std));
}

#define ECMA_COLLATOR_P(zv) ecma_IntlCollatorFromObj(Z_OBJ_P(zv))

extern zend_class_entry *ecma_ce_IntlCollator;
extern zend_object_handlers ecma_handlers_IntlCollator;

zend_object *ecma_createIntlCollator(zend_class_entry *classEntry);

PHP_MINIT_FUNCTION(ecma_intl_collator);

#endif /* ECMA_INTL_PHP_CLASSES_COLLATOR_H */
