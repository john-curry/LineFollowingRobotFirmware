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
  volatile uint32_t count = 100000;
  while (count--);
}

void read_Input(Input * input) {
  clear_Data(input);

  for (uint8_t i = 0; i < 7; i++) {
    GPIO_ResetBits(GPIOD, GPIO_Pin_All);
    GPIO_SetBits  (GPIOD, pins[i]);
    delay();
    ADC_RegularChannelConfig(ADC1, channels[i], 1, ADC_SampleTime_3Cycles);
    ADC_SoftwareStartConv(ADC1);
    while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
    input->data[i] = ADC_GetConversionValue(ADC1);
  }
  GPIO_SetBits(GPIOD, GPIO_Pin_All);
}
