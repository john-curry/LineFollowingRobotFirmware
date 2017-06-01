#include "ai.h"

State * get_Next_States() {
  // TODO: implement all states
  return NULL;
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

void execute_State(State current_state) {
  /* TODO: implement functionality */

  switch (current_state.uuid) {
    default:
      break;
  }
}
