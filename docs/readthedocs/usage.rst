.. _usage:

=====
Usage
=====

An instance of :php:class:`Ecma\\Intl\\Locale` represents a Unicode locale
identifier and provides an API for manipulating Unicode locales.

The following example was adapted from `an example in the MDN Web Docs
<https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/Locale#try_it>`_.
In comparing the examples, you can see the similarities and differences between
the implementations. In fact, they're more similar than not.

.. code-block:: php

    use Ecma\Intl\Locale;
    use Ecma\Intl\Locale\Options;

    $korean = new Locale('ko', new Options(
        script: 'Kore',
        region: 'KR',
        hourCycle: 'h23',
        calendar: 'gregory',
    ));

    $japanese = new Locale('ja-Jpan-JP-u-ca-japanese-hc-h12');

    var_export($korean->baseName);
    var_export($japanese->baseName);
    // Expected output: 'ko-Kore-KR' 'ja-Jpan-JP'

    var_export($korean->hourCycle);
    var_export($japanese->hourCycle);
    // Expected output: 'h23' 'h12'

Basic Usage
-----------

Basic use of ``Locale`` involves passing a string locale identifier to the
constructor as the ``$tag`` parameter.

.. code-block:: php

    use Ecma\Intl\Locale;

    $us = new Locale('en-US');

Usage With Options
------------------

Along with the required ``$tag`` parameter, the ``Locale`` constructor also
accepts an optional :php:class:`Ecma\\Intl\\Locale\\Options` instance as the
``$options`` parameter.

.. code-block:: php

    use Ecma\Intl\Locale;
    use Ecma\Intl\Locale\Options;

    $us12hour = new Locale('en-US', new Options(hourCycle: 'h12'));
    var_export($us12hour->hourCycle); // Prints 'h12'
