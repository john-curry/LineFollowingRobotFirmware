#include "gpio.h"

void init_Timer() {
  /* TODO: For some reason this does not fire when I want it to */
  /* Timer datastructure */
  TIM_TimeBaseInitTypeDef timerInitStructure; 

  /* Enable timer clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  
  /* Initialize clock */
  timerInitStructure.TIM_Prescaler = 0;
  timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  timerInitStructure.TIM_Period = 8399;
  timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  timerInitStructure.TIM_RepetitionCounter = 0;

  /* Start timer */
  TIM_TimeBaseInit(TIM4, &timerInitStructure);
  TIM_Cmd(TIM4, ENABLE);
  //TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
}

void set_PWM(int chan, bool on) {
  /* enable pwn on timer */
  TIM_OCInitTypeDef TIM_OCStruct;
  TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_Low;

  /* set the duty cycle */
  /*  50% duty cycle:     pulse_length = ((8399 + 1) * 50) / 100 - 1 = 4199 */
  TIM_OCStruct.TIM_Pulse = on ? 7199 : 0; /* 50% duty cycle */
  switch (chan) {
    case 1:
      TIM_OC1Init(TIM4, &TIM_OCStruct);
      TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
    break;
    case 2:
      TIM_OC2Init(TIM4, &TIM_OCStruct);
      TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
    break;
    case 3:
      TIM_OC3Init(TIM4, &TIM_OCStruct);
      TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
    break;
    case 4:
      TIM_OC4Init(TIM4, &TIM_OCStruct);
      TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);
    break;
  }
}

void set_PWM_OFF() {
  /* enable pwn on timer */
  TIM_OCInitTypeDef TIM_OCStruct;
  TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_Low;

  /* set the duty cycle */
  /*  50% duty cycle:     pulse_length = ((8399 + 1) * 50) / 100 - 1 = 4199 */
  TIM_OCStruct.TIM_Pulse = 0; 
  TIM_OC1Init(TIM4, &TIM_OCStruct);
  TIM_OC4Init(TIM4, &TIM_OCStruct);
  TIM_OC2Init(TIM4, &TIM_OCStruct);
  TIM_OC3Init(TIM4, &TIM_OCStruct);
  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
  TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
  TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);
}


void init_GPIOD(Robot * robot) {
  /* GPIOD Periph clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);

  /* Initialization struct */
  GPIO_InitTypeDef  GPIO_InitStructure;

  /* Configure PD12, PD13, PD14 */
  GPIO_InitStructure.GPIO_Pin = robot->motor_plr
                              | robot->motor_prr
                              | robot->motor_prf;

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

  GPIO_Init(GPIOD, &GPIO_InitStructure);
}

void init_GPIOB(Robot * robot) {
  /* GPIOD Periph clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

  GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_TIM4);

  /* Initialization struct */
  GPIO_InitTypeDef  GPIO_InitStructure;

  GPIO_InitStructure.GPIO_Pin = robot->motor_plf;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

  GPIO_Init(GPIOB, &GPIO_InitStructure);
}
