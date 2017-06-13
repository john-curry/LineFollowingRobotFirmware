#ifndef INPUT_H
#define INPUT_H

#include "stm32f4_discovery.h"

#define MAX_INPUTS 32
ADC_InitTypeDef       ADC_InitStructure;
ADC_CommonInitTypeDef ADC_CommonInitStructure;
GPIO_InitTypeDef      GPIO_InitStructure;

//typedef struct input_type {
//  char * input_name;
//} Input;
//
//static Input INPUTS[MAX_INPUTS] = {
//  {
//    . input_name = 


void init_Input(void); 
uint16_t read_Input(void); 
#endif
