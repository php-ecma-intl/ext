<?php

declare(strict_types=1);

use Ecma\Intl;
use Ecma\Intl\Locale;

readonly class MyLocale extends Locale
{
}

$tag = 'ar';
$tag2 = 'fa';
$tag3 = 'zh';
$loc = new Locale($tag);
$loc2 = new MyLocale($tag2);

test('Intl::getCanonicalLocales accepts Locale as an argument')
    ->expect(Intl::getCanonicalLocales($loc))
    ->toHaveCount(1)
    ->{0}->toBe($tag);

it('Intl::getCanonicalLocales accepts extended Locale as an argument')
    ->expect(Intl::getCanonicalLocales($loc2))
    ->toHaveCount(1)
    ->{0}->toBe($tag2);

it('Intl::getCanonicalLocales accepts array containing Locale and string values')
    ->expect(Intl::getCanonicalLocales([$loc, $tag3, $loc2]))
    ->toHaveCount(3)
    ->{0}->toBe($tag)
    ->{1}->toBe($tag3)
    ->{2}->toBe($tag2);
