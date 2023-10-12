/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 0a9caf1fa256e5d5624abd6246fe876110ad77b5 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Ecma_Intl_defaultLocale, 0, 0, Ecma\\Intl\\Locale, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_getCanonicalLocales, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, locales, Traversable|Stringable, MAY_BE_ARRAY|MAY_BE_STRING|MAY_BE_NULL, NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_supportedValuesOf, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, category, Ecma\\Intl\\Category, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Ecma_Intl___construct, 0, 0, 0)
ZEND_END_ARG_INFO()


ZEND_METHOD(Ecma_Intl, defaultLocale);
ZEND_METHOD(Ecma_Intl, getCanonicalLocales);
ZEND_METHOD(Ecma_Intl, supportedValuesOf);
ZEND_METHOD(Ecma_Intl, __construct);


static const zend_function_entry class_Ecma_Intl_methods[] = {
	ZEND_ME(Ecma_Intl, defaultLocale, arginfo_class_Ecma_Intl_defaultLocale, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Ecma_Intl, getCanonicalLocales, arginfo_class_Ecma_Intl_getCanonicalLocales, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Ecma_Intl, supportedValuesOf, arginfo_class_Ecma_Intl_supportedValuesOf, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Ecma_Intl, __construct, arginfo_class_Ecma_Intl___construct, ZEND_ACC_PRIVATE)
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
