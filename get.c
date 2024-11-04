#include "kvs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* get(kvs_t* kvs, const char* key)
{
	node_t* current =kvs->db;

	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			return strdup(current->value);
		}
		current = current-> next;
	}
	return NULL;
}


/*	node_t* current = kvs->head;

	for (int i= kvs->level; i>= 0; i--){
		while(current->next[i] && strcmp(current->next[i]->key, key) <0 ) {
			current = current->next[i];
		}
	}
	current =current->next[0];

	if (current && strcmp(current->key, key) == 0) {
		return strdup(current->value);
	}
	return NULL;
}
	 do program here 

	char* value = (char*)malloc(sizeof(char)*100);

	if(!value){
		printf("Failed to malloc\n");
		return NULL;
	}

	strcpy(value, "deadbeaf");
	return value;

}*/
