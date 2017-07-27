#ifndef CONFIG
#define CONFIG

#define SPEED 7199

#define HIGH_SPEED SPEED

#define MED_SPEED ((SPEED) - 1000)

#define LOW_SPEED ((SPEED) - 3000) 

#define NO_SPEED 0

#define DELAY 100000

#define COUNT 0xAFFFFF;

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

#endif
