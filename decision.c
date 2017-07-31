#include "actn_timer.h"
#include "decision.h"
void make_Decision(Decision * decision, Directions * directions, Maze * maze, Robot * robot) {
}

void set_Decision(Decision * dec, int direction) {
  for (int i = 0; i < MAX_DECISIONS; i++) {
    if (is_Decision(&DECISIONS[i], direction)) {
      *dec = DECISIONS[i];
      return;
    }
  }
}

bool is_Decision(Decision * dec, int direction) {
  if (dec->opcode == direction) return true;
  return false;
}
