Hardware programming should be done in the robot\_logic.c file.

High level decision making should go in the ai.c eval method.

Reading from input is in input.c and input initialization and setup is in init\_input.c

When DEBUG is set, the robot reads a set of instructions from script.h. The instructions are
defined in states.h.

Current maze solving algorithm takes random paths until it reaches the end goal. Better 
algorithm soon to follow.

Put this in the Project Folder of the stm32\_discovery\_arm\_gcc\
ie on my computer:
  /home/src/bigboss/src/stm32\_discovery\_arm\_gcc/STM32F4-Discovery\_FW\_V1.1.0/Project/

and for OSX:
  /Users/bigboss/src/stm32\_discovery\_arm\_gcc/STM32F4-Discovery\_FW\_V1.1.0/Project/

Coding Conventions:
  All structs are typedef with capitals for the first letter.
  All methods are capitalized at the second word.
  Multiple words are spaced with underscores.
  References and pointers are not capitalized.
  Openning brackets go on same line as keyword.
