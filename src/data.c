#include <assert.h>
#include <data.h>
#include <stdio.h>
#include <string.h>
#include <style.h>

void init_recipe(Recipe *recipe, char name[BUFFER_SIZE], int n_ingredients,
                 float quantities_of_ingredients[BUFFER_SIZE],
                 char ingredients[BUFFER_SIZE][BUFFER_SIZE], int n_instructions,
                 char instructions[BUFFER_SIZE][BUFFER_SIZE]) {
  strcpy(recipe->name, name);

  recipe->n_ingredients = n_ingredients;
  memcpy(recipe->quantities_of_ingredients, quantities_of_ingredients,
         sizeof recipe->quantities_of_ingredients);
  memcpy(recipe->ingredients, ingredients, sizeof recipe->ingredients);

  recipe->n_instructions = n_instructions;
  memcpy(recipe->instructions, instructions, sizeof recipe->instructions);
}

/* Searches a recipe by name and returns its index. */
int search_recipe_by_name(char name[BUFFER_SIZE], int n_recipes,
                          Recipe recipes[]) {
  for (int i = 0; i < n_recipes; i++) {
    if (strcmp(name, recipes[i].name) == 0)
      return i;
  }

  return -1;
}

void modify_recipe(int i, Recipe recipes[], char name[BUFFER_SIZE],
                   int new_n_ingredients,
                   float new_quantities_of_ingredients[BUFFER_SIZE],
                   char new_ingredients[BUFFER_SIZE][BUFFER_SIZE],
                   int new_n_instructions,
                   char new_instructions[BUFFER_SIZE][BUFFER_SIZE]) {
  init_recipe(&recipes[i], name, new_n_ingredients,
              new_quantities_of_ingredients, new_ingredients,
              new_n_instructions, new_instructions);
}

void show_recipe(int i, Recipe recipes[]) {
  printf(BLU "Nombre: " RESET "%s\n", recipes[i].name);
  puts(BLU "Ingredientes: " RESET);

  for (int j = 0; j < recipes[i].n_ingredients; j++)
    printf("\t- %s\t%.2f\n", recipes[i].ingredients[j],
           recipes[i].quantities_of_ingredients[j]);

  puts(BLU "\nInstrucciones:" RESET);
  for (int j = 0; j < recipes[i].n_instructions; j++)
    printf("\t%i. %s\n", j + 1, recipes[i].instructions[j]);
}

void show_all_recipes_names(int n_recipes, Recipe recipes[]) {
  for (int i = 0; i < n_recipes; i++) {
    printf(BLU "%i. " RESET "%s\n", i + 1, recipes[i].name);
  }
}

/*
 * "Moves" each recipe on the right if i one index to the left.
 */
void remove_recipe_from_array(int i, int *n_recipes, int array_length,
                              Recipe recipes[]) {
  for (int j = i; j < *n_recipes - 1; j++)
    if (j != array_length - 1)
      recipes[j] = recipes[j + 1];

  *n_recipes = *n_recipes - 1;
}
