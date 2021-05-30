#include <data.h>
#include <stdio.h>
#include <style.h>

void show_recipe(RecipeData *data, int i) {
  printf(BLU "Nombre: " RESET "%s\n", data->recipe_names[i]);
  puts(BLU "Ingredientes: " RESET);

  for (int j = 0; j < data->numbers_of_ingredients[i]; j++)
    printf("\t- %s\t%.2f\n", data->ingredient_names[i][j],
           data->quantites_of_ingredient[i][j]);

  puts(BLU "\nInstrucciones:" RESET);
  for (int j = 0; j < data->numbers_of_instructions[i]; j++)
    printf("\t%i. %s\n", j + 1, data->instructions[i][j]);
}

void show_all_recipes(RecipeData *data) {
  for (int i = 0; i < data->number_of_recipes; i++) {
    printf(BLU "%i. " RESET "%s\n", i + 1, data->recipe_names[i]);
  }
}
