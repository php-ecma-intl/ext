/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 106d28459eefd3da09ff06bea663a991ecbedcf6 */




static const zend_function_entry class_Ecma_Intl_Calendar_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ecma_Intl_CaseFirst_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ecma_Intl_Collation_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Ecma_Intl_HourCycle_methods[] = {
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

static zend_class_entry *register_class_Ecma_Intl_CaseFirst(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Ecma\\Intl\\CaseFirst", IS_STRING, class_Ecma_Intl_CaseFirst_methods);

	zval enum_case_False_value;
	zend_string *enum_case_False_value_str = zend_string_init("false", strlen("false"), 1);
	ZVAL_STR(&enum_case_False_value, enum_case_False_value_str);
	zend_enum_add_case_cstr(class_entry, "False", &enum_case_False_value);

	zval enum_case_Lower_value;
	zend_string *enum_case_Lower_value_str = zend_string_init("lower", strlen("lower"), 1);
	ZVAL_STR(&enum_case_Lower_value, enum_case_Lower_value_str);
	zend_enum_add_case_cstr(class_entry, "Lower", &enum_case_Lower_value);

	zval enum_case_Upper_value;
	zend_string *enum_case_Upper_value_str = zend_string_init("upper", strlen("upper"), 1);
	ZVAL_STR(&enum_case_Upper_value, enum_case_Upper_value_str);
	zend_enum_add_case_cstr(class_entry, "Upper", &enum_case_Upper_value);

	return class_entry;
}

static zend_class_entry *register_class_Ecma_Intl_Collation(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Ecma\\Intl\\Collation", IS_STRING, class_Ecma_Intl_Collation_methods);

	zval enum_case_Big5han_value;
	zend_string *enum_case_Big5han_value_str = zend_string_init("big5han", strlen("big5han"), 1);
	ZVAL_STR(&enum_case_Big5han_value, enum_case_Big5han_value_str);
	zend_enum_add_case_cstr(class_entry, "Big5han", &enum_case_Big5han_value);

	zval enum_case_Compat_value;
	zend_string *enum_case_Compat_value_str = zend_string_init("compat", strlen("compat"), 1);
	ZVAL_STR(&enum_case_Compat_value, enum_case_Compat_value_str);
	zend_enum_add_case_cstr(class_entry, "Compat", &enum_case_Compat_value);

	zval enum_case_Dict_value;
	zend_string *enum_case_Dict_value_str = zend_string_init("dict", strlen("dict"), 1);
	ZVAL_STR(&enum_case_Dict_value, enum_case_Dict_value_str);
	zend_enum_add_case_cstr(class_entry, "Dict", &enum_case_Dict_value);

	zval enum_case_Direct_value;
	zend_string *enum_case_Direct_value_str = zend_string_init("direct", strlen("direct"), 1);
	ZVAL_STR(&enum_case_Direct_value, enum_case_Direct_value_str);
	zend_enum_add_case_cstr(class_entry, "Direct", &enum_case_Direct_value);

	zval enum_case_Ducet_value;
	zend_string *enum_case_Ducet_value_str = zend_string_init("ducet", strlen("ducet"), 1);
	ZVAL_STR(&enum_case_Ducet_value, enum_case_Ducet_value_str);
	zend_enum_add_case_cstr(class_entry, "Ducet", &enum_case_Ducet_value);

	zval enum_case_Emoji_value;
	zend_string *enum_case_Emoji_value_str = zend_string_init("emoji", strlen("emoji"), 1);
	ZVAL_STR(&enum_case_Emoji_value, enum_case_Emoji_value_str);
	zend_enum_add_case_cstr(class_entry, "Emoji", &enum_case_Emoji_value);

	zval enum_case_Eor_value;
	zend_string *enum_case_Eor_value_str = zend_string_init("eor", strlen("eor"), 1);
	ZVAL_STR(&enum_case_Eor_value, enum_case_Eor_value_str);
	zend_enum_add_case_cstr(class_entry, "Eor", &enum_case_Eor_value);

	zval enum_case_Gb2312_value;
	zend_string *enum_case_Gb2312_value_str = zend_string_init("gb2312", strlen("gb2312"), 1);
	ZVAL_STR(&enum_case_Gb2312_value, enum_case_Gb2312_value_str);
	zend_enum_add_case_cstr(class_entry, "Gb2312", &enum_case_Gb2312_value);

	zval enum_case_Phonebk_value;
	zend_string *enum_case_Phonebk_value_str = zend_string_init("phonebk", strlen("phonebk"), 1);
	ZVAL_STR(&enum_case_Phonebk_value, enum_case_Phonebk_value_str);
	zend_enum_add_case_cstr(class_entry, "Phonebk", &enum_case_Phonebk_value);

	zval enum_case_Phonetic_value;
	zend_string *enum_case_Phonetic_value_str = zend_string_init("phonetic", strlen("phonetic"), 1);
	ZVAL_STR(&enum_case_Phonetic_value, enum_case_Phonetic_value_str);
	zend_enum_add_case_cstr(class_entry, "Phonetic", &enum_case_Phonetic_value);

	zval enum_case_Pinyin_value;
	zend_string *enum_case_Pinyin_value_str = zend_string_init("pinyin", strlen("pinyin"), 1);
	ZVAL_STR(&enum_case_Pinyin_value, enum_case_Pinyin_value_str);
	zend_enum_add_case_cstr(class_entry, "Pinyin", &enum_case_Pinyin_value);

	zval enum_case_Reformed_value;
	zend_string *enum_case_Reformed_value_str = zend_string_init("reformed", strlen("reformed"), 1);
	ZVAL_STR(&enum_case_Reformed_value, enum_case_Reformed_value_str);
	zend_enum_add_case_cstr(class_entry, "Reformed", &enum_case_Reformed_value);

	zval enum_case_Search_value;
	zend_string *enum_case_Search_value_str = zend_string_init("search", strlen("search"), 1);
	ZVAL_STR(&enum_case_Search_value, enum_case_Search_value_str);
	zend_enum_add_case_cstr(class_entry, "Search", &enum_case_Search_value);

	zval enum_case_Searchjl_value;
	zend_string *enum_case_Searchjl_value_str = zend_string_init("searchjl", strlen("searchjl"), 1);
	ZVAL_STR(&enum_case_Searchjl_value, enum_case_Searchjl_value_str);
	zend_enum_add_case_cstr(class_entry, "Searchjl", &enum_case_Searchjl_value);

	zval enum_case_Standard_value;
	zend_string *enum_case_Standard_value_str = zend_string_init("standard", strlen("standard"), 1);
	ZVAL_STR(&enum_case_Standard_value, enum_case_Standard_value_str);
	zend_enum_add_case_cstr(class_entry, "Standard", &enum_case_Standard_value);

	zval enum_case_Stroke_value;
	zend_string *enum_case_Stroke_value_str = zend_string_init("stroke", strlen("stroke"), 1);
	ZVAL_STR(&enum_case_Stroke_value, enum_case_Stroke_value_str);
	zend_enum_add_case_cstr(class_entry, "Stroke", &enum_case_Stroke_value);

	zval enum_case_Trad_value;
	zend_string *enum_case_Trad_value_str = zend_string_init("trad", strlen("trad"), 1);
	ZVAL_STR(&enum_case_Trad_value, enum_case_Trad_value_str);
	zend_enum_add_case_cstr(class_entry, "Trad", &enum_case_Trad_value);

	zval enum_case_Unihan_value;
	zend_string *enum_case_Unihan_value_str = zend_string_init("unihan", strlen("unihan"), 1);
	ZVAL_STR(&enum_case_Unihan_value, enum_case_Unihan_value_str);
	zend_enum_add_case_cstr(class_entry, "Unihan", &enum_case_Unihan_value);

	zval enum_case_Zhuyin_value;
	zend_string *enum_case_Zhuyin_value_str = zend_string_init("zhuyin", strlen("zhuyin"), 1);
	ZVAL_STR(&enum_case_Zhuyin_value, enum_case_Zhuyin_value_str);
	zend_enum_add_case_cstr(class_entry, "Zhuyin", &enum_case_Zhuyin_value);

	return class_entry;
}

static zend_class_entry *register_class_Ecma_Intl_HourCycle(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Ecma\\Intl\\HourCycle", IS_STRING, class_Ecma_Intl_HourCycle_methods);

	zval enum_case_H11_value;
	zend_string *enum_case_H11_value_str = zend_string_init("h11", strlen("h11"), 1);
	ZVAL_STR(&enum_case_H11_value, enum_case_H11_value_str);
	zend_enum_add_case_cstr(class_entry, "H11", &enum_case_H11_value);

	zval enum_case_H12_value;
	zend_string *enum_case_H12_value_str = zend_string_init("h12", strlen("h12"), 1);
	ZVAL_STR(&enum_case_H12_value, enum_case_H12_value_str);
	zend_enum_add_case_cstr(class_entry, "H12", &enum_case_H12_value);

	zval enum_case_H23_value;
	zend_string *enum_case_H23_value_str = zend_string_init("h23", strlen("h23"), 1);
	ZVAL_STR(&enum_case_H23_value, enum_case_H23_value_str);
	zend_enum_add_case_cstr(class_entry, "H23", &enum_case_H23_value);

	zval enum_case_H24_value;
	zend_string *enum_case_H24_value_str = zend_string_init("h24", strlen("h24"), 1);
	ZVAL_STR(&enum_case_H24_value, enum_case_H24_value_str);
	zend_enum_add_case_cstr(class_entry, "H24", &enum_case_H24_value);

	return class_entry;
}
