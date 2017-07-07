#include <string.h>
#include "input.h"
#include "stm32f4xx_tim.h"

bool is_Input(char * input_name, Input * in) {
  if (strcmp(input_name, in->input_name) == 0) return true;
  return false;
}

void clear_Data(Input * input) {
  for (uint16_t i = 0; i < 7; i++) {
    input->data[i] = 0;
  }
}

void delay() {
  volatile uint32_t count = 1000000;
  while (count--);
}

void read_Input(Input * input) {
  clear_Data(input);

  for (uint16_t i = 0; i < 7; i++) {
    GPIO_ResetBits(GPIOC, ADDR);
    GPIO_SetBits(GPIOC, i);
    
    while((ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET)
       && (TIM_GetITStatus(TIM2, TIM_IT_Update)  != RESET)) {}

    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

    ADC_RegularChannelConfig(ADC1, i + 8, 1, ADC_SampleTime_15Cycles);
    ADC_SoftwareStartConv(ADC1);
    input->data[i] = ADC_GetConversionValue(ADC1);
  }
  GPIO_SetBits(GPIOC, ADDR);
}

