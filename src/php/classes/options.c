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

#include "php/classes/options.h"

zend_object_handlers ecma_handlers_IntlOptions;

zend_object *ecma_createIntlOptions(zend_class_entry *classEntry)
{
	ecma_IntlOptions *intlOptions;

	intlOptions = zend_object_alloc(sizeof(struct ecma_IntlOptions), classEntry);

	zend_object_std_init(&intlOptions->std, classEntry);
	object_properties_init(&intlOptions->std, classEntry);

#if PHP_VERSION_ID < 80300
	intlOptions->std.handlers = &ecma_handlers_IntlOptions;
#endif

	return &intlOptions->std;
}

bool ecma_endOfOptions(zval *object, bool allowNull)
{
	HashTable *ht = HASH_OF(object);

	while (zend_hash_has_more_elements(ht) == SUCCESS) {
		zval *value = zend_hash_get_current_data(ht);

		if (EXPECTED(Z_TYPE_P(value) == IS_INDIRECT)) {
			value = Z_INDIRECT_P(value);
		}

		if (!isNull(value) || allowNull == true) {
			// This value is not null, or we allow null, so stop here.
			return false;
		}

		zend_hash_move_forward(ht);
	}

	return true;
}

void ecma_freeIntlOptionsObj(zend_object *object)
{
	ecma_IntlOptions *intlOptions = ecma_IntlOptionsFromObj(object);
	zend_object_std_dtor(&intlOptions->std);
}

void ecma_getCurrentOptionKey(zval *rv, zval *object, bool allowNull)
{
	HashTable *ht = HASH_OF(object);

	while (zend_hash_has_more_elements(ht) == SUCCESS) {
		zval *value = zend_hash_get_current_data(ht);

		if (EXPECTED(Z_TYPE_P(value) == IS_INDIRECT)) {
			value = Z_INDIRECT_P(value);
		}

		if (!isNull(value) || allowNull == true) {
			// This value is not null, or we allow null, so stop here.
			zend_hash_get_current_key_zval(ht, rv);
			break;
		}

		zend_hash_move_forward(ht);
	}
}

void ecma_getCurrentOptionValue(zval *rv, zval *object, bool allowNull)
{
	HashTable *ht = HASH_OF(object);

	while (zend_hash_has_more_elements(ht) == SUCCESS) {
		zval *value = zend_hash_get_current_data(ht);

		if (EXPECTED(Z_TYPE_P(value) == IS_INDIRECT)) {
			value = Z_INDIRECT_P(value);
		}

		if (!isNull(value) || allowNull == true) {
			// This value is not null, or we allow null, so stop here.
			ZVAL_COPY(rv, value);
			break;
		}

		zend_hash_move_forward(ht);
	}
}

int ecma_getOptionBool(zend_class_entry *ce, zend_object *options, const char *name)
{
	zval *option, rv;

	if (options == NULL) {
		return -1;
	}

	option = zend_read_property(ce, options, name, strlen(name), false, &rv);

	if (Z_TYPE_P(option) == IS_TRUE) {
		return true;
	}

	if (Z_TYPE_P(option) == IS_FALSE) {
		return false;
	}

	return -1;
}

const char *ecma_getOptionString(zend_class_entry *ce, zend_object *options, const char *name)
{
	zval *option, rv;

	if (options == NULL) {
		return NULL;
	}

	option = zend_read_property(ce, options, name, strlen(name), false, &rv);

	if (Z_TYPE_P(option) == IS_STRING) {
		return Z_STRVAL_P(option);
	}

	return NULL;
}

void ecma_nextOption(zval *object, bool allowNull)
{
	HashTable *ht = HASH_OF(object);

	zend_hash_move_forward(ht);

	while (zend_hash_has_more_elements(ht) == SUCCESS) {
		zval *value = zend_hash_get_current_data(ht);

		if (EXPECTED(Z_TYPE_P(value) == IS_INDIRECT)) {
			value = Z_INDIRECT_P(value);
		}

		if (!isNull(value) || allowNull == true) {
			// This value is not null, or we allow null, so stop here.
			break;
		}

		zend_hash_move_forward(ht);
	}
}

void ecma_rewindOptions(zval *object)
{
	HashTable *ht = HASH_OF(object);
	zend_hash_internal_pointer_reset(ht);
}
