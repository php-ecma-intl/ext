/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 16a2914b84618354aca7d622fbaf98ff5e33a381 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ecma_Intl_Locale_TextInfo___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, direction, Ecma\\Intl\\Locale\\CharacterDirection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_Locale_TextInfo_jsonSerialize, 0, 0, IS_OBJECT, 0)
ZEND_END_ARG_INFO()


ZEND_METHOD(Ecma_Intl_Locale_TextInfo, __construct);
ZEND_METHOD(Ecma_Intl_Locale_TextInfo, jsonSerialize);


static const zend_function_entry class_Ecma_Intl_Locale_TextInfo_methods[] = {
	ZEND_ME(Ecma_Intl_Locale_TextInfo, __construct, arginfo_class_Ecma_Intl_Locale_TextInfo___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Ecma_Intl_Locale_TextInfo, jsonSerialize, arginfo_class_Ecma_Intl_Locale_TextInfo_jsonSerialize, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Ecma_Intl_Locale_TextInfo(zend_class_entry *class_entry_JsonSerializable)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ecma\\Intl\\Locale", "TextInfo", class_Ecma_Intl_Locale_TextInfo_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_READONLY_CLASS;
	zend_class_implements(class_entry, 1, class_entry_JsonSerializable);

	zend_string *property_direction_class_Ecma_Intl_Locale_CharacterDirection = zend_string_init("Ecma\\Intl\\Locale\\CharacterDirection", sizeof("Ecma\\Intl\\Locale\\CharacterDirection")-1, 1);
	zval property_direction_default_value;
	ZVAL_UNDEF(&property_direction_default_value);
	zend_string *property_direction_name = zend_string_init("direction", sizeof("direction") - 1, 1);
	zend_declare_typed_property(class_entry, property_direction_name, &property_direction_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_direction_class_Ecma_Intl_Locale_CharacterDirection, 0, 0));
	zend_string_release(property_direction_name);

	return class_entry;
}
