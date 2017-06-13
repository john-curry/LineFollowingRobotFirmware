#include "robot.h"
#include "ai.h"
#include "gpio.h"

void init_Robot(Robot * robot) {
  robot->motor_plf = GPIO_Pin_1;
  robot->motor_plr = GPIO_Pin_0;

  robot->motor_prf = GPIO_Pin_3;
  robot->motor_prr = GPIO_Pin_2;
}
