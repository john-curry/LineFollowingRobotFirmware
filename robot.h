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

  uint16_t motor_plf;
  uint16_t motor_plr;

  uint16_t motor_prf;
  uint16_t motor_prr;


} Robot;

void init_Robot(Robot * robot);
#endif
