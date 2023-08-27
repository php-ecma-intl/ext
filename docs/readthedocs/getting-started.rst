.. _getting-started:

===============
Getting Started
===============

Requirements
############

ecma_intl requires the following:

* PHP 8.2+
* ICU 70.1+

`ICU <https://unicode-org.github.io/icu/>`_ is a C++ and C library that provides
full-featured Unicode support. You'll need to install a package that includes
the *development headers*. Here are a few pointers:

* On macOS or Linux, you may use `Homebrew <https://brew.sh>`_ to install the
  `icu4c package <https://formulae.brew.sh/formula/icu4c>`_.
* If using `APT <https://en.wikipedia.org/wiki/APT_(software)>`_, install the
  *libicu-dev* package.
* If using `YUM <https://en.wikipedia.org/wiki/Yum_(software)>`_ or
  `DNF <https://en.wikipedia.org/wiki/DNF_(software)>`_, install the
  *libicu-devel* package.

Installation
############

The quickest way to install ecma_intl is with ``pecl``:

.. code-block:: bash

    pecl install ecma_intl-alpha

.. hint::

    In this example, we're appending "-alpha" to the end of the package name
    because the package has no stable releases, and by default, ``pecl`` will
    not install non-stable packages.

In some cases, you might need to set the ``PKG_CONFIG_PATH`` environment
variable so the installer can find the libicu library and header files.

For example, if using Homebrew, you may do something like this:

.. code-block:: bash

    PKG_CONFIG_PATH="$(brew --prefix icu4c)/lib/pkgconfig" pecl install ecma_intl-alpha

Configuration
#############

Before you can use ecma_intl, you'll need to tell PHP to load it. You do this by
adding the following line to the ``php.ini`` file:

.. code-block:: ini

    extension=ecma_intl

.. tip::

    For a more automated approach, if ``php-config --ini-dir`` returns a value,
    you may do something like this:

    .. code-block:: bash

        echo "extension=ecma_intl" > $(php-config --ini-dir)/ecma_intl.ini

    Or you may append the value to ``php.ini`` with something like this:

    .. code-block:: bash

        echo "extension=ecma_intl" >> $(php-config --ini-path)/php.ini

To verify your installation, type ``php --ri ecma_intl``, and you should see
output similar to the following:

.. code-block:: text

    ecma_intl

    Internationalization Support, Ecma-style (ECMA-402) => enabled
    ecma_intl version => 0.1.0
    ICU version => 73.2
    ICU Data version => 73.2
    ICU TZData version => 2023c
    ICU Unicode version => 15.0
