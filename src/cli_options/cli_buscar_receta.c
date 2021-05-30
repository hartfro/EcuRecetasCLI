#include <constants.h>
#include <data.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <style.h>

#define RECIPE_NOT_FOUND_ERROR RED "¡Receta no encontrada!"

void cli_buscar_receta(RecipeData *data) {
  char recipe_name[BUFFER_SIZE];

  // Get input.
  puts(CLR);
  puts(BLD "Ingrese el nombre de la receta a buscar." RESET);

  fgets(recipe_name, BUFFER_SIZE, stdin);

  // Perform linear search through data.
  bool found_recipe = false;
  int i;
  for (i = 0; i < data->number_of_recipes; i++) {
    if (strcmp(recipe_name, data->recipe_names[i]) == 0) {
      found_recipe = true;
      break;
    }
  }

  if (found_recipe) {
    puts(CLR);
    show_recipe(data, i);
  } else {
    puts(CLR);
    puts(RECIPE_NOT_FOUND_ERROR);
  }

  puts(GRN "\nPresione " BLD "ENTER " RESET GRN "para continuar.");
  getchar();
}
