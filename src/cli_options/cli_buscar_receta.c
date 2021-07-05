#include <constants.h>
#include <data.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <style.h>

void cli_buscar_receta(int n_recipes, Recipe recipes[]) {
  char recipe_name[BUFFER_SIZE];

  // Get input.
  puts(CLR);
  puts(BLD "Ingrese el nombre de la receta a buscar." RESET);

  fgets(recipe_name, BUFFER_SIZE, stdin);

  // Perform linear search through data.
  int i = search_recipe_by_name(recipe_name, n_recipes, recipes);

  if (i >= 0) {
    puts(CLR);
    show_recipe(i, recipes);
  } else {
    puts(CLR);
    puts(RECIPE_NOT_FOUND_ERROR);
  }

  puts(GRN "\nPresione " BLD "ENTER " RESET GRN "para continuar.");
  getchar();
}
