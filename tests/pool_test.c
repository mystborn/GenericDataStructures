#include <check.h>

#include "../include/generic_pool.h"

#define POOL_INITIAL_VALUE 5

void int_init(int* i) { *i = POOL_INITIAL_VALUE; }
void int_free_resources(int* i) { }

POOL_DEFINE_H(IntPool, int_pool, int)
POOL_DEFINE_C(IntPool, int_pool, int, int_init, int_free_resources)

IntPool* pool;

void pool_start(void) {
    pool = int_pool_create();
}

void pool_reset(void) {
    int_pool_free(pool);
}

START_TEST(pool_allocate_and_deallocate) {
    IntPool value;
    ck_assert(int_pool_init(&value));
    int_pool_free_resources(&value);

    IntPool* ptr = int_pool_create();
    ck_assert(ptr);
    int_pool_free(ptr);
}
END_TEST

START_TEST(pool_get_value) {
    int* i = int_pool_get(pool);
    ck_assert(*i == POOL_INITIAL_VALUE);
}
END_TEST

START_TEST(pool_release_value) {
    int* i = int_pool_get(pool);
    ck_assert(*i == POOL_INITIAL_VALUE);
    ck_assert(int_pool_release(pool, i));
}
END_TEST

START_TEST(pool_get_released_value_reuses_memory) {
    int* i = int_pool_get(pool);
    int* j = int_pool_get(pool);
    int* copy = i;
    ck_assert(int_pool_release(pool, i));
    i = int_pool_get(pool);
    ck_assert(i == copy);
}
END_TEST

#define POOL_SIZE 1000

START_TEST(pool_stress_test) {
    int** buffer = malloc(POOL_SIZE * sizeof(*buffer));

    for(int reps = 0; reps < 2; reps++) {
        for(int i = 0; i < POOL_SIZE; i++) {
            buffer[i] = int_pool_get(pool);
            ck_assert(*buffer[i] == POOL_INITIAL_VALUE);
        }

        for(int i = 0; i < POOL_SIZE; i++)
            ck_assert(int_pool_release(pool, buffer[i]));
    }

    free(buffer);
}
END_TEST

int main(void) {
    Suite* s = suite_create("Pool Tests");
    TCase* tc = tcase_create("Pool Tests");

    tcase_add_checked_fixture(tc, pool_start, pool_reset);
    tcase_add_test(tc, pool_allocate_and_deallocate);
    tcase_add_test(tc, pool_get_value);
    tcase_add_test(tc, pool_release_value);
    tcase_add_test(tc, pool_get_released_value_reuses_memory);
    tcase_add_test(tc, pool_stress_test);


    suite_add_tcase(s, tc);

    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}