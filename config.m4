m4_include([m4/tests.m4])

PHP_ARG_ENABLE(
  [ecma_intl],
  [for i18n support, Ecma-style (ECMA-402)],
  [AS_HELP_STRING(
    [--enable-ecma_intl],
    [Enable i18n support, Ecma-style (ECMA-402)])
  ],
  [yes]
)

PHP_ARG_ENABLE(
  [criterion],
  [whether to enable support for Criterion tests],
  [AS_HELP_STRING(
    [--enable-criterion],
    [Enable support for running Criterion tests (development only)])
  ],
  [no],
  [no]
)

if test "$PHP_ECMA_INTL" != "no"; then
  PKG_CHECK_MODULES([ICU], [icu-uc >= 70.1 icu-i18n icu-io])

  PHP_EVAL_INCLINE($ICU_CFLAGS)
  PHP_EVAL_LIBLINE($ICU_LIBS, ECMA_INTL_SHARED_LIBADD)

  PHP_SUBST(ECMA_INTL_SHARED_LIBADD)
  AC_DEFINE(HAVE_ECMA_INTL, 1, [ Have ecma_intl support ])

  ECMA_INTL_COMMON_FLAGS="$ICU_CFLAGS"

  PHP_ECMA_INTL_C_SOURCES="                                                    \
    src/ecma402/calendar.c                                                     \
    src/ecma402/category.c                                                     \
    src/ecma402/collation.c                                                    \
    src/ecma402/currency.c                                                     \
    src/ecma402/error.c                                                        \
    src/ecma402/hour_cycle.c                                                   \
    src/ecma402/numbering_system.c                                             \
    src/ecma402/time_zone.c                                                    \
    src/php/classes/category.c                                                 \
    src/php/classes/intl.c                                                     \
    src/php/classes/locale.c                                                   \
    src/php/classes/locale_character_direction.c                               \
    src/php/classes/locale_options.c                                           \
    src/php/classes/locale_text_info.c                                         \
    src/php/classes/locale_week_day.c                                          \
    src/php/classes/locale_week_info.c                                         \
    src/php/classes/options.c                                                  \
    src/php/classes/supported_locales_options.c                                \
    src/php/ecma_intl.c                                                        \
    "

  PHP_ECMA_INTL_CXX_SOURCES="                                                  \
    src/ecma402/language_tag.cpp                                               \
    src/ecma402/locale.cpp                                                     \
    src/ecma402/unit.cpp                                                       \
    src/ecma402/util.cpp                                                       \
    "

  PHP_NEW_EXTENSION(
    ecma_intl,
    $PHP_ECMA_INTL_C_SOURCES,
    $ext_shared,
    ,
    $ECMA_INTL_COMMON_FLAGS,
    cxx
  )

  PHP_ADD_BUILD_DIR($ext_builddir/src/ecma402)
  PHP_ADD_BUILD_DIR($ext_builddir/src/php)
  PHP_ADD_BUILD_DIR($ext_builddir/src/php/classes)

  PHP_REQUIRE_CXX()
  PHP_CXX_COMPILE_STDCXX(11, mandatory, PHP_ECMA_INTL_STDCXX)

  EXTRA_CXXFLAGS="$PHP_ECMA_INTL_STDCXX $ICU_CXXFLAGS"
  PHP_SUBST(EXTRA_CXXFLAGS)

  if test "$ext_shared" = "no"; then
    PHP_ADD_SOURCES(
      PHP_EXT_DIR(ecma_intl),
      $PHP_ECMA_INTL_CXX_SOURCES,
      $ECMA_INTL_COMMON_FLAGS
    )
  else
    PHP_ADD_SOURCES_X(
      PHP_EXT_DIR(ecma_intl),
      $PHP_ECMA_INTL_CXX_SOURCES,
      $ECMA_INTL_COMMON_FLAGS,
      shared_objects_ecma_intl,
      yes
    )
  fi

  PHP_ADD_EXTENSION_DEP(ecma_intl, spl)

  PHP_ADD_MAKEFILE_FRAGMENT

  PHP_ADD_INCLUDE($ext_srcdir/src)
  PHP_ADD_INCLUDE($ext_builddir/src)

  if test "$PHP_CRITERION" != "no"; then
    PKG_CHECK_MODULES([CRITERION], [criterion])

    PHP_EVAL_INCLINE($CRITERION_CFLAGS)
    PHP_EVAL_LIBLINE($CRITERION_LIBS, CRITERION_LIBS)

    PHP_SUBST(CRITERION_LIBS)
    AC_DEFINE(HAVE_CRITERION, 1, [ Have Criterion support ])

    TEST_SOURCES="                                                             \
      src/ecma402/calendar.c                                                   \
      src/ecma402/category.c                                                   \
      src/ecma402/collation.c                                                  \
      src/ecma402/currency.c                                                   \
      src/ecma402/error.c                                                      \
      src/ecma402/hour_cycle.c                                                 \
      src/ecma402/language_tag.cpp                                             \
      src/ecma402/locale.cpp                                                   \
      src/ecma402/numbering_system.c                                           \
      src/ecma402/time_zone.c                                                  \
      src/ecma402/unit.cpp                                                     \
      src/ecma402/util.cpp                                                     \
      tests/criterion/ecma402/calendar_test.c                                  \
      tests/criterion/ecma402/category_test.c                                  \
      tests/criterion/ecma402/collation_test.c                                 \
      tests/criterion/ecma402/currency_test.c                                  \
      tests/criterion/ecma402/error_test.c                                     \
      tests/criterion/ecma402/hour_cycle_test.c                                \
      tests/criterion/ecma402/language_tag_test.cpp                            \
      tests/criterion/ecma402/locale_canonicalization_test.c                   \
      tests/criterion/ecma402/locale_getBaseName_test.c                        \
      tests/criterion/ecma402/locale_getCalendar_test.c                        \
      tests/criterion/ecma402/locale_getCaseFirst_test.c                       \
      tests/criterion/ecma402/locale_getCollation_test.c                       \
      tests/criterion/ecma402/locale_getCurrency_test.c                        \
      tests/criterion/ecma402/locale_getHourCycle_test.c                       \
      tests/criterion/ecma402/locale_getLanguage_test.c                        \
      tests/criterion/ecma402/locale_getNumberingSystem_test.c                 \
      tests/criterion/ecma402/locale_getRegion_test.c                          \
      tests/criterion/ecma402/locale_getScript_test.c                          \
      tests/criterion/ecma402/locale_initLocale_test.c                         \
      tests/criterion/ecma402/locale_isNumeric_test.c                          \
      tests/criterion/ecma402/locale_min_max_test.c                            \
      tests/criterion/ecma402/locale_options_test.c                            \
      tests/criterion/ecma402/locale_test.c                                    \
      tests/criterion/ecma402/numbering_system_test.c                          \
      tests/criterion/ecma402/time_zone_test.c                                 \
      tests/criterion/ecma402/unit_test.c                                      \
      tests/criterion/ecma402/util_test.cpp                                    \
      tests/criterion/test.c                                                   \
      "

    TEST_ADD_SOURCES(
      PHP_EXT_DIR(ecma_intl),
      $TEST_SOURCES,
      $ICU_CFLAGS,
      criterion_objects,
    )

    PHP_SUBST(criterion_objects)
  fi
fi
