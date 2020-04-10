#include <check.h>

#define GENERIC_EVENT_IMPLEMENTATION

#include "../include/generic_event.h"

EVENT_DEFINE_0_H(Action, action)
EVENT_DEFINE_C(Action, action)

EVENT_DEFINE_2_H(Callback, callback, int, int)
EVENT_DEFINE_C(Callback, callback)

static Action* action;
static Callback* callback;
static GdsEvent* gds_event;

void action_set(void* ctx) {
    *(int*)ctx = 5;
}

void callback_set(void* ctx, int left, int right) {
    *(int*)ctx = left - right;
}

void gds_event_set(void* ctx, int value) {
    *(int*)ctx = value;
}

void event_start(void) {
    action = action_create();
    callback = callback_create();
    gds_event = gds_event_create();
}

void event_reset(void) {
    action_free(action);
    callback_free(callback);
    gds_event_free(gds_event);
}

START_TEST(action_allocate_and_deallocate) {
    Action value;
    action_init(&value);
    action_free_resources(&value);
    Action* ptr = action_create();
    ck_assert(ptr);
    action_free(ptr);
}
END_TEST

START_TEST(callback_allocate_and_deallocate) {
    Callback value;
    callback_init(&value);
    callback_free_resources(&value);
    Callback* ptr = callback_create();
    ck_assert(ptr);
    callback_free(ptr);
}
END_TEST

START_TEST(gds_event_allocate_and_deallocate) {
    GdsEvent value;
    gds_event_init(&value);
    gds_event_free_resources(&value);
    GdsEvent* ptr = gds_event_create();
    ck_assert(ptr);
    gds_event_free(ptr);
}
END_TEST

START_TEST(action_subscribe_true) {
    ck_assert(action_subscribe(action, NULL, action_set));
}
END_TEST

START_TEST(callback_subscribe_true) {
    ck_assert(callback_subscribe(callback, NULL, callback_set));
}
END_TEST

START_TEST(gds_event_subscribe_true) {
    ck_assert(gds_event_subscribe(gds_event, NULL, gds_event_set));
}
END_TEST

START_TEST(action_unsubscribe_true) {
    ck_assert(action_subscribe(action, NULL, action_set));
    ck_assert(action_unsubscribe(action, NULL, action_set));
}
END_TEST

START_TEST(callback_unsubscribe_true) {
    ck_assert(callback_subscribe(callback, NULL, callback_set));
    ck_assert(callback_unsubscribe(callback, NULL, callback_set));
}
END_TEST

START_TEST(gds_event_unsubscribe_true) {
    ck_assert(gds_event_subscribe(gds_event, NULL, gds_event_set));
    ck_assert(gds_event_unsubscribe(gds_event, NULL, gds_event_set));
}
END_TEST

START_TEST(action_unsubscribe_different_context) {
    int ctx;
    ck_assert(action_subscribe(action, &ctx, action_set));
    ck_assert(!action_unsubscribe(action, NULL, action_set));
}
END_TEST

START_TEST(callback_unsubscribe_different_context) {
    int ctx;
    ck_assert(callback_subscribe(callback, &ctx, callback_set));
    ck_assert(!callback_unsubscribe(callback, NULL, callback_set));
}
END_TEST

START_TEST(gds_event_unsubscribe_different_context) {
    int ctx;
    ck_assert(gds_event_subscribe(gds_event, &ctx, gds_event_set));
    ck_assert(!gds_event_unsubscribe(gds_event, NULL, gds_event_set));
}
END_TEST

START_TEST(action_unsubscribe_different_function) {
    int ctx;
    ck_assert(action_subscribe(action, &ctx, action_set));
    ck_assert(!action_unsubscribe(action, &ctx, NULL));
}
END_TEST

START_TEST(callback_unsubscribe_different_function) {
    int ctx;
    ck_assert(callback_subscribe(callback, &ctx, callback_set));
    ck_assert(!callback_unsubscribe(callback, &ctx, NULL));
}
END_TEST

START_TEST(gds_event_unsubscribe_different_function) {
    int ctx;
    ck_assert(gds_event_subscribe(gds_event, &ctx, gds_event_set));
    ck_assert(!gds_event_unsubscribe(gds_event, &ctx, NULL));
}
END_TEST

START_TEST(action_trigger_single_sub) {
    int ctx;
    action_subscribe(action, &ctx, action_set);
    action_trigger(action);
    ck_assert(ctx == 5);
}
END_TEST

START_TEST(callback_trigger_single_sub) {
    int ctx;
    callback_subscribe(callback, &ctx, callback_set);
    callback_trigger(callback, 20, 10);
    ck_assert(ctx == 10);
}
END_TEST

START_TEST(gds_event_trigger_single_sub) {
    int ctx;
    gds_event_subscribe(gds_event, &ctx, gds_event_set);
    GDS_EVENT_TRIGGER(gds_event, GDS_EVENT_SIGNATURE(int), 13);
    ck_assert(ctx = 13);
}
END_TEST

START_TEST(action_trigger_multiple_subs) {
    int ctx1, ctx2;
    action_subscribe(action, &ctx1, action_set);
    action_subscribe(action, &ctx2, action_set);
    action_trigger(action);
    ck_assert(ctx1 == 5);
    ck_assert(ctx2 == 5);
}
END_TEST

START_TEST(callback_trigger_multiple_subs) {
    int ctx1, ctx2;
    callback_subscribe(callback, &ctx1, callback_set);
    callback_subscribe(callback, &ctx2, callback_set);
    callback_trigger(callback, 20, 10);
    ck_assert(ctx1 == 10);
    ck_assert(ctx2 == 10);
}
END_TEST

START_TEST(gds_event_trigger_multiple_subs) {
    int ctx1, ctx2;
    gds_event_subscribe(gds_event, &ctx1, gds_event_set);
    gds_event_subscribe(gds_event, &ctx2, gds_event_set);
    GDS_EVENT_TRIGGER(gds_event, GDS_EVENT_SIGNATURE(int), 15);
    ck_assert(ctx1 = 15);
    ck_assert(ctx2 = 15);
}
END_TEST

static int global_value = 0;
static void incr_global_value(void* ctx) {
    global_value++;
}

START_TEST(gds_event_trigger_no_args) {
    int pre = global_value;
    ck_assert(gds_event_subscribe(gds_event, NULL, incr_global_value));
    GDS_EVENT_TRIGGER(gds_event, GDS_EVENT_DEFAULT);
    ck_assert(global_value == pre + 1);
}
END_TEST

int main(void) {
    Suite* s = suite_create("Event Tests");
    TCase* tc = tcase_create("Event Tests");

    tcase_add_checked_fixture(tc, event_start, event_reset);
    tcase_add_test(tc, action_allocate_and_deallocate);
    tcase_add_test(tc, callback_allocate_and_deallocate);
    tcase_add_test(tc, gds_event_allocate_and_deallocate);
    tcase_add_test(tc, action_subscribe_true);
    tcase_add_test(tc, callback_subscribe_true);
    tcase_add_test(tc, gds_event_subscribe_true);
    tcase_add_test(tc, action_unsubscribe_true);
    tcase_add_test(tc, callback_unsubscribe_true);
    tcase_add_test(tc, gds_event_unsubscribe_true);
    tcase_add_test(tc, action_unsubscribe_different_context);
    tcase_add_test(tc, callback_unsubscribe_different_context);
    tcase_add_test(tc, gds_event_unsubscribe_different_context);
    tcase_add_test(tc, action_unsubscribe_different_function);
    tcase_add_test(tc, callback_unsubscribe_different_function);
    tcase_add_test(tc, gds_event_unsubscribe_different_function);
    tcase_add_test(tc, action_trigger_single_sub);
    tcase_add_test(tc, callback_trigger_single_sub);
    tcase_add_test(tc, gds_event_trigger_single_sub);
    tcase_add_test(tc, action_trigger_multiple_subs);
    tcase_add_test(tc, callback_trigger_multiple_subs);
    tcase_add_test(tc, gds_event_trigger_multiple_subs);
    tcase_add_test(tc, gds_event_trigger_no_args);

    suite_add_tcase(s, tc);

    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}