<?php

declare(strict_types=1);

use Ecma\Intl;

// Since PHP's object model is very different from JavaScript's, we can't test
// whether the getCanonicalLocales "property" is writable, enumerable, or
// configurable, so we take an alternate approach here and test that it's a
// public static method. This ensures any polyfills or alternate implementations
// are identical.

$reflected = new ReflectionMethod(Intl::class, 'getCanonicalLocales');
$firstParameter = $reflected->getParameters()[0] ?? null;

it('is a static method on Ecma\\Intl')
    ->expect($reflected->isStatic())
    ->toBeTrue();

it('is a public method on Ecma\\Intl')
    ->expect($reflected->isPublic())
    ->toBeTrue();

it('has a first parameter')
    ->expect($firstParameter)
    ->toBeInstanceOf(ReflectionParameter::class);

test('its first parameter is required')
    ->expect($firstParameter->isOptional())
    ->toBeFalse();

test("its first parameter is named 'locales'")
    ->expect($firstParameter->getName())
    ->toBe('locales');

// @todo The parameter should also accept Ecma\Intl\Locale.
test("its first parameter's type is 'Traversable|array|string'", function () use ($firstParameter): void {
    $unionType = $firstParameter->getType();

    expect($unionType)
        ->toBeInstanceOf(ReflectionUnionType::class)
        ->and($unionType->allowsNull())
        ->toBeFalse();

    $typeNames = [];
    foreach ($unionType->getTypes() as $type) {
        $typeNames[] = $type->getName();
    }

    expect($typeNames)
        ->toHaveCount(3)
        ->toContain('array', 'string', Traversable::class);
});
