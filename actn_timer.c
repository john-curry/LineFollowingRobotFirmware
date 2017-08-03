#include "stm32f4_discovery.h"
#include "config.h"
#include "actn_timer.h"

void init_Action_Timer() {
  /* Enable timer clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

  TIM_TimeBaseInitTypeDef timerInitStructure; 
  
  /* Initialize clock */
  timerInitStructure.TIM_Prescaler = 8400;
  timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  timerInitStructure.TIM_Period = MILLIS;
  timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  timerInitStructure.TIM_RepetitionCounter = 0;

  TIM_TimeBaseInit(TIM2, &timerInitStructure);
  TIMER.active = false;
  TIMER.done = false;
}

bool timer_Started() {
  return TIMER.active;
}

bool timer_Done() {
  return TIMER.done;
}

void stop_Timer() {
  TIMER.active = false;
  TIM_Cmd(TIM2, DISABLE);
  TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
}

void restart_Timer() {
  TIMER.active = false;
  TIMER.done = false;
  TIM_Cmd(TIM2, DISABLE);
  TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
}

void start_Timer() {
  TIMER.active = true;
  TIMER.done = false;
  TIM_Cmd(TIM2, ENABLE);
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
}

void update_Timer() {
  if (!timer_Started()) return;

  if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) {
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    stop_Timer();
    TIMER.done = true;
  }
}
