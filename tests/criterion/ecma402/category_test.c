#include "src/ecma402/category.h"
#include "tests/criterion/test.h"

#define TEST_SUITE ecma402Category

#define CATEGORY_CAPACITY_TEST(name, category, expectedCapacity)               \
  Test(TEST_SUITE, getsCapacityFor##name##Category) {                          \
    int actualCapacity = getCapacityForCategory(category);                     \
    cr_assert(eq(int, actualCapacity, expectedCapacity));                      \
  }

CATEGORY_CAPACITY_TEST(Calendar, CATEGORY_CALENDAR, CATEGORY_CALENDAR_CAPACITY)
CATEGORY_CAPACITY_TEST(Collation, CATEGORY_COLLATION,
                       CATEGORY_COLLATION_CAPACITY)
CATEGORY_CAPACITY_TEST(Currency, CATEGORY_CURRENCY, CATEGORY_CURRENCY_CAPACITY)
CATEGORY_CAPACITY_TEST(NumberingSystem, CATEGORY_NUMBERING_SYSTEM,
                       CATEGORY_NUMBERING_SYSTEM_CAPACITY)
CATEGORY_CAPACITY_TEST(TimeZone, CATEGORY_TIME_ZONE,
                       CATEGORY_TIME_ZONE_CAPACITY)
CATEGORY_CAPACITY_TEST(Unit, CATEGORY_UNIT, CATEGORY_UNIT_CAPACITY)
