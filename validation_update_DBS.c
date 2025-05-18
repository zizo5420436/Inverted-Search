#include "invertedIndex.h"
void validate_update_n_store(file_node_t **Head, char *filenames,int argc)
{
    if(argc < 2)
    {
        printf("ERROR:NO ENOUGH FILES AVAIL \n");
        exit(1);
    }
    //Extension Validation 
    for(int i = 1; i<argc ;i++)
    {
        //check if the file is valid
        if(IsFileValid_update(filenames) == FAILURE)
        {
            printf("WARNING : %s is NOT A TEXT FILE\n",filenames);
            continue;
        }
        //check if the file exists
        FILE*fp;
        if((fp=fopen(filenames,"r")) == NULL)
        {
            printf("WARNING : %s FILE NOT FOUND\n",filenames);
            continue;
        }
        //check if the file is empty or not
        fseek(fp,0,SEEK_END);
        if(ftell(fp) == 0)
        {
            printf("WARNING : %s FILE IS EMPTY\n",filenames);
            continue;
        }
        fclose(fp);
        //insert the file to the list and find  the duplicates
        int status = store_filenames_to_list_update(filenames,Head);
        if(status == REPEATED)
        {
            printf("WARNING : %s DUPLICATES PRESENT\n",filenames);
            continue;
        }
        else if(status == FAILURE)
        {
            printf("ERROR:MEMORY ALLOCATION FAILED\n");
            exit(1);
        }
    }
}
int IsFileValid_update(char *name)
{
    //extension validation
    char *dot = strstr(name,".");
    if(dot != NULL)
    {
        if(strcmp(dot,".txt") != 0)
        {
            return FAILURE;
        } 
        return SUCCESS;
    }
}
//store filenames to list
int store_filenames_to_list_update(char *f_name, file_node_t **head)
{
    //check if the file is already present
    file_node_t *dup = *head;
    while(dup != NULL)
    {
        if(strcmp(dup->f_name,f_name) == 0)
        {
            return REPEATED;
        }
        dup = dup->link;
    }

    file_node_t *temp = *head;
    file_node_t *new = malloc(sizeof(file_node_t));
    if(new == NULL)
    {
        return FAILURE;
    }
    strcpy(new->f_name,f_name);
    new->link = NULL;
    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}

