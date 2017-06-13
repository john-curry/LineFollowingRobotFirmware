#ifndef INPUT_H
#define INPUT_H
#define STR_MAX 4 /* assume 8 byte char so fits in a 32 bit register */
#define INPUTS_MAX 32
#include "stm32f4_discovery.h"

ADC_InitTypeDef       ADC_InitStructure;
ADC_CommonInitTypeDef ADC_CommonInitStructure;
GPIO_InitTypeDef      GPIO_InitStructure;

/* defines the datastructure for the IR sensor input raw data */
typedef struct _input_data {
  uint8_t front;
  uint8_t data[7]; 
} Input_Data;

typedef struct _input_types {
  Input_Data data;
  char input_name[STR_MAX];
  /* eight pin input with 0 being the front pin 
     TODO: define the actual pins we will be using 
           and implement it in the init_Input method.   
  */
  uint16_t pins[8];
} Input;

static Input INPUTS[INPUTS_MAX] = {
  {
    .input_name = "left"
  },
  {
    .input_name = "rite"
  },
  {
    .input_name = "forw"
  },
};

/* TODO: implement input initialization */
void init_Input(Input * input); 

/* TODO: implement input reading */
void read_Input(Input * input); 

#endif
