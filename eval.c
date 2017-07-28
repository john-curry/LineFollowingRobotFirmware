#include "eval.h"
#include "script.h"
#include "state.h"
#include "states.h"
#include "maze.h"
#include "config.h"
#include "direction.h"
#include "decision.h"
#include <string.h>

bool eval(State * c, Robot * r, Input * in, Maze * maze) {

  Directions d;

  get_Directions(&d, in);

  Decision decision;

  make_Decision(&decision, &d, maze, r);

  switch (decision.opcode) {
    case FORWARD:
      set_State("move_forward", c);
    break;
    case LEFT:
      set_State("reverse_left", c);
    break; 
    case RIGHT:
      set_State("reverse_right", c);
    break; 
    //default:
      //set_State("stop_robot", c);
  }
      if (on_Center_Line(in) && off_Right(in)) {
        set_State("correct_right", c);
      }
      else if (on_Center_Line(in) && off_Left(in)) {
        set_State("correct_left", c);
      }
      else if (on_Center_Line(in)) {
        set_State("move_forward", c);
      }

  //if (is_Goal(in) && !is_State("start", c)) {
  //  set_State("stop_robot", c);
  //  return false;
  //}
  return false;
}
