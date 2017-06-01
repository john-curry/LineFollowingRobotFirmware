#include "ai.h"
#include "robot_logic.h"
#include "states.h"
#include <string.h>
/* private method */
bool is_State(char * state_name, State * cs) {
  if (strcmp(state_name, cs->state_name) == 0) return true;
  return false;
}

void populate_States(State * next_states) {
  // TODO: implement all states
}

Input read_Inputs() {
  Input in;
  // TODO: implement reading form IR sensors and populating input ob
  return in;
}

State eval(State * next_states, State * current, Input * in) {
  // TODO: Figure out algorithm to use to pick the next state
  //       ie something something like DFS or BFS would be a 
  //       decent choice for solving this maze.
  State s;
  return s;
}

void execute_State(Robot * robot, State * current_state) {
  /* TODO: implement functionality */
  /* 
    This is just an idea of how this method should work.
    When a new state is added, a new if statement should also
    be added. There are more elegent ways to do this, but
    they are usually more complicated and error prone.
  */
  if (is_State("move_forward", current_state)) {
    move_Forward(robot, current_state);
  }
  else if (is_State("stop", current_state)) {
    stop_Robot(robot, current_state);
  }
  else {
    /* This else block should be unreachable */
    /* TODO: implement some sort of error reporting */
  }
}

