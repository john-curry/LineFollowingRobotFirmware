#ifndef STATE_H
#define STATE_H
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "robot.h"
#include "input.h"
#include "maze.h"
/* 
  struct to hold all the data for the current state
*/

#define ARG_LEN 3

typedef struct _state {
  /* opcode for the state */
  uint8_t opcode;
  /* arguements the state takes */
  uint8_t args[ARG_LEN];
  /* for convenience sake */
  char * state_name;
} State;
/*
  Tells the robot what to do based on the current state.
  The exact behaviour should be implemented in another method
*/
void execute_State(Robot * robot, State * current_state);

bool is_State(char * state_name, State * cs);

void set_State(char * name, State * s);

#endif
