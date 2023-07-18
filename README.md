<h1 align="center">pecl/ecma_intl</h1>

<p align="center">
    <strong>A PHP implementation of <a href="https://tc39.es/ecma402/#introduction">ECMA-402</a></strong>
</p>

<!--
TODO: Make sure the following URLs are correct and working for your project.
      Then, remove these comments to display the badges, giving users a quick
      overview of your package.

<p align="center">
    <a href="https://github.com/php-ecma-intl/ext"><img src="https://img.shields.io/badge/source-php--ecma--intl/ext-blue.svg?style=flat-square" alt="Source Code"></a>
    <a href="https://packagist.org/packages/php-ecma-intl/ext"><img src="https://img.shields.io/packagist/v/php-ecma-intl/ext.svg?style=flat-square&label=release" alt="Download Package"></a>
    <a href="https://php.net"><img src="https://img.shields.io/packagist/php-v/php-ecma-intl/ext.svg?style=flat-square&colorB=%238892BF" alt="PHP Programming Language"></a>
    <a href="https://github.com/php-ecma-intl/ext/blob/main/LICENSE"><img src="https://img.shields.io/packagist/l/php-ecma-intl/ext.svg?style=flat-square&colorB=darkcyan" alt="Read License"></a>
    <a href="https://github.com/php-ecma-intl/ext/actions/workflows/continuous-integration.yml"><img src="https://img.shields.io/github/actions/workflow/status/php-ecma-intl/ext/continuous-integration.yml?branch=main&style=flat-square&logo=github" alt="Build Status"></a>
    <a href="https://codecov.io/gh/php-ecma-intl/ext"><img src="https://img.shields.io/codecov/c/gh/php-ecma-intl/ext?label=codecov&logo=codecov&style=flat-square" alt="Codecov Code Coverage"></a>
    <a href="https://shepherd.dev/github/php-ecma-intl/ext"><img src="https://img.shields.io/endpoint?style=flat-square&url=https%3A%2F%2Fshepherd.dev%2Fgithub%2Fphp-ecma-intl%2Fext%2Fcoverage" alt="Psalm Type Coverage"></a>
</p>
-->


## About

This project adheres to a [code of conduct](CODE_OF_CONDUCT.md).
By participating in this project and its community, you are expected to
uphold this code.


## Installation

TBD

``` bash
git clone https://github.com/ramsey/php-ecma-intl-ext.git ext
cd ext
phpize
./configure --enable-ecma_intl
make
make install
```

Add the following to your `php.ini` file:

```ini
extension=ecma_intl
```


<!--
## Usage

Provide a brief description or short example of how to use this library.
If you need to provide more detailed examples, use the `docs/` directory
and provide a link here to the documentation.

``` php
use Ecma\Example;

$example = new Example();
echo $example->greet('fellow human');
```
-->


## Contributing

Contributions are welcome! To contribute, please familiarize yourself with
[CONTRIBUTING.md](CONTRIBUTING.md).


## Coordinated Disclosure

Keeping user information safe and secure is a top priority, and we welcome the
contribution of external security researchers. If you believe you've found a
security issue in software that is maintained in this repository, please read
[SECURITY.md](SECURITY.md) for instructions on submitting a vulnerability report.


## Copyright and License

pecl/ecma_intl is copyright © [php-ecma-intl](https://github.com/php-ecma-intl)
contributors and licensed for use under the terms of the BSD 3-Clause "New" or
"Revised" License (BSD-3-Clause). Please see [LICENSE](LICENSE) for more
information.

pecl/ecma_intl may utilize copyrighted material under license from the
following projects:

- [International Components for Unicode \(ICU\)](https://github.com/unicode-org/icu)
- [WebKit](https://github.com/WebKit/WebKit)

Please see [NOTICE](NOTICE) for more information.
