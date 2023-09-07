/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 8a3332b06d2eaa035c994427e73148c4391d1572 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Ecma_Intl_Collator_supportedLocalesOf, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, locales, Traversable|Stringable, MAY_BE_ARRAY|MAY_BE_STRING|MAY_BE_NULL, NULL)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, options, Ecma\\Intl\\SupportedLocales\\Options, 0, "null")
ZEND_END_ARG_INFO()


ZEND_METHOD(Ecma_Intl_Collator, supportedLocalesOf);


static const zend_function_entry class_Ecma_Intl_Collator_methods[] = {
	ZEND_ME(Ecma_Intl_Collator, supportedLocalesOf, arginfo_class_Ecma_Intl_Collator_supportedLocalesOf, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Ecma_Intl_Collator(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Ecma\\Intl", "Collator", class_Ecma_Intl_Collator_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_NO_DYNAMIC_PROPERTIES|ZEND_ACC_READONLY_CLASS;

	return class_entry;
}
