#include <data.h>

/*
 * Functions corresponding to each entry in the menu.
 */
#ifndef CLI_OPTIONS_H
#define CLI_OPTIONS_H

void cli_crear_receta(
    int *n_recipes, int n_ingredients[BUFFER_SIZE],
    int n_instructions[BUFFER_SIZE],
    float quantities_of_ingredients[BUFFER_SIZE][BUFFER_SIZE],
    char recipe_names[BUFFER_SIZE][BUFFER_SIZE],
    char ingredient_names[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE],
    char instructions[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE]);

void cli_eliminar_receta();

void cli_modificar_receta(
    int n_recipes, int n_ingredients[BUFFER_SIZE],
    int n_instructions[BUFFER_SIZE],
    float quantities_of_ingredients[BUFFER_SIZE][BUFFER_SIZE],
    char recipe_names[BUFFER_SIZE][BUFFER_SIZE],
    char ingredient_names[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE],
    char instructions[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE]);

void cli_buscar_receta(
    int n_recipes, int n_ingredients[BUFFER_SIZE],
    int n_instructions[BUFFER_SIZE],
    float quantities_of_ingredients[BUFFER_SIZE][BUFFER_SIZE],
    char recipe_names[BUFFER_SIZE][BUFFER_SIZE],
    char ingredient_names[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE],
    char instructions[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE]);

void cli_mostrar_todas_recetas(int n_recipes,
                               char recipe_names[BUFFER_SIZE][BUFFER_SIZE]);

#endif
