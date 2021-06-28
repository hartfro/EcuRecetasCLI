#include <constants.h>

#ifndef DATA_H
#define DATA_H

int search_recipe_by_name(char name[BUFFER_SIZE], int n_recipes,
                          char recipe_names[BUFFER_SIZE][BUFFER_SIZE]);

void show_recipe(int i, int n_recipes, int n_ingredients[BUFFER_SIZE],
                 int n_instructions[BUFFER_SIZE],
                 float quantities_of_ingredients[BUFFER_SIZE][BUFFER_SIZE],
                 char recipe_names[BUFFER_SIZE][BUFFER_SIZE],
                 char ingredient_names[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE],
                 char instructions[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE]);

void show_all_recipes_names(int n_recipes,
                            char recipe_names[BUFFER_SIZE][BUFFER_SIZE]);

void modify_recipe(int i, char new_name[BUFFER_SIZE], int new_n_ingredients,
                   char new_ingredients[BUFFER_SIZE][BUFFER_SIZE],
                   float new_quantities_of_ingredients[BUFFER_SIZE],
                   int new_n_instructions,
                   char new_instructions[BUFFER_SIZE][BUFFER_SIZE],
                   int n_ingredients[BUFFER_SIZE],
                   int n_instructions[BUFFER_SIZE],
                   float quantities_of_ingredients[BUFFER_SIZE][BUFFER_SIZE],
                   char recipe_names[BUFFER_SIZE][BUFFER_SIZE],
                   char ingredient_names[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE],
                   char instructions[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE]);
#endif
