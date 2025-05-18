#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include "colors.h"

#define SUCCESS 0
#define FAILURE -1
#define NOELEMENT -2
#define EMPTYLIST -3
#define REPEATED -4
#define FILE_EMPTY -5
#define NOT_PRESENT -6

#define SIZE 27
#define BUFF_SIZE 255
#define NAMELENGTH 20
//inverted table

/* subnode structue */
typedef struct sub_node
{
	char f_name[NAMELENGTH];
	int w_count;
	struct sub_node *link;

}sub_node_t;

/* main node structure*/
typedef struct node
{
	char word[NAMELENGTH];
	struct node *link;
	sub_node_t *sub_link;
	int f_count;

}main_node_t;

/* file node structure (Lineked list used to store the filenames */
typedef struct file_node
{
    char f_name[NAMELENGTH];
    struct file_node *link;
}file_node_t;

typedef struct Table
{
	int index;
	main_node_t*link;
}table;


/* validating files */
void validate_n_store_filenames(file_node_t **, char *filenames[],int argc);
int IsFileValid(char *);
int store_filenames_to_list(char *f_name, file_node_t **head);

/* Create Database */
int create_DB(file_node_t *file_head,table hash_table[], main_node_t **head);
int read_datafile(main_node_t **,table hash_table[], char *f_name);
int insert_at_last_main(table hash_table[],main_node_t **head, char *word, char *f_name);
int update_sub_node(main_node_t **main_node, char *f_name);
int update_word_count(main_node_t **head, char *fname);

/* Display database */
int display_DB(table hash_table[]);

/* Update database */
int update_DB(file_node_t **file_Head,file_node_t *file1_head,table hash_table[], main_node_t **head);
void validate_update_n_store(file_node_t **Head, char *filenames,int argc);
int store_filenames_to_list_update(char *f_name, file_node_t **head);
int IsFileValid_update(char *name);
/* Search Database */
int search_DB(table hash_table[], char *word);

/* Save Database */
int save_DB(table hash_table[], char *fname);
