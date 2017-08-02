#include "maze.h"
#include "config.h"
void add_Node(Robot * r, int t) {
  nn++;
  graph[nn][change_Direction(r->facing, t)] = nn-1;
  graph[nn -1][opposite_Direction(change_Direction(r->facing, t))] = nn;
}
