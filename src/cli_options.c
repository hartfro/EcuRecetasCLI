#include <input_validation/input_receivers.h>
#include <input_validation/validators.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 300

void cli_crear_receta() {
  int number_of_ingredients, number_of_instructions;
  float quantity_of_ingredient;
  char recipe_name[BUFFER_SIZE], ingredient_name[BUFFER_SIZE],
      instruction[BUFFER_SIZE];

  fputs("Ingrese el nombre de la receta: ", stdout);
  fgets(recipe_name, BUFFER_SIZE, stdin);

  fputs("Ingrese la cantidad de ingredientes", stdout);
  int_input(&number_of_ingredients, &validate_int_g0);

  for (int i = 1; i <= number_of_ingredients; i++) {
    fputs("\nIngrese el nombre del ingrediente: ", stdout);
    fgets(ingredient_name, BUFFER_SIZE, stdin);

    fputs("Ingrese la cantidad del ingrediente", stdout);
    float_input(&quantity_of_ingredient, &validate_float_g0);
  }

  fputs("\nIngrese la cantidad de instrucciones", stdout);
  int_input(&number_of_instructions, &validate_int_g0);

  for (int i = 1; i <= number_of_instructions; i++) {
    fputs("\nIngrese cada instrucción para la receta: ", stdout);
    fgets(instruction, BUFFER_SIZE, stdin);
  }

  puts("Receta creada correctamente. Presione ENTER para continuar.");
  getchar();
}
