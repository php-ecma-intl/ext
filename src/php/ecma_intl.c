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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php/ecma_intl.h"

#include "php/classes/category.h"
#include "php/classes/intl.h"
#include "php/classes/locale.h"
#include "php/classes/locale_character_direction.h"
#include "php/classes/locale_options.h"
#include "php/classes/locale_text_info.h"
#include "php/classes/locale_week_day.h"
#include "php/classes/locale_week_info.h"

#include <ext/standard/info.h>
#include <unicode/ucal.h>

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
  registerEcmaIntl();
  registerEcmaIntlCategory();
  registerEcmaIntlLocale();
  registerEcmaIntlLocaleCharacterDirection();
  registerEcmaIntlLocaleOptions();
  PHP_MINIT(ecma_intl_locale_textinfo)(INIT_FUNC_ARGS_PASSTHRU);
  PHP_MINIT(ecma_intl_locale_weekday)(INIT_FUNC_ARGS_PASSTHRU);
  PHP_MINIT(ecma_intl_locale_weekinfo)(INIT_FUNC_ARGS_PASSTHRU);

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
  const char *timeZoneDataVersion = NULL;

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
