#include "kvs.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	kvs_t* kvs = open();
	if(!kvs) {
		fprintf(stderr, "Failed to open kvs\n");
		return -1;
	}
	FILE* file = fopen("query.dat","r");
	if(!file) {
		fprintf(stderr, "Failed to open query.dat\n");
		close(kvs);
		return -1;
	}

	FILE* answer_file = fopen("answer.dat", "w");
	if(!answer_file) {
		fprintf(stderr, "Failed to create answer.dat\n");
		fclose(file);
		close(kvs);
		return -1;
	}
	char operation[10], key[100], value[100];

	while(fscanf(file, "%[^,],%[^,],%s\n", operation, key, value) !=EOF) {
		if(strcmp(operation, "set") == 0) {
			put(kvs, key, value);
		} else if(strcmp(operation, "get") == 0) {
			char* result = get(kvs, key);
			if (result) {
				fprintf(answer_file, "%s\n", result);
				free(result);
			} else{
				fprintf(answer_file, "-1\n");
			}
		}
	}
	fclose(file);
	fclose(answer_file);
	close(kvs);
	return 0;
}

