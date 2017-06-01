#ifndef ROBOT_LOGIC_H
#define ROBOT_LOGIC_H
#include "robot.h"
#include "ai.h"

/*
  Method declarations for logic defining hardware control.
  This is where most of hardware programming should be done.
  For now all methods should be NON-BLOCKING (ie no infinite while loops)
  but this may change in future versions.
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

#endif
