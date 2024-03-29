# push_swap
  This project sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions.

### Compiling

  Run the following commands:

  * To compile
    - `make`
  * To remove objects:
    - `make clean`
  * To remove objects and binary file (program):
    - `make fclean`
  * To re-compile:
    - `make re`
  
  
### Executing

  ./push_swap <an argument the stack a formatted as a list of integers>
  
  
### Example

  ----------------------------------------------------------------------------------------------------------\
  Init a and b:\
  2\
  1\
  3\
  6\
  5\
  8\
  _ _\
  a b\
  ----------------------------------------------------------------------------------------------------------\
  Exec sa:\
  1\
  2\
  3\
  6\
  5\
  8\
  _ _\
  a b\
  ----------------------------------------------------------------------------------------------------------\
  Exec pb pb pb:\
  6 3\
  5 2\
  8 1\
  _ _\
  a b\
  ----------------------------------------------------------------------------------------------------------\
  Exec ra rb (equiv. to rr):\
  5 2\
  8 1\
  6 3\
  _ _\
  a b\
  ----------------------------------------------------------------------------------------------------------\
  Exec rra rrb (equiv. to rrr):\
  6 3\
  5 2\
  8 1\
  _ _\
  a b\
  ----------------------------------------------------------------------------------------------------------\
  Exec sa:\
  5 3\
  6 2\
  8 1\
  _ _\
  a b\
  ----------------------------------------------------------------------------------------------------------\
  Exec pa pa pa:\
  1\
  2\
  3\
  5\
  6\
  8\
  _ _\
  a b\
  ----------------------------------------------------------------------------------------------------------\
