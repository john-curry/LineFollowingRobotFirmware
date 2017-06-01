#ifndef AI_H
#define AI_H
#include <stddef.h>
#include <stdint.h>

/* 
  struct to hold all the data for the current state
*/
typedef struct mstate {
  uint32_t uuid;
} state;

/* defines the datastructure for the IR sensor input */
typedef struct minput {
  uint8_t data[8]; 
} input;

/* 
   Input: None
   Return: Array of state structs.
   Note: Should not depend on current input or current state.
*/
state * get_next_states();

/* 
   Method should read the values from GPIO pins and 
   setup the input data structure and return a reference to it.
   Input: None
   Return: input struct
*/
input read_inputs();

/* 
  Method that takes the input, current_state and all the 
  next possible states and returns the next state that 
  the robot should take. 

  Note: next_states is many states and method returns one state.
*/
state eval(state * next_states, state * current, input * in);

/*
  Tells the robot what to do based on the current state.
  The exact behaviour should be implemented in another method
*/
void execute_state(state current_state);

#endif
