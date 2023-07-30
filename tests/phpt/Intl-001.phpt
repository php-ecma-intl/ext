--TEST--
Intl cannot be instantiated
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

new \Ecma\Intl();

--EXPECTF--
Fatal error: Uncaught Error: Call to private Ecma\Intl::__construct() from global scope in %s/tests/phpt/Intl-001.php:%d
Stack trace:
#%d {main}
  thrown in %s/tests/phpt/Intl-001.php on line %d
