#ifndef GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_TRIE_ITERATOR_H
#define GENERIC_DATA_STRUCTURES_GENERIC_ITERATORS_TRIE_ITERATOR_H

#include "../generic_trie.h"


// Todo:
// This non-deterministically tries to process the same leaf node
// twice, but always sequentially. Without knowing the cause, 
// currently the band-aid fix is to keep track of the last processed
// node and if it's equal to the current node, skip it.
// It would be nice to figure out what the cause is. In order to make reading
// the code easier, here is a non-obfiscated, commented version:

// Some notes about the comments:
// - node:      Holds a character and children nodes.
//              The children are held in a list until ___TRIE_ARRAY_SIZE children
//              are added, at which point it switches to a map because that's
//              when the lookups become faster than a simple brute force through the
//              list.
// - leaf node: A node whose character was the final letter in an added word.            
// - obfuscation: The local variables in the macro need to be obfuscated in order to not
//                override user variables from the outer scope. I decided to write the
//                comments on a non-obfuscated version in order to make maintaining it
//                easier.

/*

#define char_trie_iter_start(type_name, trie, out_value)
    {
        // We allocate the out_value.
        // It's size is set to the number of elements, which should
        // be the length of the longest string in the trie,
        // plus one for the null terminator.

        // word exists so we have a value that can be deterministically
        // be freed by trie_set_iter_end.
        void* word = out_value = calloc(trie->max_depth + 1, sizeof(trie->root->value));
        int count = 0;
        int capacity = 4;

        // This is used to fix the aforementioned bug where a node tries
        // to be processed twice in a row.
        type_name ## Node* last = NULL;

        // Unfortunately the only way to iterate with a macro like this is to use
        // a stack (I think. I you have a better solution, please share).
        // The IterState struct keeps track of the array index in either the nodes
        // local array or the maps buffer, in addition to the node itself.
        struct type_name ## IterState* stack = malloc(sizeof(struct type_name ## IterState) * capacity);

        // Start with the root node at the first index.
        stack[count++] = (struct type_name ## IterState){ trie->root, 0 };

        // Keep iterating while there's still a node on the stack.
        while(count > 0) {
            // Get the node to process from the end of the stack.
            struct type_name ## IterState* state = &stack[count - 1];

            // Ignoring the root node, set the nodes character in the 
            // out_value array.
            if(___TRIE_DEPTH(state->node->depth) != 0) {
                out_value[___TRIE_DEPTH(state->node->depth) - 1] = state->node->value;
            }

            // Keep track if a child node was found.
            // If a child node is found, push it onto the stack,
            // increment the states index so it isn't processed again,
            // and go to the next iteration.
            // Otherwise, this nodes children have all been processed,
            // so it can be processed itself if it's a leaf node.
            bool found = false;
            if(state->node->count <= ___TRIE_ARRAY_SIZE) {
                // If the node is exclusively using the array,
                // just make sure the current state index
                // is less than the number of children.
                // If so, there are still children. Otherwise
                // process the current node as there are no more
                // children.

                if(state->index < state->node->count) {
                    found = true;

                    // Increase the stack size if the capacity has been reached.
                    if(count == capacity) {
                        capacity *= 2;
                        stack = realloc(stack, sizeof(*stack) * capacity);
                    }

                    // Push the child onto the stack, and increment the current states index
                    // so the child isn't processed again.
                    stack[count++] = (struct type_name ## IterState){ &state->node->array[state->index], 0 };
                    state->index++;
                }
            } else {

                // If the node is using the map, we iterate through the maps
                // internal buffer. This relies on implementation details of the
                // map, which is dangerous. While the states index is less than
                // the maps total capacity, it's possible there are still children.
                // Otherwise process the current node.
                for(; state->index < state->node->map->capacity; state->index++) {

                    // Uses an implementation detail of the map to see if
                    // a cell holds actual data. Skip it if there is no data.
                    // If there was data, a child has been found.
                    if(!state->node->map->cells[state->index].active)
                        continue;

                    found = true;

                    // Increase the stack size if the capacity has been reached.
                    if(count == capacity) {
                        capacity *= 2;
                        stack = realloc(stack, sizeof(*stack) * capacity);
                    }
                    stack[count++] = (struct type_name ## IterState){ state->node->map->cells[state->index].value, 0 };
                    state->index++;
                    break;
                }
            }

            // If there was a child, continue on to the next iteration.
            if(found)
                continue;

            // If the only node left is the root node,
            // we're done iterating. Break out of the loop.
            if(___TRIE_DEPTH(state->node->depth) == 0)
                break;

            // Pop the current node off of the stack.
            count--;

            // If the current node isn't a leaf node, then it doesn't
            // need to be processed.
            if((state->node->depth & ___TRIE_NODE_IS_LEAF) == 0) {
                continue;
            }

            // The band-aid fix for the aforementioned bug.
            // If the current node is the same as the last processed node,
            // skip it.
            if(state->node == last)
                continue;

            last = state->node;

            // Make sure the out_value is NULL terminated at the correct position.
            out_value[___TRIE_DEPTH(state->node->depth)] = 0;

*/

// Obviously this macro is just a monster. It should really be used sparingly.

// IF YOU MAKE CHANGES TO THIS, PLEASE UPDATE THE NON-OBFUSCATED VERSION AS WELL!
// You don't need to comment it (though that would be appreciated), but at least make
// sure the two forms match.

#define trie_set_iter_start(type_name, trie, out_value) \
    { \
        void* ___trie_iter_value = out_value = calloc((trie)->max_depth + 1, sizeof((trie)->root->value)); \
        assert(out_value); \
        int ___iter_trie_count = 0; \
        int ___iter_trie_capacity = 4; \
        type_name ## Node* ___iter_trie_last = NULL; \
        struct type_name ## IterState* ___iter_trie_stack = malloc(sizeof(struct type_name ## IterState) * ___iter_trie_capacity); \
        assert(___iter_trie_stack); \
        ___iter_trie_stack[___iter_trie_count++] = (struct type_name ## IterState){ (trie)->root, 0 }; \
        while(___iter_trie_count > 0) { \
            struct type_name ## IterState* ___trie_iter_state = &___iter_trie_stack[___iter_trie_count - 1]; \
            if(___TRIE_DEPTH(___trie_iter_state->node->depth) != 0) { \
                out_value[___TRIE_DEPTH(___trie_iter_state->node->depth) - 1] = ___trie_iter_state->node->value; \
            } \
            bool ___iter_trie_found = false; \
            if(___trie_iter_state->node->count <= ___TRIE_ARRAY_SIZE) { \
                if(___trie_iter_state->index < ___trie_iter_state->node->count) { \
                    ___iter_trie_found = true; \
                    if(___iter_trie_count == ___iter_trie_capacity) { \
                        ___iter_trie_capacity *= 2; \
                        ___iter_trie_stack = realloc(___iter_trie_stack, sizeof(*___iter_trie_stack) * ___iter_trie_capacity); \
                        assert(___iter_trie_stack); \
                    } \
                    ___iter_trie_stack[___iter_trie_count++] = (struct type_name ## IterState){ &___trie_iter_state->node->array[___trie_iter_state->index], 0 }; \
                    ___trie_iter_state->index++; \
                } \
            } else { \
                for(; ___trie_iter_state->index < ___trie_iter_state->node->map->capacity; ___trie_iter_state->index++) { \
                    if(!___trie_iter_state->node->map->cells[___trie_iter_state->index].active) \
                        continue; \
                    ___iter_trie_found = true; \
                    if(___iter_trie_count == ___iter_trie_capacity) { \
                        ___iter_trie_capacity *= 2; \
                        ___iter_trie_stack = realloc(___iter_trie_stack, sizeof(*___iter_trie_stack) * ___iter_trie_capacity); \
                        assert(___iter_trie_stack); \
                    } \
                    ___iter_trie_stack[___iter_trie_count++] = (struct type_name ## IterState){ ___trie_iter_state->node->map->cells[___trie_iter_state->index].value, 0 }; \
                    ___trie_iter_state->index++; \
                    break; \
                } \
            } \
 \
            if(___iter_trie_found) \
                continue; \
 \
            if(___TRIE_DEPTH(___trie_iter_state->node->depth) == 0) \
                break; \
 \
            ___iter_trie_count--; \
 \
            if((___trie_iter_state->node->depth & ___TRIE_NODE_IS_LEAF) == 0) { \
                continue; \
            } \
 \
            if(___trie_iter_state->node == ___iter_trie_last) \
                continue; \
 \
            ___iter_trie_last = ___trie_iter_state->node; \
 \
            out_value[___TRIE_DEPTH(___trie_iter_state->node->depth)] = 0; \


#define trie_set_iter_end } free(___trie_iter_value); free(___iter_trie_stack); }


#define trie_map_iter_key_start(type_name, trie, out_key) \
    { \
        void* ___trie_iter_key = out_key = calloc((trie)->max_depth + 1, sizeof((trie)->root->key)); \
        assert(out_key); \
        int ___iter_trie_count = 0; \
        int ___iter_trie_capacity = 4; \
        type_name ## Node* ___iter_trie_last = NULL; \
        struct type_name ## IterState* ___iter_trie_stack = malloc(sizeof(struct type_name ## IterState) * ___iter_trie_capacity); \
        assert(___iter_trie_stack); \
        ___iter_trie_stack[___iter_trie_count++] = (struct type_name ## IterState){ (trie)->root, 0 }; \
        while(___iter_trie_count > 0) { \
            struct type_name ## IterState* ___trie_iter_state = &___iter_trie_stack[___iter_trie_count - 1]; \
            if(___TRIE_DEPTH(___trie_iter_state->node->depth) != 0) { \
                out_key[___TRIE_DEPTH(___trie_iter_state->node->depth) - 1] = ___trie_iter_state->node->key; \
            } \
            bool ___iter_trie_found = false; \
            if(___trie_iter_state->node->count <= ___TRIE_ARRAY_SIZE) { \
                if(___trie_iter_state->index < ___trie_iter_state->node->count) { \
                    ___iter_trie_found = true; \
                    if(___iter_trie_count == ___iter_trie_capacity) { \
                        ___iter_trie_capacity *= 2; \
                        ___iter_trie_stack = realloc(___iter_trie_stack, sizeof(*___iter_trie_stack) * ___iter_trie_capacity); \
                        assert(___iter_trie_stack); \
                    } \
                    ___iter_trie_stack[___iter_trie_count++] = (struct type_name ## IterState){ &___trie_iter_state->node->array[___trie_iter_state->index], 0 }; \
                    ___trie_iter_state->index++; \
                } \
            } else { \
                for(; ___trie_iter_state->index < ___trie_iter_state->node->map->capacity; ___trie_iter_state->index++) { \
                    if(!___trie_iter_state->node->map->cells[___trie_iter_state->index].active) \
                        continue; \
                    ___iter_trie_found = true; \
                    if(___iter_trie_count == ___iter_trie_capacity) { \
                        ___iter_trie_capacity *= 2; \
                        ___iter_trie_stack = realloc(___iter_trie_stack, sizeof(*___iter_trie_stack) * ___iter_trie_capacity); \
                        assert(___iter_trie_stack); \
                    } \
                    ___iter_trie_stack[___iter_trie_count++] = (struct type_name ## IterState){ ___trie_iter_state->node->map->cells[___trie_iter_state->index].value, 0 }; \
                    ___trie_iter_state->index++; \
                    break; \
                } \
            } \
 \
            if(___iter_trie_found) \
                continue; \
 \
            if(___TRIE_DEPTH(___trie_iter_state->node->depth) == 0) \
                break; \
 \
            ___iter_trie_count--; \
 \
            if((___trie_iter_state->node->depth & ___TRIE_NODE_IS_LEAF) == 0) { \
                continue; \
            } \
 \
            if(___trie_iter_state->node == ___iter_trie_last) \
                continue; \
 \
            ___iter_trie_last = ___trie_iter_state->node; \
 \
            out_key[___TRIE_DEPTH(___trie_iter_state->node->depth)] = 0; \


#define trie_map_iter_start(type_name, trie, out_key, out_value) \
    trie_map_iter_key_start(type_name, trie, out_key) \
    out_value = ___trie_iter_state->node->value; \


#define trie_map_iter_value_start(type_name, trie, out_value) \
    { \
        void* ___trie_iter_key = NULL; \
        int ___iter_trie_count = 0; \
        int ___iter_trie_capacity = 4; \
        type_name ## Node* ___iter_trie_last = NULL; \
        struct type_name ## IterState* ___iter_trie_stack = malloc(sizeof(struct type_name ## IterState) * ___iter_trie_capacity); \
        assert(___iter_trie_stack); \
        ___iter_trie_stack[___iter_trie_count++] = (struct type_name ## IterState){ (trie)->root, 0 }; \
        while(___iter_trie_count > 0) { \
            struct type_name ## IterState* ___trie_iter_state = &___iter_trie_stack[___iter_trie_count - 1]; \
            bool ___iter_trie_found = false; \
            if(___trie_iter_state->node->count <= ___TRIE_ARRAY_SIZE) { \
                if(___trie_iter_state->index < ___trie_iter_state->node->count) { \
                    ___iter_trie_found = true; \
                    if(___iter_trie_count == ___iter_trie_capacity) { \
                        ___iter_trie_capacity *= 2; \
                        ___iter_trie_stack = realloc(___iter_trie_stack, sizeof(*___iter_trie_stack) * ___iter_trie_capacity); \
                        assert(___iter_trie_stack); \
                    } \
                    ___iter_trie_stack[___iter_trie_count++] = (struct type_name ## IterState){ &___trie_iter_state->node->array[___trie_iter_state->index], 0 }; \
                    ___trie_iter_state->index++; \
                } \
            } else { \
                for(; ___trie_iter_state->index < ___trie_iter_state->node->map->capacity; ___trie_iter_state->index++) { \
                    if(!___trie_iter_state->node->map->cells[___trie_iter_state->index].active) \
                        continue; \
                    ___iter_trie_found = true; \
                    if(___iter_trie_count == ___iter_trie_capacity) { \
                        ___iter_trie_capacity *= 2; \
                        ___iter_trie_stack = realloc(___iter_trie_stack, sizeof(*___iter_trie_stack) * ___iter_trie_capacity); \
                        assert(___iter_trie_stack); \
                    } \
                    ___iter_trie_stack[___iter_trie_count++] = (struct type_name ## IterState){ ___trie_iter_state->node->map->cells[___trie_iter_state->index].value, 0 }; \
                    ___trie_iter_state->index++; \
                    break; \
                } \
            } \
 \
            if(___iter_trie_found) \
                continue; \
 \
            if(___TRIE_DEPTH(___trie_iter_state->node->depth) == 0) \
                break; \
 \
            ___iter_trie_count--; \
 \
            if((___trie_iter_state->node->depth & ___TRIE_NODE_IS_LEAF) == 0) { \
                continue; \
            } \
 \
            if(___trie_iter_state->node == ___iter_trie_last) \
                continue; \
 \
            ___iter_trie_last = ___trie_iter_state->node; \
 \
            out_value = ___trie_iter_state->node->value; \


#define trie_map_iter_end } free(___trie_iter_key); free(___iter_trie_stack); }

#endif