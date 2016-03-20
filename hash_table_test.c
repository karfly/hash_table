#include<stdio.h>
#include "hash_table.h"

int main()
        {
        int ret = 0, i = 0;

        int key6 = 6;
        char * value6 = "six";

        int key5 = 5;
        char * value5 = "five";

        hash_table_t *my_hash_table = NULL;
        ret = hash_table_construct(&my_hash_table, 10);
        printf("Construct: ret = %d\n", ret);

        HASH_TABLE_ADD(my_hash_table, &key6, &value6);
        HASH_TABLE_ADD(my_hash_table, &key5, &value5);
        HASH_TABLE_ADD(my_hash_table, &key5, &value5);
        HASH_TABLE_ADD(my_hash_table, &key6, &value6);
        HASH_TABLE_ADD(my_hash_table, &key6, &value6);

        hash_table_print(my_hash_table);

        ret = hash_table_destruct(&my_hash_table);
        printf("Destruct: ret = %d\n", ret);

        return 0;
        }