#include "invertedIndex.h"

//create database
int create_DB(file_node_t *file_head,table hash_table[], main_node_t **head)
{
    file_node_t *temp = file_head;
    while(temp != NULL)
    {
        if(read_datafile(head,hash_table,temp->f_name) == FAILURE)
        {
            printf("ERROR:READING FILE FAILED\n");
            return FAILURE;
        }
        temp = temp->link;
    }
    return SUCCESS;
}
//read datafile
int read_datafile(main_node_t **head,table hash_table[], char *f_name)
{
    FILE *fp = fopen(f_name,"r");
    if(fp == NULL)
    {
        return FAILURE;
    }
    char buff[BUFF_SIZE];
    while(fscanf(fp,"%s",buff)!=EOF)
    {
        //convert to lower case
        for(int i = 0; i < strlen(buff); i++)
        {
            buff[i] = tolower(buff[i]);
        }
        //insert at last in main node
        if(insert_at_last_main(hash_table,head,buff,f_name) == FAILURE)
        {
            printf("ERROR:INSERTION FAILED\n");
            return FAILURE;
        }
    }
    return SUCCESS;

}
//insert at last in main node
int insert_at_last_main(table hash_table[],main_node_t **head, char *word, char *f_name)
{
    //find the index
    int index = word[0] - 'a';
    if(index < 0 || index  > 25)
    {
        index = 26;
    }
    //check if the word is already present
    main_node_t *temp = hash_table[index].link;
    while(temp != NULL)
    {
        if(strcmp(temp->word,word) == 0)
        {
            //temp->f_count++;
            return update_sub_node(&temp, f_name);
        }
        temp = temp->link;
    }
    //insert at last
    main_node_t *new = malloc(sizeof(main_node_t));
    if(new == NULL)
    {
        return FAILURE;
    }
    strcpy(new->word,word);
    new->link = NULL;
    new->sub_link = NULL;
    new->f_count = 1;
    //update the word count

    //insert at last
    if(hash_table[index].link == NULL)
    {
        hash_table[index].link = new;
        
    }
    else
    {
        temp = hash_table[index].link;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
    return update_sub_node(&new, f_name);
}
int update_sub_node(main_node_t **main_node, char *f_name)
{
    //update the sub node
    sub_node_t *temp = (*main_node)->sub_link;
    while(temp != NULL)
    {
        if(strcmp(temp->f_name,f_name) == 0)
        {
            temp->w_count++;
            return SUCCESS;
        }
        temp = temp->link;
    }
    //insert at last
    sub_node_t *new = malloc(sizeof(sub_node_t));
    if(new == NULL)
    {
        return FAILURE;
    }
    strcpy(new->f_name,f_name);
    new->w_count = 1;
    new->link = NULL;
    if((*main_node)->sub_link == NULL)
    {
        (*main_node)->sub_link = new;
        return SUCCESS;
    }
    else
    {
        temp = (*main_node)->sub_link;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
        (*main_node)->f_count++;
        return SUCCESS;
    }
    return SUCCESS;
}