#include <string.h>
#include "input.h"

bool is_Input(char * input_name, Input * in) {
  if (strcmp(input_name, in->input_name) == 0) return true;
  return false;
}

void init_Input(Input * input) {
  ADC_InitTypeDef       ADC_InitStructure;
  ADC_CommonInitTypeDef ADC_CommonInitStructure;
  GPIO_InitTypeDef      GPIO_InitStructure;
  GPIO_InitTypeDef      GPIO_InitStructure_Output;

  /* init perhipheral clocks */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

  /* configure GPIO pins for analog input */
  GPIO_InitStructure.GPIO_Pin = INPUT_PINS[0] 
                              | INPUT_PINS[1] 
                              | INPUT_PINS[2] 
                              | INPUT_PINS[3] 
                              | INPUT_PINS[4] 
                              | INPUT_PINS[5] 
                              | INPUT_PINS[6];
                               
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  /* configure GPIO pins for output */
  GPIO_InitStructure_Output.GPIO_Pin = INPUT_ADDR[0]
                                     | INPUT_ADDR[1]
                                     | INPUT_ADDR[2];

  GPIO_InitStructure_Output.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure_Output.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure_Output.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOB, &GPIO_InitStructure_Output);

  /* ADC CommonInitStructure */
  ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
  ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
  ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div6; 
  ADC_CommonInit(&ADC_CommonInitStructure);

  /* ADC InitStructure */
  ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
  ADC_InitStructure.ADC_ScanConvMode = ENABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
  //ADC_InitStructure.ADC_NbrOfDiscConversion = 0;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfConversion = 7;
  ADC_Init(ADC1, &ADC_InitStructure);

  ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 0, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 2, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 3, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 4, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 5, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 6, ADC_SampleTime_3Cycles);

  ///* Enable ADC1 **************************************************************/
  ADC_Cmd(ADC1, ENABLE);

  ADC_SoftwareStartConv(ADC1);
}

void read_Input(Input_Data * data) {



    for (uint16_t i = 0; i < 7; i++) {
      while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
      if (i & (uint16_t)1) {
        GPIO_SetBits(GPIOB, INPUT_ADDR[0]);
      } else {
        GPIO_ResetBits(GPIOB, INPUT_ADDR[0]);
      }
      if (i & (uint16_t)2) {
        GPIO_SetBits(GPIOB, INPUT_ADDR[1]);
      } else {
        GPIO_ResetBits(GPIOB, INPUT_ADDR[1]);
      }
      if (i & (uint16_t)4) {
        GPIO_SetBits(GPIOB, INPUT_ADDR[2]);
      } else {
        GPIO_ResetBits(GPIOB, INPUT_ADDR[2]);
      }
      ADC_RegularChannelConfig(ADC1, ADC_CHAN[i], i, ADC_SampleTime_3Cycles);
      ADC_SoftwareStartConv(ADC1);
      data->raw[i] = ADC_GetConversionValue(ADC1);
    }
}
