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

ZEND_BEGIN_MODULE_GLOBALS(ecma_intl)
char *defaultLocale;
ZEND_END_MODULE_GLOBALS(ecma_intl)

#if defined(ZTS) && defined(COMPILE_DL_ECMA_INTL)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

ZEND_EXTERN_MODULE_GLOBALS(ecma_intl)
#ifdef ZTS
#	define ECMA_INTL_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(ecma_intl, v)
#else
#	define ECMA_INTL_G(v) (ecma_intl_globals.v)
#endif

PHP_MINIT_FUNCTION(ecma_intl_all);
PHP_MSHUTDOWN_FUNCTION(ecma_intl);
PHP_RINIT_FUNCTION(ecma_intl);
PHP_MINFO_FUNCTION(ecma_intl);

#endif /* PHP_ECMA_INTL_H */
