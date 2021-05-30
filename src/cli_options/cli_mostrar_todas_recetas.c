#include <data.h>
#include <stdio.h>
#include <style.h>

void cli_mostrar_todas_recetas(RecipeData *data) {
  puts(CLR);
  show_all_recipes(data);

  puts(GRN "Presione " BLD "ENTER " RESET GRN "para continuar.");
  getchar();
}
