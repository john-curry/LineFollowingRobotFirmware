#ifndef STATES_H
#define STATES_H
#include "state.h"

#define MAX_STATES 13 /* For the love of all that is holy change this!! */ 

static State STATES[MAX_STATES] = {
  {
    .state_name = "move_forward",
    .opcode = 0,
  },
  {
    .state_name = "turn_right",
    .opcode = 1
  },
  {
    .state_name = "turn_left",
    .opcode = 2
  },
  {
    .state_name = "reverse_robot",
    .opcode = 3
  },
  {
    .state_name = "delay_robot",
    .opcode = 4
  },
  {
    .state_name = "stop_robot",
    .opcode = 5
  },
  {
    .state_name = "goal",
    .opcode = 6
  },
  {
    .state_name = "reverse_right",
    .opcode = 7
  },
  {
    .state_name = "reverse_left",
    .opcode = 8
  },
  {
    .state_name = "start",
    .opcode = 9
  },
  {
    .state_name = "correct_left",
    .opcode = 10
  },
  {
    .state_name = "correct_right",
    .opcode = 11
  },
  {
    .state_name = "turn_around",
    .opcode = 12 
  }
};
#endif
