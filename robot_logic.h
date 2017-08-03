#ifndef ROBOT_LOGIC 
#define ROBOT_LOGIC
#include "input.h"
#include "state.h"
bool forward_Logic(Input * in, State * c);
void left_Logic(Input * in, State * c);
void right_Logic(Input * in, State * c);
void back_Logic(Input * in, State * c);
#endif
