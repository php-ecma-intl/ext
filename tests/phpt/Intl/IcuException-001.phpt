--TEST--
IcuException is a child of \RuntimeException
--EXTENSIONS--
ecma_intl
--FILE--
<?php
use Ecma\Intl\IcuException;

echo IcuException::class . "\n";
echo get_parent_class(IcuException::class) . "\n";

--EXPECT--
Ecma\Intl\IcuException
RuntimeException
