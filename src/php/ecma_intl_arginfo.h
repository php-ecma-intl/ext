/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 4eba118035fc096632894e92384b7bd7c21cae71 */




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


static const zend_function_entry class_Ecma_Intl_NumberingSystem_methods[] = {
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

static zend_class_entry *register_class_Ecma_Intl_NumberingSystem(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Ecma\\Intl\\NumberingSystem", IS_STRING, class_Ecma_Intl_NumberingSystem_methods);

	zval enum_case_Adlm_value;
	zend_string *enum_case_Adlm_value_str = zend_string_init("adlm", strlen("adlm"), 1);
	ZVAL_STR(&enum_case_Adlm_value, enum_case_Adlm_value_str);
	zend_enum_add_case_cstr(class_entry, "Adlm", &enum_case_Adlm_value);

	zval enum_case_Ahom_value;
	zend_string *enum_case_Ahom_value_str = zend_string_init("ahom", strlen("ahom"), 1);
	ZVAL_STR(&enum_case_Ahom_value, enum_case_Ahom_value_str);
	zend_enum_add_case_cstr(class_entry, "Ahom", &enum_case_Ahom_value);

	zval enum_case_Arab_value;
	zend_string *enum_case_Arab_value_str = zend_string_init("arab", strlen("arab"), 1);
	ZVAL_STR(&enum_case_Arab_value, enum_case_Arab_value_str);
	zend_enum_add_case_cstr(class_entry, "Arab", &enum_case_Arab_value);

	zval enum_case_Arabext_value;
	zend_string *enum_case_Arabext_value_str = zend_string_init("arabext", strlen("arabext"), 1);
	ZVAL_STR(&enum_case_Arabext_value, enum_case_Arabext_value_str);
	zend_enum_add_case_cstr(class_entry, "Arabext", &enum_case_Arabext_value);

	zval enum_case_Armn_value;
	zend_string *enum_case_Armn_value_str = zend_string_init("armn", strlen("armn"), 1);
	ZVAL_STR(&enum_case_Armn_value, enum_case_Armn_value_str);
	zend_enum_add_case_cstr(class_entry, "Armn", &enum_case_Armn_value);

	zval enum_case_Armnlow_value;
	zend_string *enum_case_Armnlow_value_str = zend_string_init("armnlow", strlen("armnlow"), 1);
	ZVAL_STR(&enum_case_Armnlow_value, enum_case_Armnlow_value_str);
	zend_enum_add_case_cstr(class_entry, "Armnlow", &enum_case_Armnlow_value);

	zval enum_case_Bali_value;
	zend_string *enum_case_Bali_value_str = zend_string_init("bali", strlen("bali"), 1);
	ZVAL_STR(&enum_case_Bali_value, enum_case_Bali_value_str);
	zend_enum_add_case_cstr(class_entry, "Bali", &enum_case_Bali_value);

	zval enum_case_Beng_value;
	zend_string *enum_case_Beng_value_str = zend_string_init("beng", strlen("beng"), 1);
	ZVAL_STR(&enum_case_Beng_value, enum_case_Beng_value_str);
	zend_enum_add_case_cstr(class_entry, "Beng", &enum_case_Beng_value);

	zval enum_case_Bhks_value;
	zend_string *enum_case_Bhks_value_str = zend_string_init("bhks", strlen("bhks"), 1);
	ZVAL_STR(&enum_case_Bhks_value, enum_case_Bhks_value_str);
	zend_enum_add_case_cstr(class_entry, "Bhks", &enum_case_Bhks_value);

	zval enum_case_Brah_value;
	zend_string *enum_case_Brah_value_str = zend_string_init("brah", strlen("brah"), 1);
	ZVAL_STR(&enum_case_Brah_value, enum_case_Brah_value_str);
	zend_enum_add_case_cstr(class_entry, "Brah", &enum_case_Brah_value);

	zval enum_case_Cakm_value;
	zend_string *enum_case_Cakm_value_str = zend_string_init("cakm", strlen("cakm"), 1);
	ZVAL_STR(&enum_case_Cakm_value, enum_case_Cakm_value_str);
	zend_enum_add_case_cstr(class_entry, "Cakm", &enum_case_Cakm_value);

	zval enum_case_Cham_value;
	zend_string *enum_case_Cham_value_str = zend_string_init("cham", strlen("cham"), 1);
	ZVAL_STR(&enum_case_Cham_value, enum_case_Cham_value_str);
	zend_enum_add_case_cstr(class_entry, "Cham", &enum_case_Cham_value);

	zval enum_case_Cyrl_value;
	zend_string *enum_case_Cyrl_value_str = zend_string_init("cyrl", strlen("cyrl"), 1);
	ZVAL_STR(&enum_case_Cyrl_value, enum_case_Cyrl_value_str);
	zend_enum_add_case_cstr(class_entry, "Cyrl", &enum_case_Cyrl_value);

	zval enum_case_Deva_value;
	zend_string *enum_case_Deva_value_str = zend_string_init("deva", strlen("deva"), 1);
	ZVAL_STR(&enum_case_Deva_value, enum_case_Deva_value_str);
	zend_enum_add_case_cstr(class_entry, "Deva", &enum_case_Deva_value);

	zval enum_case_Diak_value;
	zend_string *enum_case_Diak_value_str = zend_string_init("diak", strlen("diak"), 1);
	ZVAL_STR(&enum_case_Diak_value, enum_case_Diak_value_str);
	zend_enum_add_case_cstr(class_entry, "Diak", &enum_case_Diak_value);

	zval enum_case_Ethi_value;
	zend_string *enum_case_Ethi_value_str = zend_string_init("ethi", strlen("ethi"), 1);
	ZVAL_STR(&enum_case_Ethi_value, enum_case_Ethi_value_str);
	zend_enum_add_case_cstr(class_entry, "Ethi", &enum_case_Ethi_value);

	zval enum_case_Finance_value;
	zend_string *enum_case_Finance_value_str = zend_string_init("finance", strlen("finance"), 1);
	ZVAL_STR(&enum_case_Finance_value, enum_case_Finance_value_str);
	zend_enum_add_case_cstr(class_entry, "Finance", &enum_case_Finance_value);

	zval enum_case_Fullwide_value;
	zend_string *enum_case_Fullwide_value_str = zend_string_init("fullwide", strlen("fullwide"), 1);
	ZVAL_STR(&enum_case_Fullwide_value, enum_case_Fullwide_value_str);
	zend_enum_add_case_cstr(class_entry, "Fullwide", &enum_case_Fullwide_value);

	zval enum_case_Geor_value;
	zend_string *enum_case_Geor_value_str = zend_string_init("geor", strlen("geor"), 1);
	ZVAL_STR(&enum_case_Geor_value, enum_case_Geor_value_str);
	zend_enum_add_case_cstr(class_entry, "Geor", &enum_case_Geor_value);

	zval enum_case_Gong_value;
	zend_string *enum_case_Gong_value_str = zend_string_init("gong", strlen("gong"), 1);
	ZVAL_STR(&enum_case_Gong_value, enum_case_Gong_value_str);
	zend_enum_add_case_cstr(class_entry, "Gong", &enum_case_Gong_value);

	zval enum_case_Gonm_value;
	zend_string *enum_case_Gonm_value_str = zend_string_init("gonm", strlen("gonm"), 1);
	ZVAL_STR(&enum_case_Gonm_value, enum_case_Gonm_value_str);
	zend_enum_add_case_cstr(class_entry, "Gonm", &enum_case_Gonm_value);

	zval enum_case_Grek_value;
	zend_string *enum_case_Grek_value_str = zend_string_init("grek", strlen("grek"), 1);
	ZVAL_STR(&enum_case_Grek_value, enum_case_Grek_value_str);
	zend_enum_add_case_cstr(class_entry, "Grek", &enum_case_Grek_value);

	zval enum_case_Greklow_value;
	zend_string *enum_case_Greklow_value_str = zend_string_init("greklow", strlen("greklow"), 1);
	ZVAL_STR(&enum_case_Greklow_value, enum_case_Greklow_value_str);
	zend_enum_add_case_cstr(class_entry, "Greklow", &enum_case_Greklow_value);

	zval enum_case_Gujr_value;
	zend_string *enum_case_Gujr_value_str = zend_string_init("gujr", strlen("gujr"), 1);
	ZVAL_STR(&enum_case_Gujr_value, enum_case_Gujr_value_str);
	zend_enum_add_case_cstr(class_entry, "Gujr", &enum_case_Gujr_value);

	zval enum_case_Guru_value;
	zend_string *enum_case_Guru_value_str = zend_string_init("guru", strlen("guru"), 1);
	ZVAL_STR(&enum_case_Guru_value, enum_case_Guru_value_str);
	zend_enum_add_case_cstr(class_entry, "Guru", &enum_case_Guru_value);

	zval enum_case_Hanidays_value;
	zend_string *enum_case_Hanidays_value_str = zend_string_init("hanidays", strlen("hanidays"), 1);
	ZVAL_STR(&enum_case_Hanidays_value, enum_case_Hanidays_value_str);
	zend_enum_add_case_cstr(class_entry, "Hanidays", &enum_case_Hanidays_value);

	zval enum_case_Hanidec_value;
	zend_string *enum_case_Hanidec_value_str = zend_string_init("hanidec", strlen("hanidec"), 1);
	ZVAL_STR(&enum_case_Hanidec_value, enum_case_Hanidec_value_str);
	zend_enum_add_case_cstr(class_entry, "Hanidec", &enum_case_Hanidec_value);

	zval enum_case_Hans_value;
	zend_string *enum_case_Hans_value_str = zend_string_init("hans", strlen("hans"), 1);
	ZVAL_STR(&enum_case_Hans_value, enum_case_Hans_value_str);
	zend_enum_add_case_cstr(class_entry, "Hans", &enum_case_Hans_value);

	zval enum_case_Hansfin_value;
	zend_string *enum_case_Hansfin_value_str = zend_string_init("hansfin", strlen("hansfin"), 1);
	ZVAL_STR(&enum_case_Hansfin_value, enum_case_Hansfin_value_str);
	zend_enum_add_case_cstr(class_entry, "Hansfin", &enum_case_Hansfin_value);

	zval enum_case_Hant_value;
	zend_string *enum_case_Hant_value_str = zend_string_init("hant", strlen("hant"), 1);
	ZVAL_STR(&enum_case_Hant_value, enum_case_Hant_value_str);
	zend_enum_add_case_cstr(class_entry, "Hant", &enum_case_Hant_value);

	zval enum_case_Hantfin_value;
	zend_string *enum_case_Hantfin_value_str = zend_string_init("hantfin", strlen("hantfin"), 1);
	ZVAL_STR(&enum_case_Hantfin_value, enum_case_Hantfin_value_str);
	zend_enum_add_case_cstr(class_entry, "Hantfin", &enum_case_Hantfin_value);

	zval enum_case_Hebr_value;
	zend_string *enum_case_Hebr_value_str = zend_string_init("hebr", strlen("hebr"), 1);
	ZVAL_STR(&enum_case_Hebr_value, enum_case_Hebr_value_str);
	zend_enum_add_case_cstr(class_entry, "Hebr", &enum_case_Hebr_value);

	zval enum_case_Hmng_value;
	zend_string *enum_case_Hmng_value_str = zend_string_init("hmng", strlen("hmng"), 1);
	ZVAL_STR(&enum_case_Hmng_value, enum_case_Hmng_value_str);
	zend_enum_add_case_cstr(class_entry, "Hmng", &enum_case_Hmng_value);

	zval enum_case_Hmnp_value;
	zend_string *enum_case_Hmnp_value_str = zend_string_init("hmnp", strlen("hmnp"), 1);
	ZVAL_STR(&enum_case_Hmnp_value, enum_case_Hmnp_value_str);
	zend_enum_add_case_cstr(class_entry, "Hmnp", &enum_case_Hmnp_value);

	zval enum_case_Java_value;
	zend_string *enum_case_Java_value_str = zend_string_init("java", strlen("java"), 1);
	ZVAL_STR(&enum_case_Java_value, enum_case_Java_value_str);
	zend_enum_add_case_cstr(class_entry, "Java", &enum_case_Java_value);

	zval enum_case_Jpan_value;
	zend_string *enum_case_Jpan_value_str = zend_string_init("jpan", strlen("jpan"), 1);
	ZVAL_STR(&enum_case_Jpan_value, enum_case_Jpan_value_str);
	zend_enum_add_case_cstr(class_entry, "Jpan", &enum_case_Jpan_value);

	zval enum_case_Jpanfin_value;
	zend_string *enum_case_Jpanfin_value_str = zend_string_init("jpanfin", strlen("jpanfin"), 1);
	ZVAL_STR(&enum_case_Jpanfin_value, enum_case_Jpanfin_value_str);
	zend_enum_add_case_cstr(class_entry, "Jpanfin", &enum_case_Jpanfin_value);

	zval enum_case_Jpanyear_value;
	zend_string *enum_case_Jpanyear_value_str = zend_string_init("jpanyear", strlen("jpanyear"), 1);
	ZVAL_STR(&enum_case_Jpanyear_value, enum_case_Jpanyear_value_str);
	zend_enum_add_case_cstr(class_entry, "Jpanyear", &enum_case_Jpanyear_value);

	zval enum_case_Kali_value;
	zend_string *enum_case_Kali_value_str = zend_string_init("kali", strlen("kali"), 1);
	ZVAL_STR(&enum_case_Kali_value, enum_case_Kali_value_str);
	zend_enum_add_case_cstr(class_entry, "Kali", &enum_case_Kali_value);

	zval enum_case_Kawi_value;
	zend_string *enum_case_Kawi_value_str = zend_string_init("kawi", strlen("kawi"), 1);
	ZVAL_STR(&enum_case_Kawi_value, enum_case_Kawi_value_str);
	zend_enum_add_case_cstr(class_entry, "Kawi", &enum_case_Kawi_value);

	zval enum_case_Khmr_value;
	zend_string *enum_case_Khmr_value_str = zend_string_init("khmr", strlen("khmr"), 1);
	ZVAL_STR(&enum_case_Khmr_value, enum_case_Khmr_value_str);
	zend_enum_add_case_cstr(class_entry, "Khmr", &enum_case_Khmr_value);

	zval enum_case_Knda_value;
	zend_string *enum_case_Knda_value_str = zend_string_init("knda", strlen("knda"), 1);
	ZVAL_STR(&enum_case_Knda_value, enum_case_Knda_value_str);
	zend_enum_add_case_cstr(class_entry, "Knda", &enum_case_Knda_value);

	zval enum_case_Lana_value;
	zend_string *enum_case_Lana_value_str = zend_string_init("lana", strlen("lana"), 1);
	ZVAL_STR(&enum_case_Lana_value, enum_case_Lana_value_str);
	zend_enum_add_case_cstr(class_entry, "Lana", &enum_case_Lana_value);

	zval enum_case_Lanatham_value;
	zend_string *enum_case_Lanatham_value_str = zend_string_init("lanatham", strlen("lanatham"), 1);
	ZVAL_STR(&enum_case_Lanatham_value, enum_case_Lanatham_value_str);
	zend_enum_add_case_cstr(class_entry, "Lanatham", &enum_case_Lanatham_value);

	zval enum_case_Laoo_value;
	zend_string *enum_case_Laoo_value_str = zend_string_init("laoo", strlen("laoo"), 1);
	ZVAL_STR(&enum_case_Laoo_value, enum_case_Laoo_value_str);
	zend_enum_add_case_cstr(class_entry, "Laoo", &enum_case_Laoo_value);

	zval enum_case_Latn_value;
	zend_string *enum_case_Latn_value_str = zend_string_init("latn", strlen("latn"), 1);
	ZVAL_STR(&enum_case_Latn_value, enum_case_Latn_value_str);
	zend_enum_add_case_cstr(class_entry, "Latn", &enum_case_Latn_value);

	zval enum_case_Lepc_value;
	zend_string *enum_case_Lepc_value_str = zend_string_init("lepc", strlen("lepc"), 1);
	ZVAL_STR(&enum_case_Lepc_value, enum_case_Lepc_value_str);
	zend_enum_add_case_cstr(class_entry, "Lepc", &enum_case_Lepc_value);

	zval enum_case_Limb_value;
	zend_string *enum_case_Limb_value_str = zend_string_init("limb", strlen("limb"), 1);
	ZVAL_STR(&enum_case_Limb_value, enum_case_Limb_value_str);
	zend_enum_add_case_cstr(class_entry, "Limb", &enum_case_Limb_value);

	zval enum_case_Mathbold_value;
	zend_string *enum_case_Mathbold_value_str = zend_string_init("mathbold", strlen("mathbold"), 1);
	ZVAL_STR(&enum_case_Mathbold_value, enum_case_Mathbold_value_str);
	zend_enum_add_case_cstr(class_entry, "Mathbold", &enum_case_Mathbold_value);

	zval enum_case_Mathdbl_value;
	zend_string *enum_case_Mathdbl_value_str = zend_string_init("mathdbl", strlen("mathdbl"), 1);
	ZVAL_STR(&enum_case_Mathdbl_value, enum_case_Mathdbl_value_str);
	zend_enum_add_case_cstr(class_entry, "Mathdbl", &enum_case_Mathdbl_value);

	zval enum_case_Mathmono_value;
	zend_string *enum_case_Mathmono_value_str = zend_string_init("mathmono", strlen("mathmono"), 1);
	ZVAL_STR(&enum_case_Mathmono_value, enum_case_Mathmono_value_str);
	zend_enum_add_case_cstr(class_entry, "Mathmono", &enum_case_Mathmono_value);

	zval enum_case_Mathsanb_value;
	zend_string *enum_case_Mathsanb_value_str = zend_string_init("mathsanb", strlen("mathsanb"), 1);
	ZVAL_STR(&enum_case_Mathsanb_value, enum_case_Mathsanb_value_str);
	zend_enum_add_case_cstr(class_entry, "Mathsanb", &enum_case_Mathsanb_value);

	zval enum_case_Mathsans_value;
	zend_string *enum_case_Mathsans_value_str = zend_string_init("mathsans", strlen("mathsans"), 1);
	ZVAL_STR(&enum_case_Mathsans_value, enum_case_Mathsans_value_str);
	zend_enum_add_case_cstr(class_entry, "Mathsans", &enum_case_Mathsans_value);

	zval enum_case_Mlym_value;
	zend_string *enum_case_Mlym_value_str = zend_string_init("mlym", strlen("mlym"), 1);
	ZVAL_STR(&enum_case_Mlym_value, enum_case_Mlym_value_str);
	zend_enum_add_case_cstr(class_entry, "Mlym", &enum_case_Mlym_value);

	zval enum_case_Modi_value;
	zend_string *enum_case_Modi_value_str = zend_string_init("modi", strlen("modi"), 1);
	ZVAL_STR(&enum_case_Modi_value, enum_case_Modi_value_str);
	zend_enum_add_case_cstr(class_entry, "Modi", &enum_case_Modi_value);

	zval enum_case_Mong_value;
	zend_string *enum_case_Mong_value_str = zend_string_init("mong", strlen("mong"), 1);
	ZVAL_STR(&enum_case_Mong_value, enum_case_Mong_value_str);
	zend_enum_add_case_cstr(class_entry, "Mong", &enum_case_Mong_value);

	zval enum_case_Mroo_value;
	zend_string *enum_case_Mroo_value_str = zend_string_init("mroo", strlen("mroo"), 1);
	ZVAL_STR(&enum_case_Mroo_value, enum_case_Mroo_value_str);
	zend_enum_add_case_cstr(class_entry, "Mroo", &enum_case_Mroo_value);

	zval enum_case_Mtei_value;
	zend_string *enum_case_Mtei_value_str = zend_string_init("mtei", strlen("mtei"), 1);
	ZVAL_STR(&enum_case_Mtei_value, enum_case_Mtei_value_str);
	zend_enum_add_case_cstr(class_entry, "Mtei", &enum_case_Mtei_value);

	zval enum_case_Mymr_value;
	zend_string *enum_case_Mymr_value_str = zend_string_init("mymr", strlen("mymr"), 1);
	ZVAL_STR(&enum_case_Mymr_value, enum_case_Mymr_value_str);
	zend_enum_add_case_cstr(class_entry, "Mymr", &enum_case_Mymr_value);

	zval enum_case_Mymrshan_value;
	zend_string *enum_case_Mymrshan_value_str = zend_string_init("mymrshan", strlen("mymrshan"), 1);
	ZVAL_STR(&enum_case_Mymrshan_value, enum_case_Mymrshan_value_str);
	zend_enum_add_case_cstr(class_entry, "Mymrshan", &enum_case_Mymrshan_value);

	zval enum_case_Mymrtlng_value;
	zend_string *enum_case_Mymrtlng_value_str = zend_string_init("mymrtlng", strlen("mymrtlng"), 1);
	ZVAL_STR(&enum_case_Mymrtlng_value, enum_case_Mymrtlng_value_str);
	zend_enum_add_case_cstr(class_entry, "Mymrtlng", &enum_case_Mymrtlng_value);

	zval enum_case_Nagm_value;
	zend_string *enum_case_Nagm_value_str = zend_string_init("nagm", strlen("nagm"), 1);
	ZVAL_STR(&enum_case_Nagm_value, enum_case_Nagm_value_str);
	zend_enum_add_case_cstr(class_entry, "Nagm", &enum_case_Nagm_value);

	zval enum_case_Native_value;
	zend_string *enum_case_Native_value_str = zend_string_init("native", strlen("native"), 1);
	ZVAL_STR(&enum_case_Native_value, enum_case_Native_value_str);
	zend_enum_add_case_cstr(class_entry, "Native", &enum_case_Native_value);

	zval enum_case_Newa_value;
	zend_string *enum_case_Newa_value_str = zend_string_init("newa", strlen("newa"), 1);
	ZVAL_STR(&enum_case_Newa_value, enum_case_Newa_value_str);
	zend_enum_add_case_cstr(class_entry, "Newa", &enum_case_Newa_value);

	zval enum_case_Nkoo_value;
	zend_string *enum_case_Nkoo_value_str = zend_string_init("nkoo", strlen("nkoo"), 1);
	ZVAL_STR(&enum_case_Nkoo_value, enum_case_Nkoo_value_str);
	zend_enum_add_case_cstr(class_entry, "Nkoo", &enum_case_Nkoo_value);

	zval enum_case_Olck_value;
	zend_string *enum_case_Olck_value_str = zend_string_init("olck", strlen("olck"), 1);
	ZVAL_STR(&enum_case_Olck_value, enum_case_Olck_value_str);
	zend_enum_add_case_cstr(class_entry, "Olck", &enum_case_Olck_value);

	zval enum_case_Orya_value;
	zend_string *enum_case_Orya_value_str = zend_string_init("orya", strlen("orya"), 1);
	ZVAL_STR(&enum_case_Orya_value, enum_case_Orya_value_str);
	zend_enum_add_case_cstr(class_entry, "Orya", &enum_case_Orya_value);

	zval enum_case_Osma_value;
	zend_string *enum_case_Osma_value_str = zend_string_init("osma", strlen("osma"), 1);
	ZVAL_STR(&enum_case_Osma_value, enum_case_Osma_value_str);
	zend_enum_add_case_cstr(class_entry, "Osma", &enum_case_Osma_value);

	zval enum_case_Rohg_value;
	zend_string *enum_case_Rohg_value_str = zend_string_init("rohg", strlen("rohg"), 1);
	ZVAL_STR(&enum_case_Rohg_value, enum_case_Rohg_value_str);
	zend_enum_add_case_cstr(class_entry, "Rohg", &enum_case_Rohg_value);

	zval enum_case_Roman_value;
	zend_string *enum_case_Roman_value_str = zend_string_init("roman", strlen("roman"), 1);
	ZVAL_STR(&enum_case_Roman_value, enum_case_Roman_value_str);
	zend_enum_add_case_cstr(class_entry, "Roman", &enum_case_Roman_value);

	zval enum_case_Romanlow_value;
	zend_string *enum_case_Romanlow_value_str = zend_string_init("romanlow", strlen("romanlow"), 1);
	ZVAL_STR(&enum_case_Romanlow_value, enum_case_Romanlow_value_str);
	zend_enum_add_case_cstr(class_entry, "Romanlow", &enum_case_Romanlow_value);

	zval enum_case_Saur_value;
	zend_string *enum_case_Saur_value_str = zend_string_init("saur", strlen("saur"), 1);
	ZVAL_STR(&enum_case_Saur_value, enum_case_Saur_value_str);
	zend_enum_add_case_cstr(class_entry, "Saur", &enum_case_Saur_value);

	zval enum_case_Segment_value;
	zend_string *enum_case_Segment_value_str = zend_string_init("segment", strlen("segment"), 1);
	ZVAL_STR(&enum_case_Segment_value, enum_case_Segment_value_str);
	zend_enum_add_case_cstr(class_entry, "Segment", &enum_case_Segment_value);

	zval enum_case_Shrd_value;
	zend_string *enum_case_Shrd_value_str = zend_string_init("shrd", strlen("shrd"), 1);
	ZVAL_STR(&enum_case_Shrd_value, enum_case_Shrd_value_str);
	zend_enum_add_case_cstr(class_entry, "Shrd", &enum_case_Shrd_value);

	zval enum_case_Sind_value;
	zend_string *enum_case_Sind_value_str = zend_string_init("sind", strlen("sind"), 1);
	ZVAL_STR(&enum_case_Sind_value, enum_case_Sind_value_str);
	zend_enum_add_case_cstr(class_entry, "Sind", &enum_case_Sind_value);

	zval enum_case_Sinh_value;
	zend_string *enum_case_Sinh_value_str = zend_string_init("sinh", strlen("sinh"), 1);
	ZVAL_STR(&enum_case_Sinh_value, enum_case_Sinh_value_str);
	zend_enum_add_case_cstr(class_entry, "Sinh", &enum_case_Sinh_value);

	zval enum_case_Sora_value;
	zend_string *enum_case_Sora_value_str = zend_string_init("sora", strlen("sora"), 1);
	ZVAL_STR(&enum_case_Sora_value, enum_case_Sora_value_str);
	zend_enum_add_case_cstr(class_entry, "Sora", &enum_case_Sora_value);

	zval enum_case_Sund_value;
	zend_string *enum_case_Sund_value_str = zend_string_init("sund", strlen("sund"), 1);
	ZVAL_STR(&enum_case_Sund_value, enum_case_Sund_value_str);
	zend_enum_add_case_cstr(class_entry, "Sund", &enum_case_Sund_value);

	zval enum_case_Takr_value;
	zend_string *enum_case_Takr_value_str = zend_string_init("takr", strlen("takr"), 1);
	ZVAL_STR(&enum_case_Takr_value, enum_case_Takr_value_str);
	zend_enum_add_case_cstr(class_entry, "Takr", &enum_case_Takr_value);

	zval enum_case_Talu_value;
	zend_string *enum_case_Talu_value_str = zend_string_init("talu", strlen("talu"), 1);
	ZVAL_STR(&enum_case_Talu_value, enum_case_Talu_value_str);
	zend_enum_add_case_cstr(class_entry, "Talu", &enum_case_Talu_value);

	zval enum_case_Taml_value;
	zend_string *enum_case_Taml_value_str = zend_string_init("taml", strlen("taml"), 1);
	ZVAL_STR(&enum_case_Taml_value, enum_case_Taml_value_str);
	zend_enum_add_case_cstr(class_entry, "Taml", &enum_case_Taml_value);

	zval enum_case_Tamldec_value;
	zend_string *enum_case_Tamldec_value_str = zend_string_init("tamldec", strlen("tamldec"), 1);
	ZVAL_STR(&enum_case_Tamldec_value, enum_case_Tamldec_value_str);
	zend_enum_add_case_cstr(class_entry, "Tamldec", &enum_case_Tamldec_value);

	zval enum_case_Telu_value;
	zend_string *enum_case_Telu_value_str = zend_string_init("telu", strlen("telu"), 1);
	ZVAL_STR(&enum_case_Telu_value, enum_case_Telu_value_str);
	zend_enum_add_case_cstr(class_entry, "Telu", &enum_case_Telu_value);

	zval enum_case_Thai_value;
	zend_string *enum_case_Thai_value_str = zend_string_init("thai", strlen("thai"), 1);
	ZVAL_STR(&enum_case_Thai_value, enum_case_Thai_value_str);
	zend_enum_add_case_cstr(class_entry, "Thai", &enum_case_Thai_value);

	zval enum_case_Tibt_value;
	zend_string *enum_case_Tibt_value_str = zend_string_init("tibt", strlen("tibt"), 1);
	ZVAL_STR(&enum_case_Tibt_value, enum_case_Tibt_value_str);
	zend_enum_add_case_cstr(class_entry, "Tibt", &enum_case_Tibt_value);

	zval enum_case_Tirh_value;
	zend_string *enum_case_Tirh_value_str = zend_string_init("tirh", strlen("tirh"), 1);
	ZVAL_STR(&enum_case_Tirh_value, enum_case_Tirh_value_str);
	zend_enum_add_case_cstr(class_entry, "Tirh", &enum_case_Tirh_value);

	zval enum_case_Tnsa_value;
	zend_string *enum_case_Tnsa_value_str = zend_string_init("tnsa", strlen("tnsa"), 1);
	ZVAL_STR(&enum_case_Tnsa_value, enum_case_Tnsa_value_str);
	zend_enum_add_case_cstr(class_entry, "Tnsa", &enum_case_Tnsa_value);

	zval enum_case_Traditio_value;
	zend_string *enum_case_Traditio_value_str = zend_string_init("traditio", strlen("traditio"), 1);
	ZVAL_STR(&enum_case_Traditio_value, enum_case_Traditio_value_str);
	zend_enum_add_case_cstr(class_entry, "Traditio", &enum_case_Traditio_value);

	zval enum_case_Vaii_value;
	zend_string *enum_case_Vaii_value_str = zend_string_init("vaii", strlen("vaii"), 1);
	ZVAL_STR(&enum_case_Vaii_value, enum_case_Vaii_value_str);
	zend_enum_add_case_cstr(class_entry, "Vaii", &enum_case_Vaii_value);

	zval enum_case_Wara_value;
	zend_string *enum_case_Wara_value_str = zend_string_init("wara", strlen("wara"), 1);
	ZVAL_STR(&enum_case_Wara_value, enum_case_Wara_value_str);
	zend_enum_add_case_cstr(class_entry, "Wara", &enum_case_Wara_value);

	zval enum_case_Wcho_value;
	zend_string *enum_case_Wcho_value_str = zend_string_init("wcho", strlen("wcho"), 1);
	ZVAL_STR(&enum_case_Wcho_value, enum_case_Wcho_value_str);
	zend_enum_add_case_cstr(class_entry, "Wcho", &enum_case_Wcho_value);

	return class_entry;
}
