#include <constants.h>

#ifndef DATA_H
#define DATA_H

typedef struct RecipeData {
  int number_of_recipes, numbers_of_ingredients[BUFFER_SIZE],
      numbers_of_instructions[BUFFER_SIZE];
  float quantites_of_ingredient[BUFFER_SIZE][BUFFER_SIZE];
  char recipe_names[BUFFER_SIZE][BUFFER_SIZE],
      ingredient_names[BUFFER_SIZE][BUFFER_SIZE],
      instructions[BUFFER_SIZE][BUFFER_SIZE];
} RecipeData;

#endif