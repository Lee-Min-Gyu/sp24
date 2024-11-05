#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEVEL 6

struct node {
	char key[100];
	char* value;
	struct node** forward;
	int level;
};	
typedef struct node node_t;


struct kvs{
	node_t* header; // database
	int level;// number of data
	int items; 
};
typedef struct kvs kvs_t; 


kvs_t* open();
int close(kvs_t* kvs); // free all memory space 
int put(kvs_t* kvs, const char* key, const char* value); // return -1 if failed.
char* get(kvs_t* kvs, const char* key); // return NULL if not found. 

