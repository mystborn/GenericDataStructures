#include <check.h>
#include <stdio.h>

#include "../include/generic_deque.h"
#include "../include/generic_iterators/deque_iterator.h"

DEQUE_DEFINE_H(IntDeque, id, int)
DEQUE_DEFINE_C(IntDeque, id, int)

static IntDeque* deque;

void deque_start(void) {
    deque = id_create();
}

void deque_reset(void) {
    id_free(deque);
}

START_TEST(deque_allocate_and_deallocate) {
    IntDeque temp, *ptr;

    ck_assert(id_init(&temp));
    id_free_resources(&temp);

    ck_assert(id_init_capacity(&temp, 8));
    id_free_resources(&temp);

    ck_assert(ptr = id_create());
    id_free(ptr);

    ck_assert(ptr = id_create_capacity(8));
    id_free(ptr);
}
END_TEST

START_TEST(deque_push_front_increments_count) {
    ck_assert(id_count(deque) == 0);
    for(int i = 1; i < 10; i++) {
        ck_assert(id_push_front(deque, i));
        ck_assert(id_count(deque) == i);
    }
}
END_TEST

START_TEST(deque_push_back_increments_count) {
    ck_assert(id_count(deque) == 0);
    for(int i = 1; i < 10; i++) {
        ck_assert(id_push_back(deque, i));
        ck_assert(id_count(deque) == i);
    }
}
END_TEST

START_TEST(deque_pop_front_gets_value) {
    ck_assert(id_push_front(deque, 2));
    ck_assert(id_push_back(deque, 4));
    ck_assert(id_pop_front(deque) == 2);
    ck_assert(id_pop_front(deque) == 4);
}
END_TEST

START_TEST(deque_pop_back_gets_value) {
    ck_assert(id_push_back(deque, 4));
    ck_assert(id_push_front(deque, 2));
    ck_assert(id_pop_back(deque) == 4);
    ck_assert(id_pop_back(deque) == 2);
}
END_TEST

START_TEST(deque_resizes_properly) {
    unsigned int capacity = id_capacity(deque);
    ck_assert(id_push_front(deque, 0));

    for (int i = 1; i < capacity; i++)
        ck_assert(id_push_back(deque, i));

    ck_assert(id_capacity(deque) == capacity);
    ck_assert(id_push_back(deque, capacity));
    ck_assert(id_capacity(deque) != capacity);

    while(id_count(deque) > 0)
        ck_assert(id_pop_back(deque) == capacity--);
}
END_TEST

#define ORDER_COUNT 100

START_TEST(deque_orders_properly) {
    int values[ORDER_COUNT];
    bool direction[ORDER_COUNT];

    for(int i = 0; i < ORDER_COUNT; i++) {
        values[i] = rand();
        if(rand() % 2) {
            direction[i] = true;
            id_push_front(deque, values[i]);
        } else {
            direction[i] = false;
            id_push_back(deque, values[i]);
        }
    }

    for(int i = ORDER_COUNT - 1; i >= 0; i--) {
        if(direction[i]) {
            ck_assert(values[i] == id_pop_front(deque));
        } else {
            ck_assert(values[i] == id_pop_back(deque));
        }
    }
}
END_TEST

START_TEST(deque_peek_front_gets_value_without_removal) {
    ck_assert(id_push_back(deque, 4));
    ck_assert(id_push_front(deque, 2));
    ck_assert(id_peek_front(deque) == 2);
    ck_assert(id_pop_front(deque) == 2);
    ck_assert(id_peek_front(deque) == 4);
}
END_TEST

START_TEST(deque_peek_back_gets_value_without_removal) {
    ck_assert(id_push_front(deque, 2));
    ck_assert(id_push_back(deque, 4));
    ck_assert(id_peek_back(deque) == 4);
    ck_assert(id_pop_back(deque) == 4);
    ck_assert(id_peek_back(deque) == 2);
}
END_TEST

START_TEST(deque_clear_can_keep_capacity) {
    unsigned int capacity = id_capacity(deque);
    for(int i = 0; i <= capacity; i++)
        id_push_back(deque, i);
    ck_assert(id_capacity(deque) != capacity);
    capacity = id_capacity(deque);
    id_clear(deque, false);
    ck_assert(id_capacity(deque) == capacity);
}
END_TEST

START_TEST(deque_clear_can_reset_capacity) {
    unsigned int capacity = id_capacity(deque);
    for(int i = 0; i <= capacity; i++)
        id_push_back(deque, i);
    ck_assert(id_capacity(deque) != capacity);
    capacity = id_capacity(deque);
    id_clear(deque, true);
    ck_assert(id_capacity(deque) != capacity);
}
END_TEST

START_TEST(deque_iterates_in_order) {
    int values[ORDER_COUNT];

    for(int i = 0; i < ORDER_COUNT; i++) {
        int offset = i / 2;
        int value = rand();
        if(i % 2) {
            values[(ORDER_COUNT / 2 - 1) - offset] = value;
            id_push_front(deque, value);
        } else {
            values[ORDER_COUNT / 2 + offset] = value;
            id_push_back(deque, value);
        }
    }

    int pos = 0, out_value;
    deque_iter_start(deque, out_value) {
        ck_assert(values[pos++] == out_value);
    }
    deque_iter_end

}
END_TEST

int main(void) {
    Suite* s = suite_create("Queue Tests");
    TCase* tc = tcase_create("Queue Tests");

    tcase_add_checked_fixture(tc, deque_start, deque_reset);
    tcase_add_test(tc, deque_allocate_and_deallocate);
    tcase_add_test(tc, deque_push_front_increments_count);
    tcase_add_test(tc, deque_push_back_increments_count);
    tcase_add_test(tc, deque_pop_front_gets_value);
    tcase_add_test(tc, deque_pop_back_gets_value);
    tcase_add_test(tc, deque_resizes_properly);
    tcase_add_test(tc, deque_orders_properly);
    tcase_add_test(tc, deque_peek_front_gets_value_without_removal);
    tcase_add_test(tc, deque_peek_back_gets_value_without_removal);
    tcase_add_test(tc, deque_clear_can_keep_capacity);
    tcase_add_test(tc, deque_clear_can_reset_capacity);
    tcase_add_test(tc, deque_iterates_in_order);
    

    suite_add_tcase(s, tc);

    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}