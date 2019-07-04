#include <check.h>

#include "../include/generic_queue.h"

QUEUE_DEFINE_H(IntQueue, iq, int)

QUEUE_DEFINE_C(IntQueue, iq, int)


static IntQueue* queue;

void queue_start(void) {
    queue = malloc(sizeof(IntQueue));
    iq_init(queue);
}

void queue_reset(void) {
    iq_free(queue);
    free(queue);
}

START_TEST(queue_allocate_and_deallocate) {
    IntQueue temp;
    ck_assert(iq_init(&temp) != NULL);
    iq_free(&temp);

    ck_assert(iq_init_capacity(&temp, 8));
    iq_free(&temp);
}
END_TEST

START_TEST(queue_enqueue_increments_count) {
    ck_assert(iq_count(queue) == 0);
    for(int i = 0; i < 10; i++) {
        iq_enqueue(queue, i);
        ck_assert(iq_count(queue) == i + 1);
    }
}
END_TEST

START_TEST(queue_dequeue_gets_value) {
    for(int i = 0; i < 4; i++) {
        iq_enqueue(queue, i);
    }
    for(int i = 0; i < 4; i++) {
        ck_assert(iq_dequeue(queue) == i);
        ck_assert(iq_count(queue) == 3 - i);
    }
} 
END_TEST

START_TEST(queue_enqueue_then_dequeue_works_properly) {
    for(int i = 0; i < 4; i++)
        iq_enqueue(queue, i);

    ck_assert(iq_dequeue(queue) == 0);
    iq_enqueue(queue, 4);
    ck_assert(queue->capacity == 4);
    iq_enqueue(queue, 5);
    ck_assert(queue->capacity == 8);
    ck_assert(iq_dequeue(queue) == 1);
}
END_TEST

START_TEST(queue_peek_gets_value_without_removing) {
    for(int i = 0; i < 4; i++)
        iq_enqueue(queue, i);

    ck_assert(iq_peek(queue) == 0);
    ck_assert(iq_count(queue) == 4);
    iq_dequeue(queue);
    ck_assert(iq_peek(queue) == 1);
}
END_TEST

START_TEST(queue_clear_clears) {
    for(int i = 0; i < 4; i++)
        iq_enqueue(queue, i);

    ck_assert(queue->capacity == 4);
    ck_assert(queue->count == 4);
    iq_clear(queue);
    ck_assert(queue->capacity == 4);
    ck_assert(queue->count == 0);

    for(int i = 0; i < 4; i++)
        iq_enqueue(queue, i);

    ck_assert(queue->capacity == 4);
    ck_assert(queue->count == 4);
}
END_TEST

int main(void) {
    Suite* s = suite_create("Queue Tests");
    TCase* tc = tcase_create("Queue Tests");

    tcase_add_checked_fixture(tc, queue_start, queue_reset);
    tcase_add_test(tc, queue_allocate_and_deallocate);
    tcase_add_test(tc, queue_enqueue_increments_count);
    tcase_add_test(tc, queue_dequeue_gets_value);
    tcase_add_test(tc, queue_enqueue_then_dequeue_works_properly);
    tcase_add_test(tc, queue_peek_gets_value_without_removing);
    tcase_add_test(tc, queue_clear_clears);

    suite_add_tcase(s, tc);

    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}