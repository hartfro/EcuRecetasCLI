#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 300

void cli_crear_receta() {
  int number_of_ingredients, number_of_instructions;
  char quantity_of_ingredient[BUFFER_SIZE],
      number_of_ingredients_str[BUFFER_SIZE], recipe_name[BUFFER_SIZE],
      ingredient_name[BUFFER_SIZE], instruction[BUFFER_SIZE],
      measurement[BUFFER_SIZE], number_of_instructions_str[BUFFER_SIZE];

  fputs("Ingrese el nombre de la receta: ", stdout);
  fgets(recipe_name, BUFFER_SIZE, stdin);

  while (1) {
    fputs("Ingrese la cantidad de ingredientes: ", stdout);
    fgets(number_of_ingredients_str, BUFFER_SIZE, stdin);

    number_of_ingredients = atoi(number_of_ingredients_str);

    if (number_of_ingredients <= 0) {
      printf("Cantidad incorrecta. Intente de nuevo.\n");
      continue;
    }

    break;
  }

  for (int i = 1; i <= number_of_ingredients; i++) {
    fputs("Ingrese el nombre del ingrediente: ", stdout);
    fgets(ingredient_name, BUFFER_SIZE, stdin);

    while (1) {
      fputs("Ingrese la cantidad del ingrediente: ", stdout);
      fgets(quantity_of_ingredient, BUFFER_SIZE, stdin);

      float quantity_of_ingredientFloat = atof(quantity_of_ingredient);

      if (quantity_of_ingredient <= 0) {
        printf("Cantidad incorrecta. Intente de nuevo.\n");
        continue;
      }

      break;
    }
  }

  while (1) {
    fputs("Ingrese la cantidad de instrucciones: ", stdout);
    fgets(number_of_instructions_str, BUFFER_SIZE, stdin);

    number_of_instructions = atoi(number_of_instructions_str);

    if (number_of_instructions <= 0) {
      printf("Cantidad incorrecta. Intente de nuevo.\n");
      continue;
    }

    break;
  }

  for (int i = 1; i <= number_of_instructions; i++) {
    fputs("Ingrese cada instrucción para la receta: ", stdout);
    fgets(instruction, BUFFER_SIZE, stdin);
  }
}
