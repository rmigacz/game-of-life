#include "gamefunc.h"

#define STEPS 10000000

int main(int argc, char **argv) {
    if (argc != 3) {
    	printf("Usage: ./game-of-life file_name map_size\n");
    	return 1;
    }

    char *file_name = argv[1];
    int map_size = atoi(argv[2]);

    int **map = init_map(file_name, map_size);

    if (map == NULL) {
	return 2;
    }

    print_map(map, map_size);
    
    int i = 0;
    struct timespec reqtime;
    reqtime.tv_sec = 0;
    reqtime.tv_nsec = 25000000;

    while (i < STEPS) {
	    iterate(map, map_size);
	    nanosleep(&reqtime, NULL);
	    print_map(map, map_size);
	    i++;
    }

   free_map(map, map_size);
    return 0;
}
