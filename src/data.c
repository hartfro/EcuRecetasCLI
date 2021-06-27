#include <data.h>
#include <stdio.h>
#include <string.h>
#include <style.h>

/* Searches a recipe by name and returns its index. */
int search_recipe_by_name(char name[BUFFER_SIZE], int n_recipes,
                          char recipe_names[BUFFER_SIZE][BUFFER_SIZE]) {
  for (int i = 0; i < n_recipes; i++) {
    if (strcmp(name, recipe_names[i]) == 0)
      return i;
  }

  return -1;
}

void show_recipe(int i, int n_recipes, int n_ingredients[BUFFER_SIZE],
                 int n_instructions[BUFFER_SIZE],
                 float quantities_of_ingredients[BUFFER_SIZE][BUFFER_SIZE],
                 char recipe_names[BUFFER_SIZE][BUFFER_SIZE],
                 char ingredient_names[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE],
                 char instructions[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE]) {
  printf(BLU "Nombre: " RESET "%s\n", recipe_names[i]);
  puts(BLU "Ingredientes: " RESET);

  for (int j = 0; j < n_ingredients[i]; j++)
    printf("\t- %s\t%.2f\n", ingredient_names[i][j],
           quantities_of_ingredients[i][j]);

  puts(BLU "\nInstrucciones:" RESET);
  for (int j = 0; j < n_instructions[i]; j++)
    printf("\t%i. %s\n", j + 1, instructions[i][j]);
}

void show_all_recipes_names(int n_recipes,
                            char recipe_names[BUFFER_SIZE][BUFFER_SIZE]) {
  for (int i = 0; i < n_recipes; i++) {
    printf(BLU "%i. " RESET "%s\n", i + 1, recipe_names[i]);
  }
}
