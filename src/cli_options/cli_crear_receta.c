#include <constants.h>
#include <data.h>
#include <input_validation/input_receivers.h>
#include <input_validation/validators.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <style.h>
#include <utils.h>

void cli_crear_receta(int *n_recipes, Recipe recipes[]) {
  int i = *n_recipes;
  *n_recipes = *n_recipes + 1;

  // Recibir datos por stdin.
  puts(CLR);

  fputs(BLD "Ingrese el nombre de la receta: " RESET, stdout);
  fgets(recipes[i].name, BUFFER_SIZE, stdin);
  remove_last_char(recipes[i].name);

  fputs(BLD "Ingrese el número de ingredientes" RESET, stdout);
  int_input(&recipes[i].n_ingredients, &validate_int_g0, false);

  for (int j = 0; j < recipes[i].n_ingredients; j++) {
    fputs(BLD "\nIngrese el nombre del ingrediente: " RESET, stdout);
    fgets(recipes[i].ingredients[j], BUFFER_SIZE, stdin);
    remove_last_char(recipes[i].ingredients[j]);

    fputs(BLD "Ingrese la cantidad del ingrediente" RESET, stdout);
    float_input(&recipes[i].quantities_of_ingredients[j], &validate_float_g0,
                false);
  }

  fputs(BLD "\nIngrese la cantidad de instrucciones" RESET, stdout);
  int_input(&recipes[i].n_instructions, &validate_int_g0, false);

  for (int j = 0; j < recipes[i].n_instructions; j++) {
    fputs(BLD "\nIngrese cada instrucción para la receta: " RESET, stdout);
    fgets(recipes[i].instructions[j], BUFFER_SIZE, stdin);
    remove_last_char(recipes[i].instructions[j]);
  }

  dump_data(*n_recipes, recipes, DATA_FILE);
  puts(GRN "Receta creada exitosamente. Presione " BLD "ENTER " RESET GRN
           "para continuar." RESET);
  getchar();
}
