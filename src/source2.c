#include "include/internal_header.h"

void
print_number()
{
  int number = PRINT_NUMBER;

  print_hello();
  printf("number: %04x\n", number);

  return;
}