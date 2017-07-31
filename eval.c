#include "eval.h"
#include "script.h"
#include "state.h"
#include "states.h"
#include "maze.h"
#include "config.h"
#include "direction.h"
#include "decision.h"
#include "actn_timer.h"
#include <string.h>

static int count = 0;
bool eval(State * c, Robot * r, Decision * decision, Maze * maze) {
  update_Timer();

  Directions d;

  Input in;

  read_Input(&in);

  get_Directions(&d, &in);
  
  if (left_Corner(&d)) {
    decision->opcode = LEFT;
  } else if (right_Corner(&d)) {
    decision->opcode = RIGHT;
  } else if (forward_Direction(&d)) {
    decision->opcode = FORWARD;
  }
  switch (decision->opcode) {
    case FORWARD:
      if (on_Center_Line(&in) && off_Right(&in)) {
        set_State("correct_right", c);
      }
      else if (on_Center_Line(&in) && off_Left(&in)) {
        set_State("correct_left", c);
      }
      else if (on_Center_Line(&in)) {
        set_State("move_forward", c);
      } 
      else if (line_Left(&in)) {
        set_State("turn_left", c);
      }
      else if (line_Right(&in)) {
        set_State("turn_right", c);
      }
      //else if (!on_Center_Line(&in)) {
      //  set_State("stop_robot", c);
      //}
      else {
        //set_State("stop_robot", c);
      }
    break;
    case LEFT:
      set_State("reverse_left", c);
    break; 
    case RIGHT:
      set_State("reverse_right", c);
    break; 
    case NONE:
      set_State("stop_robot", c);
    break; 
    default:
      set_State("stop_robot", c);
    break;
  }

  //if (is_Goal(in) && !is_State("start", c)) {
  //  set_State("stop_robot", c);
  //  return false;
  //}
  return false;
}
