#include "invertedIndex.h"

//Display Database
int display_DB(table hash_table[])
{
    
    printf("\n========================= DATABASE CONTENTS ==========================\n");
    printf("\n");
    int flag = 0;
    for(int i = 0 ; i < SIZE ; i++)
    {
        main_node_t *temp = hash_table[i].link;
        while(temp != NULL)
        {
            flag = 1;
            printf("[%d] - %-15s | Found in %d file(s) ", i,temp->word, temp->f_count);
            sub_node_t *sub_temp = temp->sub_link;
            while(sub_temp != NULL)
            {
                printf(" | File: %-8s | Count: %-3d", sub_temp->f_name, sub_temp->w_count);
                sub_temp = sub_temp->link;
            }
            printf("\n------------------------------------------------------------------------\n");
            temp = temp->link;

        }
    }
    if(flag == 0)
    {
        printf("🚨 Database is empty! No words stored.\n");
        return EMPTYLIST;
    }
    //printf("===============================================\n");
    return SUCCESS;
}