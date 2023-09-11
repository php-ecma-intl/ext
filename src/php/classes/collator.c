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

#include "php/classes/collator.h"

#include "ecma402/error.h"
#include "php/supported_locales.h"

#include "php/classes/collator_arginfo.h"

#include <ext/spl/spl_iterators.h>

zend_class_entry *ecma_ce_IntlCollator = NULL;
zend_object_handlers ecma_handlers_IntlCollator;

static void freeCollatorObj(zend_object *object);

PHP_MINIT_FUNCTION(ecma_intl_collator)
{
	ecma_ce_IntlCollator = register_class_Ecma_Intl_Collator();
	ecma_ce_IntlCollator->create_object = ecma_createIntlCollator;
#if PHP_VERSION_ID >= 80300
	ecma_ce_IntlCollator->default_object_handlers = &ecma_handlers_IntlCollator;
#endif

	memcpy(&ecma_handlers_IntlCollator, zend_get_std_object_handlers(), sizeof(zend_object_handlers));

	ecma_handlers_IntlCollator.offset = XtOffsetOf(ecma_IntlCollator, std);
	ecma_handlers_IntlCollator.free_obj = freeCollatorObj;

	return SUCCESS;
}

zend_object *ecma_createIntlCollator(zend_class_entry *classEntry)
{
	ecma_IntlCollator *intlCollator;

	intlCollator = zend_object_alloc(sizeof(struct ecma_IntlCollator), classEntry);

	zend_object_std_init(&intlCollator->std, classEntry);
	object_properties_init(&intlCollator->std, classEntry);

#if PHP_VERSION_ID < 80300
	intlCollator->std.handlers = &ecma_handlers_IntlCollator;
#endif

	return &intlCollator->std;
}

PHP_METHOD(Ecma_Intl_Collator, supportedLocalesOf)
{
	return ecma_supportedLocalesOf(execute_data, return_value);
}

static void freeCollatorObj(zend_object *object)
{
	ecma_IntlCollator *intlCollator = ecma_IntlCollatorFromObj(object);
	zend_object_std_dtor(&intlCollator->std);
}
