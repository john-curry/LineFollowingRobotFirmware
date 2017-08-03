#ifndef MAZE_H
#define MAZE_H
#include <stdint.h>
#include <stdbool.h>
#include "direction.h"
#include "robot.h"
#define MN 4 
typedef struct maze {} Maze;
static int number_nodes = 1;
static int graph[][2] = {
  { -1 , -1 },
  { -1 , -1 },
  { -1 , -1 },
  { -1 , -1 },
  { -1 , -1 },
  { -1 , -1 },
  { -1 , -1 },
  { -1 , -1 },
  { -1 , -1 },
  { -1 , -1 },
  { -1 , -1 }
};

//void add_Edge(int from, int to) {
//}  
#endif
