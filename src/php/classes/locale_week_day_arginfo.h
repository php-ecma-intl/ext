/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 48f2ce6de6cf74fe5b1287def88c60e462514690 */




static const zend_function_entry class_Ecma_Intl_Locale_WeekDay_methods[] = {
	ZEND_FE_END
};

static zend_class_entry *register_class_Ecma_Intl_Locale_WeekDay(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Ecma\\Intl\\Locale\\WeekDay", IS_LONG, class_Ecma_Intl_Locale_WeekDay_methods);

	zval enum_case_Monday_value;
	ZVAL_LONG(&enum_case_Monday_value, 1);
	zend_enum_add_case_cstr(class_entry, "Monday", &enum_case_Monday_value);

	zval enum_case_Tuesday_value;
	ZVAL_LONG(&enum_case_Tuesday_value, 2);
	zend_enum_add_case_cstr(class_entry, "Tuesday", &enum_case_Tuesday_value);

	zval enum_case_Wednesday_value;
	ZVAL_LONG(&enum_case_Wednesday_value, 3);
	zend_enum_add_case_cstr(class_entry, "Wednesday", &enum_case_Wednesday_value);

	zval enum_case_Thursday_value;
	ZVAL_LONG(&enum_case_Thursday_value, 4);
	zend_enum_add_case_cstr(class_entry, "Thursday", &enum_case_Thursday_value);

	zval enum_case_Friday_value;
	ZVAL_LONG(&enum_case_Friday_value, 5);
	zend_enum_add_case_cstr(class_entry, "Friday", &enum_case_Friday_value);

	zval enum_case_Saturday_value;
	ZVAL_LONG(&enum_case_Saturday_value, 6);
	zend_enum_add_case_cstr(class_entry, "Saturday", &enum_case_Saturday_value);

	zval enum_case_Sunday_value;
	ZVAL_LONG(&enum_case_Sunday_value, 7);
	zend_enum_add_case_cstr(class_entry, "Sunday", &enum_case_Sunday_value);

	return class_entry;
}
