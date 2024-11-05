#include "kvs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* get(kvs_t* kvs, const char* key)
{
	node_t* current =kvs->header;
	
	for (int i = kvs->level; i >= 0; i--) {
		while (current->forward[i] && strcmp(current->forward[i]->key, key) < 0) {
			current = current->forward[i];
		}
	}
	current = current->forward[0];

	if(current && strcmp(current->key, key) == 0 ) {
		return strdup(current->value);
	}
	return NULL;
}
