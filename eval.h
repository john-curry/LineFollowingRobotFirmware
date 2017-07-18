#ifndef EVAL_H
#define EVAL_H
#include "state.h"
#include "input.h"
#include "maze.h"
/* 
  Method that takes the input, current_state and all the 
  next possible states and returns the next state that 
  the robot should take. 
  Note: next_states is many states and method returns one state.
*/
bool eval(State * current, Input * in, Maze * maze);
#endif
