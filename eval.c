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
  if (is_Goal(in)) {
    set_State("robot_stop", current);
  } else if (on_Center_Line(in)) {
    set_State("move_forward", current);
  } else if (line_Right(in)) {
    set_State("turn_right", current);
  } else if (line_Left(in)) {
    set_State("turn_left", current);
  } else {
    set_State("turn_right", current);
  }
  return false;
#endif 
}
