#include "robot.h"
#include "gpio.h"

void init_Robot(Robot * robot) {
  robot->motor_plf = GPIO_Pin_15;
  robot->motor_plr = GPIO_Pin_13;

  robot->motor_prf = GPIO_Pin_12;
  robot->motor_prr = GPIO_Pin_14;
}
