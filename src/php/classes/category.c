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

#include "php/classes/category.h"

zend_class_entry *ecma_ce_IntlCategory = NULL;

void registerEcmaIntlCategory() {
  ecma_ce_IntlCategory = register_class_Ecma_Intl_Category();
}
