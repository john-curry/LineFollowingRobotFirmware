#include <string.h>
#include "input.h"
#define LEFT_F  0 // Far left
#define LEFT_N  1 // Near left
#define LEFT_C  2 // Left of center
#define CENTER  3
#define RIGHT_C 4
#define RIGHT_N 5
#define RIGHT_F 6
/* High value mean black Low value means white*/
bool is_High(Input * input, uint8_t pin) {
  uint16_t value = input->data[pin];
  uint16_t high  = sensor_high[pin];
  uint16_t low   = sensor_low[pin];

  if (value < low)  return false;
  if (value > high) return true;
   
  int mid = ((int)high + (int)low)/2;
  
  if (value > mid) return true;
  return false;
}

bool on_Line(Input * in) {
  for (int i = 0; i < 7; i++) {
    if (is_High(in, i)) return true;
  }
  return false;
}

bool is_Junction(Input * in) {
  if (left_Turn(in) || right_Turn(in)) return true;
  return false;
}

bool line_Left(Input * in) {
  if (is_High(in, LEFT_F) || is_High(in, LEFT_N)) return true;
  return false;
}

bool line_Right(Input * in) {
  if (is_High(in, RIGHT_F) || is_High(in, RIGHT_N)) return true;
  return false;
}

bool left_Turn(Input * in) {
  if (is_High(in, LEFT_F) && is_High(in, LEFT_N) && is_High(in, LEFT_C)) return true;
  return false;
}

bool right_Turn(Input * in) {
  if (is_High(in, RIGHT_F) && is_High(in, RIGHT_N) && is_High(in, RIGHT_C)) return true;
  return false;
}

bool on_Center_Line(Input * in) {
  if (is_High(in, CENTER)) {
    return true;
  }
  return false;
}

bool off_Line(Input * in) {
  for (int i = 0; i < 7; i++) {
    if (is_High(in, i)) return false;
  }
  return true;
}


bool is_Goal(Input * in) {
  for (int i = 0; i < 7; i++) {
    if (!is_High(in, i)) return false;
  }
  return true;
} 

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
    GPIO_ResetBits(GPIOD, 0b111);
    GPIO_SetBits  (GPIOD, pins[i]);
    delay();
    ADC_RegularChannelConfig(ADC1, channels[i], 1, ADC_SampleTime_3Cycles);
    ADC_SoftwareStartConv(ADC1);
    while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
    input->data[i] = ADC_GetConversionValue(ADC1);
  }
  GPIO_SetBits(GPIOD, 0b111);
}
