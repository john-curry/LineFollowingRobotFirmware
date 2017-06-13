#define LineFollowingRobot
#include "stm32f4_discovery.h"
#include "ai.h"
#include "robot.h"
#include "maze.h"
#include "states.h"
#include "input.h"
#include "gpio.h"

void Delay(__IO uint32_t nCount);
void init_GPIO(Robot * robot);
void flash_GPIO();

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
                                                            
  do {
    //flash_GPIO();
    
    //uint16_t value = read_Input();
                                                              
    /* see what the robot can do next */
    State next_states;
    
    /* pick the action the robot to take */
    eval(&current_state, &next_states, &in);  

    /* do thing that the robot should do */
    execute_State(&robot, &current_state);

  //} while (current_state != NULL);
  } while (1);

  return 0;
}

