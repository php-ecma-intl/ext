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

#include "php/classes/locale_character_direction.h"

#include "php/classes/locale_character_direction_arginfo.h"

zend_class_entry *ecma_ce_IntlLocaleCharacterDirection = NULL;

PHP_MINIT_FUNCTION(ecma_intl_locale_characterdirection)
{
	ecma_ce_IntlLocaleCharacterDirection = register_class_Ecma_Intl_Locale_CharacterDirection();

	return SUCCESS;
}
