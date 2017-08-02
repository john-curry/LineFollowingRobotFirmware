#define LineFollowingRobot
#include "stm32f4_discovery.h"

#include "state.h"
#include "eval.h"
#include "robot.h"
#include "maze.h"
#include "input.h"
#include "gpio.h"
#include "init_input.h"
#include "actn_timer.h"
#include "decision.h"
int main(void) {
  
  /* holds all the data about the robot */
  Robot robot;

  /* polulate robot with values used and init_GPIO */
  init_Robot(&robot);

  /* enable ADC TODO: still does not work */
  init_Input();

  /* holds all the data about the maze so far */
  Maze maze;

  /* struct to hold the current action the robot is doing */ 
  State current_state; 

  Decision decision;

  decision.opcode = FORWARD;
  init_Action_Timer();  

  while (!eval(&current_state, &robot, &decision, &maze)) {
    /* do thing that the robot should do */
    execute_State(&robot, &current_state);
  }
  set_State("stop_robot", &current_state);
  execute_State(&robot, &current_state);
  while(true);
  return 0;
}

