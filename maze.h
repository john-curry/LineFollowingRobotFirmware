#ifndef MAZE_H
#define MAZE_H
#include <stdint.h>
#include <stdbool.h>
#include "direction.h"
#include "robot.h"
#define MN 4 

typedef struct maze { } Maze;
static int nn = 0;
static int count = 0;
static int cn = 0;

static int graph[][4] = {
  /* North, south, east, west */
  { -1 , -1 , -1 , -1 },
  { -1 , -1 , -1 , -1 },
  { -1 , -1 , -1 , -1 },
  { -1 , -1 , -1 , -1 },
  { -1 , -1 , -1 , -1 }
};
static bool visited[MN] = {
    true,
    false,
    false,
    false
};
void add_Node(Robot * r, int t);

void mark_visited();
#endif
