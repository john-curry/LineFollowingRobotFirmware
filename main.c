#define LineFollowingRobot
#include "stm32f4_discovery.h"
#include "ai.h"
#include "robot.h"
#include "maze.h"
#include "states.h"

void Delay(__IO uint32_t nCount);
void init_GPIO();
void flash_GPIO();

Robot robot;

uint16_t p1 = GPIO_Pin_3;
uint16_t p2 = GPIO_Pin_1;

int main(void) {
  
  /* enable and setup pins PD12, PD13 */
  init_GPIO();

  /* holds all the data about the robot */
  //Robot * robot;

  /* holds all the data about the maze so far */
  Maze * maze;

  /* what the robot is currently doing */
  State * current_state;
                                                            
  do {
    flash_GPIO();
    /* get the data from the sensors */
    Input in = read_Inputs(); 
                                                              
    /* see what the robot can do next */
    State * next_states = STATES;
    
    /* pick the action the robot to take */
    *current_state = eval(next_states, current_state, &in);  

    /* do thing that the robot should do */
    if (current_state != NULL) {
      execute_State(&robot, current_state);
    }

  //} while (current_state != NULL);
  } while (1);

  return 0;
}

void init_GPIO() {
  /* GPIOD Periph clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

  /* Initialization struct */
  GPIO_InitTypeDef  GPIO_InitStructure;

  /* Configure PD12, PD13 */
  GPIO_InitStructure.GPIO_Pin = p1 | p2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  //GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
}

void flash_GPIO() {
  /* Turn on GPIO PD12, PD13 */
  GPIO_SetBits(GPIOE, p1);
  GPIO_SetBits(GPIOE, p2);

  /* Insert delay */
  Delay(0x3FFFFF);

  //GPIO_ResetBits(GPIOE, p1 | p2);
  
  /* Insert delay */
  Delay(0xFFFFFF);
}

void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}
