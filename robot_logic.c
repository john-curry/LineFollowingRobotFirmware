#include "robot_logic.h"
#include "gpio.h"
#include "config.h"

/* TODO: Add a check to see if pins are already set */
/* TODO: Comment this sectiON */
/* TODO: Test this sectiON */
#define CHAN 4
#define ON (true)
#define OFF (false)
void left_MF(bool on) {
  set_PWM(4, on);
}
void right_MF(bool on) {
  set_PWM(1, on);
}
void left_MR(bool on) {
  set_PWM(2, on);
}
void right_MR(bool on) {
  set_PWM(3, on);
}

void left_MF_Speed(int on) {
  set_PWM_Speed(4, on);
}
void right_MF_Speed(int on) {
  set_PWM_Speed(1, on);
}
void left_MR_Speed(int on) {
  set_PWM_Speed(2, on);
}
void right_MR_Speed(int on) {
  set_PWM_Speed(3, on);
}

void correct_Left(Robot * robot, State * current_state) {
   left_MF_Speed(HIGH_SPEED);
   left_MR_Speed(NO_SPEED);
  right_MF_Speed(MED_SPEED);
  right_MR_Speed(NO_SPEED);
}

void correct_Right(Robot * robot, State * current_state) {
   left_MF_Speed(MED_SPEED);
   left_MR_Speed(NO_SPEED);
  right_MF_Speed(HIGH_SPEED);
  right_MR_Speed(NO_SPEED);
}

void move_Forward(Robot * robot, State * current_state) {
  left_MF(ON);
  left_MR(OFF);
  right_MF(ON);
  right_MR(OFF);
}

void stop_Robot(Robot * robot, State * current_state) {
  left_MF(ON);
  left_MR(ON);
  right_MF(ON);
  right_MR(ON);
}

void reverse_Robot(Robot * robot, State * current_state) {
  left_MF(OFF);
  left_MR(ON);
  right_MF(OFF);
  right_MR(ON);
}

void turn_Left(Robot * robot, State * current_state) {
  left_MR(OFF);
  right_MF(OFF);
  left_MF_Speed(HIGH_SPEED);
  right_MR_Speed(MED_SPEED);
}

void turn_Right(Robot * robot, State * current_state) {
  left_MF(OFF);
  right_MR(OFF);
  left_MR_Speed(MED_SPEED);
  right_MF_Speed(HIGH_SPEED);
}

void reverse_Left(Robot * robot, State * current_state) {
  left_MF_Speed(HIGH_SPEED);
  left_MR(OFF);
  right_MF(OFF);
  right_MR_Speed(MED_SPEED);
  delay_Robot(robot, current_state);
}

void reverse_Right(Robot * robot, State * current_state) {
  left_MF(OFF);
  left_MR_Speed(MED_SPEED);
  right_MF_Speed(HIGH_SPEED);
  right_MR(OFF);
  delay_Robot(robot, current_state);
}

void turn_Around(Robot * robot, State * current_state) {
  turn_Right(robot, current_state);
  delay_Robot(robot, current_state);
  delay_Robot(robot, current_state);
}

void delay_Robot(Robot * robot, State * current_state) {
  volatile uint32_t count = COUNT;
  while (count--);
}

void start_Robot(Robot * robot, State * current_state) {
  left_MF(ON);
  left_MR(ON);
  right_MF(ON);
  right_MR(ON);
}

void victory_Dance(Robot * robot, State * current_state) {
  left_MF(ON);
  left_MR(ON);
  right_MF(ON);
  right_MR(ON);
}
