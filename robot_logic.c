#include "robot_logic.h"
bool forward_Logic(Input * in, State * c) {
  if (on_Line(in) || off_Right(in) || off_Left(in)) {
    if (off_Left(in) && !off_Right(in)) {
      set_State("correct_left", c);
      return false;
    }
    if (off_Right(in) && !off_Left(in)) {
      set_State("correct_right", c);
      return false;
    }
    if (off_Right(in) && off_Left(in)) {
      set_State("move_forward", c);
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
    if (line_Left(in) && !line_Right(in)) {
      set_State("turn_left", c);
      return false;
    }
    if (line_Right(in) && !line_Left(in)) {
      set_State("turn_right", c);
      return false;
    }
    if (line_Right(in) && line_Left(in)) {
      set_State("move_forward", c);
      return false;
    }
    if (line_Right(in)) {
      set_State("turn_right", c);
      return false;
    }
    if (line_Left(in)) {
      set_State("turn_left", c);
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
