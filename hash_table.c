#include <stdlib.h>
#include <string.h>

#include "hash_table.h"
#include "hash_table_debug.h"

#define _HASH_TABLE_DELETE_ELEM(elem) do                                        \
                                        {                                       \
                                        free(elem->key);   elem->key = NULL;    \
                                        free(elem->value); elem->value = NULL;  \
                                        free(elem);        elem = NULL;         \
                                        } while(0);                             \

struct hash_table_elem
        {
        size_t key_s;
        size_t value_s;

        void * key;
        void * value;

        struct hash_table_elem * next;
        };

struct hash_table
        {
        struct hash_table_elem  ** entry;

        size_t count;
        size_t size;
        };

ret_code_t hash_table_construct(hash_table_t ** hash_table_ptr, size_t size)
        {
        if (!hash_table_ptr || size <= 0)
                {
                return WRONG_ARGUMENTS;
                }

        hash_table_t * new_hash_table = (hash_table_t *)calloc(1, sizeof(hash_table_t *));
        if (!new_hash_table)
                {
                DEBUG_LOG("failed to allocate memory for new hash_table");
                goto error_hash_table_mem_aloc;
                }

        new_hash_table->size = size;

        new_hash_table->entry = (hash_table_elem_t **) calloc(new_hash_table->size, sizeof(hash_table_elem_t *));
        if (!new_hash_table->entry)
                {
                DEBUG_LOG("failed to allocate memory for new hash table entry");
                free(new_hash_table);
                goto error_hash_table_entry_mem_aloc;
                }

        *hash_table_ptr = new_hash_table;
        return SUCCESS;

        error_hash_table_entry_mem_aloc:
                free(new_hash_table);
                new_hash_table = NULL;

        error_hash_table_mem_aloc:

        return ERROR;
        }

ret_code_t hash_table_destruct(hash_table_t ** hash_table_ptr)
        {
        if (!hash_table_ptr)
                {
                return WRONG_ARGUMENTS;
                }

        hash_table_t * hash_table = *hash_table_ptr;

        int i = 0;
        for (i = 0; i < hash_table->size; i++)
                {
                while(hash_table->entry[i])
                        {
                        hash_table_elem_t * temp_elem = hash_table->entry[i];
                        hash_table->entry[i] = hash_table->entry[i]->next;

                        _HASH_TABLE_DELETE_ELEM(temp_elem);
                        }
                }
        free(hash_table->entry);
        hash_table->entry = NULL;

        free(hash_table);
        hash_table = NULL;

        return SUCCESS;
        }
