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
bool can_turn = true;

bool forward_Logic(Input * in, State * c); 
void left_Logic(Input * in, State * c);
void right_Logic(Input * in, State * c);
void back_Logic(Input * in, State * c);

bool eval(State * c, Robot * r, Decision * decision, Maze * maze) {
  update_Timer();

  Input in;

  read_Input(&in);
  
  int op = decision->opcode;
  if (make_Turn_Left(&in) && can_turn) {
    decision->opcode = LEFT;
    
  } else if (make_Turn_Right(&in) && can_turn) {
    decision->opcode = RIGHT;
  }

  else if (is_High(&in, CENTER) || on_Center_Line(&in) || (line_Left(&in)) || (line_Right(&in)) || !can_turn) {
    decision->opcode = FORWARD;
  } else if (off_Line(&in) && can_turn) {
    decision->opcode = BACK;
  } else {
    decision->opcode = NONE;
  }

  can_turn = true;

  switch (decision->opcode) {
    case FORWARD:
      forward_Logic(&in, c);
    break;
    case LEFT:
      can_turn = false;
      left_Logic(&in, c);
    break; 
    case RIGHT:
      can_turn = false;
      right_Logic(&in, c);
    break; 
    case NONE:
      set_State("stop_robot", c);
    break; 
    case BACK:
      can_turn = false;
      back_Logic(&in, c);
    break; 
    default:
      set_State("stop_robot", c);
    break;
  }
  return false;
}
bool forward_Logic(Input * in, State * c) {
  if (on_Line(in)) {
    if (off_Right(in) && off_Left(in)) {
      set_State("move_forward", c);
      return false;
    }
    if (off_Right(in) && !off_Left(in)) {
      set_State("correct_right", c);
      return false;
   }
    if (off_Left(in) && !off_Right(in)) {
      set_State("correct_left", c);
      return false;
    }
    if (off_Right(in)) {
      set_State("correct_right", c);
      return false;
    }
    if (off_Left(in)) {
      set_State("correct_left", c);
      return false;
    }
  }
  else {
    if (line_Right(in) && line_Left(in)) {
      set_State("move_forward", c);
      return false;
    }
    if (line_Left(in) && !line_Right(in)) {
      set_State("turn_left", c);
      return false;
    }
    if (line_Right(in) && !line_Left(in)) {
      set_State("turn_right", c);
      return false;
    }
  }
  set_State("move_forward", c);
  return false;
}

void left_Logic(Input * in, State * c) {
  if ((is_State("reverse_right", c) || is_State("reverse_left", c)) || is_State("turn_around", c)) {
    return;
  }
  set_State("reverse_left", c);
}

void right_Logic(Input * in, State * c) {
  if ((is_State("reverse_right", c) || is_State("reverse_left", c)) || is_State("turn_around", c)) {
    return;
  }
  set_State("reverse_right", c);
}

void back_Logic(Input * in, State * c) {
  if ((is_State("reverse_right", c) || is_State("reverse_left", c)) || is_State("turn_around", c)) return;
  set_State("turn_around", c);
  }

