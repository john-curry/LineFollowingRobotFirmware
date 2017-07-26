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
typedef struct _input_types {
  uint16_t  data[NUM_INPUTS];
  char      input_name[];
} Input;

/* On black */
static uint16_t sensor_high[NUM_INPUTS] = {
  3500, 3300, 3500, 3500, 2500, 3500, 3500
};

/* On white */
static uint16_t sensor_low[NUM_INPUTS] = {
  1400, 1000, 1000, 2600, 600, 1500, 2300
};

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
  ADC_Channel_11, // PC1
  ADC_Channel_12, // PC2
  ADC_Channel_14, // PC4
  ADC_Channel_8,  // PB0
  ADC_Channel_13, // PC3
  ADC_Channel_15, // PC5
  ADC_Channel_9,  // PB1
};

bool is_Input(char * state_name, Input * in);

void read_Input(Input * input); 

bool is_High(Input*, uint8_t);

bool on_Line(Input*);

bool off_Line(Input * in);

bool line_Left(Input * in);

bool line_Right(Input * in);

bool off_Left(Input * in);

bool off_Right(Input * in);

bool on_Center_Line(Input * in);

bool left_Turn(Input * in);

bool right_Turn(Input * in);

bool is_Goal(Input * in);

bool is_Junction(Input * in);
#endif
