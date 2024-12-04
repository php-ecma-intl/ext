#include "../test.h"

#include "ecma402/unit.h"

#define TEST_SUITE ecma402Unit

#define SANCTIONED_UNITS_COUNT 45
#define NON_SANCTIONED_UNITS_COUNT 130
#define WELL_FORMED_UNITS_COUNT 48
#define NON_WELL_FORMED_UNITS_COUNT 19

Test(TEST_SUITE, availableCanonicalUnitsIsSorted)
{
	const char **units = (const char **)malloc(sizeof(char *) * ECMA402_UNIT_CAPACITY);
	const int unitsLength = ecma402_availableCanonicalUnits(units);

	cr_expect(gt(int, unitsLength, 0));

	const char *previous = "";
	for (int i = 0; i < unitsLength; i++) {
		// Expect sorted values (i.e., this value is greater than the previous).
		cr_expect(gt(int, strcmp(units[i], previous), 0));

		previous = units[i];
	}

	free((void *)units);
}

ParameterizedTestParameters(TEST_SUITE, isSanctionedSingleUnitIdentifier)
{
	char *units[SANCTIONED_UNITS_COUNT] = {
		"acre", "bit", "byte", "celsius", "centimeter", "day", "degree", "fahrenheit", "fluid-ounce", "foot", "gallon",
		"gigabit", "gigabyte", "gram", "hectare", "hour", "inch", "kilobit", "kilobyte", "kilogram", "kilometer",
		"liter", "megabit", "megabyte", "meter", "microsecond", "mile", "mile-scandinavian", "milliliter", "millimeter",
		"millisecond", "minute", "month", "nanosecond", "ounce", "percent", "petabyte", "pound", "second", "stone",
		"terabit", "terabyte", "week", "yard", "year",
	};

	// ReSharper disable once CppDFAMemoryLeak
	// Allocated memory is freed in testFreeStrings().
	char **tests = (char **)cr_malloc(sizeof(char *) * SANCTIONED_UNITS_COUNT);

	for (int i = 0; i < SANCTIONED_UNITS_COUNT; i++) {
		tests[i] = testStrDup(units[i]);
	}

	return cr_make_param_array(const char *, tests, SANCTIONED_UNITS_COUNT, testFreeStrings);
}

ParameterizedTest(char **input, TEST_SUITE, isSanctionedSingleUnitIdentifier)
{
	cr_expect(ecma402_isSanctionedSingleUnitIdentifier(*input),
	          "Expected \"%s\" to be a sanctioned single unit identifier", *input);
}

ParameterizedTestParameters(TEST_SUITE, isNotSanctionedSingleUnitIdentifier)
{
	char *units[NON_SANCTIONED_UNITS_COUNT] = {
		"acre-foot", "ampere", "arc-minute", "arc-second", "astronomical-unit", "atmosphere", "bar", "barrel",
		"british-thermal-unit", "bushel", "calorie", "candela", "carat", "centiliter", "century", "cubic-centimeter",
		"cubic-foot", "cubic-inch", "cubic-kilometer", "cubic-meter", "cubic-mile", "cubic-yard", "cup", "cup-metric",
		"dalton", "day-person", "decade", "deciliter", "decimeter", "dessert-spoon", "dessert-spoon-imperial", "dot",
		"dram", "drop", "dunam", "earth-mass", "earth-radius", "electronvolt", "em", "fathom", "fluid-ounce-imperial",
		"foodcalorie", "furlong", "g-force", "gallon-imperial", "generic", "gigahertz", "gigawatt", "grain",
		"hectoliter", "hectopascal", "hertz", "horsepower", "inch-ofhg", "item", "jigger", "joule", "karat", "kelvin",
		"kilocalorie", "kilohertz", "kilojoule", "kilopascal", "kilowatt", "kilowatt-hour", "knot", "light-year",
		"lumen", "lux", "megahertz", "megaliter", "megapascal", "megapixel", "megawatt", "metric-ton", "microgram",
		"micrometer", "milliampere", "millibar", "milligram", "millimeter-ofhg", "milliwatt", "mole", "month-person",
		"nanometer", "nautical-mile", "newton", "newton-meter", "ohm", "ounce-troy", "parsec", "pascal", "permille",
		"permillion", "permyriad", "picometer", "pinch", "pint", "pint-metric", "pixel", "point", "pound-force",
		"pound-force-foot", "quart", "quart-imperial", "radian", "revolution", "solar-luminosity", "solar-mass",
		"solar-radius", "square-centimeter", "square-foot", "square-inch", "square-kilometer", "square-meter",
		"square-mile", "square-yard", "tablespoon", "teaspoon", "therm-us", "ton", "volt", "watt", "week-person",
		"year-person", "kilometer-per-hour", "liter-per-kilometer", "meter-per-second", "mile-per-gallon",
		"mile-per-hour",
	};

	// ReSharper disable once CppDFAMemoryLeak
	// Allocated memory is freed in testFreeStrings().
	char **tests = (char **)cr_malloc(sizeof(char *) * NON_SANCTIONED_UNITS_COUNT);

	for (int i = 0; i < NON_SANCTIONED_UNITS_COUNT; i++) {
		tests[i] = testStrDup(units[i]);
	}

	return cr_make_param_array(const char *, tests, NON_SANCTIONED_UNITS_COUNT, testFreeStrings);
}

ParameterizedTest(char **input, TEST_SUITE, isNotSanctionedSingleUnitIdentifier)
{
	cr_expect(false == ecma402_isSanctionedSingleUnitIdentifier(*input),
	          "Expected \"%s\" to not be a sanctioned single unit identifier", *input);
}

ParameterizedTestParameters(TEST_SUITE, isWellFormedUnitIdentifier)
{
	char *units[WELL_FORMED_UNITS_COUNT] = {
		"acre", "bit", "byte", "celsius", "centimeter", "day", "degree", "fahrenheit", "fluid-ounce", "foot", "gallon",
		"gigabit", "gigabyte", "gram", "hectare", "hour", "inch", "kilobit", "kilobyte", "kilogram", "kilometer",
		"kilometer-per-hour", "liter", "liter-per-kilometer", "megabit", "megabyte", "meter", "meter-per-second",
		"mile", "mile-per-gallon", "mile-per-hour", "mile-scandinavian", "milliliter", "millimeter", "millisecond",
		"minute", "month", "ounce", "percent", "petabyte", "pound", "second", "stone", "terabit", "terabyte", "week",
		"yard", "year",
	};

	char **tests = (char **)cr_malloc(sizeof(char *) * WELL_FORMED_UNITS_COUNT);

	for (int i = 0; i < WELL_FORMED_UNITS_COUNT; i++) {
		tests[i] = testStrDup(units[i]);
	}

	return cr_make_param_array(const char *, tests, WELL_FORMED_UNITS_COUNT, testFreeStrings);
}

ParameterizedTest(char **input, TEST_SUITE, isWellFormedUnitIdentifier)
{
	cr_expect(ecma402_isWellFormedUnitIdentifier(*input), "Excepted \"%s\" to be a well-formed unit identifier",
	          *input);
}

ParameterizedTestParameters(TEST_SUITE, isNotWellFormedUnitIdentifier)
{
	char *units[NON_WELL_FORMED_UNITS_COUNT] = {
		"acre-foot", "foobar", "dot-per-centimeter", "dot-per-inch", "kilowatt-hour-per-100-kilometer",
		"liter-per-100-kilometer", "meter-per-square-second", "mile-per-gallon-imperial",
		"milligram-ofglucose-per-deciliter", "milligram-per-deciliter", "millimole-per-liter", "pixel-per-centimeter",
		"pixel-per-inch", "pound-force-per-square-inch", "meter-per-", "-per-gallon", "meter-per-foobar",
		"foobar-per-gallon", "kilometer-per-hour-per-year",
	};

	char **tests = (char **)cr_malloc(sizeof(char *) * NON_WELL_FORMED_UNITS_COUNT);

	for (int i = 0; i < NON_WELL_FORMED_UNITS_COUNT; i++) {
		tests[i] = testStrDup(units[i]);
	}

	return cr_make_param_array(const char *, tests, NON_WELL_FORMED_UNITS_COUNT, testFreeStrings);
}

ParameterizedTest(char **input, TEST_SUITE, isNotWellFormedUnitIdentifier)
{
	cr_expect(false == ecma402_isWellFormedUnitIdentifier(*input),
	          "Expected \"%s\" to not be a well-formed unit identifier", *input);
}
