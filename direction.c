#include "direction.h"
#include "config.h"
Direction change_Direction(Direction d, int t) {
  if (d == North) {
    if      (t == LEFT)    return West; 
    else if (t == RIGHT)   return East; 
    else if (t == BACK)    return South; 
    else                   return North; 
  }
  else if (d == South) {
    if      (t == LEFT)    return East; 
    else if (t == RIGHT)   return West; 
    else if (t == BACK)    return North; 
    else                   return South; 
  }
  else if (d == West) {
    if      (t == LEFT)    return South; 
    else if (t == RIGHT)   return North; 
    else if (t == BACK)    return East; 
    else                   return West; 
  }
  else { // East
    if      (t == LEFT)    return North; 
    else if (t == RIGHT)   return South; 
    else if (t == BACK)    return West; 
    else                   return East; 
  }
}

Direction opposite_Direction(Direction d) {
  if (d == North) return South;
  else if (d == South) return North;
  else if (d == East) return West;
  else return East;
}
