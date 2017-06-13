#ifndef AI_H
#define AI_H
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
   Input: None
   Return: Array of state structs.
   Note: Should not depend on current input or current state.
*/
void populate_States(State * next_states);

/* 
  Method that takes the input, current_state and all the 
  next possible states and returns the next state that 
  the robot should take. 
  Note: next_states is many states and method returns one state.
*/
bool eval(State * current, Input * in, Maze * maze);

/*
  Tells the robot what to do based on the current state.
  The exact behaviour should be implemented in another method
*/
void execute_State(Robot * robot, State * current_state);

bool is_State(char * state_name, State * cs);

void set_State(State * s, char * name);
#endif
