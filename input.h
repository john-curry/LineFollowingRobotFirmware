#ifndef INPUT_H
#define INPUT_H
#define STR_MAX 4 /* assume 8 byte char so fits in a 32 bit register */
#define INPUTS_MAX 32
#include <stdbool.h>
#include "stm32f4_discovery.h"
#define NUM_INPUTS 7
/* defines the datastructure for the IR sensor input raw data */
typedef struct _input_data {
  uint8_t raw[7]; 
} Input_Data;

typedef struct _input_types {
  Input_Data data;
  char input_name[STR_MAX];
} Input;

static uint16_t INPUT_ADDR[3] = {
  GPIO_Pin_0,
  GPIO_Pin_1,
  GPIO_Pin_2,
};

static uint16_t INPUT_PINS[7] = {
  GPIO_Pin_0,
  GPIO_Pin_1,
  GPIO_Pin_2,
  GPIO_Pin_3,
  GPIO_Pin_4,
  GPIO_Pin_5,
  GPIO_Pin_6
};

static uint16_t ADC_CHAN[7] = {
  ADC_Channel_0,
  ADC_Channel_1,
  ADC_Channel_2,
  ADC_Channel_3,
  ADC_Channel_4,
  ADC_Channel_5,
  ADC_Channel_6
};

bool is_Input(char * state_name, Input * in);

/* TODO: implement input initialization */
void init_Input(Input * input); 

/* TODO: implement input reading */
void read_Input(Input_Data * input); 

#endif
