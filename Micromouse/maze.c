#ifdef MAP_C
#define MAP_C

#include "maze.h"

uint8_t maze[mapsize][mapsize];
int destination_x = map_center;
int destination_y = map_center+1;
int current_x;
int current_y;
current_x = 0;
current_y = 0;

int M_distance(){
  int temp;
  temp = abs(destination_x - current_x) + abs(destination_y - current_y);
  return temp;
}



#endif
