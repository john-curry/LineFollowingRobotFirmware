#include "maze.h"

void add_Node(Maze * maze, int direction) {
  maze->num_nodes++;
  int node = maze->num_nodes;
  maze->edge[node][direction] = true;
}

void init_Maze(Maze * maze) {
  maze->num_nodes = 0;
  maze->current_node = 0;
  maze->last_node = -1;
  for (int i = 0; i < MAX_NODES; i++) {
    maze->visited[i] = false;
  }
  for (int i = 0; i < MAX_NODES; i++) {
    for (int j = 0; j < MAX_NODES; j++) {
      maze->edge[i][j] = false;
    }
  }
}

bool visited(Maze * maze, int node) {
  return maze->visited[node];
}

void visit_Node(Maze * maze, int node) {
  maze->visited[node] = true;
}
