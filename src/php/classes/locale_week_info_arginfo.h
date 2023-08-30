/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 3051c3b438167cf62f52ffb9330009339345353b */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ecma_Intl_Locale_WeekInfo___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, firstDay, Ecma\\Intl\\Locale\\WeekDay, 0)
	ZEND_ARG_TYPE_INFO(0, weekend, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, minimalDays, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_Locale_WeekInfo_jsonSerialize, 0, 0, IS_OBJECT, 0)
ZEND_END_ARG_INFO()


ZEND_METHOD(Ecma_Intl_Locale_WeekInfo, __construct);
ZEND_METHOD(Ecma_Intl_Locale_WeekInfo, jsonSerialize);


static const zend_function_entry class_Ecma_Intl_Locale_WeekInfo_methods[] = {
	ZEND_ME(Ecma_Intl_Locale_WeekInfo, __construct, arginfo_class_Ecma_Intl_Locale_WeekInfo___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale_WeekInfo, jsonSerialize, arginfo_class_Ecma_Intl_Locale_WeekInfo_jsonSerialize, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Ecma_Intl_Locale_WeekInfo(zend_class_entry *class_entry_JsonSerializable)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ecma\\Intl\\Locale", "WeekInfo", class_Ecma_Intl_Locale_WeekInfo_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_READONLY_CLASS;
	zend_class_implements(class_entry, 1, class_entry_JsonSerializable);

	zend_string *property_firstDay_class_Ecma_Intl_Locale_WeekDay = zend_string_init("Ecma\\Intl\\Locale\\WeekDay", sizeof("Ecma\\Intl\\Locale\\WeekDay")-1, 1);
	zval property_firstDay_default_value;
	ZVAL_UNDEF(&property_firstDay_default_value);
	zend_string *property_firstDay_name = zend_string_init("firstDay", sizeof("firstDay") - 1, 1);
	zend_declare_typed_property(class_entry, property_firstDay_name, &property_firstDay_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_firstDay_class_Ecma_Intl_Locale_WeekDay, 0, 0));
	zend_string_release(property_firstDay_name);

	zval property_minimalDays_default_value;
	ZVAL_UNDEF(&property_minimalDays_default_value);
	zend_string *property_minimalDays_name = zend_string_init("minimalDays", sizeof("minimalDays") - 1, 1);
	zend_declare_typed_property(class_entry, property_minimalDays_name, &property_minimalDays_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_minimalDays_name);

	zval property_weekend_default_value;
	ZVAL_UNDEF(&property_weekend_default_value);
	zend_string *property_weekend_name = zend_string_init("weekend", sizeof("weekend") - 1, 1);
	zend_declare_typed_property(class_entry, property_weekend_name, &property_weekend_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_weekend_name);

	return class_entry;
}
