#ifndef ROBOT_H
#define ROBOT_H
#include <stdint.h>
#include "stm32f4_discovery.h"
typedef struct _robot {
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

  uint16_t motor_pin_left  : GPIO_Pin_1;

  uint16_t motor_pin_right : GPIO_Pin_3;


} Robot;
#endif
