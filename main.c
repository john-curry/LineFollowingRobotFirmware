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
int main(void) {
  
  /* holds all the data about the robot */
  Robot robot;

  /* polulate robot with values used and init_GPIO */
  init_Robot(&robot);

  /* data structure to hold input data */
  Input input;

  /* enable ADC TODO: still does not work */
  init_Input(&input);

  /* holds all the data about the maze so far */
  Maze maze;

  /* struct to hold the current action the robot is doing */ 
  State current_state; 

  set_State("move_forward", &current_state); 
  /* 
     Run the eval method and start control loop.

     The method eval will read from the input,
     update the maze object and alse update  
     the current_state.
     The method eval will return true only when 
     robot has obtained the "goal" state.
  */ 
  read_Input(&input);

  init_Action_Timer();  
  while (!eval(&current_state, &robot, &input, &maze)) {
    read_Input(&input);
    /* do thing that the robot should do */
    execute_State(&robot, &current_state);
  }
  set_State("stop_robot", &current_state);
  execute_State(&robot, &current_state);
  while(true);
  return 0;
}

