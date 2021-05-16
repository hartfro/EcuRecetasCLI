#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_ERROR_MSG "\nValor inválido. Intente de nuevo.\n"
#define BUFFER_SIZE 100

void int_input(int *x, bool (*validator)(int a)) {
  char input_str[BUFFER_SIZE];
  int input;

  while (1) {
    fputs(": ", stdout);
    fgets(input_str, BUFFER_SIZE, stdin);

    input = atoi(input_str);

    if ((*validator)(input)) {
      *x = input;
      break;
    }

    puts(INPUT_ERROR_MSG);
  }
}
