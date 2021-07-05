#include <data.h>

/*
 * Functions corresponding to each entry in the menu.
 */
#ifndef CLI_OPTIONS_H
#define CLI_OPTIONS_H

void cli_crear_receta(int *n_recipes, Recipe recipes[]);

void cli_eliminar_receta(int *n_recipes, int array_length, Recipe recipes[]);

void cli_modificar_receta(int n_recipes, Recipe recipes[]);

void cli_buscar_receta(int n_recipes, Recipe recipes[]);

void cli_mostrar_todas_recetas(int n_recipes, Recipe recipes[]);

#endif
