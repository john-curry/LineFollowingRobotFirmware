#include "gpio.h"

void init_GPIO(Robot * robot) {
  /* GPIOD Periph clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  /* Initialization struct */
  GPIO_InitTypeDef  GPIO_InitStructure;

  /* Configure PD12, PD13 */
  GPIO_InitStructure.GPIO_Pin = robot->motor_plf
                              | robot->motor_plr
                              | robot->motor_prr
                              | robot->motor_prf;

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  //GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  GPIO_ResetBits(GPIOD, robot->motor_plf
                      | robot->motor_plr
                      | robot->motor_prr
                      | robot->motor_prf);
}

void flash_GPIO() {
  /* Turn on GPIO PD12, PD13 */
  //GPIO_SetBits(GPIOD, p1);
  //GPIO_SetBits(GPIOD, p2);

  /* Insert delay */
  Delay(0x3FFFFF);

  //GPIO_ResetBits(GPIOD, p1 | p2);
  
  /* Insert delay */
  Delay(0xFFFFFF);
}

void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}
