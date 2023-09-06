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

#ifndef ECMA_INTL_PHP_COMMON_H
#define ECMA_INTL_PHP_COMMON_H

#include "common.h"

#include <php.h>

#include <Zend/zend_enum.h>
#include <Zend/zend_interfaces.h>
#include <unicode/uchar.h>
#include <unicode/uversion.h>

static inline bool isArray(zval *arg) { return EXPECTED(Z_TYPE_P(arg) == IS_ARRAY); }

static inline bool isFalse(zval *arg) { return EXPECTED(Z_TYPE_P(arg) == IS_FALSE); }

static inline bool isIterable(zval *arg) { return EXPECTED(zend_is_iterable(arg)); }

static inline bool isNull(zval *arg) { return EXPECTED(Z_TYPE_P(arg) == IS_NULL); }

static inline bool isString(zval *arg) { return EXPECTED(Z_TYPE_P(arg) == IS_STRING); }

static inline bool isStringable(zval *arg) {
	return EXPECTED(Z_TYPE_P(arg) == IS_OBJECT) &&
	       EXPECTED(zend_class_implements_interface(Z_OBJCE_P(arg), zend_ce_stringable));
}

static inline int iteratorToHashTable(zend_object_iterator *iter, void *dest) {
	zval *value;
	HashTable *ht = (HashTable *)dest;

	value = iter->funcs->get_current_data(iter);
	if (EG(exception)) {
		return ZEND_HASH_APPLY_STOP;
	}
	if (value == NULL) {
		return ZEND_HASH_APPLY_STOP;
	}
	Z_TRY_ADDREF_P(value);
	zend_hash_next_index_insert(ht, value);
	return ZEND_HASH_APPLY_KEEP;
}

static inline void serializeObjectProperties(zval *rv, zval *object, bool allowNull) {
	HashTable *ht;
	zend_string *key;
	zval *value;

	ht = HASH_OF(object);

	object_init(rv);

	ZEND_HASH_FOREACH_STR_KEY_VAL(ht, key, value)
	if (EXPECTED(Z_TYPE_P(value) == IS_INDIRECT)) {
		value = Z_INDIRECT_P(value);
	}
	if (!isNull(value) || allowNull == true) {
		add_property_zval(rv, ZSTR_VAL(key), value);
	}
	ZEND_HASH_FOREACH_END();
}

#endif /* ECMA_INTL_PHP_COMMON_H */
