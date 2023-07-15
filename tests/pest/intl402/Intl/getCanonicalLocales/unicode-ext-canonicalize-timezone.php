<?php

declare(strict_types=1);

use Ecma\Intl;

// <key name="tz" [...] alias="timezone">
$testData = [
    // Similar to the "ca" extension key, assume "preferred" holds the canonical
    // value and "name" the alias value.

    // <type name="cnckg" [...] deprecated="true" preferred="cnsha"/>
    'cnckg' => 'cnsha',

    // NB: "Eire" matches the |uvalue| production.
    // <type name="iedub" [...] alias="Europe/Dublin Eire"/>
    'eire' => 'iedub',

    // NB: "EST" matches the |uvalue| production.
    // <type name="utcw05" [...] alias="Etc/GMT+5 EST"/>
    'est' => 'utcw05',

    // NB: "GMT0" matches the |uvalue| production.
    // <type name="gmt" [...] alias="Etc/GMT Etc/GMT+0 Etc/GMT-0 Etc/GMT0 Etc/Greenwich GMT GMT+0 GMT-0 GMT0 Greenwich"/>
    'gmt0' => 'gmt',

    // NB: "UCT" matches the |uvalue| production.
    // <type name="utc" [...] alias="Etc/UTC Etc/UCT Etc/Universal Etc/Zulu UCT UTC Universal Zulu"/>
    'uct' => 'utc',

    // NB: "Zulu" matches the |uvalue| production.
    // <type name="utc" [...] alias="Etc/UTC Etc/UCT Etc/Universal Etc/Zulu UCT UTC Universal Zulu"/>
    'zulu' => 'utc',
];

it('canonicalizes for the "tz" Unicode subtag extension key', function (
    string $alias,
    string $name,
): void {
    $tag = "und-u-tz-$alias";
    $canonical = "und-u-tz-$name";

    expect(isCanonicalizedStructurallyValidLanguageTag($tag))
        ->toBeFalse()
        ->and(isCanonicalizedStructurallyValidLanguageTag($canonical))
        ->toBeTrue()
        ->and(Intl::getCanonicalLocales($tag))
        ->toHaveCount(1)
        ->{0}->toBe($canonical);
})->with(array_map(
    fn ($k, $v) => [$k, $v],
    array_keys($testData),
    array_values($testData),
));

