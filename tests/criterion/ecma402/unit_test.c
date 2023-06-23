#include "tests/criterion/test.h"

#include "src/ecma402/unit.h"

#define TEST_SUITE ecma402Unit

Test(TEST_SUITE, availableCanonicalUnitsIsSorted) {
  const char **units;
  int unitsLength;

  units = malloc(sizeof(char *) * ECMA402_UNIT_CAPACITY);
  unitsLength = ecma402_availableCanonicalUnits(units);

  cr_expect(gt(int, unitsLength, 0));

  const char *previous = "";
  for (int i = 0; i < unitsLength; i++) {
    // Expect sorted values (i.e., this value is greater than the previous).
    cr_expect(gt(int, strcmp(units[i], previous), 0));

    previous = units[i];
  }

  free(units);
}

ParameterizedTestParameters(TEST_SUITE, isSanctionedSingleUnitIdentifier) {
  char **tests = cr_malloc(sizeof(char *) * 45);

  tests[0] = testStrDup("acre");
  tests[1] = testStrDup("bit");
  tests[2] = testStrDup("byte");
  tests[3] = testStrDup("celsius");
  tests[4] = testStrDup("centimeter");
  tests[5] = testStrDup("day");
  tests[6] = testStrDup("degree");
  tests[7] = testStrDup("fahrenheit");
  tests[8] = testStrDup("fluid-ounce");
  tests[9] = testStrDup("foot");
  tests[10] = testStrDup("gallon");
  tests[11] = testStrDup("gigabit");
  tests[12] = testStrDup("gigabyte");
  tests[13] = testStrDup("gram");
  tests[14] = testStrDup("hectare");
  tests[15] = testStrDup("hour");
  tests[16] = testStrDup("inch");
  tests[17] = testStrDup("kilobit");
  tests[18] = testStrDup("kilobyte");
  tests[19] = testStrDup("kilogram");
  tests[20] = testStrDup("kilometer");
  tests[21] = testStrDup("liter");
  tests[22] = testStrDup("megabit");
  tests[23] = testStrDup("megabyte");
  tests[24] = testStrDup("meter");
  tests[25] = testStrDup("microsecond");
  tests[26] = testStrDup("mile");
  tests[27] = testStrDup("mile-scandinavian");
  tests[28] = testStrDup("milliliter");
  tests[29] = testStrDup("millimeter");
  tests[30] = testStrDup("millisecond");
  tests[31] = testStrDup("minute");
  tests[32] = testStrDup("month");
  tests[33] = testStrDup("nanosecond");
  tests[34] = testStrDup("ounce");
  tests[35] = testStrDup("percent");
  tests[36] = testStrDup("petabyte");
  tests[37] = testStrDup("pound");
  tests[38] = testStrDup("second");
  tests[39] = testStrDup("stone");
  tests[40] = testStrDup("terabit");
  tests[41] = testStrDup("terabyte");
  tests[42] = testStrDup("week");
  tests[43] = testStrDup("yard");
  tests[44] = testStrDup("year");

  return cr_make_param_array(const char *, tests, 45, testFreeStrings);
}

ParameterizedTest(char **input, TEST_SUITE, isSanctionedSingleUnitIdentifier) {
  cr_expect(ecma402_isSanctionedSingleUnitIdentifier(*input),
            "Expected \"%s\" to be a sanctioned single unit identifier",
            *input);
}

ParameterizedTestParameters(TEST_SUITE, isNotSanctionedSingleUnitIdentifier) {
  char **tests = cr_malloc(sizeof(char *) * 130);

  tests[0] = testStrDup("acre-foot");
  tests[1] = testStrDup("ampere");
  tests[2] = testStrDup("arc-minute");
  tests[3] = testStrDup("arc-second");
  tests[4] = testStrDup("astronomical-unit");
  tests[5] = testStrDup("atmosphere");
  tests[6] = testStrDup("bar");
  tests[7] = testStrDup("barrel");
  tests[8] = testStrDup("british-thermal-unit");
  tests[9] = testStrDup("bushel");
  tests[10] = testStrDup("calorie");
  tests[11] = testStrDup("candela");
  tests[12] = testStrDup("carat");
  tests[13] = testStrDup("centiliter");
  tests[14] = testStrDup("century");
  tests[15] = testStrDup("cubic-centimeter");
  tests[16] = testStrDup("cubic-foot");
  tests[17] = testStrDup("cubic-inch");
  tests[18] = testStrDup("cubic-kilometer");
  tests[19] = testStrDup("cubic-meter");
  tests[20] = testStrDup("cubic-mile");
  tests[21] = testStrDup("cubic-yard");
  tests[22] = testStrDup("cup");
  tests[23] = testStrDup("cup-metric");
  tests[24] = testStrDup("dalton");
  tests[25] = testStrDup("day-person");
  tests[26] = testStrDup("decade");
  tests[27] = testStrDup("deciliter");
  tests[28] = testStrDup("decimeter");
  tests[29] = testStrDup("dessert-spoon");
  tests[30] = testStrDup("dessert-spoon-imperial");
  tests[31] = testStrDup("dot");
  tests[32] = testStrDup("dram");
  tests[33] = testStrDup("drop");
  tests[34] = testStrDup("dunam");
  tests[35] = testStrDup("earth-mass");
  tests[36] = testStrDup("earth-radius");
  tests[37] = testStrDup("electronvolt");
  tests[38] = testStrDup("em");
  tests[39] = testStrDup("fathom");
  tests[40] = testStrDup("fluid-ounce-imperial");
  tests[41] = testStrDup("foodcalorie");
  tests[42] = testStrDup("furlong");
  tests[43] = testStrDup("g-force");
  tests[44] = testStrDup("gallon-imperial");
  tests[45] = testStrDup("generic");
  tests[46] = testStrDup("gigahertz");
  tests[47] = testStrDup("gigawatt");
  tests[48] = testStrDup("grain");
  tests[49] = testStrDup("hectoliter");
  tests[50] = testStrDup("hectopascal");
  tests[51] = testStrDup("hertz");
  tests[52] = testStrDup("horsepower");
  tests[53] = testStrDup("inch-ofhg");
  tests[54] = testStrDup("item");
  tests[55] = testStrDup("jigger");
  tests[56] = testStrDup("joule");
  tests[57] = testStrDup("karat");
  tests[58] = testStrDup("kelvin");
  tests[59] = testStrDup("kilocalorie");
  tests[60] = testStrDup("kilohertz");
  tests[61] = testStrDup("kilojoule");
  tests[62] = testStrDup("kilopascal");
  tests[63] = testStrDup("kilowatt");
  tests[64] = testStrDup("kilowatt-hour");
  tests[65] = testStrDup("knot");
  tests[66] = testStrDup("light-year");
  tests[67] = testStrDup("lumen");
  tests[68] = testStrDup("lux");
  tests[69] = testStrDup("megahertz");
  tests[70] = testStrDup("megaliter");
  tests[71] = testStrDup("megapascal");
  tests[72] = testStrDup("megapixel");
  tests[73] = testStrDup("megawatt");
  tests[74] = testStrDup("metric-ton");
  tests[75] = testStrDup("microgram");
  tests[76] = testStrDup("micrometer");
  tests[77] = testStrDup("milliampere");
  tests[78] = testStrDup("millibar");
  tests[79] = testStrDup("milligram");
  tests[80] = testStrDup("millimeter-ofhg");
  tests[81] = testStrDup("milliwatt");
  tests[82] = testStrDup("mole");
  tests[83] = testStrDup("month-person");
  tests[84] = testStrDup("nanometer");
  tests[85] = testStrDup("nautical-mile");
  tests[86] = testStrDup("newton");
  tests[87] = testStrDup("newton-meter");
  tests[88] = testStrDup("ohm");
  tests[89] = testStrDup("ounce-troy");
  tests[90] = testStrDup("parsec");
  tests[91] = testStrDup("pascal");
  tests[92] = testStrDup("permille");
  tests[93] = testStrDup("permillion");
  tests[94] = testStrDup("permyriad");
  tests[95] = testStrDup("picometer");
  tests[96] = testStrDup("pinch");
  tests[97] = testStrDup("pint");
  tests[98] = testStrDup("pint-metric");
  tests[99] = testStrDup("pixel");
  tests[100] = testStrDup("point");
  tests[101] = testStrDup("pound-force");
  tests[102] = testStrDup("pound-force-foot");
  tests[103] = testStrDup("quart");
  tests[104] = testStrDup("quart-imperial");
  tests[105] = testStrDup("radian");
  tests[106] = testStrDup("revolution");
  tests[107] = testStrDup("solar-luminosity");
  tests[108] = testStrDup("solar-mass");
  tests[109] = testStrDup("solar-radius");
  tests[110] = testStrDup("square-centimeter");
  tests[111] = testStrDup("square-foot");
  tests[112] = testStrDup("square-inch");
  tests[113] = testStrDup("square-kilometer");
  tests[114] = testStrDup("square-meter");
  tests[115] = testStrDup("square-mile");
  tests[116] = testStrDup("square-yard");
  tests[117] = testStrDup("tablespoon");
  tests[118] = testStrDup("teaspoon");
  tests[119] = testStrDup("therm-us");
  tests[120] = testStrDup("ton");
  tests[121] = testStrDup("volt");
  tests[122] = testStrDup("watt");
  tests[123] = testStrDup("week-person");
  tests[124] = testStrDup("year-person");

  // These are well-formed, but they aren't sanctioned single-unit identifiers.
  tests[125] = testStrDup("kilometer-per-hour");
  tests[126] = testStrDup("liter-per-kilometer");
  tests[127] = testStrDup("meter-per-second");
  tests[128] = testStrDup("mile-per-gallon");
  tests[129] = testStrDup("mile-per-hour");

  return cr_make_param_array(const char *, tests, 130, testFreeStrings);
}

ParameterizedTest(char **input, TEST_SUITE,
                  isNotSanctionedSingleUnitIdentifier) {
  cr_expect(false == ecma402_isSanctionedSingleUnitIdentifier(*input),
            "Expected \"%s\" to not be a sanctioned single unit identifier",
            *input);
}

ParameterizedTestParameters(TEST_SUITE, isWellFormedUnitIdentifier) {
  char **tests = cr_malloc(sizeof(*tests) * 48);

  tests[0] = testStrDup("acre");
  tests[1] = testStrDup("bit");
  tests[2] = testStrDup("byte");
  tests[3] = testStrDup("celsius");
  tests[4] = testStrDup("centimeter");
  tests[5] = testStrDup("day");
  tests[6] = testStrDup("degree");
  tests[7] = testStrDup("fahrenheit");
  tests[8] = testStrDup("fluid-ounce");
  tests[9] = testStrDup("foot");
  tests[10] = testStrDup("gallon");
  tests[11] = testStrDup("gigabit");
  tests[12] = testStrDup("gigabyte");
  tests[13] = testStrDup("gram");
  tests[14] = testStrDup("hectare");
  tests[15] = testStrDup("hour");
  tests[16] = testStrDup("inch");
  tests[17] = testStrDup("kilobit");
  tests[18] = testStrDup("kilobyte");
  tests[19] = testStrDup("kilogram");
  tests[20] = testStrDup("kilometer");
  tests[21] = testStrDup("kilometer-per-hour");
  tests[22] = testStrDup("liter");
  tests[23] = testStrDup("liter-per-kilometer");
  tests[24] = testStrDup("megabit");
  tests[25] = testStrDup("megabyte");
  tests[26] = testStrDup("meter");
  tests[27] = testStrDup("meter-per-second");
  tests[28] = testStrDup("mile");
  tests[29] = testStrDup("mile-per-gallon");
  tests[30] = testStrDup("mile-per-hour");
  tests[31] = testStrDup("mile-scandinavian");
  tests[32] = testStrDup("milliliter");
  tests[33] = testStrDup("millimeter");
  tests[34] = testStrDup("millisecond");
  tests[35] = testStrDup("minute");
  tests[36] = testStrDup("month");
  tests[37] = testStrDup("ounce");
  tests[38] = testStrDup("percent");
  tests[39] = testStrDup("petabyte");
  tests[40] = testStrDup("pound");
  tests[41] = testStrDup("second");
  tests[42] = testStrDup("stone");
  tests[43] = testStrDup("terabit");
  tests[44] = testStrDup("terabyte");
  tests[45] = testStrDup("week");
  tests[46] = testStrDup("yard");
  tests[47] = testStrDup("year");

  return cr_make_param_array(const char *, tests, 48, testFreeStrings);
}

ParameterizedTest(char **input, TEST_SUITE, isWellFormedUnitIdentifier) {
  cr_expect(ecma402_isWellFormedUnitIdentifier(*input),
            "Excepted \"%s\" to be a well-formed unit identifier", *input);
}

ParameterizedTestParameters(TEST_SUITE, isNotWellFormedUnitIdentifier) {
  char **tests = cr_malloc(sizeof(*tests) * 19);

  tests[0] = testStrDup("acre-foot");
  tests[1] = testStrDup("foobar");
  tests[2] = testStrDup("dot-per-centimeter");
  tests[3] = testStrDup("dot-per-inch");
  tests[4] = testStrDup("kilowatt-hour-per-100-kilometer");
  tests[5] = testStrDup("liter-per-100-kilometer");
  tests[6] = testStrDup("meter-per-square-second");
  tests[7] = testStrDup("mile-per-gallon-imperial");
  tests[8] = testStrDup("milligram-ofglucose-per-deciliter");
  tests[9] = testStrDup("milligram-per-deciliter");
  tests[10] = testStrDup("millimole-per-liter");
  tests[11] = testStrDup("pixel-per-centimeter");
  tests[12] = testStrDup("pixel-per-inch");
  tests[13] = testStrDup("pound-force-per-square-inch");
  tests[14] = testStrDup("meter-per-");
  tests[15] = testStrDup("-per-gallon");
  tests[16] = testStrDup("meter-per-foobar");
  tests[17] = testStrDup("foobar-per-gallon");
  tests[18] = testStrDup("kilometer-per-hour-per-year");

  return cr_make_param_array(const char *, tests, 19, testFreeStrings);
}

ParameterizedTest(char **input, TEST_SUITE, isNotWellFormedUnitIdentifier) {
  cr_expect(false == ecma402_isWellFormedUnitIdentifier(*input),
            "Expected \"%s\" to not be a well-formed unit identifier", *input);
}
