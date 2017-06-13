#define LineFollowingRobot
#include "stm32f4_discovery.h"

#include "ai.h"
#include "robot.h"
#include "maze.h"
#include "input.h"
#include "gpio.h"
#include "states.h"

int main(void) {
  
  /* holds all the data about the robot */
  Robot robot;

  /* polulate robot with values used */
  init_Robot(&robot);

  /* enable and setup the GPIO pins the robot uses */
  init_GPIO(&robot); 
  /* data structure to hold input data */
  Input in;

  /* enable ADC */
  //init_Input();

  /* holds all the data about the maze so far */
  //Maze * maze;

  /* what the robot is currently doing */
  State current_state;
  //execute_State(&robot, &STATES[0]);
  //execute_State(&robot, &STATES[3]);
  do {
    /* pick the action the robot to take */
    eval(&current_state, &in);  

    /* do thing that the robot should do */
    execute_State(&robot, &current_state);

  } while (1);

  return 0;
}

