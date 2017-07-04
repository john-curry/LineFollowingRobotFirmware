#include <string.h>
#include "input.h"

bool is_Input(char * input_name, Input * in) {
  if (strcmp(input_name, in->input_name) == 0) return true;
  return false;
}

void clear_Data(Input * input) {
  for (uint16_t i = 0; i < 7; i++) {
    input->data[i] = 0;
  }
}

uint16_t read_LED(uint16_t pin) {
  GPIO_ResetBits(GPIOB, ADDR);
  GPIO_SetBits(GPIOB, pin);
  ADC_SoftwareStartConv(ADC1);
  while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET) {}
  return ADC_GetConversionValue(ADC1);
}

void read_Input(Input * input) {
  clear_Data(input);
  for (uint16_t i = 0; i < 7; i++) {
    GPIO_ResetBits(GPIOB, ADDR);
    GPIO_SetBits(GPIOB, i);
    ADC_RegularChannelConfig(ADC1, i, 1, ADC_SampleTime_3Cycles);
    ADC_SoftwareStartConv(ADC1);
    while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET) {}
    input->data[i] = ADC_GetConversionValue(ADC1);
  }
  GPIO_SetBits(GPIOB, ADDR);
}
