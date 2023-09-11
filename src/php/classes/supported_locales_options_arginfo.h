/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 04f145fc83e7d7e5db1575064f9dd04e535ff1f5 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ecma_Intl_SupportedLocales_Options___construct, 0, 0, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, localeMatcher, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_SupportedLocales_Options_jsonSerialize, 0, 0, IS_OBJECT, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_Ecma_Intl_SupportedLocales_Options_current, 0, 0, MAY_BE_STRING|MAY_BE_BOOL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_SupportedLocales_Options_next, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_SupportedLocales_Options_key, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_SupportedLocales_Options_valid, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ecma_Intl_SupportedLocales_Options_rewind arginfo_class_Ecma_Intl_SupportedLocales_Options_next


ZEND_METHOD(Ecma_Intl_SupportedLocales_Options, __construct);
ZEND_METHOD(Ecma_Intl_SupportedLocales_Options, jsonSerialize);
ZEND_METHOD(Ecma_Intl_SupportedLocales_Options, current);
ZEND_METHOD(Ecma_Intl_SupportedLocales_Options, next);
ZEND_METHOD(Ecma_Intl_SupportedLocales_Options, key);
ZEND_METHOD(Ecma_Intl_SupportedLocales_Options, valid);
ZEND_METHOD(Ecma_Intl_SupportedLocales_Options, rewind);


static const zend_function_entry class_Ecma_Intl_SupportedLocales_Options_methods[] = {
	ZEND_ME(Ecma_Intl_SupportedLocales_Options, __construct, arginfo_class_Ecma_Intl_SupportedLocales_Options___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_SupportedLocales_Options, jsonSerialize, arginfo_class_Ecma_Intl_SupportedLocales_Options_jsonSerialize, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_SupportedLocales_Options, current, arginfo_class_Ecma_Intl_SupportedLocales_Options_current, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_SupportedLocales_Options, next, arginfo_class_Ecma_Intl_SupportedLocales_Options_next, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_SupportedLocales_Options, key, arginfo_class_Ecma_Intl_SupportedLocales_Options_key, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_SupportedLocales_Options, valid, arginfo_class_Ecma_Intl_SupportedLocales_Options_valid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_SupportedLocales_Options, rewind, arginfo_class_Ecma_Intl_SupportedLocales_Options_rewind, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Ecma_Intl_SupportedLocales_Options(zend_class_entry *class_entry_Iterator, zend_class_entry *class_entry_JsonSerializable)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ecma\\Intl\\SupportedLocales", "Options", class_Ecma_Intl_SupportedLocales_Options_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_NO_DYNAMIC_PROPERTIES|ZEND_ACC_READONLY_CLASS;
	zend_class_implements(class_entry, 2, class_entry_Iterator, class_entry_JsonSerializable);

	zval property_localeMatcher_default_value;
	ZVAL_UNDEF(&property_localeMatcher_default_value);
	zend_string *property_localeMatcher_name = zend_string_init("localeMatcher", sizeof("localeMatcher") - 1, 1);
	zend_declare_typed_property(class_entry, property_localeMatcher_name, &property_localeMatcher_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING|MAY_BE_NULL));
	zend_string_release(property_localeMatcher_name);

	return class_entry;
}
