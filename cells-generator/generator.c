#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define DEFAULT_FILE_NAME "cells"

int main(int argc, char **argv) {
    if (argc < 2 || argc > 4) {
	printf("Usage: ./cells-generator number-of-cells [file-name]\n");
	return 1;
    }
    
    int cells_numb = atoi(argv[1]);
    char *file_name;
    FILE *fp;
    
    if (argc == 2) {
	file_name = DEFAULT_FILE_NAME;
    } else {
	file_name = argv[2];
    }
    
    fp = fopen(file_name,"w");

    if (fp == NULL) {
	fclose(fp);
	fprintf(stderr, "Could not create %s.\n", file_name);
	return 2;
    }
    
    srand(time(NULL));

    for (int i = 0; i < cells_numb; i++) {
	for (int j = 0; j < cells_numb; j++) {
	    fprintf(fp, "%d ", rand() % 2);
	}
	fprintf(fp, "\n");
    }

    fclose(fp);

    return 0;
}
