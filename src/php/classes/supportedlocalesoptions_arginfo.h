/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: cb5ca353a108c4cebe1ba16c4651a7a2ff9711e4 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ecma_Intl_SupportedLocalesOptions___construct, 0, 0, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, localeMatcher, Stringable, MAY_BE_STRING|MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_SupportedLocalesOptions_jsonSerialize, 0, 0, IS_OBJECT, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_class_Ecma_Intl_SupportedLocalesOptions_current, 0, 0, MAY_BE_STRING|MAY_BE_BOOL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_SupportedLocalesOptions_next, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_SupportedLocalesOptions_key, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_SupportedLocalesOptions_valid, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Ecma_Intl_SupportedLocalesOptions_rewind arginfo_class_Ecma_Intl_SupportedLocalesOptions_next


ZEND_METHOD(Ecma_Intl_SupportedLocalesOptions, __construct);
ZEND_METHOD(Ecma_Intl_SupportedLocalesOptions, jsonSerialize);
ZEND_METHOD(Ecma_Intl_SupportedLocalesOptions, current);
ZEND_METHOD(Ecma_Intl_SupportedLocalesOptions, next);
ZEND_METHOD(Ecma_Intl_SupportedLocalesOptions, key);
ZEND_METHOD(Ecma_Intl_SupportedLocalesOptions, valid);
ZEND_METHOD(Ecma_Intl_SupportedLocalesOptions, rewind);


static const zend_function_entry class_Ecma_Intl_SupportedLocalesOptions_methods[] = {
	ZEND_ME(Ecma_Intl_SupportedLocalesOptions, __construct, arginfo_class_Ecma_Intl_SupportedLocalesOptions___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_SupportedLocalesOptions, jsonSerialize, arginfo_class_Ecma_Intl_SupportedLocalesOptions_jsonSerialize, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_SupportedLocalesOptions, current, arginfo_class_Ecma_Intl_SupportedLocalesOptions_current, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_SupportedLocalesOptions, next, arginfo_class_Ecma_Intl_SupportedLocalesOptions_next, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_SupportedLocalesOptions, key, arginfo_class_Ecma_Intl_SupportedLocalesOptions_key, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_SupportedLocalesOptions, valid, arginfo_class_Ecma_Intl_SupportedLocalesOptions_valid, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_SupportedLocalesOptions, rewind, arginfo_class_Ecma_Intl_SupportedLocalesOptions_rewind, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Ecma_Intl_SupportedLocalesOptions(zend_class_entry *class_entry_Iterator, zend_class_entry *class_entry_JsonSerializable)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ecma\\Intl", "SupportedLocalesOptions", class_Ecma_Intl_SupportedLocalesOptions_methods);
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
