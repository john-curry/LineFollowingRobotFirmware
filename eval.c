#include "eval.h"
#include "debug.h"
#include "script.h"
#include "state.h"
#include "states.h"
#include "maze.h"
#include <string.h>
bool eval(State * current, Input * in, Maze * maze) {
  // TODO: Figure out algorithm to use to pick the next state
  //       ie something something like DFS or BFS would be a 
  //       decent choice for solving this maze.
  //strcpy(in->input_name, current->state_name); 
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
  if (is_Goal(in) && !is_State("start", current)) {
    set_State("stop_robot", current);
    return false;
  }
  
  if (!on_Center_Line(in) && line_Right(in)) {
    set_State("turn_right", current);
  }
  else if (!on_Center_Line(in) && line_Left(in)) {
    set_State("turn_left", current);
  }
  else if (right_Turn(in) && !is_State("reverse_right", current)) {
    set_State("reverse_right", current);
  } 
  else if (left_Turn(in) && !is_State("reverse_left", current)) {
    set_State("reverse_left", current);
  } 
  else if (on_Center_Line(in)) {
    set_State("move_forward", current);
  } 
  else if (line_Right(in) || right_Turn(in)) {
    set_State("turn_right", current);
  } 
  else if (line_Left(in) || left_Turn(in)) {
    set_State("turn_left", current);
  } 
  else if (!on_Line(in)) {
    set_State("turn_right", current);
  }
  else {
    set_State("turn_right", current);
  }
  return false;
#endif 
}
