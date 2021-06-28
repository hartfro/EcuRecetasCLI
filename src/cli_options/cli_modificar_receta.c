#include <constants.h>
#include <data.h>
#include <input_validation/input_receivers.h>
#include <input_validation/validators.h>
#include <stdio.h>
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
    fputs(BLD "Ingrese el nuevo nombre de la receta: " RESET, stdout);
    fgets(new_name, BUFFER_SIZE, stdin);

    fputs(BLD "Ingrese el nuevo número de ingredientes" RESET, stdout);
    int_input(&new_n_ingredients, &validate_int_g0);

    for (int j = 0; j < new_n_ingredients; j++) {
      fputs(BLD "\nIngrese el nombre del ingrediente: " RESET, stdout);
      fgets(new_ingredients[j], BUFFER_SIZE, stdin);

      fputs(BLD "Ingrese la cantidad del ingrediente" RESET, stdout);
      float_input(&new_quantities_of_ingredients[j], &validate_float_g0);
    }

    fputs(BLD "\nIngrese la nueva cantidad de instrucciones" RESET, stdout);
    int_input(&new_n_instructions, &validate_int_g0);

    for (int j = 0; j < new_n_instructions; j++) {
      fputs(BLD "\nIngrese cada instrucción para la receta: " RESET, stdout);
      fgets(new_instructions[j], BUFFER_SIZE, stdin);
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
