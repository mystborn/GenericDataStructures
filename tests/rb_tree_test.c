#include "../include/generic_rbtree.h"
#include <string.h>
#include <stdio.h>

#include <check.h>

static inline int int_cmp(int left, int right) {
    return left < right ? -1 : (left == right ? 0 : 1);
}

RBTREE_DEFINE_H(IITree, iitree, int, int)

RBTREE_DEFINE_C(IITree, iitree, int, int, int_cmp, INT_MIN)

START_TEST(tree_allocates_and_deallocates_no_elements) {
    IITree tree;
    iitree_init(&tree);
    iitree_free_resources(&tree);

    IITree* tree_ptr = iitree_create();
    iitree_free(tree_ptr);
}
END_TEST

START_TEST(tree_allocates_and_deallocates_some_elements) {
    IITree tree;
    iitree_init(&tree);

    iitree_add(&tree, 0, 0);
    iitree_add(&tree, 1, 1);

    ck_assert(iitree_count(&tree) == 2);

    iitree_free_resources(&tree);

    ck_assert(iitree_count(&tree) == 0);

    IITree* tree_ptr = iitree_create();

    iitree_add(tree_ptr, 0, 0);
    iitree_add(tree_ptr, 1, 1);

    ck_assert(iitree_count(tree_ptr) == 2);

    iitree_free(tree_ptr);
}
END_TEST

START_TEST(tree_adds_items_in_order_simple) {
    IITree tree;
    iitree_init(&tree);

    for(int i = 0; i < 6; i++) {
        iitree_add(&tree, i, i);
    }

    ck_assert(iitree_count(&tree) == 6);

    int value = 0;
    int index = 0;
    IITreeNode** stack = malloc(sizeof(IITreeNode*) * 6);
    IITreeNode* node = iitree_root(&tree);
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

    iitree_free_resources(&tree);
}
END_TEST

START_TEST(tree_adds_items_in_order_complex) {
    IITree tree;
    iitree_init(&tree);

    iitree_add(&tree, 0, 0);
    iitree_add(&tree, 5, 5);
    iitree_add(&tree, 2, 2);
    iitree_add(&tree, 1, 1);
    iitree_add(&tree, 4, 4);
    iitree_add(&tree, 3, 3);

    ck_assert(iitree_count(&tree) == 6);

    int value = 0;
    int index = 0;
    IITreeNode** stack = malloc(sizeof(IITreeNode*) * 6);
    IITreeNode* node = iitree_root(&tree);
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

    iitree_free_resources(&tree);
}
END_TEST

START_TEST(tree_remove_root) {
    IITree tree;
    iitree_init(&tree);

    ck_assert(iitree_root(&tree) == NULL);

    iitree_add(&tree, 1, 1);

    ck_assert(iitree_root(&tree) != NULL);
    ck_assert(iitree_count(&tree) == 1);

    iitree_remove(&tree, 1);

    ck_assert(iitree_root(&tree) == NULL);
    ck_assert(iitree_count(&tree) == 0);

    iitree_free_resources(&tree);
}
END_TEST

START_TEST(tree_remove_preserves_order) {
    IITree tree;
    iitree_init(&tree);

    int values[] = { 0, 1, 2, 4, 5 };

    for(int i = 0; i < 6; i++)
        iitree_add(&tree, i, i);

    iitree_remove(&tree, 3);

    int value = 0;
    int index = 0;
    IITreeNode** stack = malloc(sizeof(IITreeNode*));
    IITreeNode* node = iitree_root(&tree);
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

    iitree_free_resources(&tree);
}
END_TEST

START_TEST(tree_remove_min_removes_min) {
    IITree tree;
    iitree_init(&tree);

    for(int i = 0; i < 6; i++)
        iitree_add(&tree, i, i);

    for(int i = 0; i < 6; i++) {
        int value = iitree_remove_min(&tree);
        ck_assert(value == i);
    }

    iitree_free_resources(&tree);
}
END_TEST

START_TEST(tree_remove_max_removes_max) {
    IITree tree;
    iitree_init(&tree);

    for(int i = 0; i < 6; i++)
        iitree_add(&tree, i, i);

    for(int i = 5; i >= 0; i--) {
        int value = iitree_remove_max(&tree);
        ck_assert(value == i);
    }

    iitree_free_resources(&tree);
}
END_TEST

START_TEST(tree_get_invalid_key_returns_default) {
    IITree tree;
    iitree_init(&tree);

    for(int i = 0; i < 6; i++)
        iitree_add(&tree, i, i);

    ck_assert(iitree_get(&tree, 10) == INT_MIN);

    iitree_free_resources(&tree);
}
END_TEST

START_TEST(tree_get_valid_key_returns_value) {
    IITree tree;
    iitree_init(&tree);

    for(int i = 0; i < 6; i++)
        iitree_add(&tree, i, i);

    for(int i = 0; i < 6; i++)
        ck_assert(iitree_get(&tree, i) == i);

    iitree_free_resources(&tree);
}
END_TEST

START_TEST(tree_get_min_returns_min) {
    IITree tree;
    iitree_init(&tree);

    for(int i = 0; i < 6; i++)
        iitree_add(&tree, i, i);

    ck_assert(iitree_get_min(&tree) == 0);

    iitree_free_resources(&tree);
}
END_TEST

START_TEST(tree_get_max_returns_max) {
    IITree tree;
    iitree_init(&tree);

    for(int i = 0; i < 6; i++)
        iitree_add(&tree, i, i);

    ck_assert(iitree_get_max(&tree) == 5);

    iitree_free_resources(&tree);
}
END_TEST

int main(void) {
    int number_failed;

    Suite* s = suite_create("RB Tree");
    TCase* tc = tcase_create("RB Tree");

    tcase_add_test(tc, tree_allocates_and_deallocates_no_elements);
    tcase_add_test(tc, tree_allocates_and_deallocates_some_elements);
    tcase_add_test(tc, tree_adds_items_in_order_simple);
    tcase_add_test(tc, tree_adds_items_in_order_complex);
    tcase_add_test(tc, tree_remove_root);
    tcase_add_test(tc, tree_remove_preserves_order);
    tcase_add_test(tc, tree_remove_min_removes_min);
    tcase_add_test(tc, tree_remove_max_removes_max);
    tcase_add_test(tc, tree_get_invalid_key_returns_default);
    tcase_add_test(tc, tree_get_valid_key_returns_value);
    tcase_add_test(tc, tree_get_min_returns_min);
    tcase_add_test(tc, tree_get_max_returns_max);

    suite_add_tcase(s, tc);
    
    SRunner* sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}