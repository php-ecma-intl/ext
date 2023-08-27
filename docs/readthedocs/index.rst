.. _index:

==============
pecl/ecma_intl
==============

`pecl/ecma_intl <https://github.com/php-ecma-intl>`_ is a **PHP** implementation of
the `ECMAScript Internationalization API Specification <https://tc39.es/ecma402/>`_
(ECMA-402).

.. admonition:: But, wait!
    :class: danger

    PHP isn't JavaScript, silly! 🤪

That's right!

There are a few differences from ECMA-402, but for the most part, **things work
as one might expect**. This means you can read the `Intl documentation on MDN
<https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl>`_
and translate it to PHP with a few small changes!

Here are a few of the key differences:

Namespaces:
  This implementation uses `PHP namespaces <https://www.php.net/namespaces>`_. The
  top-level namespace is ``Ecma``, and most everything is under the ``Ecma\Intl``
  namespace. This means that ``Intl.Locale`` in JavaScript becomes
  :php:class:`Ecma\\Intl\\Locale` in PHP.

Accessor syntax:
  Where JavaScript uses dot notation (``.``) for property and method access,
  PHP uses "arrows" made up of the hyphen and greater-than characters (``->``);
  for static methods, PHP uses double colon (``::``). This means
  ``Intl.getCanonicalLocales()`` in JavaScript becomes
  :php:meth:`Ecma\\Intl::getCanonicalLocales()` in PHP, and ``locale.baseName`` in
  JavaScript becomes ``$locale->baseName`` in PHP.

Object model:
  JavaScript is a `prototype-based language <https://en.wikipedia.org/wiki/Prototype-based_programming>`_,
  while PHP is a `class-based language <https://en.wikipedia.org/wiki/Class-based_programming>`_.
  As a result, objects in this implementation have some nuanced differences that
  diverge from the ECMA-402 standard.

  Additionally, JavaScript has generic objects (i.e., ``{}``) it passes around
  like hashes. The closest equivalent in PHP is an associative array, but we
  chose to use stronger typing in this implementation. As a result, many of the
  object hashes defined in ECMA-402 (e.g., the options argument passed to the
  ``Intl.Locale`` constructor) are objects with typed properties in PHP (e.g.,
  :php:class:`Ecma\\Intl\\Locale\\Options`).

Contents
--------

.. toctree::
   :maxdepth: 2
   :includehidden:

   getting-started
   usage
   reference

Indices and tables
------------------

* :ref:`genindex`
* :ref:`search`

----

| For `pecl/ecma_intl <https://github.com/php-ecma-intl/ext>`__ at |version|.
  Updated on |today|.
| This documentation is licensed under the `Creative Commons Attribution
  4.0 International <https://creativecommons.org/licenses/by/4.0/>`_ license.
