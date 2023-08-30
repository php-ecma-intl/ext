/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: b724e4f4feafd36532cb91b7639d6efb8257563e */




static const zend_function_entry class_Ecma_Intl_Locale_CharacterDirection_methods[] = {
	ZEND_FE_END
};

static zend_class_entry *register_class_Ecma_Intl_Locale_CharacterDirection(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Ecma\\Intl\\Locale\\CharacterDirection", IS_STRING, class_Ecma_Intl_Locale_CharacterDirection_methods);

	zval enum_case_LeftToRight_value;
	zend_string *enum_case_LeftToRight_value_str = zend_string_init("ltr", strlen("ltr"), 1);
	ZVAL_STR(&enum_case_LeftToRight_value, enum_case_LeftToRight_value_str);
	zend_enum_add_case_cstr(class_entry, "LeftToRight", &enum_case_LeftToRight_value);

	zval enum_case_RightToLeft_value;
	zend_string *enum_case_RightToLeft_value_str = zend_string_init("rtl", strlen("rtl"), 1);
	ZVAL_STR(&enum_case_RightToLeft_value, enum_case_RightToLeft_value_str);
	zend_enum_add_case_cstr(class_entry, "RightToLeft", &enum_case_RightToLeft_value);

	return class_entry;
}
