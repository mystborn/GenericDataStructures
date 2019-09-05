#include <check.h>

#include "../include/generic_list.h"
#include "../include/generic_iterators/list_iterator.h"

LIST_DEFINE_H(IntList, il, int)

LIST_DEFINE_C(IntList, il, int)

IntList* list;

void list_start(void) {
    list = il_create();
}

void list_reset(void) {
    il_free(list);
}

START_TEST(list_allocate_and_deallocate) {
    IntList temp1;
    ck_assert(il_init(&temp1));
    il_free_resources(&temp1);
    ck_assert(il_init_capacity(&temp1, 8));
    il_free_resources(&temp1);
    IntList* temp2 = il_create();
    ck_assert(temp2);
    il_free(temp2);
}
END_TEST

START_TEST(list_add_increments_count) {
    for(int i = 0; i < 10; i++) {
        il_add(list, i);
        ck_assert(il_count(list) == i + 1);
    }
}
END_TEST

START_TEST(list_get_returns_value) {
    for(int i = 0; i < 10; i++)
        il_add(list, i);

    for(int i = 0; i < 10; i++)
        ck_assert(il_get(list, i) == i);
}
END_TEST

START_TEST(list_set_existing_index_overwrites) {
    for(int i = 0; i < 4; i++)
        il_add(list, i);

    ck_assert(il_count(list) == 4);
    il_set(list, 2, 8);
    ck_assert(il_count(list) == 4);

    ck_assert(il_get(list, 2) == 8);
}
END_TEST

START_TEST(list_set_at_list_count_adds) {
    for(int i = 0; i < 4; i++)
        il_add(list, i);

    il_set(list, 4, 4);
    ck_assert(il_count(list) == 5);
    ck_assert(il_get(list, 4) == 4);
}
END_TEST

START_TEST(list_remove_middle_index_shifts_elements) {
    for(int i = 0; i < 6; i++)
        il_add(list, i);

    il_remove(list, 0);
    ck_assert(il_count(list) == 5);

    for(int i = 1; i < 6; i++)
        ck_assert(il_get(list, i - 1) == i);

    il_remove(list, 3);
    ck_assert(il_count(list) == 4);

    int values[] = { 1, 2, 3, 5 };

    for(int i = 0; i < 4; i++)
        ck_assert(il_get(list, i) == values[i]);
}
END_TEST

START_TEST(list_remove_end_keeps_order) {
    for(int i = 0; i < 6; i++)
        il_add(list, i);

    il_remove(list, 5);
    for(int i = 0; i < 5; i++)
        ck_assert(il_get(list, i) == i);
}
END_TEST

START_TEST(list_peek_gets_last_value_without_removing) {
    il_add(list, 4);
    ck_assert(il_peek(list) == 4);
    ck_assert(il_count(list) == 1);
    il_add(list, 7);
    ck_assert(il_peek(list) == 7);
    ck_assert(il_count(list) == 2);
}
END_TEST

START_TEST(list_pop_gets_last_value_and_removes) {
    il_add(list, 4);
    il_add(list, 7);
    ck_assert(il_pop(list) == 7);
    ck_assert(il_count(list) == 1);
    ck_assert(il_pop(list) == 4);
    ck_assert(il_count(list) == 0);
}
END_TEST

START_TEST(list_insert_middle_shifts_values) {
    for(int i = 1; i < 6; i++)
        il_add(list, i);

    il_insert(list, 0, 0);
    for(int i = 0; i < 6; i++) 
        ck_assert(il_get(list, i) == i);

    il_insert(list, 2, 22);

    int values[] = { 0, 1, 22, 2, 3, 4, 5 };
    for(int i = 0; i < 7; i++) 
        ck_assert(il_get(list, i) == values[i]);
}
END_TEST

START_TEST(list_insert_end_adds_value) {
    for(int i = 0; i < 5; i++)
        il_add(list, i);

    il_insert(list, 5, 5);

    for(int i = 0; i < 6; i++)
        ck_assert(il_get(list, i) == i);
}
END_TEST

START_TEST(list_iter_all) {
    for(int i = 0; i < 5; i++)
        il_add(list, i);

    int value;
    int current = 0;
    list_iter_start(list, value) {
        ck_assert(current == value);
        current++;
    }
    list_iter_end
    ck_assert(current == 5);
}
END_TEST

START_TEST(list_iter_some) {
    for(int i = 0; i < 5; i++)
        il_add(list, i);

    int value;
    int current = 0;
    list_iter_start(list, value) {
        ck_assert(current == value);
        current++;
        if(current == 3)
            break;
    }
    list_iter_end
    ck_assert(current == 3);
}
END_TEST

int main(void) {
    Suite* s = suite_create("List Tests");
    TCase* tc = tcase_create("List Tests");

    tcase_add_checked_fixture(tc, list_start, list_reset);
    tcase_add_test(tc, list_allocate_and_deallocate);
    tcase_add_test(tc, list_add_increments_count);
    tcase_add_test(tc, list_get_returns_value);
    tcase_add_test(tc, list_set_existing_index_overwrites);
    tcase_add_test(tc, list_set_at_list_count_adds);
    tcase_add_test(tc, list_remove_middle_index_shifts_elements);
    tcase_add_test(tc, list_remove_end_keeps_order);
    tcase_add_test(tc, list_peek_gets_last_value_without_removing);
    tcase_add_test(tc, list_pop_gets_last_value_and_removes);
    tcase_add_test(tc, list_insert_middle_shifts_values);
    tcase_add_test(tc, list_insert_end_adds_value);
    tcase_add_test(tc, list_iter_all);
    tcase_add_test(tc, list_iter_some);

    suite_add_tcase(s, tc);

    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}