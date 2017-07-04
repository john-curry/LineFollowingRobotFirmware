#include "init_input.h"
#include "stm32f4_discovery.h"
void init_Input(Input * input) {
  ADC_InitTypeDef       ADC_InitStructure;
  ADC_CommonInitTypeDef ADC_CommonInitStructure;
  GPIO_InitTypeDef      GPIO_InitStructure;
  GPIO_InitTypeDef      GPIO_InitStructure_Output;

  /* init perhipheral clocks */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

  /* configure GPIO pins for analog input GPIOA */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 
                              | GPIO_Pin_1 
                              | GPIO_Pin_2 
                              | GPIO_Pin_3 
                              | GPIO_Pin_4 
                              | GPIO_Pin_5 
                              | GPIO_Pin_6;

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* configure GPIO pins for output GPIOB */
  GPIO_InitStructure_Output.GPIO_Pin = ADDR;
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
  ADC_InitStructure.ADC_ScanConvMode = DISABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = DISABLE; 
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfConversion = 7;
  ADC_Init(ADC1, &ADC_InitStructure);

  //for (int i = 0; i < 7; i++) {
  //  ADC_RegularChannelConfig(ADC1, i, i, ADC_SampleTime_3Cycles);
  //}
  ///* Enable ADC1 **************************************************************/
  ADC_Cmd(ADC1, ENABLE);
  //ADC_SoftwareStartConv(ADC1);
}
