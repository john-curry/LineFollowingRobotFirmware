#ifndef STATES_H
#define STATES_H

#include "ai.h"

#define MAX_STATES 32
/* 
  This structure defines all the possible states that
  the robot can execute. If new functionality is added,
  then this structure should be updated as well as the 
  execute_State method in the ai.c file and a method
  added to the robot_logic.(c/h) source file.
*/
static State STATES[MAX_STATES] = {
  {
    .state_name = "move_forward"
  },
  {
    .state_name = "stop"
  }
};
#endif
