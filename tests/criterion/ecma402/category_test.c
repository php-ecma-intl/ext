#include "src/ecma402/calendar.h"
#include "src/ecma402/category.h"
#include "src/ecma402/collation.h"
#include "src/ecma402/currency.h"
#include "tests/criterion/test.h"

#define TEST_SUITE ecma402Category

#define CATEGORY_VALUES_TEST(name, category, capacity)                         \
  Test(TEST_SUITE, getsSupportedValuesFor##name##Category) {                   \
    const char **values;                                                       \
    int count;                                                                 \
    values = (const char **)malloc(sizeof(const char *) * capacity);           \
    count = getSupportedValuesForCategory(category, values);                   \
    cr_expect(values != NULL);                                                 \
    cr_expect(gt(int, count, 0));                                              \
    free(values);                                                              \
  }

#define CATEGORY_CAPACITY_TEST(name, category, expectedCapacity)               \
  Test(TEST_SUITE, getsCapacityFor##name##Category) {                          \
    int actualCapacity = getCapacityForCategory(category);                     \
    cr_assert(eq(int, actualCapacity, expectedCapacity));                      \
  }

CATEGORY_VALUES_TEST(Collation, CATEGORY_COLLATION, COLLATION_CAPACITY)

CATEGORY_CAPACITY_TEST(Calendar, CATEGORY_CALENDAR, CALENDAR_CAPACITY)
CATEGORY_CAPACITY_TEST(Collation, CATEGORY_COLLATION, COLLATION_CAPACITY)
CATEGORY_CAPACITY_TEST(Currency, CATEGORY_CURRENCY, CURRENCY_CAPACITY)
CATEGORY_CAPACITY_TEST(NumberingSystem, CATEGORY_NUMBERING_SYSTEM,
                       CATEGORY_NUMBERING_SYSTEM_CAPACITY)
CATEGORY_CAPACITY_TEST(TimeZone, CATEGORY_TIME_ZONE,
                       CATEGORY_TIME_ZONE_CAPACITY)
CATEGORY_CAPACITY_TEST(Unit, CATEGORY_UNIT, CATEGORY_UNIT_CAPACITY)

Test(TEST_SUITE, getsSupportedValuesForInvalidCategory) {
  const char **values;
  int count;

  values = (const char **)malloc(sizeof(const char *) * 1);
  count = getSupportedValuesForCategory("foo", values);

  cr_expect(eq(int, count, 0));

  free(values);
}
