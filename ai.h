#ifndef AI_H
#define AI_H
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "robot.h"
/* 
  struct to hold all the data for the current state
*/
typedef struct _state {
  /* uuid should be the unique to the state_name */
  uint32_t uuid;
  /* for convenience sake */
  char * state_name;
} State;

/* defines the datastructure for the IR sensor input */
typedef struct _input {
  uint8_t data[8]; 
} Input;

/* 
   Input: None
   Return: Array of state structs.
   Note: Should not depend on current input or current state.
*/
void populate_States(State * next_states);

/* 
   Method should read the values from GPIO pins and 
   setup the input data structure and return a reference to it.
   Input: None
   Return: input struct
*/
Input read_Inputs();

/* 
  Method that takes the input, current_state and all the 
  next possible states and returns the next state that 
  the robot should take. 
  Note: next_states is many states and method returns one state.
*/
void eval(State * current, Input * in);

/*
  Tells the robot what to do based on the current state.
  The exact behaviour should be implemented in another method
*/
void execute_State(Robot * robot, State * current_state);

bool is_State(char * state_name, State * cs);
#endif
