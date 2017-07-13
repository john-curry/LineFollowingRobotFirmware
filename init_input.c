#include "init_input.h"

void init_Timer() {
  /* TODO: For some reason this does not fire when I want it to */
  /* Timer datastructure */
  TIM_TimeBaseInitTypeDef timerInitStructure; 

  /* Enable timer clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  
  /* Initialize clock */
  timerInitStructure.TIM_Prescaler = 83;
  timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  timerInitStructure.TIM_Period = 2999;
  timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  timerInitStructure.TIM_RepetitionCounter = 0;

  /* Start timer */
  TIM_TimeBaseInit(TIM2, &timerInitStructure);
  TIM_Cmd(TIM2, ENABLE);
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
}

 void init_Input(Input * input) {
  input->calibrated = false;
  ADC_InitTypeDef       ADC_InitStructure;
  ADC_CommonInitTypeDef ADC_CommonInitStructure;
  GPIO_InitTypeDef      GPIO_InitStructure_B;
  GPIO_InitTypeDef      GPIO_InitStructure_C;
  GPIO_InitTypeDef      GPIO_InitStructure_Output;

  /* init perhipheral clocks */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

  /* configure GPIO pins for analog input GPIOB */
  GPIO_InitStructure_B.GPIO_Pin  = GPIO_Pin_0 
                                 | GPIO_Pin_1; 
  GPIO_InitStructure_B.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_InitStructure_B.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOB, &GPIO_InitStructure_B);

  /* configure GPIO pins for analog input GPIOC */
  GPIO_InitStructure_C.GPIO_Pin  = GPIO_Pin_1 
                                 | GPIO_Pin_2 
                                 | GPIO_Pin_3
                                 | GPIO_Pin_4
                                 | GPIO_Pin_5;
  GPIO_InitStructure_C.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_InitStructure_C.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOC, &GPIO_InitStructure_C);


  /* configure GPIO pins for output GPIOD */
  GPIO_InitStructure_Output.GPIO_Pin   = GPIO_Pin_0 
                                       | GPIO_Pin_1 
                                       | GPIO_Pin_2;
  GPIO_InitStructure_Output.GPIO_Mode  = GPIO_Mode_OUT;
  GPIO_InitStructure_Output.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure_Output.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_Init(GPIOD, &GPIO_InitStructure_Output);

  /* ADC CommonInitStructure */
  ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
  ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
  ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div6; 
  ADC_CommonInit(&ADC_CommonInitStructure);

  /* ADC InitStructure */
  ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
  ADC_InitStructure.ADC_ScanConvMode = DISABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = DISABLE; 
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfConversion = 7;

  /* Enable ADC1 */
  ADC_Init(ADC1, &ADC_InitStructure);
  ADC_Cmd(ADC1, ENABLE);
  init_Timer();
}
