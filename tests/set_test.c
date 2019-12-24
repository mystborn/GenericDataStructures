#include "../include/generic_set.h"
#include "../include/generic_iterators/set_iterator.h"
#include <string.h>
#include <stdio.h>

#include <check.h>

SET_DEFINE_H(StringSet, str_set, char*)
SET_DEFINE_C(StringSet, str_set, char*, gds_fnv32, strcmp)

static StringSet* set;

void set_start(void) {
    set = str_set_create();
}

void set_reset(void) {
    str_set_free(set);
}

START_TEST(set_allocate_and_deallocate) {
    // Mostly just a fake test to make sure these don't crash the program.
    StringSet temp;
    ck_assert(str_set_init(&temp));
    str_set_free_resources(&temp);

    // Run it twice just to be extra sure.
    ck_assert(str_set_init(&temp));
    str_set_free_resources(&temp);
}
END_TEST

START_TEST(set_add_new_value_adds) {
    ck_assert(str_set_add(set, "owl"));
    ck_assert(str_set_count(set) == 1);
    ck_assert(str_set_add(set, "pig"));
    ck_assert(str_set_count(set) == 2);
}
END_TEST

START_TEST(set_add_duplicate_value_doesnt_add) {
    ck_assert(str_set_add(set, "owl"));
    ck_assert(!str_set_add(set, "owl"));
}
END_TEST

START_TEST(set_contains_existing_key) {
    str_set_add(set, "owl");
    str_set_add(set, "cow");
    ck_assert(str_set_contains(set, "owl"));
    ck_assert(str_set_contains(set, "cow"));
}
END_TEST

START_TEST(set_doesnt_contain_missing_key) {
    str_set_add(set, "owl");
    ck_assert(!str_set_contains(set, "cow"));
    ck_assert(!str_set_contains(set, "raven"));
}
END_TEST

START_TEST(set_remove_existing_key_removes) {
    str_set_add(set, "owl");
    ck_assert(str_set_contains(set, "owl"));
    ck_assert(str_set_remove(set, "owl"));
    ck_assert(!str_set_contains(set, "owl"));
}
END_TEST

START_TEST(set_remove_missing_key_returns_false) {
    ck_assert(!str_set_remove(set, "owl"));
    ck_assert(!str_set_remove(set, "raven"));
}
END_TEST

START_TEST(set_union_contains_left_and_right) {
    StringSet* left = str_set_create();
    StringSet* right = str_set_create();
    StringSet* result = str_set_create();

    str_set_add(left, "cow");
    str_set_add(right, "pig");

    ck_assert(str_set_union(left, right, result));
    ck_assert(str_set_count(result) == 2);
    ck_assert(str_set_contains(result, "cow"));
    ck_assert(str_set_contains(result, "pig"));
    ck_assert(!str_set_contains(result, "raven"));

    str_set_free(left);
    str_set_free(right);
    str_set_free(result);
}
END_TEST

START_TEST(set_intersect_contains_left_and_right_shared) {
    StringSet* left = str_set_create();
    StringSet* right = str_set_create();
    StringSet* result = str_set_create();

    str_set_add(left, "cow");
    str_set_add(left, "raven");
    str_set_add(right, "pig");
    str_set_add(right, "raven");

    ck_assert(str_set_intersect(left, right, result));
    ck_assert(str_set_count(result) == 1);
    ck_assert(!str_set_contains(result, "cow"));
    ck_assert(str_set_contains(result, "raven"));
    ck_assert(!str_set_contains(result, "pig"));

    str_set_free(left);
    str_set_free(right);
    str_set_free(result);
}
END_TEST

START_TEST(set_complement_contains_left_only) {
    StringSet* left = str_set_create();
    StringSet* right = str_set_create();
    StringSet* result = str_set_create();

    str_set_add(left, "cow");
    str_set_add(left, "raven");
    str_set_add(right, "pig");
    str_set_add(right, "cow");

    ck_assert(str_set_complement(left, right, result));
    ck_assert(str_set_count(result) == 1);
    ck_assert(!str_set_contains(result, "cow"));
    ck_assert(str_set_contains(result, "raven"));
    ck_assert(!str_set_contains(result, "pig"));

    str_set_free(left);
    str_set_free(right);
    str_set_free(result);
}
END_TEST

START_TEST(set_is_superset_left_is_superset) {
    StringSet* left = str_set_create();
    StringSet* right = str_set_create();

    str_set_add(left, "cow");
    str_set_add(left, "raven");
    str_set_add(left, "pig");
    str_set_add(right, "pig");
    str_set_add(right, "cow");

    ck_assert(str_set_is_superset(left, right));
    ck_assert(!str_set_is_superset(right, left));

    str_set_free(left);
    str_set_free(right);
}
END_TEST

START_TEST(set_resizes_when_load_factor_is_reached) {
    char* ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ck_assert(set->load_factor < strlen(ALPHABET));

    uint32_t load_factor = set->load_factor;
    int i = 0;
    while(load_factor == set->load_factor)
        str_set_add(set, ALPHABET + i++);

    ck_assert(set->load_factor == load_factor * 2);
}
END_TEST

#define ARRAY_SIZE(array) (sizeof((array)) / sizeof(*(array)))

START_TEST(set_iter_all) {
    char* animals[] = { "owl", "cow", "raven" };
    for(int i = 0; i < ARRAY_SIZE(animals); i++)
        str_set_add(set, animals[i]);

    int count = 0;
    char* value;
    bool found;
    set_iter_start(set, value) {
        found = false;
        for(int i = 0; i < ARRAY_SIZE(animals); i++) {
            if(strcmp(value, animals[i]) == 0) {
                found = true;
                break;
            }
        }
        ck_assert(found);
        count++;
    }
    set_iter_end

    ck_assert(count == 3);
}
END_TEST

START_TEST(set_iter_some) {
    str_set_add(set, "owl");
    str_set_add(set, "cow");
    str_set_add(set, "raven");

    char* dummy;
    int count = 0;
    set_iter_start(set, dummy) {
        if(++count == 2)
            break;
    }
    set_iter_end

    ck_assert(count == 2);
}
END_TEST

START_TEST(set_iter_skip) {
    str_set_add(set, "owl");
    str_set_add(set, "cow");
    str_set_add(set, "raven");

    char* dummy;
    int count = 0;
    int count2 = 0;
    set_iter_start(set, dummy) {
        if(++count == 2)
            continue;
        count2++;
    }
    set_iter_end

    ck_assert(count == 3);
    ck_assert(count2 == 2);
}
END_TEST

int main(void) {
    Suite* s = suite_create("Set Tests");
    TCase* tc = tcase_create("Set Tests");

    tcase_add_checked_fixture(tc, set_start, set_reset);
    tcase_add_test(tc, set_allocate_and_deallocate);
    tcase_add_test(tc, set_add_new_value_adds);
    tcase_add_test(tc, set_add_duplicate_value_doesnt_add);
    tcase_add_test(tc, set_contains_existing_key);
    tcase_add_test(tc, set_doesnt_contain_missing_key);
    tcase_add_test(tc, set_remove_existing_key_removes);
    tcase_add_test(tc, set_remove_missing_key_returns_false);
    tcase_add_test(tc, set_union_contains_left_and_right);
    tcase_add_test(tc, set_intersect_contains_left_and_right_shared);
    tcase_add_test(tc, set_complement_contains_left_only);
    tcase_add_test(tc, set_is_superset_left_is_superset);
    tcase_add_test(tc, set_resizes_when_load_factor_is_reached);
    tcase_add_test(tc, set_iter_all);
    tcase_add_test(tc, set_iter_some);
    tcase_add_test(tc, set_iter_skip);
    tcase_add_test(tc, set_allocate_and_deallocate);
    tcase_add_test(tc, set_allocate_and_deallocate);
    tcase_add_test(tc, set_allocate_and_deallocate);

    suite_add_tcase(s, tc);

    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}