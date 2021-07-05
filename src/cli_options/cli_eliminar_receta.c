#include <data.h>
#include <stdio.h>
#include <style.h>

void cli_eliminar_receta(int *n_recipes, int array_length, Recipe *recipes) {
  char recipe_name[BUFFER_SIZE];

  // Get input.
  puts(CLR);
  puts(BLD "Ingrese el nombre de la receta a eliminar." RESET);

  fgets(recipe_name, BUFFER_SIZE, stdin);

  // Perform linear search through data.
  int i = search_recipe_by_name(recipe_name, *n_recipes, recipes);

  if (i >= 0) {
    remove_recipe_from_array(i, n_recipes, array_length, recipes);
    puts(BLU "Receta eliminada correctamente." RESET);
  } else {
    puts(CLR);
    puts(RECIPE_NOT_FOUND_ERROR);
  }

  puts(GRN "\nPresione " BLD "ENTER " RESET GRN "para continuar.");
  getchar();
}