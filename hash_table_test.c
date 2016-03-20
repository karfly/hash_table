#include <stdio.h>
#include "hash_table.h"

int main()
        {
        int ret = 0, i = 0;

        size_t offset1  = 12;
        size_t offset10 = 12 + 10;
        void * ptr10    = (void *)0xDEAD;
        void * ptr11    = (void *)0xFF;

        size_t offset2  = 512;
        void * ptr20    = (void *)0xBABE;

        hash_table_t *my_hash_table = NULL;

        ret = hash_table_construct(&my_hash_table, 10);
        printf("Construct: ret = %d\n", ret);

        HASH_TABLE_ADD(my_hash_table, &offset1, &ptr10);
        hash_table_print(my_hash_table);
        HASH_TABLE_ADD(my_hash_table, &offset2, &ptr20);
        hash_table_print(my_hash_table);
        HASH_TABLE_ADD(my_hash_table, &offset1, &ptr10);
        hash_table_print(my_hash_table);
        HASH_TABLE_ADD(my_hash_table, &offset10, &ptr11);
        hash_table_print(my_hash_table);
        HASH_TABLE_ADD(my_hash_table, &offset1, &ptr10);
        hash_table_print(my_hash_table);

        ret = hash_table_destruct(&my_hash_table);
        printf("Destruct: ret = %d\n", ret);

        return 0;
        }