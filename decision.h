#ifndef DECISION_H
#define DECISION_H
#include "decision.h"
#include "robot.h"
#include "maze.h"
#include "config.h"

#define MAX_DECISIONS 5

typedef struct _decision {
  char * name; 
  uint8_t opcode;
} Decision;

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
  },
  {
    .name = "none",
    .opcode = NONE,
  }
};
#endif

