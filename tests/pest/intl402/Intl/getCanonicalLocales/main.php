<?php

declare(strict_types=1);

use Ecma\Intl;

$tests = [
    ['test' => [], 'expected' => []],
    ['test' => 'ab-cd', 'expected' => ['ab-CD']],
    ['test' => ['ab-cd'], 'expected' => ['ab-CD']],
    ['test' => ['ab-cd', 'FF'], 'expected' => ['ab-CD', 'ff']],
    ['test' => ['th-th-u-nu-thai'], 'expected' => ['th-TH-u-nu-thai']],
];

it('maintains the default expected behavior', function (
    mixed $test,
    array $expected,
): void {
    expect(Intl::getCanonicalLocales($test))->toBe($expected);
})->with($tests);

