#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <check.h>

#include "../include/generic_map.h"

MAP_DEFINE_H(StringMap, string_map, char*, char*)

MAP_DEFINE_C(StringMap, string_map, char*, char*, fnv32, strcmp, NULL)

static StringMap* map;

static int test_number = 0;

void map_start(void) {
    map = string_map_create();
}

void map_reset(void) {
    string_map_free(map);
}

START_TEST(map_allocate_and_deallocate) {
    StringMap temp;
    ck_assert(string_map_init(&temp) != NULL);
    string_map_free_resources(&temp);
}
END_TEST

START_TEST(map_add_new_key_adds) {
    ck_assert(string_map_add(map, "hello", "world"));
    ck_assert(string_map_count(map) == 1);
}
END_TEST

START_TEST(map_add_duplicate_key_doesnt_add) {
    ck_assert(string_map_add(map, "hello", "world"));
    ck_assert(!string_map_add(map, "hello", "new world"));
}
END_TEST

START_TEST(map_get_existing_key_returns_value) {
    string_map_add(map, "hello", "world");
    ck_assert(strcmp(string_map_get(map, "hello"), "world") == 0);
}
END_TEST

START_TEST(map_get_missing_key_returns_default) {
    ck_assert(string_map_get(map, "hello") == NULL);
}
END_TEST

START_TEST(map_set_new_key_add) {
    ck_assert(string_map_count(map) == 0);
    string_map_set(map, "Alexander", "Hamilton");
    ck_assert(string_map_count(map) == 1);
    ck_assert(strcmp(string_map_get(map, "Alexander"), "Hamilton") == 0);
}
END_TEST

START_TEST(map_set_existing_key_replaces) {
    string_map_add(map, "hello", "world");
    ck_assert(strcmp(string_map_get(map, "hello"), "world") == 0);
    string_map_set(map, "hello", "new world");
    ck_assert(strcmp(string_map_get(map, "hello"), "new world") == 0);
}
END_TEST

START_TEST(map_remove_existing_key_removes) {
    string_map_add(map, "hello", "world");
    ck_assert(string_map_count(map) == 1);
    ck_assert(string_map_remove(map, "hello"));
    ck_assert(string_map_count(map) == 0);
}
END_TEST

START_TEST(map_remove_missing_key_returns_false) {
    ck_assert(!string_map_remove(map, "hello"));
}
END_TEST

START_TEST(map_resizes_when_load_factor_is_hit) {
    string_map_add(map, "a", "a");
    string_map_add(map, "b", "b");
    string_map_add(map, "c", "c");
    string_map_add(map, "d", "d");
    ck_assert(map->load_factor == 4);
    ck_assert(map->capacity == 8);
    string_map_add(map, "e", "e");
    ck_assert(map->load_factor == 8);
    ck_assert(map->capacity == 16);
    ck_assert(strcmp(string_map_get(map, "a"), "a") == 0);
    ck_assert(strcmp(string_map_get(map, "b"), "b") == 0);
}
END_TEST

int main(void) {
    Suite* s = suite_create("Map Tests");
    TCase* tc = tcase_create("Map Tests");

    tcase_add_checked_fixture(tc, map_start, map_reset);
    tcase_add_test(tc, map_allocate_and_deallocate);
    tcase_add_test(tc, map_add_new_key_adds);
    tcase_add_test(tc, map_add_duplicate_key_doesnt_add);
    tcase_add_test(tc, map_get_existing_key_returns_value);
    tcase_add_test(tc, map_get_missing_key_returns_default);
    tcase_add_test(tc, map_set_new_key_add);
    tcase_add_test(tc, map_set_existing_key_replaces);
    tcase_add_test(tc, map_remove_existing_key_removes);
    tcase_add_test(tc, map_remove_missing_key_returns_false);
    tcase_add_test(tc, map_resizes_when_load_factor_is_hit);

    suite_add_tcase(s, tc);

    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}