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

#include "php/classes/locale_week_info.h"

#include "php/classes/locale_week_day.h"

#include "php/classes/locale_week_info_arginfo.h"

#include <ext/json/php_json.h>

zend_class_entry *ecma_ce_IntlLocaleWeekInfo = NULL;
zend_object_handlers ecma_handlers_IntlLocaleWeekInfo;

static void freeLocaleWeekInfoObj(zend_object *object);

PHP_MINIT_FUNCTION(ecma_intl_locale_weekinfo) {
	ecma_ce_IntlLocaleWeekInfo = register_class_Ecma_Intl_Locale_WeekInfo(php_json_serializable_ce);
	ecma_ce_IntlLocaleWeekInfo->create_object = ecma_createIntlLocaleWeekInfo;
#if PHP_VERSION_ID >= 80300
	ecma_ce_IntlLocaleWeekInfo->default_object_handlers = &ecma_handlers_IntlLocaleWeekInfo;
#endif

	memcpy(&ecma_handlers_IntlLocaleWeekInfo, zend_get_std_object_handlers(), sizeof(zend_object_handlers));

	ecma_handlers_IntlLocaleWeekInfo.offset = XtOffsetOf(ecma_IntlLocaleWeekInfo, std);
	ecma_handlers_IntlLocaleWeekInfo.free_obj = freeLocaleWeekInfoObj;

	return SUCCESS;
}
zend_object *ecma_createIntlLocaleWeekInfo(zend_class_entry *classEntry) {
	ecma_IntlLocaleWeekInfo *intlLocaleWeekInfo;

	intlLocaleWeekInfo = zend_object_alloc(sizeof(struct ecma_IntlLocaleWeekInfo), classEntry);

	zend_object_std_init(&intlLocaleWeekInfo->std, classEntry);
	object_properties_init(&intlLocaleWeekInfo->std, classEntry);

#if PHP_VERSION_ID < 80300
	intlLocaleWeekInfo->std.handlers = &ecma_handlers_IntlLocaleWeekInfo;
#endif

	return &intlLocaleWeekInfo->std;
}

PHP_METHOD(Ecma_Intl_Locale_WeekInfo, __construct) {
	zval *firstDay, *weekend, *weekendItem;
	zend_object *this;
	zend_long minimalDays;
	ecma_IntlLocaleWeekInfo *intlLocaleWeekInfo;

	ZEND_PARSE_PARAMETERS_START(3, 3)
	Z_PARAM_OBJECT_OF_CLASS(firstDay, ecma_ce_IntlLocaleWeekDay);
	Z_PARAM_ARRAY(weekend)
	Z_PARAM_LONG(minimalDays)
	ZEND_PARSE_PARAMETERS_END();

	// Ensure each item in the weekend array is a WeekDay instance.
	ZEND_HASH_FOREACH_VAL(Z_ARR_P(weekend), weekendItem);
	if (!EXPECTED(Z_TYPE_P(weekendItem) == IS_OBJECT) ||
	    !EXPECTED(instanceof_function(Z_OBJCE_P(weekendItem), ecma_ce_IntlLocaleWeekDay) != 0)) {
		zend_argument_type_error(2, "must be of type array<Ecma\\Intl\\Locale\\WeekDay>, %s found in array",
		                         zend_zval_type_name(weekendItem));
		RETURN_THROWS();
	}
	ZEND_HASH_FOREACH_END();

	// Ensure minimalDays is of value 1 - 7.
	if (minimalDays < 1 || minimalDays > 7) {
		zend_argument_value_error(3, "must be an integer from 1 to 7");
		RETURN_THROWS();
	}

	intlLocaleWeekInfo = ECMA_LOCALE_WEEK_INFO_P(getThis());
	this = &intlLocaleWeekInfo->std;

	zend_update_property(ecma_ce_IntlLocaleWeekInfo, this, "firstDay", strlen("firstDay"), firstDay);

	zend_update_property(ecma_ce_IntlLocaleWeekInfo, this, "weekend", strlen("weekend"), weekend);

	zend_update_property_long(ecma_ce_IntlLocaleWeekInfo, this, "minimalDays", strlen("minimalDays"), minimalDays);
}

PHP_METHOD(Ecma_Intl_Locale_WeekInfo, jsonSerialize) {
	ecma_IntlLocaleWeekInfo *intlLocaleWeekInfo;
	zend_object *this;
	zval firstDay, weekend, minimalDays, rv;

	ZEND_PARSE_PARAMETERS_NONE();

	intlLocaleWeekInfo = ECMA_LOCALE_WEEK_INFO_P(getThis());
	this = &intlLocaleWeekInfo->std;

	firstDay = *zend_read_property(ecma_ce_IntlLocaleWeekInfo, this, "firstDay", strlen("firstDay"), false, &rv);
	weekend = *zend_read_property(ecma_ce_IntlLocaleWeekInfo, this, "weekend", strlen("weekend"), false, &rv);
	minimalDays =
		*zend_read_property(ecma_ce_IntlLocaleWeekInfo, this, "minimalDays", strlen("minimalDays"), false, &rv);

	object_init(return_value);
	add_property_zval(return_value, "firstDay", &firstDay);
	add_property_zval(return_value, "weekend", &weekend);
	add_property_zval(return_value, "minimalDays", &minimalDays);
}

static void freeLocaleWeekInfoObj(zend_object *object) {
	ecma_IntlLocaleWeekInfo *intlLocaleWeekInfo = ecma_IntlLocaleWeekInfoFromObj(object);
	zend_object_std_dtor(&intlLocaleWeekInfo->std);
}
