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

#include "icu_exception.h"

#include <ext/spl/spl_exceptions.h>

zend_class_entry *ecma_ce_IntlIcuException = NULL;

void registerEcmaIntlIcuException() {
  ecma_ce_IntlIcuException =
      register_class_Ecma_Intl_IcuException(spl_ce_RuntimeException);
}
