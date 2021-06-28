#include <data.h>
#include <stdio.h>
#include <style.h>

void cli_mostrar_todas_recetas(int n_recipes,
                               char recipe_names[BUFFER_SIZE][BUFFER_SIZE]) {
  puts(CLR);
  show_all_recipes_names(n_recipes, recipe_names);

  puts(GRN "Presione " BLD "ENTER " RESET GRN "para continuar.");
  getchar();
}
