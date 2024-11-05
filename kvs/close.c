#include "kvs.h"

int close(kvs_t* kvs)
{
	node_t* current = kvs->header->forward[0];
	node_t* next;

	while( current !=NULL){
		next =current->forward[0];
		free(current->value);
		free(current->forward);
		free(current);
		current = next;
	}
	free(kvs->header->forward);
	free(kvs->header);
	free (kvs);
	/* do program */
	return 0;
}
