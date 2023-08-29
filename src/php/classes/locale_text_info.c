/**
 * Copyright (c) php-ecma-intl contributors.
 *
 * This source file is subject to the BSD-3-Clause license that is bundled with
 * this package in the file LICENSE and is available at the following web
 * address: https://opensource.org/license/bsd-3-clause/
 *
 * This source file may utilize copyrighted material from third-party open
 * source projects, the use of which is acknowledged in the NOTICE file bundled
 * with this package.
 */

#include "php/classes/locale_text_info.h"

#include "php/classes/locale_character_direction.h"

#include <ext/json/php_json.h>

zend_class_entry *ecma_ce_IntlLocaleTextInfo = NULL;
zend_object_handlers ecma_handlers_IntlLocaleTextInfo;

static void freeLocaleTextInfoObj(zend_object *object);

PHP_MINIT_FUNCTION(ecma_intl_locale_textinfo) {
  ecma_ce_IntlLocaleTextInfo =
      register_class_Ecma_Intl_Locale_TextInfo(php_json_serializable_ce);
  ecma_ce_IntlLocaleTextInfo->create_object = ecma_createIntlLocaleTextInfo;

  memcpy(&ecma_handlers_IntlLocaleTextInfo, zend_get_std_object_handlers(),
         sizeof(zend_object_handlers));

  ecma_handlers_IntlLocaleTextInfo.offset =
      XtOffsetOf(ecma_IntlLocaleTextInfo, std);
  ecma_handlers_IntlLocaleTextInfo.free_obj = freeLocaleTextInfoObj;
}

zend_object *ecma_createIntlLocaleTextInfo(zend_class_entry *classEntry) {
  ecma_IntlLocaleTextInfo *intlLocaleTextInfo;

  intlLocaleTextInfo =
      zend_object_alloc(sizeof(struct ecma_IntlLocaleTextInfo), classEntry);

  zend_object_std_init(&intlLocaleTextInfo->std, classEntry);
  object_properties_init(&intlLocaleTextInfo->std, classEntry);

  intlLocaleTextInfo->std.handlers = &ecma_handlers_IntlLocaleTextInfo;

  return &intlLocaleTextInfo->std;
}

PHP_METHOD(Ecma_Intl_Locale_TextInfo, __construct) {
  zval *directionObj;
  zend_object *this;
  ecma_IntlLocaleTextInfo *intlLocaleTextInfo;

  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_OBJECT_OF_CLASS(directionObj, ecma_ce_IntlLocaleCharacterDirection);
  ZEND_PARSE_PARAMETERS_END();

  intlLocaleTextInfo = ECMA_LOCALE_TEXT_INFO_P(getThis());
  this = &intlLocaleTextInfo->std;

  zend_update_property(ecma_ce_IntlLocaleTextInfo, this, "direction",
                       strlen("direction"), directionObj);
}

PHP_METHOD(Ecma_Intl_Locale_TextInfo, jsonSerialize) {
  ecma_IntlLocaleTextInfo *intlLocaleTextInfo;
  zend_object *this;
  zval direction, rv;

  ZEND_PARSE_PARAMETERS_NONE();

  object_init(return_value);

  intlLocaleTextInfo = ECMA_LOCALE_TEXT_INFO_P(getThis());
  this = &intlLocaleTextInfo->std;

  direction = *zend_read_property(ecma_ce_IntlLocaleTextInfo, this, "direction",
                                  strlen("direction"), false, &rv);
  add_property_zval(return_value, "direction", &direction);
}

static void freeLocaleTextInfoObj(zend_object *object) {
  ecma_IntlLocaleTextInfo *intlLocaleTextInfo =
      ecma_IntlLocaleTextInfoFromObj(object);
  zend_object_std_dtor(&intlLocaleTextInfo->std);
}
