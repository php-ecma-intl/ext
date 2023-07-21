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

#include "php/classes/locale.h"

#include "ecma402/language_tag.h"
#include "ecma402/locale.h"

#include <Zend/zend_interfaces.h>
#include <string.h>
#include <unicode/uloc.h>

zend_class_entry *ecma_ce_IntlLocale = NULL;
zend_object_handlers ecma_handlers_IntlLocale;

static void freeLocaleObj(zend_object *object);

void registerEcmaIntlLocale() {
  ecma_ce_IntlLocale = register_class_Ecma_Intl_Locale(zend_ce_stringable);
  ecma_ce_IntlLocale->create_object = ecma_createIntlLocale;

  memcpy(&ecma_handlers_IntlLocale, zend_get_std_object_handlers(),
         sizeof(zend_object_handlers));

  ecma_handlers_IntlLocale.offset = XtOffsetOf(ecma_IntlLocale, std);
  ecma_handlers_IntlLocale.free_obj = freeLocaleObj;
}

zend_object *ecma_createIntlLocale(zend_class_entry *classEntry) {
  ecma_IntlLocale *intlLocale;

  intlLocale = zend_object_alloc(sizeof(struct ecma_IntlLocale), classEntry);

  zend_object_std_init(&intlLocale->std, classEntry);
  object_properties_init(&intlLocale->std, classEntry);

  intlLocale->std.handlers = &ecma_handlers_IntlLocale;
  intlLocale->original = NULL;
  intlLocale->canonical = NULL;

  return &intlLocale->std;
}

PHP_METHOD(Ecma_Intl_Locale, __construct) {
  char *tagArg = NULL;
  size_t tagArgLength = 0;
  ecma_IntlLocale *intlLocale;
  ecma402_errorStatus *errorStatus;
  char *canonicalized;

  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_STRING(tagArg, tagArgLength)
  ZEND_PARSE_PARAMETERS_END();

  if (!ecma402_isStructurallyValidLanguageTag(tagArg)) {
    zend_value_error("Invalid language tag \"%s\"", tagArg);
    RETURN_THROWS();
  }

  errorStatus = ecma402_initErrorStatus();
  canonicalized = (char *)emalloc(sizeof(char) * ULOC_FULLNAME_CAPACITY);

  ecma402_canonicalizeUnicodeLocaleId(tagArg, canonicalized, errorStatus);

  if (ecma402_hasError(errorStatus)) {
    zend_value_error("%s", errorStatus->errorMessage);
    efree(canonicalized);
  } else {
    intlLocale = ECMA_LOCALE_P(getThis());
    intlLocale->original = estrdup(tagArg);
    intlLocale->canonical = canonicalized;
  }

  ecma402_freeErrorStatus(errorStatus);
}

PHP_METHOD(Ecma_Intl_Locale, __toString) {
  ZEND_PARSE_PARAMETERS_NONE();
  ecma_IntlLocale *intlLocale = ECMA_LOCALE_P(getThis());
  RETURN_STRING(intlLocale->canonical);
}

static void freeLocaleObj(zend_object *object) {
  ecma_IntlLocale *intlLocale = ecma_IntlLocaleFromObj(object);
  zend_object_std_dtor(&intlLocale->std);

  if (intlLocale->original) {
    efree(intlLocale->original);
    intlLocale->original = NULL;
  }

  if (intlLocale->canonical) {
    efree(intlLocale->canonical);
    intlLocale->canonical = NULL;
  }
}
