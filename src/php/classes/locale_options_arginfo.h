/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 0eb713c3b794d355ceb68b6bc3d64653511a138d */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ecma_Intl_Locale_Options___construct, 0, 0, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, calendar, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, caseFirst, Stringable, MAY_BE_STRING|MAY_BE_FALSE|MAY_BE_NULL, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, collation, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, currency, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, hourCycle, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, language, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, numberingSystem, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, numeric, _IS_BOOL, 1, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, region, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
	ZEND_ARG_OBJ_TYPE_MASK(0, script, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_Locale_Options_jsonSerialize, 0, 0, IS_OBJECT, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_Ecma_Intl_Locale_Options_current, 0, 0, MAY_BE_STRING|MAY_BE_BOOL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_Locale_Options_next, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_Locale_Options_key, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_Locale_Options_valid, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ecma_Intl_Locale_Options_rewind arginfo_class_Ecma_Intl_Locale_Options_next


ZEND_METHOD(Ecma_Intl_Locale_Options, __construct);
ZEND_METHOD(Ecma_Intl_Locale_Options, jsonSerialize);
ZEND_METHOD(Ecma_Intl_Locale_Options, current);
ZEND_METHOD(Ecma_Intl_Locale_Options, next);
ZEND_METHOD(Ecma_Intl_Locale_Options, key);
ZEND_METHOD(Ecma_Intl_Locale_Options, valid);
ZEND_METHOD(Ecma_Intl_Locale_Options, rewind);


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

	zval property_currency_default_value;
	ZVAL_UNDEF(&property_currency_default_value);
	zend_string *property_currency_name = zend_string_init("currency", sizeof("currency") - 1, 1);
	zend_declare_typed_property(class_entry, property_currency_name, &property_currency_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_currency_name);

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
