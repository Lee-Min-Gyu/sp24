#include "kvs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LEVEL 10
#define PROBABILITY 0.5


int put(kvs_t* kvs, const char* key, const char* value) {

	node_t* new_node = (node_t*)malloc(sizeof(node_t));
	if(!new_node){
		return -1;
	}

	strcpy(new_node->key,key);
	new_node->value = strdup(value);
	new_node->next = kvs->db;
	kvs->db = new_node;
	kvs->items++;
	return 0;
}



/*
int random_level() {
	int level =0;
	while ((rand() % 2) && (level < MAX_LEVEL)) {
		level++;
	}
	return level;
}

int put(kvs_t* kvs, const char* key, const char* value){
	node_t* update[MAX_LEVEL];
	node_t* current = kvs->head;
	

	for (int i = kvs -> level; i >= 0; i--){
		while (current ->next[i] && strcmp(current->next[i] ->key, key) <0) {
			current = current ->next[i];
	}
		update[i] = current;
	}
	current = current ->next[0];

	if (current && strcmp(current->key, key) == 0) {
		free(current->value);
		current->value = strdup(value);
		return 0;
	}

	int new_level = random_level();
	if (new_level > kvs->level) {
		for ( int i = kvs->level + 1; i <= new_level; i++) {
			update[i] = kvs->head;
		}
		kvs->level = new_level;
	}
	node_t* new_node = (node_t*)malloc(sizeof(node_t));
	strcpy(new_node->key, key);
	new_node -> value = strdup(value);
	new_node->next = (node_t**)malloc((new_level +1) * sizeof(node_t));
	
	for (int i =0; i <= new_level; i++) {
		new_node->next[i] = update[i] -> next[i];
		update[i]->next[i] = new_node;
	}
	kvs->items++;
	return 0;
	
	//printf("put: %s, %s\n", key, value);

	 do program here 
	//return 0;
}*/
