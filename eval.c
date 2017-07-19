#include "eval.h"
#include "debug.h"
#include "script.h"
#include "state.h"
#include "states.h"
#include "maze.h"
bool eval(State * current, Input * in, Maze * maze) {
  // TODO: Figure out algorithm to use to pick the next state
  //       ie something something like DFS or BFS would be a 
  //       decent choice for solving this maze.
#if DEBUG
  static int program_counter = 0;
  if (script[program_counter] != EOS) {
    *current = STATES[script[program_counter]];
    program_counter++;
  } else {
    program_counter = 0;
  }
  return false;
#else
  //set_State("move_forward", current);
  if (on_Line(in)) {
    *current = STATES[0]; // if center thing is back forward 
  } else {
    *current = STATES[5]; // else stop the robot
  }
  return false;
#endif 
}
