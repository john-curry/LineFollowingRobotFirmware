#include "robot.h"
#include "gpio.h"

void init_Robot(Robot * robot) {
  robot->motor_plf = GPIO_Pin_9;  /* channel 4 */
  robot->motor_plr = GPIO_Pin_13; /* channel 2 */

  robot->motor_prf = GPIO_Pin_12; /* channel 1 */
  robot->motor_prr = GPIO_Pin_14; /* channel 3 */
  init_GPIOB(robot);
  init_GPIOD(robot);
  init_Timer();
}
