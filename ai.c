#include "ai.h"
#include "robot_logic.h"
#include "states.h"
#include "script.h"
#include "debug.h"
#include <string.h>
#include <stdlib.h>
/* private method */
bool is_State(char * state_name, State * cs) {
  if (strcmp(state_name, cs->state_name) == 0) return true;
  return false;
}

void set_State(State * current, char * name) {
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

bool eval(State * current, Input * in, Maze * maze) {
  // TODO: Figure out algorithm to use to pick the next state
  //       ie something something like DFS or BFS would be a 
  //       decent choice for solving this maze.
#if DEBUG
  static int program_counter = 0;
  if (script[program_counter] != EOS) {
    *current = STATES[script[program_counter]];
    program_counter++;
  }
#else 
  if (is_State("goal", current)) {
    return true;

  } /* Do not return true past this point. Only set State current */
  /* Path Following Algorithm 
   
    Stocastically acceptable.
    Based on the idea that if you always pick a random route,
    you will eventually get to the goal.
  */
   
  if (is_Input("left", in) && is_Input("rite", in) && is_Input("forw", in)) {
    int direction = rand() % 3;
    if (direction == 0) {
      set_State(current, "turn_left");
      return false;
    }
    else if (direction == 1) {
      set_State(current, "turn_right");
      return false;
    }
    else {
      set_State(current, "move_forward");
      return false;
    }
  }

  if (is_Input("left", in) && is_Input("right", in)) {
    int direction = rand() % 2;
    if (direction == 0) {
      set_State(current, "turn_left");
      return false;
    }
    set_State(current, "turn_right");
    return false;
  }
  else if (is_Input("left", in)) {
    set_State(current, "turn_left");
    return false;
  }
  else if(is_Input("rite", in)) {
    set_State(current, "turn_right");
    return false;
  }
  else {
    set_State(current, "move_forward");
    return false;
  }

  /* PSEUDOCODE Depth First Search (DFS)

  if input has found a node
    check if node has already been visited
    if node has not been visited
      visit node
    else if node has been visited
      keep turning
    else if no new nodes
      return to last node
   */
#endif 
  return false;
}

void execute_State(Robot * robot, State * current_state) {
  /* TODO: implement functionality */
  /* 
    This is just an idea of how this method should work.
    When a new state is added, a new if statement should also
    be added. There are more elegent ways to do this, but
    they are usually more complicated and error prone.
  */
  if (is_State("move_forward", current_state)) {
    move_Forward(robot, current_state);
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

