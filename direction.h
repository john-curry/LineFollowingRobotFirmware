#ifndef DIRECTION_H
#define DIRECTION_H
#include <stdbool.h>
#include "input.h"
typedef struct _directions {
  bool dirs[4]; 
} Directions;

void get_Directions(Directions * dirs, Input * in);

bool is_Dir(Directions * d, int direction);

bool is_Junction(Directions *d);
#endif
