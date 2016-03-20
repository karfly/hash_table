#include <stdio.h>
#include "hash_table.h"

int main()
        {
        int ret = 0, i = 0;

        size_t offset1  = 256;
        size_t offset10 = 256 + 10;
        void * ptr10    = (void *)0xDEAD;
        void * ptr11    = (void *)0xFF;

        size_t offset2  = 512;
        void * ptr20    = (void *)0xBABE;

        size_t offset3  = 1024;

        void * temp = NULL;

        hash_table_t * my_hash_table = NULL;

        ret = hash_table_construct(&my_hash_table, 5);
        printf("Construct: ret = %d\n", ret);

        HASH_TABLE_ADD(my_hash_table, &offset1,  &ptr10);
        HASH_TABLE_ADD(my_hash_table, &offset2,  &ptr20);
        HASH_TABLE_ADD(my_hash_table, &offset1,  &ptr10);
        HASH_TABLE_ADD(my_hash_table, &offset10, &ptr11);
        HASH_TABLE_ADD(my_hash_table, &offset1,  &ptr10);

        hash_table_print(my_hash_table);

        //HASH_TABLE_REMOVE(my_hash_table, &offset1);

        ret = HASH_TABLE_GET(my_hash_table, &offset1, &temp);
        printf("Get: ret = %d\n", ret);
        if (temp)
                printf("GET: value = %p\n",*(void **)temp);

        hash_table_print(my_hash_table);

        HASH_TABLE_REMOVE(my_hash_table, &offset1);
        HASH_TABLE_REMOVE(my_hash_table, &offset10);
        HASH_TABLE_REMOVE(my_hash_table, &offset2);

        hash_table_print(my_hash_table);

        ret = hash_table_destruct(&my_hash_table);
        printf("Destruct: ret = %d\n", ret);

        return 0;
        }