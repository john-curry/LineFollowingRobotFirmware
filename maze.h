#ifndef MAZE_H
#define MAZE_H
#include <stdint.h>
#include <stdbool.h>
/* assume there is going to be less than 32 paths at every node */
#define MAX_EDGES 4

/* assume there is going to be less than 32 nodes in the maze */
#define MAX_NODES 32
/* 
  Struct to define what the robot knows about the maze so far.
  When the robot gets to a node, it should add it to the 
  node array at the node_index and it should update the nodes that
  are next to the node that it just found.
  This is probably so overkill it's my favorite thing.
*/
typedef struct _maze {
  int current_node;
  int last_node;
  int num_nodes;
  /*       -the node---its edges- */
  /* edge index is a direction
     0 => Forward
     1 => Right
     2 => Left
     3 => Back
  */
  bool edge[MAX_NODES][MAX_EDGES];
  bool visited[MAX_NODES];
} Maze;

void init_Maze(Maze * maze);

/*
  Adds a new node to the maze. 
  Input: the current maze and the new_node to be added.
*/
void add_Node(Maze * maze, int node);

void visit_Node(Maze * maze, int node);

#endif
