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

#ifndef ECMA_INTL_PHP_CLASSES_OPTIONS_H
#define ECMA_INTL_PHP_CLASSES_OPTIONS_H

#include "php/php_common.h"

typedef struct ecma_IntlOptions {
	zend_object std;
} ecma_IntlOptions;

static inline ecma_IntlOptions *ecma_IntlOptionsFromObj(zend_object *obj)
{
	return (ecma_IntlOptions *)((char *)(obj)-XtOffsetOf(ecma_IntlOptions, std));
}

#define ECMA_OPTIONS_P(zv) ecma_IntlOptionsFromObj(Z_OBJ_P(zv))

extern zend_object_handlers ecma_handlers_IntlOptions;

zend_object *ecma_createIntlOptions(zend_class_entry *classEntry);
void ecma_freeIntlOptionsObj(zend_object *object);

bool ecma_endOfOptions(zval *object, bool allowNull);
void ecma_getCurrentOptionKey(zval *rv, zval *object, bool allowNull);
void ecma_getCurrentOptionValue(zval *rv, zval *object, bool allowNull);
void ecma_nextOption(zval *object, bool allowNull);
void ecma_rewindOptions(zval *object);

/**
 * Returns the boolean value of the named option or -1 if the value is not set
 * or is not boolean.
 *
 * @param ce The class type of the options object.
 * @param options The options object.
 * @param name The name of the option to retrieve.
 *
 * @return Boolean true (1) or false (0), or -1 if not set or not a boolean.
 */
int ecma_getOptionBool(zend_class_entry *ce, zend_object *options, const char *name);

/**
 * Returns the string value of the named option or NULL if the value is not set
 * or is not a string.
 *
 * @param ce The class type of the options object.
 * @param options The options object.
 * @param name The name of the option to retrieve.
 *
 * @return The string value of the option, or NULL if not set or not a string.
 */
const char *ecma_getOptionString(zend_class_entry *ce, zend_object *options, const char *name);

#endif /* ECMA_INTL_PHP_CLASSES_OPTIONS_H */
