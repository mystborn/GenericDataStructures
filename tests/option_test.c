#include "../include/generic_option.h"
#include <stdlib.h>

#include <check.h>

OPTION_DEFINE_H(OptionalInt, opt_int, int)

START_TEST(option_make_function) {
    OptionalInt option = opt_int_make(2);
    ck_assert(option.value == 2);
    ck_assert(option.has_value);
}
END_TEST

START_TEST(option_make_macro) {
    OptionalInt option = gds_option_make(OptionalInt, 3);
    ck_assert(option.value == 3);
    ck_assert(option.has_value);
}
END_TEST

START_TEST(option_default_function) {
    OptionalInt option = opt_int_default();
    ck_assert(!option.has_value);
}
END_TEST

START_TEST(option_default_macro) {
    OptionalInt option = gds_option_default(OptionalInt);
    ck_assert(!option.has_value);
}
END_TEST

START_TEST(option_has_value_function) {
    OptionalInt option = opt_int_make(4);
    ck_assert(opt_int_has_value(option));
    option = opt_int_default();
    ck_assert(!opt_int_has_value(option));
}
END_TEST

START_TEST(option_has_value_macro) {
    OptionalInt option = opt_int_make(5);
    ck_assert(gds_option_has_value(option));
    option = opt_int_default();
    ck_assert(!gds_option_has_value(option));
}
END_TEST

START_TEST(option_value_function) {
    OptionalInt option = opt_int_make(6);
    ck_assert(opt_int_value(option) == 6);
}
END_TEST

START_TEST(option_value_macro) {
    OptionalInt option = opt_int_make(7);
    ck_assert(gds_option_value(option));
}
END_TEST

START_TEST(option_value_or_default_function) {
    OptionalInt option = opt_int_make(8);
    ck_assert(opt_int_value_or_default(option) == 8);
    option = opt_int_default();
    ck_assert(opt_int_value_or_default(option) == 0);
}
END_TEST

START_TEST(option_value_or_default_macro) {
    OptionalInt option = opt_int_make(9);
    ck_assert(gds_option_value_or_default(option) == 9);
    option = opt_int_default();
    ck_assert(gds_option_value_or_default(option) == 0);
}
END_TEST

int main(void) {
    Suite* s = suite_create("Optional Value Tests");
    TCase* tc = tcase_create("Optional Value Tests");

    tcase_add_test(tc, option_make_function);
    tcase_add_test(tc, option_make_macro);
    tcase_add_test(tc, option_default_function);
    tcase_add_test(tc, option_default_macro);
    tcase_add_test(tc, option_has_value_function);
    tcase_add_test(tc, option_has_value_macro);
    tcase_add_test(tc, option_value_function);
    tcase_add_test(tc, option_value_macro);
    tcase_add_test(tc, option_value_or_default_function);
    tcase_add_test(tc, option_value_or_default_macro);


    suite_add_tcase(s, tc);

    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}