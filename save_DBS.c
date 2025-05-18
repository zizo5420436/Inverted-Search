#include "invertedIndex.h"

int save_DB(table hash_table[], char *fname)
{
    //printf("Saving the database to %s\n", fname);
    FILE *fptr;
    if ((fptr = fopen(fname, "r")) != NULL)
    {
        printf("INFO : FILE EXIST ! Do you need to overwite Y/N . ");
        char ch;
        scanf(" %s",&ch);
        if(ch != 'Y')
        {
            return FAILURE;
        }
    }
    {

    }
    FILE *fp = fopen(fname, "w+");
    if (fp == NULL)
    {
        //printf("ERROR: FILE NOT FOUND\n");
        return FAILURE;
    }
    //printf("opened file\n");
    for (int i = 0; i < SIZE; i++)
    {
        main_node_t *temp = hash_table[i].link;
        if(temp != NULL)
        {
            while (temp != NULL)
            {
                fprintf(fp, "#");
                fprintf(fp,"%s;%d", temp->word, temp->f_count);
                sub_node_t *sub_temp = temp->sub_link;
                while (sub_temp != NULL)
                {
                    fprintf(fp,";%s;%d", sub_temp->f_name, sub_temp->w_count);
                    sub_temp = sub_temp->link;
                }
                temp = temp->link;
                fprintf(fp, "#\n");
            }
        }
    }
    fclose(fp);
    return SUCCESS;

}