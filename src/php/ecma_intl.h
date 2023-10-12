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

#ifndef PHP_ECMA_INTL_H
#define PHP_ECMA_INTL_H

#include "php/php_common.h"

extern zend_module_entry ecma_intl_module_entry;
#define phpext_ecma_intl_ptr &ecma_intl_module_entry

#define PHP_ECMA_INTL_VERSION "0.3.0-dev"
#define PHP_ECMA_INI_DEFAULT_LOCALE "ecma_intl.default_locale"
#define PHP_ECMA_FALLBACK_LOCALE "en"

#if defined(ZTS) && defined(COMPILE_DL_ECMA_INTL)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

PHP_MINIT_FUNCTION(ecma_intl_all);
PHP_MSHUTDOWN_FUNCTION(ecma_intl);
PHP_RINIT_FUNCTION(ecma_intl);
PHP_MINFO_FUNCTION(ecma_intl);

/**
 * Returns the default locale. First, this checks the INI setting
 * ecma_intl.default_locale. If populated, it validates and canonicalizes the
 * setting before returning it. If not set, or the value does not validate or
 * canonicalize, it falls back to the ICU default locale. If the ICU default
 * locale does not validate or canonicalize, it falls back to "en".
 *
 * The return value is already heap-allocated using emalloc() and should be
 * freed by the caller with efree().
 */
char *ecma_defaultLocale();

#endif /* PHP_ECMA_INTL_H */
