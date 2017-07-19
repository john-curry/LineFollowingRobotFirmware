#ifndef STATES_H
#define STATES_H
#include "state.h"

#define MAX_STATES 10 /* For the love of all that is holy change this!! */ 
/* 
  This structure defines all the possible states that
  the robot can execute. If new functionality is added,
  then this structure should be updated as well as the 
  execute_State method in the ai.c file and a method
  added to the robot_logic.(c/h) source file.
*/
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
  }
};
#endif
