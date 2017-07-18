#define LineFollowingRobot
#include "stm32f4_discovery.h"

#include "state.h"
#include "eval.h"
#include "robot.h"
#include "maze.h"
#include "input.h"
#include "gpio.h"
#include "init_input.h"

int main(void) {
  
  /* holds all the data about the robot */
  Robot robot;

  /* polulate robot with values used */
  init_Robot(&robot);

  /* enable and setup the GPIO pins the robot uses */
  init_GPIO(&robot); 

  /* data structure to hold input data */
  Input input;

  /* enable ADC TODO: still does not work */
  init_Input(&input);

  /* holds all the data about the maze so far */
  Maze maze;

  /* */
  //init_Maze(&maze);

  /* struct to hold the current action the robot is doing */ 
  State current_state; 

  /* Tell the robot to start in state "start". 
     See states.h for complete listing of states. 
     TODO: Fix set_State function 
  */
  //set_State("stop_robot", &current_state); 
  /* 
     Run the eval method and start control loop.

     The method eval will read from the input,
     update the maze object and alse update  
     the current_state.
     The method eval will return true only when 
     robot has obtained the "goal" state.
  */ 
  read_Input(&input);

  while (!eval(&current_state, &input, &maze)) {
    read_Input(&input);
    /* do thing that the robot should do */
    execute_State(&robot, &current_state);
  }
  return 0;
}

