/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 66088fda902da29e3ade60023204d1fad0c068ef */




static const zend_function_entry class_Ecma_Intl_Calendar_methods[] = {
	ZEND_FE_END
};

static zend_class_entry *register_class_Ecma_Intl_Calendar(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Ecma\\Intl\\Calendar", IS_STRING, class_Ecma_Intl_Calendar_methods);

	zval enum_case_Buddhist_value;
	zend_string *enum_case_Buddhist_value_str = zend_string_init("buddhist", strlen("buddhist"), 1);
	ZVAL_STR(&enum_case_Buddhist_value, enum_case_Buddhist_value_str);
	zend_enum_add_case_cstr(class_entry, "Buddhist", &enum_case_Buddhist_value);

	zval enum_case_Chinese_value;
	zend_string *enum_case_Chinese_value_str = zend_string_init("chinese", strlen("chinese"), 1);
	ZVAL_STR(&enum_case_Chinese_value, enum_case_Chinese_value_str);
	zend_enum_add_case_cstr(class_entry, "Chinese", &enum_case_Chinese_value);

	zval enum_case_Coptic_value;
	zend_string *enum_case_Coptic_value_str = zend_string_init("coptic", strlen("coptic"), 1);
	ZVAL_STR(&enum_case_Coptic_value, enum_case_Coptic_value_str);
	zend_enum_add_case_cstr(class_entry, "Coptic", &enum_case_Coptic_value);

	zval enum_case_Dangi_value;
	zend_string *enum_case_Dangi_value_str = zend_string_init("dangi", strlen("dangi"), 1);
	ZVAL_STR(&enum_case_Dangi_value, enum_case_Dangi_value_str);
	zend_enum_add_case_cstr(class_entry, "Dangi", &enum_case_Dangi_value);

	zval enum_case_Ethioaa_value;
	zend_string *enum_case_Ethioaa_value_str = zend_string_init("ethioaa", strlen("ethioaa"), 1);
	ZVAL_STR(&enum_case_Ethioaa_value, enum_case_Ethioaa_value_str);
	zend_enum_add_case_cstr(class_entry, "Ethioaa", &enum_case_Ethioaa_value);

	zval enum_case_Ethiopic_value;
	zend_string *enum_case_Ethiopic_value_str = zend_string_init("ethiopic", strlen("ethiopic"), 1);
	ZVAL_STR(&enum_case_Ethiopic_value, enum_case_Ethiopic_value_str);
	zend_enum_add_case_cstr(class_entry, "Ethiopic", &enum_case_Ethiopic_value);

	zval enum_case_Gregory_value;
	zend_string *enum_case_Gregory_value_str = zend_string_init("gregory", strlen("gregory"), 1);
	ZVAL_STR(&enum_case_Gregory_value, enum_case_Gregory_value_str);
	zend_enum_add_case_cstr(class_entry, "Gregory", &enum_case_Gregory_value);

	zval enum_case_Hebrew_value;
	zend_string *enum_case_Hebrew_value_str = zend_string_init("hebrew", strlen("hebrew"), 1);
	ZVAL_STR(&enum_case_Hebrew_value, enum_case_Hebrew_value_str);
	zend_enum_add_case_cstr(class_entry, "Hebrew", &enum_case_Hebrew_value);

	zval enum_case_Indian_value;
	zend_string *enum_case_Indian_value_str = zend_string_init("indian", strlen("indian"), 1);
	ZVAL_STR(&enum_case_Indian_value, enum_case_Indian_value_str);
	zend_enum_add_case_cstr(class_entry, "Indian", &enum_case_Indian_value);

	zval enum_case_Islamic_value;
	zend_string *enum_case_Islamic_value_str = zend_string_init("islamic", strlen("islamic"), 1);
	ZVAL_STR(&enum_case_Islamic_value, enum_case_Islamic_value_str);
	zend_enum_add_case_cstr(class_entry, "Islamic", &enum_case_Islamic_value);

	zval enum_case_IslamicCivil_value;
	zend_string *enum_case_IslamicCivil_value_str = zend_string_init("islamic-civil", strlen("islamic-civil"), 1);
	ZVAL_STR(&enum_case_IslamicCivil_value, enum_case_IslamicCivil_value_str);
	zend_enum_add_case_cstr(class_entry, "IslamicCivil", &enum_case_IslamicCivil_value);

	zval enum_case_IslamicRgsa_value;
	zend_string *enum_case_IslamicRgsa_value_str = zend_string_init("islamic-rgsa", strlen("islamic-rgsa"), 1);
	ZVAL_STR(&enum_case_IslamicRgsa_value, enum_case_IslamicRgsa_value_str);
	zend_enum_add_case_cstr(class_entry, "IslamicRgsa", &enum_case_IslamicRgsa_value);

	zval enum_case_IslamicTbla_value;
	zend_string *enum_case_IslamicTbla_value_str = zend_string_init("islamic-tbla", strlen("islamic-tbla"), 1);
	ZVAL_STR(&enum_case_IslamicTbla_value, enum_case_IslamicTbla_value_str);
	zend_enum_add_case_cstr(class_entry, "IslamicTbla", &enum_case_IslamicTbla_value);

	zval enum_case_IslamicUmalqura_value;
	zend_string *enum_case_IslamicUmalqura_value_str = zend_string_init("islamic-umalqura", strlen("islamic-umalqura"), 1);
	ZVAL_STR(&enum_case_IslamicUmalqura_value, enum_case_IslamicUmalqura_value_str);
	zend_enum_add_case_cstr(class_entry, "IslamicUmalqura", &enum_case_IslamicUmalqura_value);

	zval enum_case_Iso8601_value;
	zend_string *enum_case_Iso8601_value_str = zend_string_init("iso8601", strlen("iso8601"), 1);
	ZVAL_STR(&enum_case_Iso8601_value, enum_case_Iso8601_value_str);
	zend_enum_add_case_cstr(class_entry, "Iso8601", &enum_case_Iso8601_value);

	zval enum_case_Japanese_value;
	zend_string *enum_case_Japanese_value_str = zend_string_init("japanese", strlen("japanese"), 1);
	ZVAL_STR(&enum_case_Japanese_value, enum_case_Japanese_value_str);
	zend_enum_add_case_cstr(class_entry, "Japanese", &enum_case_Japanese_value);

	zval enum_case_Persian_value;
	zend_string *enum_case_Persian_value_str = zend_string_init("persian", strlen("persian"), 1);
	ZVAL_STR(&enum_case_Persian_value, enum_case_Persian_value_str);
	zend_enum_add_case_cstr(class_entry, "Persian", &enum_case_Persian_value);

	zval enum_case_Roc_value;
	zend_string *enum_case_Roc_value_str = zend_string_init("roc", strlen("roc"), 1);
	ZVAL_STR(&enum_case_Roc_value, enum_case_Roc_value_str);
	zend_enum_add_case_cstr(class_entry, "Roc", &enum_case_Roc_value);

	return class_entry;
}
