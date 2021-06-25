#include <constants.h>

#ifndef DATA_H
#define DATA_H

void show_recipe(int i, int n_recipes, int n_ingredients[BUFFER_SIZE],
                 int n_instructions[BUFFER_SIZE],
                 float quantities_of_ingredients[BUFFER_SIZE][BUFFER_SIZE],
                 char recipe_names[BUFFER_SIZE][BUFFER_SIZE],
                 char ingredient_names[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE],
                 char instructions[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE]);

void show_all_recipes_names(int n_recipes,
                            char recipe_names[BUFFER_SIZE][BUFFER_SIZE]);

#endif
