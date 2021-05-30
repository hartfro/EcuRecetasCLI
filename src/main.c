#include <cli_options.h>
#include <constants.h>
#include <data.h>
#include <input_validation/input_receivers.h>
#include <stdbool.h>
#include <stdio.h>
#include <style.h>

static bool menu_validator(int x) { return x > 0 && x <= 5; }
RecipeData data;

int main() {
  // Menú principal
  int opcion_menu;

  while (1) {
    puts(CLR);

    puts(RED BLD "\nEcuRecetas - Menú Principal" RESET);
    puts(BLD "1. " RESET "Crear Receta.");
    puts(BLD "2. " RESET "Eliminar Receta.");
    puts(BLD "3. " RESET "Modificar Receta.");
    puts(BLD "4. " RESET "Buscar Receta.");
    puts(BLD "5. " RESET "Salir.");

    int_input(&opcion_menu, &menu_validator);

    switch (opcion_menu) {
    case 1:
      cli_crear_receta(&data);
      break;
    case 2:
      // cli_eliminar_receta();
      break;
    case 3:
      // cli_modificar_receta();
      break;
    case 4:
      // cli_buscar_receta();
      break;
    case 5:
      puts(GRN "\n¡Gracias por usar EcuRecetas!");
      return 0;
    }
  }

  return 0;
}
