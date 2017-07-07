#ifndef INPUT_H
#define INPUT_H
#define STR_MAX 4 /* assume 8 byte char so fits in a 32 bit register */
#define INPUTS_MAX 32
#include <stdbool.h>
#include "stm32f4_discovery.h"
#include "stm32f4xx_tim.h"
#define NUM_INPUTS 7
/* defines the datastructure for the IR sensor input raw data */
typedef struct _input_data {
  uint8_t raw[7]; 
} Input_Data;

typedef struct _input_types {
  uint16_t data[7];
  char input_name[STR_MAX];
} Input;

static uint16_t ADDR = 0b111;
static uint16_t IN_PINS = 0b1111111;
static uint16_t ADC_CHANNELS = 7;

bool is_Input(char * state_name, Input * in);

uint16_t read_LED(uint16_t pin);

/* TODO: implement input initialization */
void init_Input(Input * input); 

/* TODO: implement input reading */
void read_Input(Input * input); 

#endif
