#include "maze.h"

void add_Node(Maze * maze, Node * n) {
  /* TODO: add a check to make sure node 
           isn't already in the maze
  */
  if (n->node_index < maze->num_nodes) return;

  int node = (maze->num_nodes++);
  maze->num_edges[node]++;
  maze->edge[node][maze->current_node] = true;
  maze->edge[maze->current_node][node] = true;
}

void init_Maze(Maze * maze) {
  maze->num_nodes = 0;
  for (int i = 0; i < MAX_NODES; i++) {
    maze->num_edges[i] = 0;
  }
  for (int i = 0; i < MAX_NODES; i++) {
    for (int j = 0; j < MAX_NODES; j++) {
      maze->edge[i][j] = false;
    }
  }
}
