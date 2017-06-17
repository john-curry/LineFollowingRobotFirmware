#include "robot_logic.h"

/* TODO: Add a check to see if pins are already set */
/* TODO: Comment this section */
/* TODO: Test this section */
void move_Forward(Robot * robot, State * current_state) {
  GPIO_SetBits(GPIOE, robot->motor_plf);  
  GPIO_SetBits(GPIOE, robot->motor_prf);  
  GPIO_ResetBits(GPIOE, robot->motor_plr | robot->motor_prr);
}

void stop_Robot(Robot * robot, State * current_state) {
  //GPIO_ResetBits(GPIOE, robot->motor_plr | robot->motor_prr);
  //GPIO_ResetBits(GPIOE, robot->motor_plf | robot->motor_prf);
  GPIO_SetBits(GPIOE, robot->motor_plf);  
  GPIO_SetBits(GPIOE, robot->motor_prf);  
  GPIO_SetBits(GPIOE, robot->motor_plr);  
  GPIO_SetBits(GPIOE, robot->motor_prr);  
}

void reverse_Robot(Robot * robot, State * current_state) {
  GPIO_SetBits(GPIOE, robot->motor_plr);  
  GPIO_SetBits(GPIOE, robot->motor_prr);  
  GPIO_ResetBits(GPIOE, robot->motor_plf | robot->motor_prf);
}

void turn_Left(Robot * robot, State * current_state) {
  GPIO_SetBits(GPIOE, robot->motor_plf);  
  GPIO_ResetBits(GPIOE, robot->motor_plr
                      | robot->motor_prr 
                      | robot->motor_prf);
}

void turn_Right(Robot * robot, State * current_state) {
  GPIO_SetBits(GPIOE, robot->motor_prf);  
  GPIO_ResetBits(GPIOE, robot->motor_plf
                      | robot->motor_prr 
                      | robot->motor_plr);
}

void delay_Robot(Robot * robot, State * current_state) {
  volatile uint32_t count = 0xFFFFFF;
  while (count--);
}

void victory_Dance(Robot * robot, State * current_state) {
  /* TODO: implement a victory dance sequence */
}
