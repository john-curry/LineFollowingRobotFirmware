#ifndef INPUT_H
#define INPUT_H
#define STR_MAX 4 /* assume 8 byte char so fits in a 32 bit register */
#define INPUTS_MAX 32
#include <stdbool.h>
#include "stm32f4_discovery.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_adc.h"
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
static uint8_t pins[NUM_INPUTS] = {
  0b00000000,
  0b00000001,
  0b00000010,
  0b00000011,
  0b00000100,
  0b00000101,
  0b00000110
};
static uint8_t channels[NUM_INPUTS] = {
  ADC_Channel_8,
  ADC_Channel_9,
  ADC_Channel_10,
  ADC_Channel_11,
  ADC_Channel_12,
  ADC_Channel_13,
  ADC_Channel_14
};

bool is_Input(char * state_name, Input * in);

uint16_t read_LED(uint16_t pin);

/* TODO: implement input initialization */
void init_Input(Input * input); 

/* TODO: implement input reading */
void read_Input(Input * input); 

#endif
