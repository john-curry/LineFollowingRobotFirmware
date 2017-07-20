#include "robot.h"
#include "gpio.h"

void init_Robot(Robot * robot) {
  robot->motor_plf = GPIO_Pin_7;
  robot->motor_plr = GPIO_Pin_13;

  robot->motor_prf = GPIO_Pin_12;
  robot->motor_prr = GPIO_Pin_14;
  init_GPIOB(robot);
  init_GPIOD(robot);
}
