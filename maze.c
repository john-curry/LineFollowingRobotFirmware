#include "maze.h"
#include "config.h"
void add_Edge(Maze * m, int from, int to, int dir) {
  m->edges[from][dir] = to;
  m->edges[to][(dir + 2) % 4] = from;
}

void add_Node(Maze * maze, int from, int dir) {
  maze->num_nodes++;
  add_Edge(maze, from, maze->num_nodes, dir);
}

void init_Maze(Maze * maze) {
  maze->num_nodes = 0;
  maze->current_node = 0;
  for (int i = 0; i < MAX_NODES; i++) {
    maze->visited[i] = false;
  }
  for (int i = 0; i < MAX_NODES; i++) {
    for (int j = 0; j < MAX_NODES; j++) {
      maze->edges[i][j] = -1;
    }
  }
}

bool visited(Maze * m, int n) {
  return m->visited[n];
}


bool is_Edge(Maze * m, int n, int dir) {
  return (m->edges[n][dir] != -1);
}

void visit_Node(Maze * maze, Directions * d, int node) {
  maze->visited[maze->current_node] = true;
  for (int i = 0; i < 4; i++) {
    if (d->dirs[i]) {
      add_Node(maze, node, i);
    }
  }
}
