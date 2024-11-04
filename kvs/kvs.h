#ifndef KVS_H
#define KVS_H


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_KEY_SIZE 100
#define MAX_LEVEL 10

struct node {
	char key[MAX_KEY_SIZE];
	char* value;
	struct node* next;
};	
typedef struct node node_t;


struct kvs{
	node_t* db; // database
	int level;// number of data
	int items; 
};
typedef struct kvs kvs_t; 


kvs_t* open();
int close(kvs_t* kvs); // free all memory space 
int put(kvs_t* kvs, const char* key, const char* value); // return -1 if failed.
char* get(kvs_t* kvs, const char* key); // return NULL if not found. 
#endif

