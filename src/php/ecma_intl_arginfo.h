/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: d7b5c71a970d111f306134c6ebf867e40d14c1fd */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_getCanonicalLocales, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, locales, Traversable|Stringable, MAY_BE_ARRAY|MAY_BE_STRING|MAY_BE_NULL, NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_supportedValuesOf, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, category, Ecma\\Intl\\Category, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ecma_Intl___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ecma_Intl_Locale___construct, 0, 0, 1)
	ZEND_ARG_OBJ_TYPE_MASK(0, tag, Stringable, MAY_BE_STRING, NULL)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, options, Ecma\\Intl\\Locale\\Options, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_Locale___toString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_Locale_getCalendars, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ecma_Intl_Locale_getCollations arginfo_class_Ecma_Intl_Locale_getCalendars

#define arginfo_class_Ecma_Intl_Locale_getCurrencies arginfo_class_Ecma_Intl_Locale_getCalendars

#define arginfo_class_Ecma_Intl_Locale_getHourCycles arginfo_class_Ecma_Intl_Locale_getCalendars

#define arginfo_class_Ecma_Intl_Locale_getNumberingSystems arginfo_class_Ecma_Intl_Locale_getCalendars

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_Locale_getTimeZones, 0, 0, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_Locale_jsonSerialize, 0, 0, IS_OBJECT, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Ecma_Intl_Locale_maximize, 0, 0, Ecma\\Intl\\Locale, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ecma_Intl_Locale_minimize arginfo_class_Ecma_Intl_Locale_maximize

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ecma_Intl_Locale_Options___construct, 0, 0, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, calendar, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, caseFirst, Stringable, MAY_BE_STRING|MAY_BE_FALSE|MAY_BE_NULL, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, collation, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, hourCycle, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, language, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, numberingSystem, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, numeric, _IS_BOOL, 1, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, region, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, script, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_Ecma_Intl_Locale_Options_jsonSerialize arginfo_class_Ecma_Intl_Locale_jsonSerialize

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_Ecma_Intl_Locale_Options_current, 0, 0, MAY_BE_STRING|MAY_BE_BOOL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_Locale_Options_next, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ecma_Intl_Locale_Options_key arginfo_class_Ecma_Intl_Locale___toString

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_Locale_Options_valid, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ecma_Intl_Locale_Options_rewind arginfo_class_Ecma_Intl_Locale_Options_next


ZEND_METHOD(Ecma_Intl, getCanonicalLocales);
ZEND_METHOD(Ecma_Intl, supportedValuesOf);
ZEND_METHOD(Ecma_Intl, __construct);
ZEND_METHOD(Ecma_Intl_Locale, __construct);
ZEND_METHOD(Ecma_Intl_Locale, __toString);
ZEND_METHOD(Ecma_Intl_Locale, getCalendars);
ZEND_METHOD(Ecma_Intl_Locale, getCollations);
ZEND_METHOD(Ecma_Intl_Locale, getCurrencies);
ZEND_METHOD(Ecma_Intl_Locale, getHourCycles);
ZEND_METHOD(Ecma_Intl_Locale, getNumberingSystems);
ZEND_METHOD(Ecma_Intl_Locale, getTimeZones);
ZEND_METHOD(Ecma_Intl_Locale, jsonSerialize);
ZEND_METHOD(Ecma_Intl_Locale, maximize);
ZEND_METHOD(Ecma_Intl_Locale, minimize);
ZEND_METHOD(Ecma_Intl_Locale_Options, __construct);
ZEND_METHOD(Ecma_Intl_Locale_Options, jsonSerialize);
ZEND_METHOD(Ecma_Intl_Locale_Options, current);
ZEND_METHOD(Ecma_Intl_Locale_Options, next);
ZEND_METHOD(Ecma_Intl_Locale_Options, key);
ZEND_METHOD(Ecma_Intl_Locale_Options, valid);
ZEND_METHOD(Ecma_Intl_Locale_Options, rewind);


static const zend_function_entry class_Ecma_Intl_methods[] = {
	ZEND_ME(Ecma_Intl, getCanonicalLocales, arginfo_class_Ecma_Intl_getCanonicalLocales, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Ecma_Intl, supportedValuesOf, arginfo_class_Ecma_Intl_supportedValuesOf, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Ecma_Intl, __construct, arginfo_class_Ecma_Intl___construct, ZEND_ACC_PRIVATE)
	ZEND_FE_END
};


static const zend_function_entry class_Ecma_Intl_Category_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ecma_Intl_Locale_methods[] = {
	ZEND_ME(Ecma_Intl_Locale, __construct, arginfo_class_Ecma_Intl_Locale___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale, __toString, arginfo_class_Ecma_Intl_Locale___toString, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale, getCalendars, arginfo_class_Ecma_Intl_Locale_getCalendars, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale, getCollations, arginfo_class_Ecma_Intl_Locale_getCollations, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale, getCurrencies, arginfo_class_Ecma_Intl_Locale_getCurrencies, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale, getHourCycles, arginfo_class_Ecma_Intl_Locale_getHourCycles, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale, getNumberingSystems, arginfo_class_Ecma_Intl_Locale_getNumberingSystems, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale, getTimeZones, arginfo_class_Ecma_Intl_Locale_getTimeZones, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale, jsonSerialize, arginfo_class_Ecma_Intl_Locale_jsonSerialize, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale, maximize, arginfo_class_Ecma_Intl_Locale_maximize, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale, minimize, arginfo_class_Ecma_Intl_Locale_minimize, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Ecma_Intl_Locale_Options_methods[] = {
	ZEND_ME(Ecma_Intl_Locale_Options, __construct, arginfo_class_Ecma_Intl_Locale_Options___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale_Options, jsonSerialize, arginfo_class_Ecma_Intl_Locale_Options_jsonSerialize, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale_Options, current, arginfo_class_Ecma_Intl_Locale_Options_current, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale_Options, next, arginfo_class_Ecma_Intl_Locale_Options_next, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale_Options, key, arginfo_class_Ecma_Intl_Locale_Options_key, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale_Options, valid, arginfo_class_Ecma_Intl_Locale_Options_valid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale_Options, rewind, arginfo_class_Ecma_Intl_Locale_Options_rewind, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Ecma_Intl(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ecma", "Intl", class_Ecma_Intl_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	zval const_ICU_VERSION_value;
	zend_string *const_ICU_VERSION_value_str = zend_string_init(U_ICU_VERSION, strlen(U_ICU_VERSION), 1);
	ZVAL_STR(&const_ICU_VERSION_value, const_ICU_VERSION_value_str);
	zend_string *const_ICU_VERSION_name = zend_string_init_interned("ICU_VERSION", sizeof("ICU_VERSION") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_ICU_VERSION_name, &const_ICU_VERSION_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_ICU_VERSION_name);

	zval const_UNICODE_VERSION_value;
	zend_string *const_UNICODE_VERSION_value_str = zend_string_init(U_UNICODE_VERSION, strlen(U_UNICODE_VERSION), 1);
	ZVAL_STR(&const_UNICODE_VERSION_value, const_UNICODE_VERSION_value_str);
	zend_string *const_UNICODE_VERSION_name = zend_string_init_interned("UNICODE_VERSION", sizeof("UNICODE_VERSION") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_UNICODE_VERSION_name, &const_UNICODE_VERSION_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_UNICODE_VERSION_name);

	return class_entry;
}

static zend_class_entry *register_class_Ecma_Intl_Category(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Ecma\\Intl\\Category", IS_STRING, class_Ecma_Intl_Category_methods);

	zval enum_case_Calendar_value;
	zend_string *enum_case_Calendar_value_str = zend_string_init("calendar", strlen("calendar"), 1);
	ZVAL_STR(&enum_case_Calendar_value, enum_case_Calendar_value_str);
	zend_enum_add_case_cstr(class_entry, "Calendar", &enum_case_Calendar_value);

	zval enum_case_Collation_value;
	zend_string *enum_case_Collation_value_str = zend_string_init("collation", strlen("collation"), 1);
	ZVAL_STR(&enum_case_Collation_value, enum_case_Collation_value_str);
	zend_enum_add_case_cstr(class_entry, "Collation", &enum_case_Collation_value);

	zval enum_case_Currency_value;
	zend_string *enum_case_Currency_value_str = zend_string_init("currency", strlen("currency"), 1);
	ZVAL_STR(&enum_case_Currency_value, enum_case_Currency_value_str);
	zend_enum_add_case_cstr(class_entry, "Currency", &enum_case_Currency_value);

	zval enum_case_NumberingSystem_value;
	zend_string *enum_case_NumberingSystem_value_str = zend_string_init("numberingSystem", strlen("numberingSystem"), 1);
	ZVAL_STR(&enum_case_NumberingSystem_value, enum_case_NumberingSystem_value_str);
	zend_enum_add_case_cstr(class_entry, "NumberingSystem", &enum_case_NumberingSystem_value);

	zval enum_case_TimeZone_value;
	zend_string *enum_case_TimeZone_value_str = zend_string_init("timeZone", strlen("timeZone"), 1);
	ZVAL_STR(&enum_case_TimeZone_value, enum_case_TimeZone_value_str);
	zend_enum_add_case_cstr(class_entry, "TimeZone", &enum_case_TimeZone_value);

	zval enum_case_Unit_value;
	zend_string *enum_case_Unit_value_str = zend_string_init("unit", strlen("unit"), 1);
	ZVAL_STR(&enum_case_Unit_value, enum_case_Unit_value_str);
	zend_enum_add_case_cstr(class_entry, "Unit", &enum_case_Unit_value);

	return class_entry;
}

static zend_class_entry *register_class_Ecma_Intl_Locale(zend_class_entry *class_entry_JsonSerializable, zend_class_entry *class_entry_Stringable)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ecma\\Intl", "Locale", class_Ecma_Intl_Locale_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_NO_DYNAMIC_PROPERTIES|ZEND_ACC_READONLY_CLASS;
	zend_class_implements(class_entry, 2, class_entry_JsonSerializable, class_entry_Stringable);

	zval property_baseName_default_value;
	ZVAL_UNDEF(&property_baseName_default_value);
	zend_string *property_baseName_name = zend_string_init("baseName", sizeof("baseName") - 1, 1);
	zend_declare_typed_property(class_entry, property_baseName_name, &property_baseName_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_baseName_name);

	zval property_calendar_default_value;
	ZVAL_UNDEF(&property_calendar_default_value);
	zend_string *property_calendar_name = zend_string_init("calendar", sizeof("calendar") - 1, 1);
	zend_declare_typed_property(class_entry, property_calendar_name, &property_calendar_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_calendar_name);

	zval property_calendars_default_value;
	ZVAL_UNDEF(&property_calendars_default_value);
	zend_string *property_calendars_name = zend_string_init("calendars", sizeof("calendars") - 1, 1);
	zend_declare_typed_property(class_entry, property_calendars_name, &property_calendars_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_calendars_name);

	zval property_caseFirst_default_value;
	ZVAL_UNDEF(&property_caseFirst_default_value);
	zend_string *property_caseFirst_name = zend_string_init("caseFirst", sizeof("caseFirst") - 1, 1);
	zend_declare_typed_property(class_entry, property_caseFirst_name, &property_caseFirst_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_caseFirst_name);

	zval property_collation_default_value;
	ZVAL_UNDEF(&property_collation_default_value);
	zend_string *property_collation_name = zend_string_init("collation", sizeof("collation") - 1, 1);
	zend_declare_typed_property(class_entry, property_collation_name, &property_collation_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_collation_name);

	zval property_collations_default_value;
	ZVAL_UNDEF(&property_collations_default_value);
	zend_string *property_collations_name = zend_string_init("collations", sizeof("collations") - 1, 1);
	zend_declare_typed_property(class_entry, property_collations_name, &property_collations_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_collations_name);

	zval property_currencies_default_value;
	ZVAL_UNDEF(&property_currencies_default_value);
	zend_string *property_currencies_name = zend_string_init("currencies", sizeof("currencies") - 1, 1);
	zend_declare_typed_property(class_entry, property_currencies_name, &property_currencies_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_currencies_name);

	zval property_hourCycle_default_value;
	ZVAL_UNDEF(&property_hourCycle_default_value);
	zend_string *property_hourCycle_name = zend_string_init("hourCycle", sizeof("hourCycle") - 1, 1);
	zend_declare_typed_property(class_entry, property_hourCycle_name, &property_hourCycle_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_hourCycle_name);

	zval property_hourCycles_default_value;
	ZVAL_UNDEF(&property_hourCycles_default_value);
	zend_string *property_hourCycles_name = zend_string_init("hourCycles", sizeof("hourCycles") - 1, 1);
	zend_declare_typed_property(class_entry, property_hourCycles_name, &property_hourCycles_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_hourCycles_name);

	zval property_language_default_value;
	ZVAL_UNDEF(&property_language_default_value);
	zend_string *property_language_name = zend_string_init("language", sizeof("language") - 1, 1);
	zend_declare_typed_property(class_entry, property_language_name, &property_language_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_language_name);

	zval property_numberingSystem_default_value;
	ZVAL_UNDEF(&property_numberingSystem_default_value);
	zend_string *property_numberingSystem_name = zend_string_init("numberingSystem", sizeof("numberingSystem") - 1, 1);
	zend_declare_typed_property(class_entry, property_numberingSystem_name, &property_numberingSystem_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_numberingSystem_name);

	zval property_numberingSystems_default_value;
	ZVAL_UNDEF(&property_numberingSystems_default_value);
	zend_string *property_numberingSystems_name = zend_string_init("numberingSystems", sizeof("numberingSystems") - 1, 1);
	zend_declare_typed_property(class_entry, property_numberingSystems_name, &property_numberingSystems_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_numberingSystems_name);

	zval property_numeric_default_value;
	ZVAL_UNDEF(&property_numeric_default_value);
	zend_string *property_numeric_name = zend_string_init("numeric", sizeof("numeric") - 1, 1);
	zend_declare_typed_property(class_entry, property_numeric_name, &property_numeric_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_numeric_name);

	zval property_region_default_value;
	ZVAL_UNDEF(&property_region_default_value);
	zend_string *property_region_name = zend_string_init("region", sizeof("region") - 1, 1);
	zend_declare_typed_property(class_entry, property_region_name, &property_region_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_region_name);

	zval property_script_default_value;
	ZVAL_UNDEF(&property_script_default_value);
	zend_string *property_script_name = zend_string_init("script", sizeof("script") - 1, 1);
	zend_declare_typed_property(class_entry, property_script_name, &property_script_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_script_name);

	zval property_timeZones_default_value;
	ZVAL_UNDEF(&property_timeZones_default_value);
	zend_string *property_timeZones_name = zend_string_init("timeZones", sizeof("timeZones") - 1, 1);
	zend_declare_typed_property(class_entry, property_timeZones_name, &property_timeZones_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY|MAY_BE_NULL));
	zend_string_release(property_timeZones_name);

	return class_entry;
}

static zend_class_entry *register_class_Ecma_Intl_Locale_Options(zend_class_entry *class_entry_Iterator, zend_class_entry *class_entry_JsonSerializable)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ecma\\Intl\\Locale", "Options", class_Ecma_Intl_Locale_Options_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_NO_DYNAMIC_PROPERTIES|ZEND_ACC_READONLY_CLASS;
	zend_class_implements(class_entry, 2, class_entry_Iterator, class_entry_JsonSerializable);

	zval property_calendar_default_value;
	ZVAL_UNDEF(&property_calendar_default_value);
	zend_string *property_calendar_name = zend_string_init("calendar", sizeof("calendar") - 1, 1);
	zend_declare_typed_property(class_entry, property_calendar_name, &property_calendar_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_calendar_name);

	zval property_caseFirst_default_value;
	ZVAL_UNDEF(&property_caseFirst_default_value);
	zend_string *property_caseFirst_name = zend_string_init("caseFirst", sizeof("caseFirst") - 1, 1);
	zend_declare_typed_property(class_entry, property_caseFirst_name, &property_caseFirst_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_caseFirst_name);

	zval property_collation_default_value;
	ZVAL_UNDEF(&property_collation_default_value);
	zend_string *property_collation_name = zend_string_init("collation", sizeof("collation") - 1, 1);
	zend_declare_typed_property(class_entry, property_collation_name, &property_collation_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_collation_name);

	zval property_hourCycle_default_value;
	ZVAL_UNDEF(&property_hourCycle_default_value);
	zend_string *property_hourCycle_name = zend_string_init("hourCycle", sizeof("hourCycle") - 1, 1);
	zend_declare_typed_property(class_entry, property_hourCycle_name, &property_hourCycle_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_hourCycle_name);

	zval property_language_default_value;
	ZVAL_UNDEF(&property_language_default_value);
	zend_string *property_language_name = zend_string_init("language", sizeof("language") - 1, 1);
	zend_declare_typed_property(class_entry, property_language_name, &property_language_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_language_name);

	zval property_numberingSystem_default_value;
	ZVAL_UNDEF(&property_numberingSystem_default_value);
	zend_string *property_numberingSystem_name = zend_string_init("numberingSystem", sizeof("numberingSystem") - 1, 1);
	zend_declare_typed_property(class_entry, property_numberingSystem_name, &property_numberingSystem_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_numberingSystem_name);

	zval property_numeric_default_value;
	ZVAL_UNDEF(&property_numeric_default_value);
	zend_string *property_numeric_name = zend_string_init("numeric", sizeof("numeric") - 1, 1);
	zend_declare_typed_property(class_entry, property_numeric_name, &property_numeric_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL|MAY_BE_NULL));
	zend_string_release(property_numeric_name);

	zval property_region_default_value;
	ZVAL_UNDEF(&property_region_default_value);
	zend_string *property_region_name = zend_string_init("region", sizeof("region") - 1, 1);
	zend_declare_typed_property(class_entry, property_region_name, &property_region_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_region_name);

	zval property_script_default_value;
	ZVAL_UNDEF(&property_script_default_value);
	zend_string *property_script_name = zend_string_init("script", sizeof("script") - 1, 1);
	zend_declare_typed_property(class_entry, property_script_name, &property_script_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_script_name);

	return class_entry;
}
