#ifndef TIMER_H
#define TIMER_H
#include <stdbool.h>
typedef struct _timer {
  bool active;
  bool done;
} Timer;

static Timer TIMER = {
  .active = false,
  .done   = false
};

void init_Action_Timer();
bool timer_Done();
bool timer_Started();
void stop_Timer();
void start_Timer();
void update_Timer();
#endif
