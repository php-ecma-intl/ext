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

#ifndef ECMA_INTL_PHP_COMMON_H
#define ECMA_INTL_PHP_COMMON_H

#include "common.h"

#include <php.h>
#include <zend_enum.h>

#include "php/ecma_intl_arginfo.h"

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

#endif /* ECMA_INTL_PHP_COMMON_H */
