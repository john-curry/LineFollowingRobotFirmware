#ifndef GPIO_H
#define GPIO_H
#include "stm32f4_discovery.h"
#include "robot.h"
void Delay(__IO uint32_t nCount);
void init_GPIOD(Robot * robot);
void init_GPIOB(Robot * robot);
void flash_GPIO();
#endif
