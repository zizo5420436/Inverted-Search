#include "invertedIndex.h"
int search_DB(table hash_table[],char *word)
{
    //if the hash table is empty
    for (int i = 0; word[i]; i++) 
    {
        word[i] = tolower(word[i]);
    }
    int index = word[0] - 'a';
    if(index < 0 || index > 25)
    {
        index = 26;
    }
    main_node_t *temp = hash_table[index].link;
    while(temp != NULL)
    {
        if(strcmp(temp->word,word)==0)
        {
            printf("DONE : %s IS FOUNDED\n",word);
            return SUCCESS;
        }
        temp = temp->link;
    }
    printf("ERROR : %s NOT FOUND\n",word);
    return SUCCESS;
}

