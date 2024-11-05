#include "kvs.h"


kvs_t* open()
{
	kvs_t* kvs = (kvs_t*)malloc(sizeof(kvs_t));
	kvs->header = (node_t*)malloc(sizeof(node_t));
	kvs->header->forward = (node_t**)malloc(sizeof(node_t*) * (MAX_LEVEL + 1));

	for (int i = 0; i <= MAX_LEVEL; i++) {
		kvs->header->forward[i] = NULL;
	}
	kvs->level = 0;
	kvs->items = 0;

	srand(time(NULL));
	return kvs;

}
