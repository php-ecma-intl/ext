<?php

use Ecma\Test\TestCase;

uses(TestCase::class)->in('pest');

/**
 * @link https://unicode.org/reports/tr35/tr35.html#Unicode_locale_identifier
 */
const TYPE_VALUE_PATTERN = '/^[a-z0-9]{3,8}(-[a-z0-9]{3,8})*$/';
