#include<stdio.h>
#include "hash_table.h"

int main()
        {
        int ret = 0, i = 0;

        hash_table_t *my_hash_table = NULL;
        ret = hash_table_construct(&my_hash_table, 1024);
        printf("Construct: ret = %d\n", ret);

        ret = hash_table_destruct(&my_hash_table);
        printf("Construct: ret = %d\n", ret);

        return 0;
        }