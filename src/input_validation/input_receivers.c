#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_ERROR_MSG "\nValor inválido. Intente de nuevo.\n"
#define BUFFER_SIZE 100

bool int_input(int *x, bool (*validator)(int a), bool blank) {
  char input_str[BUFFER_SIZE];
  int input;

  while (1) {
    fputs(": ", stdout);
    fgets(input_str, BUFFER_SIZE, stdin);

    // If input was blank.
    if (blank && strcmp(input_str, "\n") == 0)
      return false;

    input = atoi(input_str);

    if ((*validator)(input)) {
      *x = input;
      break;
    }

    puts(INPUT_ERROR_MSG);
  }
  return true;
}

bool float_input(float *x, bool (*validator)(float a), bool blank) {
  char input_str[BUFFER_SIZE];
  float input;

  while (1) {
    fputs(": ", stdout);
    fgets(input_str, BUFFER_SIZE, stdin);

    // If input was blank.
    if (blank && strcmp(input_str, "\n") == 0)
      return false;

    input = atof(input_str);

    if ((*validator)(input)) {
      *x = input;
      break;
    }

    puts(INPUT_ERROR_MSG);
  }
  return true;
}
