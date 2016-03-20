#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdint.h>

#include "ret_code.h"

#define DEBUG

#define HASH_LEN table->key_num
#define HASH(x,y) hash_table_do_hash(x,y,HASH_LEN)

typedef struct hash_table_elem hash_table_elem_t;
typedef struct hash_table      hash_table_t;

ret_code_t hash_table_construct(hash_table_t ** hash_table_ptr, size_t size);
ret_code_t hash_table_destruct (hash_table_t ** hash_table_ptr);

ret_code_t hash_table_add(hash_table_t * hash_table, void * key, size_t key_s, void * value, size_t value_s);
#define HASH_TABLE_ADD(hash_table, key, value) hash_table_add(hash_table, key, sizeof(key), value, sizeof(value));

// Debug functions
void hash_table_print(hash_table_t * hash_table);

#endif // HASH_TABLE_H

