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

#include "hour_cycle.h"

zend_class_entry *ecma_ce_IntlHourCycle = NULL;

void registerEcmaIntlHourCycle() {
  ecma_ce_IntlHourCycle = register_class_Ecma_Intl_HourCycle();
}
