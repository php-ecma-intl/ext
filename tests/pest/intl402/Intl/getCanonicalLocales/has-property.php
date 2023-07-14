<?php

declare(strict_types=1);

use Ecma\Intl;

// PHP arrays and iterables don't have "length" or "has" properties, so we will
// test that we reach all items of the iterable by testing for an exception
// thrown from a Traversable class.

$tags = [
    'en-US',
    'pt-BR',
    fn (): never => throw new RuntimeException('Whoops!'),
];

$locales = new class ($tags) implements Iterator {
    public function __construct(private array $tags)
    {
    }

    public function current(): mixed
    {
        $current = current($this->tags);

        if (is_callable($current)) {
            return $current();
        }

        return $current;
    }

    public function next(): void
    {
        next($this->tags);
    }

    public function key(): string | int | null
    {
        return key($this->tags);
    }

    public function valid(): bool
    {
        return key($this->tags) !== null;
    }

    public function rewind(): void
    {
        reset($this->tags);
    }
};

it('iterates through Traversable', function () use ($locales): void {
    expect(fn () => Intl::getCanonicalLocales($locales))
        ->toThrow(RuntimeException::class, 'Whoops!');
});
