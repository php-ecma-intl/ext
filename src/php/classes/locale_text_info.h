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

#ifndef ECMA_INTL_PHP_CLASSES_LOCALE_TEXT_INFO_H
#define ECMA_INTL_PHP_CLASSES_LOCALE_TEXT_INFO_H

#include "php/php_common.h"

typedef struct ecma_IntlLocaleTextInfo {
	zend_object std;
} ecma_IntlLocaleTextInfo;

static inline ecma_IntlLocaleTextInfo *ecma_IntlLocaleTextInfoFromObj(zend_object *obj) {
	return (ecma_IntlLocaleTextInfo *)((char *)(obj)-XtOffsetOf(ecma_IntlLocaleTextInfo, std));
}

#define ECMA_LOCALE_TEXT_INFO_P(zv) ecma_IntlLocaleTextInfoFromObj(Z_OBJ_P(zv))

extern zend_class_entry *ecma_ce_IntlLocaleTextInfo;
extern zend_object_handlers ecma_handlers_IntlLocaleTextInfo;

zend_object *ecma_createIntlLocaleTextInfo(zend_class_entry *classEntry);

PHP_MINIT_FUNCTION(ecma_intl_locale_textinfo);

#endif /* ECMA_INTL_PHP_CLASSES_LOCALE_TEXT_INFO_H */
