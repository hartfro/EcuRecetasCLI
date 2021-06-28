#include <constants.h>
#include <data.h>
#include <input_validation/input_receivers.h>
#include <input_validation/validators.h>
#include <stdio.h>
#include <string.h>
#include <style.h>

void cli_modificar_receta(
    int n_recipes, int n_ingredients[BUFFER_SIZE],
    int n_instructions[BUFFER_SIZE],
    float quantities_of_ingredients[BUFFER_SIZE][BUFFER_SIZE],
    char recipe_names[BUFFER_SIZE][BUFFER_SIZE],
    char ingredient_names[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE],
    char instructions[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE]) {

  char recipe_name[BUFFER_SIZE], new_name[BUFFER_SIZE],
      new_ingredients[BUFFER_SIZE][BUFFER_SIZE],
      new_instructions[BUFFER_SIZE][BUFFER_SIZE];
  int new_n_ingredients, new_n_instructions;
  float new_quantities_of_ingredients[BUFFER_SIZE];

  puts(CLR);
  puts(BLD "Ingrese el nombre de la receta a modificar." RESET);

  fgets(recipe_name, BUFFER_SIZE, stdin);
  int i = search_recipe_by_name(recipe_name, n_recipes, recipe_names);

  if (i >= 0) {
    // If recipe was found.
    fputs(BLD "Ingrese el nuevo nombre de la receta (en blanco para no "
              "modificar): " RESET,
          stdout);
    fgets(new_name, BUFFER_SIZE, stdin);

    if (strcmp(new_name, "\n")) {
      strcpy(new_name, recipe_names[i]);
    }

    char s_n_str[BUFFER_SIZE];
    puts(BLU BLD "¿Modificar ingredientes? (s/n)" RESET);
    fgets(s_n_str, BUFFER_SIZE, stdin);

    if (strcmp(s_n_str, "s\n") == 0) {
      fputs(BLD "Ingrese el nuevo número de ingredientes (en blanco para no "
                "modificar)" RESET,
            stdout);
      int_input(&new_n_ingredients, &validate_int_g0);

      for (int j = 0; j < new_n_ingredients; j++) {
        fputs(BLD "\nIngrese el nombre del ingrediente: " RESET, stdout);
        fgets(new_ingredients[j], BUFFER_SIZE, stdin);

        fputs(BLD "Ingrese la cantidad del ingrediente" RESET, stdout);
        float_input(&new_quantities_of_ingredients[j], &validate_float_g0);
      }
    } else {
      new_n_ingredients = n_ingredients[i];
      memcpy(new_ingredients, ingredient_names[i], sizeof new_ingredients);
      memcpy(new_quantities_of_ingredients, quantities_of_ingredients[i],
             sizeof new_quantities_of_ingredients);
    }

    puts(BLU BLD "¿Modificar instrucciones? (s/n)" RESET);
    fgets(s_n_str, BUFFER_SIZE, stdin);

    if (strcmp(s_n_str, "s\n") == 0) {
      fputs(BLD "\nIngrese la nueva cantidad de instrucciones" RESET, stdout);
      int_input(&new_n_instructions, &validate_int_g0);

      for (int j = 0; j < new_n_instructions; j++) {
        fputs(BLD "\nIngrese cada instrucción para la receta: " RESET, stdout);
        fgets(new_instructions[j], BUFFER_SIZE, stdin);
      }
    } else {
      new_n_instructions = n_instructions[i];
      memcpy(new_instructions, instructions[i], sizeof new_instructions);
    }

    modify_recipe(i, new_name, new_n_ingredients, new_ingredients,
                  new_quantities_of_ingredients, new_n_instructions,
                  new_instructions, n_ingredients, n_instructions,
                  quantities_of_ingredients, recipe_names, ingredient_names,
                  instructions);

    puts(GRN "Receta modificada exitosamente." RESET);
  } else
    puts(RECIPE_NOT_FOUND_ERROR);

  puts(GRN "\nPresione " BLD "ENTER " RESET GRN "para continuar.");
  getchar();
}
