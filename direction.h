#ifndef DIRECTION_H
#define DIRECTION_H
#include <stdbool.h>
typedef enum _direction { 
  North = 0, 
  South = 1, 
  East = 2, 
  West = 3 
} Direction;

Direction change_Direction(Direction d, int t);
Direction opposite_Direction(Direction d);
#endif
