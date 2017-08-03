#ifndef CONFIG
#define CONFIG

#define MILLIS 10000

#define DEBUG true

#define SPEED 7599

#define HIGH_SPEED SPEED

#define MED_SPEED ((SPEED) - 500)

#define LOW_SPEED ((SPEED) - 1200) 

#define NO_SPEED 0

#define DELAY 100000

#define COUNT 0xDFFFFF;

#define COUNT_FORWARD 0x000000;

#define COUNT_TURN 0x00000F;

#define COUNT_CORRECT 0x000000;

#define COUNT_TURN_AROUND 0xEFFFFF;

#define LEFT_F  0 // Far left
#define LEFT_N  1 // Near left
#define LEFT_C  2 // Left of center
#define CENTER  3
#define RIGHT_C 4
#define RIGHT_N 5
#define RIGHT_F 6

#define BACK    0
#define LEFT    1
#define FORWARD 2
#define RIGHT   3
#define NONE  (4)
#endif
