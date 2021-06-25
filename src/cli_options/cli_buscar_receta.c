#include <constants.h>
#include <data.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <style.h>

#define RECIPE_NOT_FOUND_ERROR RED "¡Receta no encontrada!"

void cli_buscar_receta(
    int n_recipes, int n_ingredients[BUFFER_SIZE],
    int n_instructions[BUFFER_SIZE],
    float quantities_of_ingredients[BUFFER_SIZE][BUFFER_SIZE],
    char recipe_names[BUFFER_SIZE][BUFFER_SIZE],
    char ingredient_names[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE],
    char instructions[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE]) {
  char recipe_name[BUFFER_SIZE];

  // Get input.
  puts(CLR);
  puts(BLD "Ingrese el nombre de la receta a buscar." RESET);

  fgets(recipe_name, BUFFER_SIZE, stdin);

  // Perform linear search through data.
  bool found_recipe = false;
  int i;
  for (i = 0; i < n_recipes; i++) {
    if (strcmp(recipe_name, recipe_names[i]) == 0) {
      found_recipe = true;
      break;
    }
  }

  if (found_recipe) {
    puts(CLR);
    show_recipe(i, n_recipes, n_ingredients, n_instructions,
                quantities_of_ingredients, recipe_names, ingredient_names,
                instructions);
  } else {
    puts(CLR);
    puts(RECIPE_NOT_FOUND_ERROR);
  }

  puts(GRN "\nPresione " BLD "ENTER " RESET GRN "para continuar.");
  getchar();
}
