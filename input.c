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
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

    GPIO_ResetBits(GPIOD, GPIO_Pin_All);
    GPIO_SetBits  (GPIOD, pins[i]);
    delay();

    //ADC_RegularChannelConfig(ADC1, (i + (uint8_t)0x08), 1, ADC_SampleTime_3Cycles);
    ADC_RegularChannelConfig(ADC1, channels[i], 1, ADC_SampleTime_3Cycles);
    ADC_SoftwareStartConv(ADC1);

    //while((TIM_GetITStatus(TIM2, TIM_IT_Update)   != RESET));

    while((ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET)) { }
    input->data[i] = ADC_GetConversionValue(ADC1);
  }
  GPIO_SetBits(GPIOD, GPIO_Pin_All);
}
//void read_Input(Input * input) {
//  clear_Data(input);
//
//  //for (uint16_t i = 0; i < 7; i++) {
//    //GPIO_ResetBits(GPIOD, ADDR);
//    GPIO_SetBits  (GPIOD, 0b011);
//    
//    //while((ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET)) { }
//    //while ((TIM_GetITStatus(TIM2, TIM_IT_Update)  != RESET)) {}
//
//    //TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//
//    ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_15Cycles);
//    ADC_SoftwareStartConv(ADC1);
//    input->data[0] = ADC_GetConversionValue(ADC1);
//    //ADC_ClearFlag(ADC1, ADC_FLAG_EOC);
//  //}
//  //GPIO_SetBits(GPIOD, ADDR);
//}
//
