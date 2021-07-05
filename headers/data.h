#include <constants.h>

#ifndef DATA_H
#define DATA_H

typedef struct Recipe {
  char name[BUFFER_SIZE];

  int n_ingredients;
  float quantities_of_ingredients[BUFFER_SIZE];
  char ingredients[BUFFER_SIZE][BUFFER_SIZE];

  int n_instructions;
  char instructions[BUFFER_SIZE][BUFFER_SIZE];
} Recipe;

void init_recipe(Recipe *recipe, char name[BUFFER_SIZE], int n_ingredients,
                 float quantities_of_ingredients[BUFFER_SIZE],
                 char ingredients[BUFFER_SIZE][BUFFER_SIZE], int n_instructions,
                 char instructions[BUFFER_SIZE][BUFFER_SIZE]);

int search_recipe_by_name(char name[], int n_recipes, Recipe recipes[]);

void show_recipe(int i, Recipe recipes[]);

void show_all_recipes_names(int n_recipes, Recipe recipes[]);

void modify_recipe(int i, Recipe recipes[], char name[BUFFER_SIZE],
                   int new_n_ingredients,
                   float new_quantities_of_ingredients[BUFFER_SIZE],
                   char new_ingredients[BUFFER_SIZE][BUFFER_SIZE],
                   int new_n_instructions,
                   char new_instructions[BUFFER_SIZE][BUFFER_SIZE]);

void remove_recipe_from_array(int i, int *n_recipes, int array_length,
                              Recipe recipes[]);
#endif
