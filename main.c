#define LineFollowingRobot
#include "stm32f4_discovery.h"
#include "ai.h"
#include "robot.h"
#include "maze.h"

void Delay(__IO uint32_t nCount);
void Init_GPIO();

int main(void) {

  /* GPIOD Periph clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  Init_GPIO();

  /* holds all the data about the robot */
  Robot * robot;

  /* holds all the data about the maze so far */
  Maze * maze;

  /* what the robot is currently doing */
  State * current_state;
                                                            
  /* get the data from the sensors */
  Input in = read_Inputs(); 
                                                            
  /* see what the robot can do next */
  State * next_states = get_Next_States();
  
  /* pick the first thing for the robot to do */
  *current_state = eval(next_states, current_state, &in);  

  while (current_state != NULL) {
    
    /* do thing that the robot should do */
    execute_State(*current_state);

    /* So that the robot does not run at max speed */
    Delay(0x3FFFFF); 

    Input in = read_Inputs(); 
                                                              
    State * next_states = get_Next_States();
    
    State current_state = eval(next_states, &current_state, &in);  

    /* Turn on GPIO PD12, PD13 */
    GPIO_SetBits(GPIOD, GPIO_Pin_12);
    GPIO_SetBits(GPIOD, GPIO_Pin_13);

    /* Insert delay */
    Delay(0x3FFFFF);
    
    /* Turn off GPIO PD12, PD13 */
    GPIO_ResetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13);
    
    /* Insert delay */
    Delay(0xFFFFFF);
  }
  return 0;
}

void Init_GPIO() {
  /* Initialization struct */
  GPIO_InitTypeDef  GPIO_InitStructure;

  /* Configure PD12, PD13 */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
}

void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}
