#include "invertedIndex.h"

int update_DB(file_node_t **file_Head,file_node_t *file1_head,table hash_table[], main_node_t **main_head)
{
    //validation of update database files
    file_node_t *temp = file1_head;
    while(temp != NULL)
    {
        //validate if it is a backup file or not
        FILE *fp = fopen(temp->f_name,"r");
        if(fp == NULL)
        {
            printf("ERROR : %s FILE NOT FOUND\n",temp->f_name);
            temp = temp->link;
            continue;
        }
        fseek(fp,0,SEEK_SET);
        if(fgetc(fp) != '#')
        {
            printf("ERROR : %s IS NOT A BACKUP FILE\n",temp->f_name);
            temp = temp->link;
            continue;
        }
        fseek(fp,-2,SEEK_END);
        if(fgetc(fp) != '#')
        {
            printf("ERROR : %s IS NOT A BACKUP FILE\n",temp->f_name);
            temp = temp->link;
            continue;
        }
        fclose(fp);
        temp = temp->link;
    }
    printf("DONE : VALIDATION OF BACKUP FILES\n");
    //update the database
    temp = file1_head;
    FILE *fp = fopen(temp->f_name,"r");
    if(fp == NULL)
    {
        printf("ERROR : %s FILE NOT FOUND\n",temp->f_name);
        return FAILURE;
    }
    char buff[BUFF_SIZE];
    //printf("DONE : OPENING FILE\n");
    while(fgets(buff,BUFF_SIZE,fp) != NULL)
    {
        //buff[strcspn(buff, "\n")] = '\0';
        //remove the newline character
        buff[strlen(buff)-1] = '\0';
        char *token = strtok(buff+1,";");

        //exact word
        char word[NAMELENGTH];
        strcpy(word,token);

        //exact f_count
        token = strtok(NULL,";");
        int f_count = atoi(token);
        //insert hash table
        int index = word[0] - 'a';
        if(index < 0 || index > 25)
        {
            index = 26;
        }
        //printf("DONE : INSERTING WORD : %s\n",word);
        main_node_t *new = malloc(sizeof(main_node_t));
        if(new == NULL)
        {
            return FAILURE;
        }
        strcpy(new->word,word);
        new->f_count = f_count;
        new->link = NULL;
        new->sub_link = NULL;
        if(hash_table[index].link == NULL)
        {
            hash_table[index].link = new;
        }
        else
        {
            main_node_t *temp = hash_table[index].link;
            while(temp->link != NULL)
            {
                temp = temp->link;
                //update the sub node
            }
            temp->link = new;
        }
        //update the sub node
        while((token = strtok(NULL, ";")) != NULL)
        {
            file_node_t *dup = *file_Head;
            while(dup != NULL)
            {
                if(strcmp(dup->f_name,token) == 0)
                {
                    
                    printf("ERROR : %s FILE ALREADY PRESENT\n",token);
                    //remove the file from the list
                    if(*file_Head == dup)
                    {
                        *file_Head = dup->link;
                        free(dup);
                    }
                    else{
                        file_node_t *temp = *file_Head;
                        while(temp->link != dup)
                        {
                            temp = temp->link;
                        }
                        temp->link = dup->link;
                        free(dup); 
                    } 
                }
                dup = dup->link;
            }
            sub_node_t *new_sub = malloc(sizeof(sub_node_t));
            if(new_sub == NULL)
            {
                return FAILURE;
            }
            //check if the file is already present
            
            strcpy(new_sub->f_name,token);
            token = strtok(NULL,";");
            new_sub->w_count = atoi(token);
            new_sub->link = NULL;
            if(new->sub_link == NULL)
            {
                new->sub_link = new_sub;
            }
            else
            {
                //printf("DONE : INSERTING SUBNODE : %s\n",new_sub->f_name);
                //travel to the last node
                sub_node_t *temp = new->sub_link;
                while(temp->link != NULL)
                {
                    temp = temp->link;
                }
                temp->link = new_sub;
            }
        }
    }
    return SUCCESS;
}