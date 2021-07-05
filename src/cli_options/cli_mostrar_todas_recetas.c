#include <data.h>
#include <stdio.h>
#include <style.h>

void cli_mostrar_todas_recetas(int n_recipes, Recipe recipes[]) {
  puts(CLR);
  show_all_recipes_names(n_recipes, recipes);

  puts(GRN "Presione " BLD "ENTER " RESET GRN "para continuar.");
  getchar();
}
