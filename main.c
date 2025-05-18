#include "invertedIndex.h"
int flag = 0;

int main (int argc,char *argv[])
{
    //validate the files
     //file linked list
     file_node_t *file_head = NULL;
     //validation
      validate_n_store_filenames(&file_head,argv,argc);
      printf("DONE : VALIDATION\n");
    //create hash table
    table *hash_table = (table *)malloc(sizeof(table)*SIZE);
    if(hash_table == NULL)
    {
        printf("ERROR:MEMORY ALLOCATION FAILED\n");
        exit(1);
    }
    for(int i = 0; i < SIZE; i++)
    {
        hash_table[i].index = i;
        hash_table[i].link = NULL;
    }
    while(1)
    {
        printf("1. Create Database\n2. Display Database\n3. Search Database\n4. Save Database\n5. Update Database\n6. Exit\n");
        int choice;
        printf("Enter your choice : ");
        if (scanf("%d", &choice) != 1)  // Check if input is a valid integer
        {
            printf("ERROR: Invalid input! Please enter a number.\n");

            while (getchar() != '\n');  // Discard invalid input
            continue;  // Restart loop
        }
        switch(choice)
        {
            case 1:
                main_node_t *main_head = NULL;
                if(create_DB(file_head,hash_table,&main_head) == FAILURE)
                {
                    printf("ERROR:DATABASE CREATION FAILED\n");
                    break;
                }
                flag = 1;
                printf("DONE : DATABASE CREATION\n");
                break;
            case 2:
                if(display_DB(hash_table) == FAILURE)
                {
                    printf("ERROR:DISPLAY FAILED\n");
                    exit(1);
                }
                break;
            case 3:
                char search[BUFF_SIZE];
                printf("Enter the word : ");
                scanf("%s",search);
                if(search_DB(hash_table,search) == FAILURE)
                {
                    printf("ERROR:SEARCH FAILED\n");
                    exit(1);
                }
                break;
            case 4:
                char fname[BUFF_SIZE];
                printf("Enter the filename : ");
                scanf("%s",fname);
                if(save_DB(hash_table,fname) == FAILURE)
                {
                    printf("ERROR:SAVE FAILED\n");
                    exit(1);
                }
                printf("DONE : DATABASE SAVED\n");
                break;
            case 5:
                if(flag == 1)
                {
                    printf("ERROR : UPDATE FAILED !. DATABASE IS ALREADY CREATED. \n");
                    exit(1);
                }
                //take input of backup files
                printf("Enter the backup files : ");
                char backup[BUFF_SIZE];
                scanf("%s",backup);
                file_node_t *backup_head = NULL;
                //validation
                validate_update_n_store(&backup_head,backup,3);
                //print the backup files
                file_node_t *temp = backup_head;
                while(temp != NULL)
                {
                    printf("%s\n",temp->f_name);
                    temp = temp->link;
                }
                if(update_DB(&file_head,backup_head,hash_table,&main_head) == FAILURE)
                {
                    printf("ERROR:UPDATE FAILED\n");
                    exit(1);
                }
                break;
            case 6:
                exit(0);
                break;    
            default:
                printf("INVALID CHOICE\n");
                break;
        }
    }
    
}
    