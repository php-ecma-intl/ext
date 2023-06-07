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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <unicode/ucal.h>
#include <unicode/uchar.h>
#include <unicode/uversion.h>

#include "ecma_intl.h"

#include "src/php/classes/calendar.h"
#include "src/php/classes/case_first.h"
#include "src/php/classes/category.h"
#include "src/php/classes/collation.h"
#include "src/php/classes/hour_cycle.h"
#include "src/php/classes/icu_exception.h"
#include "src/php/classes/locale_matcher.h"
#include "src/php/classes/numbering_system.h"
#include "src/php/classes/style.h"

#include <ext/standard/info.h>

zend_module_entry ecma_intl_module_entry = {STANDARD_MODULE_HEADER,
                                            "ecma_intl",
                                            NULL,
                                            PHP_MINIT(ecma_intl),
                                            NULL,
                                            PHP_RINIT(ecma_intl),
                                            NULL,
                                            PHP_MINFO(ecma_intl),
                                            PHP_ECMA_INTL_VERSION,
                                            STANDARD_MODULE_PROPERTIES};

#ifdef COMPILE_DL_ECMA_INTL
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(ecma_intl)
#endif

PHP_MINIT_FUNCTION(ecma_intl) {
  registerEcmaIntlCalendar();
  registerEcmaIntlCaseFirst();
  registerEcmaIntlCategory();
  registerEcmaIntlCollation();
  registerEcmaIntlHourCycle();
  registerEcmaIntlIcuException();
  registerEcmaIntlLocaleMatcher();
  registerEcmaIntlNumberingSystem();
  registerEcmaIntlStyle();

  return SUCCESS;
}

PHP_RINIT_FUNCTION(ecma_intl) {
#if defined(ZTS) && defined(COMPILE_DL_ECMA_INTL)
  ZEND_TSRMLS_CACHE_UPDATE();
#endif

  return SUCCESS;
}

PHP_MINFO_FUNCTION(ecma_intl) {
  UErrorCode status = U_ZERO_ERROR;
  const char *timeZoneDataVersion;

  timeZoneDataVersion = ucal_getTZDataVersion(&status);
  if (U_FAILURE(status)) {
    timeZoneDataVersion = "n/a";
  }

  php_info_print_table_start();
  php_info_print_table_header(
      2, "Internationalization Support, Ecma-style (ECMA-402)", "enabled");
  php_info_print_table_row(2, "ecma_intl version", PHP_ECMA_INTL_VERSION);
  php_info_print_table_row(2, "ICU version", U_ICU_VERSION);
  php_info_print_table_row(2, "ICU Data version", U_ICU_DATA_VERSION);
  php_info_print_table_row(2, "ICU TZData version", timeZoneDataVersion);
  php_info_print_table_row(2, "ICU Unicode version", U_UNICODE_VERSION);
  php_info_print_table_end();
}
