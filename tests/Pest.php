<?php

use Ecma\Test\TestCase;

uses(TestCase::class)->in('pest');

/**
 * @link https://unicode.org/reports/tr35/tr35.html#Unicode_locale_identifier Unicode Locale Identifier
 */
const TYPE_PRODUCTION_PATTERN = '/^[a-z0-9]{3,8}(-[a-z0-9]{3,8})*$/';

/**
 * Pattern that matches three-letter ISO 4217 currency codes
 *
 * @link https://tc39.es/ecma402/#sec-availablecanonicalcurrencies ECMA-402, section 6.4, AVailableCanonicalCurrencies()
 */
const CURRENCY_PATTERN = '/^[A-Z]{3}$/';
