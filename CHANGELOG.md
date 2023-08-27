# php-ecma-intl/ext Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/)
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## 0.1.1 - 2023-08-27

### Added

- Nothing.

### Changed

- Nothing.

### Deprecated

- Nothing.

### Removed

- Nothing.

### Fixed

- Remove `package.xml` from the manifest to avoid MD5 checksum errors when attempting to install via `pecl`.


## 0.1.0 - 2023-08-27

### Added

- Initial release with initial functionality ported from [ECMA-402, 10th edition](https://402.ecma-international.org/10.0/):
  - `Ecma\Intl` static class with static methods `getCanonicalLocales()` and `supportedValuesOf()`
  - `Ecma\Intl\Category` enum to pass to `Intl::supportedValuesOf()`
  - `Ecma\Intl\Locale` to represent Unicode locales
  - `Ecma\Intl\Locale\Options` for manipulating locales when creating instances of `Ecma\Intl\Locale`
  - Various classes for representing locale information:
    - `Ecma\Intl\Locale\TextInfo` and `Ecma\Intl\Locale\CharacterDirection`
    - `Ecma\Intl\Locale\WeekInfo` and `Ecma\Intl\Locale\WeekDay`

### Changed

- Nothing.

### Deprecated

- Nothing.

### Removed

- Nothing.

### Fixed

- Nothing.
