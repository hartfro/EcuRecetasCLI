#include <cli_options.h>
#include <input_validation/input_receivers.h>
#include <stdbool.h>
#include <stdio.h>

static bool menu_validator(int x) { return x > 0 && x <= 5; }

int main() {
  // Menú principal
  int opcion_menu;

  while (1) {
    clear_screen();
    puts("\nEcuRecetas - Menú Principal");
    puts("1. Crear Receta.");
    puts("2. Eliminar Receta.");
    puts("3. Modificar Receta.");
    puts("4. Buscar Receta.");
    puts("5. Salir.");

    int_input(&opcion_menu, &menu_validator);

    switch (opcion_menu) {
    case 1:
      cli_crear_receta();
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
      puts("\n¡Gracias por usar EcuRecetas!");
      return 0;
    }
  }

  return 0;
}
