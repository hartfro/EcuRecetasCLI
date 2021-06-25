#include <constants.h>
#include <data.h>
#include <input_validation/input_receivers.h>
#include <input_validation/validators.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <style.h>

void cli_crear_receta(
    int *n_recipes, int n_ingredients[BUFFER_SIZE],
    int n_instructions[BUFFER_SIZE],
    float quantities_of_ingredients[BUFFER_SIZE][BUFFER_SIZE],
    char recipe_names[BUFFER_SIZE][BUFFER_SIZE],
    char ingredient_names[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE],
    char instructions[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE]) {
  int i = *n_recipes;
  *n_recipes = *n_recipes + 1;

  // Recibir datos por stdin.
  puts(CLR);

  fputs(BLD "Ingrese el nombre de la receta: " RESET, stdout);
  fgets(recipe_names[i], BUFFER_SIZE, stdin);

  fputs(BLD "Ingrese el número de ingredientes" RESET, stdout);
  int_input(&n_ingredients[i], &validate_int_g0);

  for (int j = 0; j < n_ingredients[i]; j++) {
    fputs(BLD "\nIngrese el nombre del ingrediente: " RESET, stdout);
    fgets(ingredient_names[i][j], BUFFER_SIZE, stdin);

    fputs(BLD "Ingrese la cantidad del ingrediente" RESET, stdout);
    float_input(&quantities_of_ingredients[i][j], &validate_float_g0);
  }

  fputs(BLD "\nIngrese la cantidad de instrucciones" RESET, stdout);
  int_input(&n_instructions[i], &validate_int_g0);

  for (int j = 0; j < n_instructions[i]; j++) {
    fputs(BLD "\nIngrese cada instrucción para la receta: " RESET, stdout);
    fgets(instructions[i][j], BUFFER_SIZE, stdin);
  }

  puts(GRN "Receta creada exitosamente. Presione " BLD "ENTER " RESET GRN
           "para continuar." RESET);
  getchar();
}
