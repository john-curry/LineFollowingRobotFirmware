#ifndef DECISION_H
#define DECISION_H
#include "decision.h"
#include "direction.h"
#include "robot.h"
#include "maze.h"
#include "config.h"

#define MAX_DECISIONS 4

typedef struct _decision {
  char * name; 
  uint8_t opcode;
} Decision;

void make_Decision(Decision * decision, Directions * directions, Maze * maze, Robot * robot);

bool is_Decision(Decision * dec, int direction);

void set_Decision(Decision * dec, int direction);

static Decision DECISIONS[MAX_DECISIONS] = {
  {
    .name = "go_left",
    .opcode = LEFT,
  },
  {
    .name = "go_right",
    .opcode = RIGHT,
  },
  {
    .name = "go_back",
    .opcode = BACK,
  },
  {
    .name = "go_forward",
    .opcode = FORWARD,
  }
};
#endif

