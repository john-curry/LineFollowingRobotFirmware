#include "robot.h"
#include "gpio.h"
#include "config.h"


void init_Robot(Robot * robot) {
  robot->motor_plf = GPIO_Pin_15;  /* channel 4 */
  robot->motor_plr = GPIO_Pin_13; /* channel 2 */

  robot->motor_prf = GPIO_Pin_12; /* channel 1 */
  robot->motor_prr = GPIO_Pin_14; /* channel 3 */
  robot->facing = North;
  init_GPIOB(robot);
  init_GPIOD(robot);
  init_Timer();
}
