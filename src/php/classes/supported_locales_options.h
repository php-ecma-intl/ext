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

#ifndef ECMA_INTL_PHP_CLASSES_SUPPORTED_LOCALES_OPTIONS_H
#define ECMA_INTL_PHP_CLASSES_SUPPORTED_LOCALES_OPTIONS_H

#include "php/php_common.h"

#include "php/classes/options.h"

extern zend_class_entry *ecma_ce_IntlSupportedLocalesOptions;

PHP_MINIT_FUNCTION(ecma_intl_supported_locales_options);

#endif /* ECMA_INTL_PHP_CLASSES_SUPPORTED_LOCALES_OPTIONS_H */
