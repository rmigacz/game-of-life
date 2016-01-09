#include "gamefunc.h"

// load data from the file into the array
int** init_map(char *filename, int map_size) {
    FILE *inptr = fopen(filename, "r");

    if (inptr == NULL) {
	printf("Could not open %s. \n", filename);
	return NULL;
    }

    int **map = (int **)malloc(map_size * sizeof(int *));

    for (int row = 0; row < map_size; row++) {
	map[row] = (int *)malloc(map_size * sizeof(int));
    }

    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
	    fscanf(inptr, "%d", &map[i][j]);
	}
    }
    
    fclose(inptr);
    
    return map;
}

// free memory allocated for the map
void free_map(int **map, int map_size) {
    // free each row
    for (int row = 0; row < map_size; row++) {
    	free(map[row]);
    }
    // free the memory of the pointers to the rows
    free(map);
}

// print map
void print_map(int **map, int map_size) {
    system("clear");

    for (int row = 0; row < map_size; row++) { 
	for (int col = 0; col < map_size; col++) {
		if (map[row][col]) {
			printf("*");
        	} else {
        		printf(" ");
       		}
    	}
	printf("\n");
    }
}

// change all states in map
void iterate(int** map, int map_size) {
    int result_map [map_size][map_size];
    int alive_neighbours = 0;
    int row, col;

    int row_minus = 0;
    int row_plus = 0;
    int col_minus = 0;
    int col_plus = 0;

    for (row = 0; row < map_size; row++) {
    	for (col = 0; col < map_size; col++) {
        	result_map[row][col] = 0;
		
		if (row - 1 < 0) {
		    row_minus = map_size - 1;
		} else {
		    row_minus = row - 1;
		}
	
		if (row + 1 == map_size) {
		    row_plus = 0;
		} else {
		    row_plus = row + 1;
		}

		if (col - 1 < 0) {
		    col_minus = map_size - 1;
		} else {
		    col_minus = col - 1;
		}

		if (col + 1 == map_size) {
		    col_plus = 0;
		} else {
		    col_plus = col + 1;
		}

		if (map[row_minus][col]) 		alive_neighbours++;
		if (map[row_minus][col_plus])		alive_neighbours++;
		if (map[row][col_plus])			alive_neighbours++;
		if (map[row_plus][col_plus])		alive_neighbours++;
		if (map[row_plus][col])			alive_neighbours++;
		if (map[row_plus][col_minus])		alive_neighbours++;
		if (map[row][col_minus])		alive_neighbours++;
		if (map[row_minus][col_minus])		alive_neighbours++;
        
        
		if (alive_neighbours == 3) {
			result_map[row][col] = 1;
		} else if (alive_neighbours == 2 && map[row][col] == 1) {
			result_map[row][col] = 1;
		} else {
		    result_map[row][col] = 0;
		}

		alive_neighbours = 0;
	}
     }

     for (int row = 0; row < map_size; row++) {
	 for (int col = 0; col < map_size; col++) {
	     map[row][col] = result_map[row][col];
	 }
     }
}
