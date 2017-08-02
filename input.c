#include <string.h>
#include "input.h"
#include "config.h"
/* High value mean black Low value means white*/

bool is_High(Input * input, uint8_t pin) {
  uint16_t value = input->data[pin];
  uint16_t high  = sensor_high[pin];
  uint16_t low   = sensor_low[pin];

  if (value < low)  return false;
  if (value > high) return true;
  
  double h = (double)h; 
  double l = (double)l;
  double v = (double)value;
  double m = (double)(h + l)/(double)2;
  
  if (value > ((high/2) + (low/2))) return true;
  return false;
}

bool on_Line(Input * in) {
  if (is_High(in, CENTER)) {
    return true;
  }
  return false;
}

bool off_Left(Input * in) {
  if (is_High(in, LEFT_C)) return true;
  return false;
}

bool off_Right(Input * in) {
  if (is_High(in, RIGHT_C)) return true;
  return false;
}

bool line_Left(Input * in) {
  if (is_High(in, LEFT_C) || is_High(in, LEFT_N) || is_High(in, LEFT_F)) return true;
  return false;
}

bool line_Right(Input * in) {
  if (is_High(in, RIGHT_C) || is_High(in, RIGHT_N) || is_High(in, RIGHT_F)) return true;
  return false;
}

// ------------------ TURNING LOGIC ---------------------------------------
bool left_Turn(Input * in) {
  if (is_High(in, LEFT_F) && is_High(in, LEFT_N) && is_High(in, LEFT_C)) return true;
  return false;
}

bool right_Turn(Input * in) {
  if (is_High(in, RIGHT_F) && is_High(in, RIGHT_N) && is_High(in, RIGHT_C)) return true;
  return false;
}
// --------------------------------------------------------------------------------

bool on_Center_Line(Input * in) {
  if (is_High(in, CENTER) || is_High(in, RIGHT_C) || is_High(in, LEFT_C)) {
    return true;
  }
  return false;
}

bool make_Turn_Left(Input * in) {
  if (left_Turn(in)) {
    return true;
  }
  return false;
}

bool make_Turn_Right(Input * in) {
  if (right_Turn(in)) {
    return true;
  }
  return false;
}

bool off_Line(Input * in) {
  if (!is_High(in, CENTER) && !is_High(in, LEFT_F) && !is_High(in, RIGHT_F)) return true;
  return false;
}

bool is_Goal(Input * in) {
  if (is_High(in, 0) 
   && is_High(in, 1) 
   && is_High(in, 2) 
   && is_High(in, 3) 
   && is_High(in, 4) 
   && is_High(in, 5) 
   && is_High(in, 6)) return true;
  return false;
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
  volatile uint32_t count = DELAY;
  while (count--);
}


void read_Input(Input * input) {
  clear_Data(input);

  GPIO_ResetBits(GPIOD, GPIO_Pin_0);
  GPIO_ResetBits(GPIOD, GPIO_Pin_0);
  for (uint8_t i = 0; i < 7; i++) {
    //GPIO_ResetBits(GPIOD, 0b111);
    //GPIO_SetBits  (GPIOD, pins[i]);
    if (i % 2 == 1) {
      GPIO_SetBits(GPIOD, GPIO_Pin_2);
    } else {
      GPIO_ResetBits(GPIOD, GPIO_Pin_2);
    }
    if (i == 2 || i == 3 || i == 6) {
      GPIO_SetBits(GPIOD, GPIO_Pin_0);
    } else {
      GPIO_ResetBits(GPIOD, GPIO_Pin_0);
    }
    if (i < 4) {
      GPIO_ResetBits(GPIOC, GPIO_Pin_11);
    } else {
      GPIO_SetBits(GPIOC, GPIO_Pin_11);
    }
    delay();
    ADC_RegularChannelConfig(ADC1, channels[i], 1, ADC_SampleTime_3Cycles);
    ADC_SoftwareStartConv(ADC1);
    while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
    input->data[i] = ADC_GetConversionValue(ADC1);
  }
  GPIO_SetBits(GPIOD, 0b111);
}
