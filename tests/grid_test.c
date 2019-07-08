#include <check.h>

#include "../include/generic_grid.h"

GRID_DEFINE_H(IntGrid, ig, int)

GRID_DEFINE_C(IntGrid, ig, int)

static IntGrid* grid;

void grid_start(void) {
    grid = ig_create(5, 5);
}

void grid_reset(void) {
    ig_free(grid);
}

START_TEST(grid_allocate_and_deallocate) {
    IntGrid temp1;
    ig_init(&temp1, 2, 2);
    ck_assert(temp1.grid);
    ig_free_resources(&temp1);
    IntGrid* temp2 = ig_create(2, 2);
    ck_assert(temp2->grid);
    ig_free(temp2);
}
END_TEST

START_TEST(grid_check_width) {
    ck_assert(ig_width(grid) == 5);
}
END_TEST

START_TEST(grid_check_height) {
    ck_assert(ig_height(grid) == 5);
}
END_TEST

START_TEST(grid_get_and_set) {
    for(int i = 0; i < 5; i++) {
        ig_set(grid, i, i, i);
    }

    for(int i = 0; i < 5; i++) {
        ck_assert(ig_get(grid, i, i) == i);
    }
}
END_TEST

START_TEST(grid_clears_sets_all) {
    ig_clear(grid, 12);
    for(int h = 0; h < ig_height(grid); h++) {
        for(int w = 0; w < ig_width(grid); w++) {
            ck_assert(ig_get(grid, w, h) == 12);
        }
    }
}
END_TEST

int main(void) {
    Suite* s = suite_create("Grid Tests");
    TCase* tc = tcase_create("Grid Tests");

    tcase_add_checked_fixture(tc, grid_start, grid_reset);
    tcase_add_test(tc, grid_check_width);
    tcase_add_test(tc, grid_check_height);
    tcase_add_test(tc, grid_get_and_set);
    tcase_add_test(tc, grid_clears_sets_all);

    suite_add_tcase(s, tc);

    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}