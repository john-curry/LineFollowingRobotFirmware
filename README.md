Skelaton code for the control of the robot via the mircocontroller.

Hardware programming should be done in the robot\_logic.c file.

High level decision making should go in the ai.c eval method.

Code is judiciously commented so please read.

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
