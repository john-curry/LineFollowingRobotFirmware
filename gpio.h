#ifndef GPIO_H
#define GPIO_H
#include "stm32f4_discovery.h"
#include "robot.h"
#include <stdbool.h>
void Delay(__IO uint32_t nCount);
void init_GPIOD(Robot * robot);
void init_GPIOB(Robot * robot);
void init_Timer();
void set_PWM(int chan, bool on);
void set_PWM_Speed(int chan, int speed);
void flash_GPIO();
#endif
