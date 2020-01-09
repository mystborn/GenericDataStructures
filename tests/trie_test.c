#include <check.h>
#include <stdio.h>

#include "../include/generic_trie.h"
#include "../include/generic_iterators/trie_iterator.h"

TRIE_SET_DEFINE_H(StringTrie, str_trie, char)

TRIE_SET_DEFINE_C(StringTrie, str_trie, char)

TRIE_MAP_DEFINE_H(SITrie, si_trie, char, int)

TRIE_MAP_DEFINE_C(SITrie, si_trie, char, int)

static char* simple_words[] = {
    "hello",
    "world",
    "owl",
    "fox",
    "raven",
    "cat",
    "cow",
    "moo",
    "meow",
    "vs",
    "nyan"
};

// This can't share any words with simple_words either.

static char* complex_words[] = {
    "This",
    "is",
    "a",
    "rather",
    "complex",
    "sentence",
    "that",
    "contains",
    "no",
    "duplicate",
    "words",
    "in",
    "order",
    "to",
    "make",
    "sure",
    "the",
    "trie_set",
    "has",
    "an",
    "opportunity",
    "resize",
    "when",
    "number",
    "twenty",
    "reached",
    ","
    "but",
    "too",
    "little",
    "letters",
    "left",
    "after",
    "all",
    "uh",
    "oh",
    "spaghettio",
    "Generic",
    "Data",
    "Structures",
    "set",
    "of",
    "C",
    "header",
    "files",
    "contain",
    "macros",
    "which",
    "generate",
    "strongly",
    "typed",
    "data",
    "structures",
    "fashion",
    "similar",
    "c++",
    "templates",
    "Each",
    "two",
    "type",
    "corresponds",
    "name",
    "first",
    "macro",
    "can",
    "go",
    "file",
    "functions",
    "are",
    "used",
    "across",
    "multiple",
    "compilation",
    "units"
};

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(*array))

static StringTrie* trie_set;
static SITrie* trie_map;

void trie_set_start(void) {
    trie_set = str_trie_create();
}

void trie_set_reset(void) {
    str_trie_free(trie_set);
}

void trie_map_start(void) {
    trie_map = si_trie_create();
}

void trie_map_reset(void) {
    si_trie_free(trie_map);
}

START_TEST(trie_set_allocate_and_deallocate) {
    StringTrie temp, *ptr;
    ck_assert(str_trie_init(&temp));
    str_trie_free_resources(&temp);
    ptr = str_trie_create();
    ck_assert(ptr);
    str_trie_free(ptr);
}
END_TEST

START_TEST(trie_set_simple_add_new_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
        ck_assert(str_trie_count(trie_set) == i);
        ck_assert(str_trie_add(trie_set, simple_words[i]));
        ck_assert(str_trie_count(trie_set) == i + 1);
    }
}
END_TEST

START_TEST(trie_set_simple_add_repeat_value_fails) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
        ck_assert(str_trie_count(trie_set) == i);
        ck_assert(str_trie_add(trie_set, simple_words[i]));
        ck_assert(str_trie_count(trie_set) == i + 1);
    }

    for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
        ck_assert(!str_trie_add(trie_set, simple_words[i]));
    }
}
END_TEST

START_TEST(trie_set_complex_add_new_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
        ck_assert(str_trie_count(trie_set) == i);
        ck_assert(str_trie_add(trie_set, complex_words[i]));
        ck_assert(str_trie_count(trie_set) == i + 1);
    }
}
END_TEST

START_TEST(trie_set_complex_add_repeat_value_fails) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
        ck_assert(str_trie_count(trie_set) == i);
        ck_assert(str_trie_add(trie_set, complex_words[i]));
        ck_assert(str_trie_count(trie_set) == i + 1);
    }

    for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
        ck_assert(!str_trie_add(trie_set, complex_words[i]));
    }
}
END_TEST

START_TEST(trie_set_simple_contains_added_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(str_trie_add(trie_set, simple_words[i]));

    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(str_trie_contains(trie_set, simple_words[i]));
}
END_TEST

START_TEST(trie_set_simple_contains_missing_value_fails) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(str_trie_add(trie_set, simple_words[i]));

    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(!str_trie_contains(trie_set, complex_words[i]));
}
END_TEST

START_TEST(trie_set_complex_contains_added_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(str_trie_add(trie_set, complex_words[i]));

    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(str_trie_contains(trie_set, complex_words[i]));
}
END_TEST

START_TEST(trie_set_complex_contains_missing_value_fails) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(str_trie_add(trie_set, complex_words[i]));

    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(!str_trie_contains(trie_set, simple_words[i]));
}
END_TEST

START_TEST(trie_set_simple_remove_added_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(str_trie_add(trie_set, simple_words[i]));

    for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
        unsigned int count = str_trie_count(trie_set);
        ck_assert(str_trie_remove(trie_set, simple_words[i]));
        ck_assert(str_trie_count(trie_set) == count - 1);
    }
}
END_TEST

START_TEST(trie_set_simple_remove_missing_value_fails) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(str_trie_add(trie_set, simple_words[i]));

    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(!str_trie_remove(trie_set, complex_words[i]));
}
END_TEST

START_TEST(trie_set_complex_remove_added_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(str_trie_add(trie_set, complex_words[i]));

    for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
        unsigned int count = str_trie_count(trie_set);
        ck_assert(str_trie_remove(trie_set, complex_words[i]));
        ck_assert(str_trie_count(trie_set) == count - 1);
    }
}
END_TEST

START_TEST(trie_set_complex_remove_missing_value_fails) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(str_trie_add(trie_set, complex_words[i]));

    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(!str_trie_remove(trie_set, simple_words[i]));
}
END_TEST

START_TEST(trie_set_simple_add_and_remove) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(str_trie_add(trie_set, simple_words[i]));

    for(int i = 0; i < ARRAY_SIZE(simple_words); i += 2)
        ck_assert(str_trie_remove(trie_set, simple_words[i]));

    for(int i = 1; i < ARRAY_SIZE(simple_words); i += 2)
        ck_assert(str_trie_contains(trie_set, simple_words[i]));

    for(int i = 0; i < ARRAY_SIZE(simple_words); i += 2)
        ck_assert(!str_trie_contains(trie_set, simple_words[i]));
}
END_TEST

START_TEST(trie_set_complex_add_and_remove) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(str_trie_add(trie_set, complex_words[i]));

    for(int i = 0; i < ARRAY_SIZE(complex_words); i += 2)
        ck_assert(str_trie_remove(trie_set, complex_words[i]));

    for(int i = 1; i < ARRAY_SIZE(complex_words); i += 2)
        ck_assert(str_trie_contains(trie_set, complex_words[i]));

    for(int i = 0; i < ARRAY_SIZE(complex_words); i += 2)
        ck_assert(!str_trie_contains(trie_set, complex_words[i]));
}
END_TEST

START_TEST(trie_set_simple_iter) {
    int word_count[ARRAY_SIZE(simple_words)] = { 0 };
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(str_trie_add(trie_set, simple_words[i]));

    char* value;
    trie_set_iter_start(StringTrie, trie_set, value) {
        for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
            if(strcmp(value, simple_words[i]) == 0) {
                ck_assert(word_count[i] == 0);
                word_count[i] += 1;
            }
        }
    }
    trie_set_iter_end

    for(int i = 0; i < ARRAY_SIZE(word_count); i++) {
        ck_assert(word_count[i] == 1);
    }
}
END_TEST

START_TEST(trie_set_complex_iter) {
    int word_count[ARRAY_SIZE(complex_words)] = { 0 };
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(str_trie_add(trie_set, complex_words[i]));

    char* value;
    trie_set_iter_start(StringTrie, trie_set, value) {
        for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
            if(strcmp(value, complex_words[i]) == 0) {
                ck_assert(word_count[i] == 0);
                word_count[i] += 1;
            }
        }
    }
    trie_set_iter_end

    for(int i = 0; i < ARRAY_SIZE(word_count); i++) {
        ck_assert(word_count[i] == 1);
    }
}
END_TEST

START_TEST(trie_map_allocate_and_deallocate) {
    SITrie temp, *ptr;
    ck_assert(si_trie_init(&temp));
    si_trie_free_resources(&temp);
    ptr = si_trie_create();
    ck_assert(ptr);
    si_trie_free(ptr);
}
END_TEST

START_TEST(trie_map_simple_add_new_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
        ck_assert(si_trie_count(trie_map) == i);
        ck_assert(si_trie_add(trie_map, simple_words[i], i));
        ck_assert(si_trie_count(trie_map) == i + 1);
        ck_assert(si_trie_get(trie_map, simple_words[i]) == i);
    }
}
END_TEST

START_TEST(trie_map_simple_add_repeat_value_fails) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
        ck_assert(si_trie_count(trie_map) == i);
        ck_assert(si_trie_add(trie_map, simple_words[i], i));
        ck_assert(si_trie_count(trie_map) == i + 1);
    }

    for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
        ck_assert(!si_trie_add(trie_map, simple_words[i], i));
    }
}
END_TEST

START_TEST(trie_map_complex_add_new_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
        ck_assert(si_trie_count(trie_map) == i);
        ck_assert(si_trie_add(trie_map, complex_words[i], i));
        ck_assert(si_trie_count(trie_map) == i + 1);
        ck_assert(si_trie_get(trie_map, complex_words[i]) == i);
    }
}
END_TEST

START_TEST(trie_map_complex_add_repeat_value_fails) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
        ck_assert(si_trie_count(trie_map) == i);
        ck_assert(si_trie_add(trie_map, complex_words[i], i));
        ck_assert(si_trie_count(trie_map) == i + 1);
    }

    for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
        ck_assert(!si_trie_add(trie_map, complex_words[i], i));
    }
}
END_TEST

START_TEST(trie_map_simple_set_new_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
        ck_assert(si_trie_count(trie_map) == i);
        ck_assert(si_trie_set(trie_map, simple_words[i], i));
        ck_assert(si_trie_count(trie_map) == i + 1);
        ck_assert(si_trie_get(trie_map, simple_words[i]) == i);
    }
}
END_TEST

START_TEST(trie_map_simple_set_repeat_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
        ck_assert(si_trie_count(trie_map) == i);
        ck_assert(si_trie_set(trie_map, simple_words[i], i));
        ck_assert(si_trie_count(trie_map) == i + 1);
        ck_assert(si_trie_get(trie_map, simple_words[i]) == i);
    }

    unsigned int count = si_trie_count(trie_map);

    for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
        ck_assert(si_trie_set(trie_map, simple_words[i], i + 1));
        ck_assert(si_trie_get(trie_map, simple_words[i]) == i + 1);
        ck_assert(si_trie_count(trie_map) == count);
    }
}
END_TEST

START_TEST(trie_map_complex_set_new_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
        ck_assert(si_trie_count(trie_map) == i);
        ck_assert(si_trie_set(trie_map, complex_words[i], i));
        ck_assert(si_trie_count(trie_map) == i + 1);
        ck_assert(si_trie_get(trie_map, complex_words[i]) == i);
    }
}
END_TEST

START_TEST(trie_map_complex_set_repeat_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
        ck_assert(si_trie_count(trie_map) == i);
        ck_assert(si_trie_set(trie_map, complex_words[i], i));
        ck_assert(si_trie_count(trie_map) == i + 1);
        ck_assert(si_trie_get(trie_map, complex_words[i]) == i);
    }

    unsigned int count = si_trie_count(trie_map);

    for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
        ck_assert(si_trie_set(trie_map, complex_words[i], i + 1));
        ck_assert(si_trie_get(trie_map, complex_words[i]) == i + 1);
        ck_assert(si_trie_count(trie_map) == count);
    }
}
END_TEST

START_TEST(trie_map_get_missing_value_returns_default) {
    ck_assert(si_trie_get(trie_map, "moo") == 0);
}
END_TEST

START_TEST(trie_map_simple_try_get_added_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(si_trie_set(trie_map, simple_words[i], i));

    int value;
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
        ck_assert(si_trie_try_get(trie_map, simple_words[i], &value));
        ck_assert(value == i);
    }
}
END_TEST

START_TEST(trie_map_simple_try_get_missing_value_fails) {
    int value = 4;
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
        ck_assert(!si_trie_try_get(trie_map, simple_words[i], &value));
        ck_assert(value == 4);
    }
}
END_TEST

START_TEST(trie_map_complex_try_get_added_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(si_trie_set(trie_map, complex_words[i], i));

    int value;
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
        ck_assert(si_trie_try_get(trie_map, complex_words[i], &value));
        ck_assert(value == i);
    }
}
END_TEST

START_TEST(trie_map_complex_try_get_missing_value_fails) {
    int value = 6;
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
        ck_assert(!si_trie_try_get(trie_map, complex_words[i], &value));
        ck_assert(value == 6);
    }
}
END_TEST

START_TEST(trie_map_simple_remove_added_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(si_trie_set(trie_map, simple_words[i], i));

    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(si_trie_remove(trie_map, simple_words[i]));

    ck_assert(si_trie_count(trie_map) == 0);
}
END_TEST

START_TEST(trie_map_simple_remove_missing_fails) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(!si_trie_remove(trie_map, simple_words[i]));
}
END_TEST

START_TEST(trie_map_simple_remove_some_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(si_trie_set(trie_map, simple_words[i], i));

    for(int i = 0; i < ARRAY_SIZE(simple_words); i += 2)
        ck_assert(si_trie_remove(trie_map, simple_words[i]));

    for(int i = 0; i < ARRAY_SIZE(simple_words); i += 2) {
        if(i % 2)
            ck_assert(si_trie_try_get(trie_map, simple_words[i], NULL));
        else
            ck_assert(!si_trie_try_get(trie_map, simple_words[i], NULL));
    }
}
END_TEST

START_TEST(trie_map_complex_remove_added_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(si_trie_set(trie_map, complex_words[i], i));

    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(si_trie_remove(trie_map, complex_words[i]));

    ck_assert(si_trie_count(trie_map) == 0);
}
END_TEST

START_TEST(trie_map_complex_remove_missing_fails) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(!si_trie_remove(trie_map, complex_words[i]));
}
END_TEST

START_TEST(trie_map_complex_remove_some_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(si_trie_set(trie_map, complex_words[i], i));

    for(int i = 0; i < ARRAY_SIZE(complex_words); i += 2)
        ck_assert(si_trie_remove(trie_map, complex_words[i]));

    for(int i = 0; i < ARRAY_SIZE(complex_words); i += 2) {
        if(i % 2)
            ck_assert(si_trie_try_get(trie_map, complex_words[i], NULL));
        else
            ck_assert(!si_trie_try_get(trie_map, complex_words[i], NULL));
    }
}
END_TEST

START_TEST(trie_map_simple_get_and_remove_added_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(si_trie_set(trie_map, simple_words[i], i));

    int value;
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
        ck_assert(si_trie_get_and_remove(trie_map, simple_words[i], &value));
        ck_assert(value == i);
    }

    ck_assert(si_trie_count(trie_map) == 0);
}
END_TEST

START_TEST(trie_map_simple_get_and_remove_missing_value_fails) {
    int value = 5;
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
        ck_assert(!si_trie_get_and_remove(trie_map, simple_words[i], &value));
        ck_assert(value == 5);
    }
}
END_TEST

START_TEST(trie_map_simple_get_and_remove_some_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(si_trie_set(trie_map, simple_words[i], i));

    int value;
    for(int i = 0; i < ARRAY_SIZE(simple_words); i += 2) {
        ck_assert(si_trie_get_and_remove(trie_map, simple_words[i], &value));
        ck_assert(value == i);
    }

    for(int i = 0; i < ARRAY_SIZE(simple_words); i += 2) {
        if(i % 2)
            ck_assert(si_trie_try_get(trie_map, simple_words[i], NULL));
        else
            ck_assert(!si_trie_try_get(trie_map, simple_words[i], NULL));
    }
}
END_TEST

START_TEST(trie_map_complex_get_and_remove_added_value_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(si_trie_set(trie_map, complex_words[i], i));

    int value;
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
        ck_assert(si_trie_get_and_remove(trie_map, complex_words[i], &value));
        ck_assert(value == i);
    }

    ck_assert(si_trie_count(trie_map) == 0);
}
END_TEST

START_TEST(trie_map_complex_get_and_remove_missing_value_fails) {
    int value = 5;
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
        ck_assert(!si_trie_get_and_remove(trie_map, complex_words[i], &value));
        ck_assert(value == 5);
    }
}
END_TEST

START_TEST(trie_map_complex_get_and_remove_some_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(si_trie_set(trie_map, complex_words[i], i));

    int value;
    for(int i = 0; i < ARRAY_SIZE(complex_words); i += 2) {
        ck_assert(si_trie_get_and_remove(trie_map, complex_words[i], &value));
        ck_assert(value == i);
    }

    for(int i = 0; i < ARRAY_SIZE(complex_words); i += 2) {
        if(i % 2)
            ck_assert(si_trie_try_get(trie_map, complex_words[i], NULL));
        else
            ck_assert(!si_trie_try_get(trie_map, complex_words[i], NULL));
    }
}
END_TEST

START_TEST(trie_map_simple_clear_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(si_trie_set(trie_map, simple_words[i], i));

    ck_assert(si_trie_clear(trie_map));
    ck_assert(si_trie_count(trie_map) == 0);
}
END_TEST

START_TEST(trie_map_complex_clear_succeeds) {
    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(si_trie_set(trie_map, complex_words[i], i));

    ck_assert(si_trie_clear(trie_map));
    ck_assert(si_trie_count(trie_map) == 0);
}
END_TEST

START_TEST(trie_map_simple_iter_both) {
    int word_count[ARRAY_SIZE(simple_words)] = { 0 };

    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(si_trie_set(trie_map, simple_words[i], i));

    char* key;
    int value;
    trie_map_iter_start(SITrie, trie_map, key, value) {
        ck_assert(strcmp(key, simple_words[value]) == 0);
        word_count[value] += 1;
    }
    trie_map_iter_end

    for(int i = 0; i < ARRAY_SIZE(word_count); i++) {
        ck_assert(word_count[i] == 1);
    }
}
END_TEST

START_TEST(trie_map_simple_iter_key) {
    int word_count[ARRAY_SIZE(simple_words)] = { 0 };

    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(si_trie_set(trie_map, simple_words[i], i));

    char* key;
    trie_map_iter_key_start(SITrie, trie_map, key) {
        for(int i = 0; i < ARRAY_SIZE(simple_words); i++) {
            if(strcmp(key, simple_words[i]) == 0) {
                word_count[i] += 1;
            }
        }
    }
    trie_map_iter_end

    for(int i = 0; i < ARRAY_SIZE(word_count); i++) {
        ck_assert(word_count[i] == 1);
    }
}
END_TEST

START_TEST(trie_map_simple_iter_value) {
    int word_count[ARRAY_SIZE(simple_words)] = { 0 };

    for(int i = 0; i < ARRAY_SIZE(simple_words); i++)
        ck_assert(si_trie_set(trie_map, simple_words[i], i));

    int value;
    trie_map_iter_value_start(SITrie, trie_map, value) {
        word_count[value] += 1;
    }
    trie_map_iter_end

    for(int i = 0; i < ARRAY_SIZE(word_count); i++) {
        ck_assert(word_count[i] == 1);
    }
}
END_TEST

START_TEST(trie_map_complex_iter_both) {
    int word_count[ARRAY_SIZE(complex_words)] = { 0 };

    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(si_trie_set(trie_map, complex_words[i], i));

    char* key;
    int value;
    trie_map_iter_start(SITrie, trie_map, key, value) {
        ck_assert(strcmp(key, complex_words[value]) == 0);
        word_count[value] += 1;
    }
    trie_map_iter_end

    for(int i = 0; i < ARRAY_SIZE(word_count); i++) {
        ck_assert(word_count[i] == 1);
    }
}
END_TEST

START_TEST(trie_map_complex_iter_key) {
    int word_count[ARRAY_SIZE(complex_words)] = { 0 };

    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(si_trie_set(trie_map, complex_words[i], i));

    char* key;
    trie_map_iter_key_start(SITrie, trie_map, key) {
        for(int i = 0; i < ARRAY_SIZE(complex_words); i++) {
            if(strcmp(key, complex_words[i]) == 0) {
                word_count[i] += 1;
            }
        }
    }
    trie_map_iter_end

    for(int i = 0; i < ARRAY_SIZE(word_count); i++) {
        ck_assert(word_count[i] == 1);
    }
}
END_TEST

START_TEST(trie_map_complex_iter_value) {
    int word_count[ARRAY_SIZE(complex_words)] = { 0 };

    for(int i = 0; i < ARRAY_SIZE(complex_words); i++)
        ck_assert(si_trie_set(trie_map, complex_words[i], i));

    int value;
    trie_map_iter_value_start(SITrie, trie_map, value) {
        word_count[value] += 1;
    }
    trie_map_iter_end

    for(int i = 0; i < ARRAY_SIZE(word_count); i++) {
        ck_assert(word_count[i] == 1);
    }
}
END_TEST

int main(void) {
    Suite* s = suite_create("Trie Tests");
    TCase* tc_set = tcase_create("Trie Set Tests");
    TCase* tc_map = tcase_create("Trie Map Tests");

    tcase_add_checked_fixture(tc_set, trie_set_start, trie_set_reset);
    tcase_add_test(tc_set, trie_set_allocate_and_deallocate);
    tcase_add_test(tc_set, trie_set_simple_add_new_value_succeeds);
    tcase_add_test(tc_set, trie_set_simple_add_repeat_value_fails);
    tcase_add_test(tc_set, trie_set_complex_add_new_value_succeeds);
    tcase_add_test(tc_set, trie_set_complex_add_repeat_value_fails);
    tcase_add_test(tc_set, trie_set_simple_contains_added_value_succeeds);
    tcase_add_test(tc_set, trie_set_simple_contains_missing_value_fails);
    tcase_add_test(tc_set, trie_set_complex_contains_added_value_succeeds);
    tcase_add_test(tc_set, trie_set_complex_contains_missing_value_fails);
    tcase_add_test(tc_set, trie_set_simple_remove_added_value_succeeds);
    tcase_add_test(tc_set, trie_set_simple_remove_missing_value_fails);
    tcase_add_test(tc_set, trie_set_complex_remove_added_value_succeeds);
    tcase_add_test(tc_set, trie_set_complex_remove_missing_value_fails);
    tcase_add_test(tc_set, trie_set_simple_add_and_remove);
    tcase_add_test(tc_set, trie_set_complex_add_and_remove);
    tcase_add_test(tc_set, trie_set_simple_iter);
    tcase_add_test(tc_set, trie_set_complex_iter);

    tcase_add_checked_fixture(tc_map, trie_map_start, trie_map_reset);
    tcase_add_test(tc_map, trie_map_allocate_and_deallocate);
    tcase_add_test(tc_map, trie_map_simple_add_new_value_succeeds);
    tcase_add_test(tc_map, trie_map_simple_add_repeat_value_fails);
    tcase_add_test(tc_map, trie_map_complex_add_new_value_succeeds);
    tcase_add_test(tc_map, trie_map_complex_add_repeat_value_fails);
    tcase_add_test(tc_map, trie_map_simple_set_new_value_succeeds);
    tcase_add_test(tc_map, trie_map_simple_set_repeat_value_succeeds);
    tcase_add_test(tc_map, trie_map_complex_set_new_value_succeeds);
    tcase_add_test(tc_map, trie_map_complex_set_repeat_value_succeeds);
    tcase_add_test(tc_map, trie_map_get_missing_value_returns_default);
    tcase_add_test(tc_map, trie_map_simple_try_get_added_value_succeeds);
    tcase_add_test(tc_map, trie_map_simple_try_get_missing_value_fails);
    tcase_add_test(tc_map, trie_map_complex_try_get_added_value_succeeds);
    tcase_add_test(tc_map, trie_map_complex_try_get_missing_value_fails);
    tcase_add_test(tc_map, trie_map_simple_remove_added_succeeds);
    tcase_add_test(tc_map, trie_map_simple_remove_missing_fails);
    tcase_add_test(tc_map, trie_map_simple_remove_some_succeeds);
    tcase_add_test(tc_map, trie_map_complex_remove_added_succeeds);
    tcase_add_test(tc_map, trie_map_complex_remove_missing_fails);
    tcase_add_test(tc_map, trie_map_complex_remove_some_succeeds);
    tcase_add_test(tc_map, trie_map_simple_get_and_remove_added_value_succeeds);
    tcase_add_test(tc_map, trie_map_simple_get_and_remove_missing_value_fails);
    tcase_add_test(tc_map, trie_map_simple_get_and_remove_some_succeeds);
    tcase_add_test(tc_map, trie_map_complex_get_and_remove_added_value_succeeds);
    tcase_add_test(tc_map, trie_map_complex_get_and_remove_missing_value_fails);
    tcase_add_test(tc_map, trie_map_complex_get_and_remove_some_succeeds);
    tcase_add_test(tc_map, trie_map_simple_clear_succeeds);
    tcase_add_test(tc_map, trie_map_complex_clear_succeeds);
    tcase_add_test(tc_map, trie_map_simple_iter_both);
    tcase_add_test(tc_map, trie_map_simple_iter_key);
    tcase_add_test(tc_map, trie_map_simple_iter_value);
    tcase_add_test(tc_map, trie_map_complex_iter_both);
    tcase_add_test(tc_map, trie_map_complex_iter_key);
    tcase_add_test(tc_map, trie_map_complex_iter_value);

    suite_add_tcase(s, tc_set);
    suite_add_tcase(s, tc_map);

    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}