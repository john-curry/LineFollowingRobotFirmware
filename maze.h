#ifndef MAZE_H
#define MAZE_H
#include <stdint.h>
#include <stdbool.h>
/* assume there is going to be less than 32 paths at every node */
#define MAX_EDGES 32

/* assume there is going to be less than 32 nodes in the maze */
#define MAX_NODES 32

/* 
  Struct for a node in the maze.
  Here a node is a split in the maze that gives multiple paths.
  Probably overkill but just in case.
*/
typedef struct _node {
  /* 
     Should be unique to the node. ie increment node_index for
     every node the robot encounters.
  */
  uint16_t node_index;
} Node;

/* 
  Struct to define what the robot knows about the maze so far.
  When the robot gets to a node, it should add it to the 
  node array at the node_index and it should update the nodes that
  are next to the node that it just found.
  This is probably so overkill it's my favorite thing.
*/
typedef struct _maze {
  int current_node;
  int num_nodes;
  int num_edges[MAX_NODES];
  bool edge[MAX_NODES][MAX_NODES];
} Maze;

void init_Maze(Maze * maze);

/*
  Adds a new node to the maze. 
  Input: the current maze and the new_node to be added.
*/
void add_Node(Maze * maze, Node * new_node);

#endif
