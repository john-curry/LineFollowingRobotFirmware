#include "direction.h"
#include "input.h"
#include "config.h"

bool is_Junction(Directions * d) {
  if (left_Corner(d) && right_Corner(d)) return true;
  if (forward_Direction(d) && right_Corner(d)) return true;
  if (forward_Direction(d) && left_Corner(d)) return true;
  return false;
}

bool is_Corner(Directions * d) {
  return d->dirs[LEFT] ^ d->dirs[RIGHT];
}

bool left_Corner(Directions * d) {
  //if (!is_Corner(d)) return false;
  return d->dirs[LEFT];
}

bool right_Corner(Directions * d) {
  //if (!is_Corner(d)) return false;
  return d->dirs[RIGHT];
}

bool forward_Direction(Directions * d) {
  //if (!is_Corner(d)) return false;
  return d->dirs[FORWARD];
}

bool dead_End(Directions * d) {
  for (int i = 1; i < 4; i++) {
    if (d->dirs[i]) return false;
  }
  return true;
}

void set_Dir(Directions * d, int n) {
  d->dirs[n] = true;
}
void reset_Dir(Directions * d) {
  for (int i = 0; i < 4; i++) {
    d->dirs[i] = false;
  }
}

bool is_Dir(Directions * d, int direction) {
  return d->dirs[direction];
}

void get_Directions(Directions * d, Input * in) {
  reset_Dir(d);
  if (left_Turn(in)) {
    set_Dir(d, LEFT);
  }
  if (right_Turn(in)) {
    set_Dir(d, RIGHT);
  }
  if (on_Center_Line(in)) {
    set_Dir(d, FORWARD);
  }
  set_Dir(d, BACK);
}

