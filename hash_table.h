#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include<sys/types.h>
#include<stdint.h>

#include "ret_code.h"

#define DEBUG

#define HASH_LEN table->key_num
#define HASH(x,y) hash_table_do_hash(x,y,HASH_LEN)

typedef struct hash_table_elem hash_table_elem_t;
typedef struct hash_table      hash_table_t;

ret_code_t hash_table_construct(hash_table_t ** hash_table_ptr, size_t size);
ret_code_t hash_table_destruct (hash_table_t ** hash_table_ptr);




#endif // HASH_TABLE_H

