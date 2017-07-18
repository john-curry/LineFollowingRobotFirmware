#include "state.h"
#include "robot_logic.h"
#include "states.h"
#include "script.h"
#include "input.h"
#include "debug.h"
#include <string.h>
#include <stdlib.h>
/* private method */
bool is_State(char * state_name, State * cs) {
  if (strcmp(state_name, cs->state_name) == 0) return true;
  return false;
}

void set_State(char * name, State * current) {
  /* TODO: for some reason is broken */
  for (State * s = &STATES[0]; s != NULL; s += sizeof(State*)) {
    if (is_State(name, s)) {
      current = s;
    }
  }
  /* impossible code path */
}

void populate_States(State * next_states) {
  // TODO: implement all states
}


void execute_State(Robot * robot, State * current_state) {
  /* do the action associated the the current state */
  if (is_State("move_forward", current_state)) {
    move_Forward(robot, current_state);
  }
  else if (is_State("start", current_state)) {
    start_Robot(robot, current_state);
  }
  else if (is_State("turn_right", current_state)) {
    turn_Right(robot, current_state);
  }
  else if (is_State("turn_left", current_state)) {
    turn_Left(robot, current_state);
  }
  else if (is_State("reverse_robot", current_state)) {
    reverse_Robot(robot, current_state);
  }
  else if (is_State("reverse_right", current_state)) {
    reverse_Right(robot, current_state);
  }
  else if (is_State("reverse_left", current_state)) {
    reverse_Left(robot, current_state);
  }
  else if (is_State("delay_robot", current_state)) {
    delay_Robot(robot, current_state);
  }
  else if (is_State("stop_robot", current_state)) {
    stop_Robot(robot, current_state);
  }
  else if (is_State("goal", current_state)) {
    victory_Dance(robot, current_state);
  }
  else {
    /* This else block should be unreachable */
    /* TODO: implement some sort of error reporting */
  }
}

