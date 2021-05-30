#include <constants.h>
#include <data.h>
#include <input_validation/input_receivers.h>
#include <input_validation/validators.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <style.h>

void cli_crear_receta(RecipeData *data) {
  int number_of_ingredients, number_of_instructions;
  float quantity_of_ingredients[BUFFER_SIZE];
  char recipe_name[BUFFER_SIZE], ingredient_names[BUFFER_SIZE][BUFFER_SIZE],
      instructions[BUFFER_SIZE][BUFFER_SIZE];

  // Recibir datos por stdin.
  puts(CLR);

  fputs(BLD "Ingrese el nombre de la receta: " RESET, stdout);
  fgets(recipe_name, BUFFER_SIZE, stdin);

  fputs(BLD "Ingrese el número de ingredientes" RESET, stdout);
  int_input(&number_of_ingredients, &validate_int_g0);

  for (int i = 0; i < number_of_ingredients; i++) {
    fputs(BLD "\nIngrese el nombre del ingrediente: " RESET, stdout);
    fgets(ingredient_names[i], BUFFER_SIZE, stdin);

    fputs(BLD "Ingrese la cantidad del ingrediente" RESET, stdout);
    float_input(&quantity_of_ingredients[i], &validate_float_g0);
  }

  fputs(BLD "\nIngrese la cantidad de instrucciones" RESET, stdout);
  int_input(&number_of_instructions, &validate_int_g0);

  for (int i = 0; i < number_of_instructions; i++) {
    fputs(BLD "\nIngrese cada instrucción para la receta: " RESET, stdout);
    fgets(instructions[i], BUFFER_SIZE, stdin);
  }

  // Actualizar datos.
  int i = data->number_of_recipes++;
  strcpy(data->recipe_names[i], recipe_name);
  data->numbers_of_ingredients[i] = number_of_ingredients;
  memcpy(data->ingredient_names[i], ingredient_names,
         sizeof data->ingredient_names[i]);
  memcpy(data->quantites_of_ingredient[i], quantity_of_ingredients,
         sizeof data->quantites_of_ingredient[i]);
  data->numbers_of_instructions[i] = number_of_instructions;
  memcpy(data->instructions[i], instructions, sizeof data->instructions[i]);

  puts(GRN "Receta creada exitosamente. Presione " BLD "ENTER " RESET GRN
           "para continuar." RESET);
  getchar();
}
