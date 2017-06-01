#ifndef ROBOT_H
#define ROBOT_H
#include "ai.h"
typedef struct _robot {
  State * current_state;
  /* 
    the amount that we change the angle by 
    TODO: calibrate wheel rotation
  */
  uint16_t delta_angle; // = 
  /* 
    Distance between the ir sensors 
    TODO: measure distance between ir sensors
  */
  uint16_t ir_distance; // =
  /* 
    Distance between the motors 
    TODO: measure distance between motors 
  */
  uint16_t wh_distance; // = 
} Robot;


#endif
