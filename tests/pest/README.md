# Test262: ECMAScript Test Suite

This is a PHP port of the `intl402` test suite for [ECMA-402](https://tc39.es/ecma402/)
from [Test262](https://github.com/tc39/test262). This port is up-to-date with
Test262, as of the version of Test262 included in this project as a Git
submodule at [resources/test262](../../resources/test262).

Since PHP does not follow the same conventions as JavaScript, PHP code
implementing ECMA-402, will differ from the specification. Where it differs,
this test suite follows the reference implementation for
[pecl/ecma_intl](https://github.com/ramsey/php-ecma-intl-ext). Polyfills may use
this test suite to ensure compatibility with pecl/ecma_intl.

## Structure

Files within this test suite use the [Pest testing framework](https://pestphp.com)
and are named according to their names and paths within the original Test262
repository. For example, the test file `intl402/Intl/getCanonicalLocales/
complex-region-subtag-replacement.php` has a corresponding test file in Test262
at the path `test/intl402/Intl/getCanonicalLocales/complex-region-subtag-
replacement.js`.
