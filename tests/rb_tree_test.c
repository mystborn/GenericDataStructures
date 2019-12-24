#include "../include/generic_rbtree.h"
#include "../include/generic_iterators/rbtree_iterator.h"
#include <string.h>
#include <stdio.h>

#include <check.h>

static inline int int_cmp(int left, int right) {
    return left < right ? -1 : (left == right ? 0 : 1);
}

RBTREE_DEFINE_H(IITree, iitree, int, int)

RBTREE_DEFINE_C(IITree, iitree, int, int, int_cmp)

static IITree* tree;
static int test_num = 0;

void tree_start(void) {
    tree = iitree_create();
}

void tree_reset(void) {
    iitree_free(tree, true);
}

START_TEST(tree_allocates_and_deallocates_no_elements) {
    IITree temp;
    iitree_init(&temp);
    iitree_free_resources(&temp);

    IITree* tree_ptr = iitree_create();
    iitree_free(tree_ptr, true);
}
END_TEST

START_TEST(tree_allocates_and_deallocates_some_elements) {
    IITree temp;
    iitree_init(&temp);

    iitree_add(&temp, 0, 0);
    iitree_add(&temp, 1, 1);

    ck_assert(iitree_count(&temp) == 2);

    iitree_free_resources(&temp);

    ck_assert(iitree_count(&temp) == 0);

    IITree* tree_ptr = iitree_create();

    iitree_add(tree_ptr, 0, 0);
    iitree_add(tree_ptr, 1, 1);

    ck_assert(iitree_count(tree_ptr) == 2);

    iitree_free(tree_ptr, true);
}
END_TEST

START_TEST(tree_adds_items_in_order_simple) {
    for(int i = 0; i < 6; i++) {
        iitree_add(tree, i, i);
    }

    ck_assert(iitree_count(tree) == 6);

    int value = 0;
    int index = 0;
    IITreeNode** stack = malloc(sizeof(IITreeNode*) * 6);
    IITreeNode* node = iitree_root(tree);
    while(node != NULL) {
        while(node->left != NULL) {
            stack[index++] = node;
            node = node->left;
        }
        ck_assert(value == node->value);
        value++;
        while(node->right == NULL && index > 0) {
            node = stack[--index];
            ck_assert(value == node->value);
            value++;
        }
        node = node->right;
    }
    free(stack);
}
END_TEST

START_TEST(tree_adds_items_in_order_complex) {
    iitree_add(tree, 0, 0);
    iitree_add(tree, 5, 5);
    iitree_add(tree, 2, 2);
    iitree_add(tree, 1, 1);
    iitree_add(tree, 4, 4);
    iitree_add(tree, 3, 3);

    ck_assert(iitree_count(tree) == 6);

    int value = 0;
    int index = 0;
    IITreeNode** stack = malloc(sizeof(IITreeNode*) * 6);
    IITreeNode* node = iitree_root(tree);
    while(node != NULL) {
        while(node->left != NULL) {
            stack[index++] = node;
            node = node->left;
        }
        ck_assert(value == node->value);
        value++;
        while(node->right == NULL && index > 0) {
            node = stack[--index];
            ck_assert(value == node->value);
            value++;
        }
        node = node->right;

    }
    free(stack);
}
END_TEST

START_TEST(tree_remove_root) {
    ck_assert(iitree_root(tree) == NULL);

    iitree_add(tree, 1, 1);

    ck_assert(iitree_root(tree) != NULL);
    ck_assert(iitree_count(tree) == 1);

    ck_assert(iitree_remove(tree, 1, NULL));

    ck_assert(iitree_root(tree) == NULL);
    ck_assert(iitree_count(tree) == 0);
}
END_TEST

START_TEST(tree_remove_preserves_order) {
    int values[] = { 0, 1, 2, 4, 5 };

    for(int i = 0; i < 6; i++) {
        iitree_add(tree, i, i);
    }

    iitree_remove(tree, 3, NULL);

    int value = 0;
    int index = 0;
    IITreeNode** stack = malloc(sizeof(IITreeNode*) * iitree_count(tree));
    IITreeNode* node = iitree_root(tree);
    while(node != NULL) {
        while(node->left != NULL) {
            stack[index++] = node;
            node = node->left;
        }
        ck_assert(values[value] == node->value);
        value++;
        while(node->right == NULL && index > 0) {
            node = stack[--index];
            ck_assert(values[value] == node->value);
            value++;
        }
        node = node->right;
    }

    free(stack);
}
END_TEST

START_TEST(tree_remove_min_removes_min) {
    for(int i = 0; i < 6; i++)
        iitree_add(tree, i, i);

    for(int i = 0; i < 6; i++) {
        int value;
        iitree_remove_min(tree, &value);
        ck_assert(value == i);
    }
}
END_TEST

START_TEST(tree_remove_max_removes_max) {
    for(int i = 0; i < 6; i++)
        iitree_add(tree, i, i);

    for(int i = 5; i >= 0; i--) {
        int value;
        iitree_remove_max(tree, &value);
        ck_assert(value == i);
    }
}
END_TEST

START_TEST(tree_get_invalid_key_returns_false) {
    for(int i = 0; i < 6; i++)
        iitree_add(tree, i, i);

    int value;
    ck_assert(!iitree_get(tree, 10, &value));
}
END_TEST

START_TEST(tree_get_valid_key_returns_true) {
    for(int i = 0; i < 6; i++)
        iitree_add(tree, i, i);

    for(int i = 0; i < 6; i++) {
        int value;
        ck_assert(iitree_get(tree, i, &value));
        ck_assert(value == i);
    }
}
END_TEST

START_TEST(tree_get_min_returns_min) {
    for(int i = 0; i < 6; i++)
        iitree_add(tree, i, i);

    int value;
    iitree_get_min(tree, &value);

    ck_assert(value == 0);
}
END_TEST

START_TEST(tree_get_max_returns_max) {
    for(int i = 0; i < 6; i++)
        iitree_add(tree, i, i);

    int value;
    iitree_get_max(tree, &value);

    ck_assert(value == 5);
}
END_TEST

START_TEST(tree_iter_all) {
    for(int i = 0; i <= 6; i++)
        iitree_add(tree, i, 6-i);

    int key, value;
    int count = 0;
    rbtree_iter_start(IITree, tree, key, value) {
        ck_assert(count == key);
        ck_assert(value == 6-key);
        count++;
    }
    rbtree_iter_end
    ck_assert(count == 7);
}
END_TEST

START_TEST(tree_iter_some) {
    for(int i = 0; i < 6; i++)
        iitree_add(tree, i, i);

    int key, value;
    int count = 0;
    rbtree_iter_start(IITree, tree, key, value) {
        ck_assert(count == key);
        count++;
        if(count == 3)
            break;
    }
    rbtree_iter_end
    ck_assert(count == 3);
}
END_TEST

START_TEST(tree_iter_keys) {
    for(int i = 0; i <= 6; i++)
        iitree_add(tree, i, 6-i);

    int key;
    int count = 0;
    rbtree_iter_keys_start(IITree, tree, key) {
        ck_assert(count == key);
        count++;
    }
    rbtree_iter_end
    ck_assert(count == 7);
}
END_TEST

START_TEST(tree_iter_values) {
    for(int i = 0; i <= 6; i++)
        iitree_add(tree, i, 6-i);

    int value;
    int count = 0;
    rbtree_iter_values_start(IITree, tree, value) {
        ck_assert(value == 6-count);
        count++;
    }
    rbtree_iter_end
    ck_assert(count == 7);
}
END_TEST

int main(void) {
    int number_failed;

    Suite* s = suite_create("RB Tree");
    TCase* tc = tcase_create("RB Tree");

    tcase_add_checked_fixture(tc, tree_start, tree_reset);
    tcase_add_test(tc, tree_allocates_and_deallocates_no_elements);
    tcase_add_test(tc, tree_allocates_and_deallocates_some_elements);
    tcase_add_test(tc, tree_adds_items_in_order_simple);
    tcase_add_test(tc, tree_adds_items_in_order_complex);
    tcase_add_test(tc, tree_remove_root);
    tcase_add_test(tc, tree_remove_preserves_order);
    tcase_add_test(tc, tree_remove_min_removes_min);
    tcase_add_test(tc, tree_remove_max_removes_max);
    tcase_add_test(tc, tree_get_invalid_key_returns_false);
    tcase_add_test(tc, tree_get_valid_key_returns_true);
    tcase_add_test(tc, tree_get_min_returns_min);
    tcase_add_test(tc, tree_get_max_returns_max);
    tcase_add_test(tc, tree_iter_all);
    tcase_add_test(tc, tree_iter_some);
    tcase_add_test(tc, tree_iter_keys);
    tcase_add_test(tc, tree_iter_values);

    suite_add_tcase(s, tc);
    
    SRunner* sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}