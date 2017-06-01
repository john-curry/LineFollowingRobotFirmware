#ifndef STATES_H
#define STATES_H

#include "ai.h"

#define MAX_STATES 32

static State STATES[MAX_STATES] = {
  {
    .state_name = "move_forward"
  },
  {
    .state_name = "stop"
  }
};
#endif
