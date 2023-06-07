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

#include "style.h"

zend_class_entry *ecma_ce_IntlStyle = NULL;

void registerEcmaIntlStyle() {
  ecma_ce_IntlStyle = register_class_Ecma_Intl_Style();
}
