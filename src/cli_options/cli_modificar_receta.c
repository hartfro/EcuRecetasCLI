#include <constants.h>
#include <data.h>
#include <input_validation/input_receivers.h>
#include <input_validation/validators.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <style.h>
#include <utils.h>

void cli_modificar_receta(int n_recipes, Recipe recipes[]) {
  char recipe_name[BUFFER_SIZE], new_name[BUFFER_SIZE],
      new_ingredients[BUFFER_SIZE][BUFFER_SIZE],
      new_instructions[BUFFER_SIZE][BUFFER_SIZE];
  int new_n_ingredients, new_n_instructions;
  float new_quantities_of_ingredients[BUFFER_SIZE];

  puts(CLR);
  puts(BLD "Ingrese el nombre de la receta a modificar." RESET);

  fgets(recipe_name, BUFFER_SIZE, stdin);
  remove_last_char(recipe_name);
  puts("");

  int i = search_recipe_by_name(recipe_name, n_recipes, recipes);

  if (i >= 0) {
    // If recipe was found.
    fputs(BLD "Ingrese el nuevo nombre de la receta (en blanco para no "
              "modificar): " RESET,
          stdout);
    fgets(new_name, BUFFER_SIZE, stdin);
    remove_last_char(new_name);
    puts("");

    if (strcmp(new_name, "\n") == 0) {
      strcpy(new_name, recipes[i].name); // Copy original name to new_name.
    }

    char s_n_str[BUFFER_SIZE];
    puts(BLU BLD "¿Modificar ingredientes? (s/n)" RESET);
    fgets(s_n_str, BUFFER_SIZE, stdin);
    puts("");

    if (strcmp(s_n_str, "s\n") == 0) {
      fputs(BLD "Ingrese el nuevo número de ingredientes" RESET, stdout);
      int_input(&new_n_ingredients, &validate_int_g0, false);

      for (int j = 0; j < new_n_ingredients; j++) {
        fputs(BLD "\nIngrese el nombre del ingrediente: " RESET, stdout);
        fgets(new_ingredients[j], BUFFER_SIZE, stdin);
        remove_last_char(new_ingredients[j]);

        fputs(BLD "Ingrese la cantidad del ingrediente" RESET, stdout);
        float_input(&new_quantities_of_ingredients[j], &validate_float_g0,
                    false);
      }
    } else {
      // Copy original values to new values.
      new_n_ingredients = recipes[i].n_ingredients;
      memcpy(new_ingredients, recipes[i].ingredients, sizeof new_ingredients);
      memcpy(new_quantities_of_ingredients,
             recipes[i].quantities_of_ingredients,
             sizeof new_quantities_of_ingredients);
    }

    puts(BLU BLD "\n¿Modificar instrucciones? (s/n)" RESET);
    fgets(s_n_str, BUFFER_SIZE, stdin);
    puts("");

    if (strcmp(s_n_str, "s\n") == 0) {
      fputs(BLD "Ingrese la nueva cantidad de instrucciones" RESET, stdout);
      int_input(&new_n_instructions, &validate_int_g0, false);

      for (int j = 0; j < new_n_instructions; j++) {
        fputs(BLD "\nIngrese cada instrucción para la receta: " RESET, stdout);
        fgets(new_instructions[j], BUFFER_SIZE, stdin);
        remove_last_char(new_instructions[j]);
      }
    } else {
      // Copy original instructions to new instructions.
      new_n_instructions = recipes[i].n_instructions;
      memcpy(new_instructions, recipes[i].instructions,
             sizeof new_instructions);
    }

    modify_recipe(i, recipes, new_name, new_n_ingredients,
                  new_quantities_of_ingredients, new_ingredients,
                  new_n_instructions, new_instructions);

    puts(GRN "\nReceta modificada exitosamente." RESET);
  } else
    puts(RECIPE_NOT_FOUND_ERROR);

  puts(GRN "\nPresione " BLD "ENTER " RESET GRN "para continuar.");
  getchar();
}
