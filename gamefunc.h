#ifndef GAMEFUNC_H
#define GAMEFUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int** init_map(char* filename, int map_size);
void free_map(int** map, int map_size);
void print_map(int** map, int map_size);
void iterate(int** map, int map_size);

#endif
