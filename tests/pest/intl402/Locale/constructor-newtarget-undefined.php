<?php

declare(strict_types=1);

use Ecma\Intl\Locale;

$reflected = new ReflectionClass(Locale::class);

it('has a constructor')
    ->expect($reflected->hasMethod('__construct'))
    ->toBeTrue();

it('is instantiable')
    ->expect($reflected->isInstantiable())
    ->toBeTrue();

test('its constructor requires a parameter')
    ->expect($reflected->getConstructor()?->getParameters()[0]->isOptional())
    ->toBeFalse();

it('throws TypeError for a null value', function (): void {
    expect(fn () => new Locale(null))
        ->toThrow(TypeError::class);
});
