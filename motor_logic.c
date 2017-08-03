#include "motor_logic.h"
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

void delay_Forward() {
  volatile uint32_t count = COUNT_FORWARD;
  while (count--);
}

void delay_Turn() {
  volatile uint32_t count = COUNT_TURN;
  while (count--);
}

void delay_Correct() {
  volatile uint32_t count = COUNT_CORRECT;
  while (count--);
}

void correct_Left(Robot * robot, State * current_state) {
   left_MR(OFF);
  right_MR(OFF);
   left_MF_Speed(MED_SPEED);
  right_MF_Speed(LOW_SPEED);
  //delay_Correct();
}

void correct_Right(Robot * robot, State * current_state) {
  left_MR(OFF);
  right_MR(OFF);
  left_MF_Speed(LOW_SPEED);
  right_MF_Speed(MED_SPEED);
  //delay_Correct();
}

void turn_Left(Robot * robot, State * current_state) {
  left_MR(OFF);
  right_MR(OFF);
   left_MF_Speed(MED_SPEED);
  right_MF_Speed(NO_SPEED);
  delay_Turn();
}

void turn_Right(Robot * robot, State * current_state) {
  right_MR(OFF);
  left_MR(OFF);
   left_MF_Speed(NO_SPEED);
  right_MF_Speed(MED_SPEED);
  delay_Turn();
}

void reverse_Left(Robot * robot, State * current_state) {
  left_MF_Speed(HIGH_SPEED);
  right_MR_Speed(HIGH_SPEED);
  left_MR(OFF);
  right_MF(OFF);
  delay_Robot(robot, current_state);
}

void reverse_Right(Robot * robot, State * current_state) {
  right_MF_Speed(HIGH_SPEED);
  left_MR_Speed(HIGH_SPEED);
  left_MF(OFF);
  right_MR(OFF);
  delay_Robot(robot, current_state);
}

void delay_Turn_Around(Robot * robot, State * current_state) {
  volatile uint32_t count = COUNT_TURN_AROUND;
  while (count--);
}

void turn_Around(Robot * robot, State * current_state) {
  left_MF_Speed(HIGH_SPEED);
  left_MR(OFF);
  right_MF(OFF);
  right_MR_Speed(HIGH_SPEED);
  delay_Turn_Around(robot, current_state);
  delay_Turn_Around(robot, current_state);
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

void move_Forward(Robot * robot, State * current_state) {
   left_MF_Speed(MED_SPEED);
  right_MF_Speed(MED_SPEED);
  left_MR(OFF);
  right_MR(OFF);
  delay_Forward();
}
