#ifndef ROBOT_LOGIC_H
#define ROBOT_LOGIC_H
#include "robot.h"
#include "state.h"
/*
  Method declarations for logic defining hardware control.
  This is where most of hardware programming should be done.
  For now all methods should be NON-BLOCKING (ie no infinite while loops)
  but this may change in future versions.
  None of these methods should call the read_Inputs method for now
  but I am willing to debate this point.
*/

/* 
  Move robot forward my an incremental amount.
  Turn on motors if they are not already on or keep them on.
*/
void move_Forward(Robot * robot, State * current_state);

/*
  Turn off motor or ensure that they are still off.
*/
void stop_Robot(Robot * robot, State * current_state);

void reverse_Robot(Robot * robot, State * current_state);

void turn_Left(Robot * robot, State * current_state);

void turn_Right(Robot * robot, State * current_state);

void delay_Robot(Robot * robot, State * current_state);

void victory_Dance(Robot * robot, State * current_state);

void start_Robot(Robot * robot, State * current_state);

void reverse_Left(Robot * robot, State * current_state);

void reverse_Right(Robot * robot, State * current_state);

void correct_Left(Robot * robot, State * current_state);

void correct_Right(Robot * robot, State * current_state);

void turn_Around(Robot * robot, State * current_state);
#endif
