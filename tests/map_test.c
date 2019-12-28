#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "../include/generic_map.h"
#include "../include/generic_iterators/map_iterator.h"

MAP_DEFINE_H(StringMap, string_map, char*, char*)

MAP_DEFINE_C(StringMap, string_map, char*, char*, gds_fnv32, strcmp)

static StringMap* map;

static char* ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void map_start(void) {
    map = string_map_create();
}

void map_reset(void) {
    string_map_free(map);
}

START_TEST(map_allocate_and_deallocate) {
    StringMap temp;
    ck_assert(string_map_init(&temp));
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
    uint32_t capacity = map->capacity;
    uint32_t load_factor = map->load_factor;
    for(int i = 0; i <= load_factor; i++)
        string_map_add(map, ALPHABET + i, ALPHABET + i);
    ck_assert(map->capacity != capacity);
}
END_TEST

START_TEST(map_clear_can_keeps_capacity) {
    uint32_t load_factor = map->load_factor;

    for(int i = 0; i <= load_factor; i++)
        string_map_add(map, ALPHABET + i, ALPHABET + i);

    uint32_t capacity = map->capacity;
    string_map_clear(map, false);
    ck_assert(map->capacity == capacity);
    ck_assert(map->count == 0);
} 
END_TEST

START_TEST(map_clear_can_reset_capacity) {
    uint32_t load_factor = map->load_factor;

    for(int i = 0; i <= load_factor; i++)
        string_map_add(map, ALPHABET + i, ALPHABET + i);

    string_map_clear(map, true);
    ck_assert(map->capacity == 0);
    ck_assert(map->count == 0);
} 
END_TEST

START_TEST(map_iter_all) {
    StringMap forward;
    StringMap reverse;
    string_map_init(&forward);
    string_map_init(&reverse);
    for(int i = 0; i < 26; i++) {
        char* mem;
        mem = calloc(8, sizeof(char));
        mem[2] = 'a' + i;
        mem[0] = 'z' - i;
        mem[4] = 'z' - i;
        mem[6] = 'a' + i;
        string_map_add(&forward, mem + 2, mem + 0);
        string_map_add(&reverse, mem + 4, mem + 6);
    }
    char* key;
    char* value;
    int count = 0;
    map_iter_start(&forward, key, value)
    {
        ck_assert(strcmp(string_map_get(&reverse, key), value) == 0);
        ck_assert(strcmp(string_map_get(&reverse, value), key) == 0);
        count++;
    }
    map_iter_end

    ck_assert(count == 26);
    for(int i = 0; i < 26; i++) {
        char temp[2] = { 'a' + i, 0 };
        free(string_map_get(&forward, temp));
    }
    string_map_free_resources(&forward);
    string_map_free_resources(&reverse);
}
END_TEST

START_TEST(map_iter_some) {
    StringMap forward;
    StringMap reverse;
    string_map_init(&forward);
    string_map_init(&reverse);
    for(int i = 0; i < 26; i++) {
        char* mem;
        mem = calloc(8, sizeof(char));
        mem[2] = 'a' + i;
        mem[0] = 'z' - i;
        mem[4] = 'z' - i;
        mem[6] = 'a' + i;
        string_map_add(&forward, mem + 2, mem + 0);
        string_map_add(&reverse, mem + 4, mem + 6);
    }
    char* key;
    char* value;
    int count = 0;
    map_iter_start(&forward, key, value)
    {
        ck_assert(strcmp(string_map_get(&reverse, key), value) == 0);
        ck_assert(strcmp(string_map_get(&reverse, value), key) == 0);
        count++;

        if(count == 13)
            break;
    }
    map_iter_end

    ck_assert(count == 13);
    for(int i = 0; i < 26; i++) {
        char temp[2] = { 'a' + i, 0 };
        free(string_map_get(&forward, temp));
    }
    string_map_free_resources(&forward);
    string_map_free_resources(&reverse);
}
END_TEST

START_TEST(map_iter_keys) {
    StringMap forward;
    StringMap reverse;
    string_map_init(&forward);
    string_map_init(&reverse);
    for(int i = 0; i < 26; i++) {
        char* mem;
        mem = calloc(8, sizeof(char));
        mem[2] = 'a' + i;
        mem[0] = 'z' - i;
        mem[4] = 'z' - i;
        mem[6] = 'a' + i;
        string_map_add(&forward, mem + 2, mem + 0);
        string_map_add(&reverse, mem + 4, mem + 6);
    }
    char* key;
    int count = 0;
    map_iter_key_start(&forward, key)
    {
        char temp[2] = { 'a' + ('z' - key[0]), 0 };
        ck_assert(strcmp(string_map_get(&reverse, key), temp) == 0);
        count++;
    }
    map_iter_end

    ck_assert(count == 26);
    for(int i = 0; i < 26; i++) {
        char temp[2] = { 'a' + i, 0 };
        free(string_map_get(&forward, temp));
    }
    string_map_free_resources(&forward);
    string_map_free_resources(&reverse);
}
END_TEST

START_TEST(map_iter_values) {
    StringMap forward;
    StringMap reverse;
    string_map_init(&forward);
    string_map_init(&reverse);
    for(int i = 0; i < 26; i++) {
        char* mem;
        mem = calloc(8, sizeof(char));
        mem[2] = 'a' + i;
        mem[0] = 'z' - i;
        mem[4] = 'z' - i;
        mem[6] = 'a' + i;
        string_map_add(&forward, mem + 2, mem + 0);
        string_map_add(&reverse, mem + 4, mem + 6);
    }
    char* value;
    int count = 0;
    map_iter_key_start(&forward, value)
    {
        char temp[2] = { 'a' + ('z' - value[0]), 0 };
        ck_assert(strcmp(string_map_get(&reverse, value), temp) == 0);
        count++;
    }
    map_iter_end

    ck_assert(count == 26);
    for(int i = 0; i < 26; i++) {
        char temp[2] = { 'a' + i, 0 };
        free(string_map_get(&forward, temp));
    }
    string_map_free_resources(&forward);
    string_map_free_resources(&reverse);
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
    tcase_add_test(tc, map_iter_all);
    tcase_add_test(tc, map_iter_some);
    tcase_add_test(tc, map_iter_keys);
    tcase_add_test(tc, map_iter_values);

    suite_add_tcase(s, tc);

    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}