#include "state.h"
#include "states.h"
#include "config.h"
#include "decision.h"
#include "robot_logic.h"
#include "eval.h"

bool can_turn = true;
int cancan = 0;

bool eval(State * c, Robot * r, Decision * decision, Maze * maze) {
  Input in;
  read_Input(&in);
  read_Input(&in);

  //set_State("move_forward", c);
  //return false;











  //if (is_Goal(&in)) {
  //  return true;
  //}
  if (is_Intersection(&in)) {
    decision->opcode = LEFT;
  }
  if (make_Turn_Left(&in)) {
    decision->opcode = LEFT;
  } 
  else if (on_Line(&in)) {
    decision->opcode = FORWARD;
  }
  else if (make_Turn_Right(&in)) {
    decision->opcode = RIGHT;
  } 
  else if (off_Left(&in)) {
    decision->opcode = FORWARD;
  } 
  else if (off_Right(&in)) {
    decision->opcode = FORWARD;
  } 
  else if (off_Line(&in) && can_turn) {
    decision->opcode = BACK;
  } 
  else if (line_Left(&in)) {
    decision->opcode = FORWARD;
  } 
  else if (line_Right(&in)) {
    decision->opcode = FORWARD;
  } 
  else {
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
    can_turn = false;
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
