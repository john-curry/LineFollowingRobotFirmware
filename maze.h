#ifndef MAZE_H
#define MAZE_H
#include <stdint.h>
#include <stdbool.h>
#include "direction.h"
#include "robot.h"
/* assume there is going to be less than 32 paths at every node */
#define MAX_EDGES 4

/* assume there is going to be less than 32 nodes in the maze */
#define MAX_NODES 32

typedef struct _maze {
  int last_node;
  int current_node; 
  int num_nodes;
  bool visited[MAX_NODES];
  int  edges[MAX_NODES][MAX_EDGES];
} Maze;

void init_Maze(Maze * maze);

/*
  Adds a new node to the maze. 
  Input: the current maze and the new_node to be added.
*/
void add_Node(Maze * maze, int from, int dir);

void visit_Node(Maze * maze, Direction*, int node);

bool visited(Maze * m, int n);

bool is_Edge(Maze * m, int n, int dir);
#endif
