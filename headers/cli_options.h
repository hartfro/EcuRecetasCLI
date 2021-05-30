#include <data.h>

#ifndef CLI_OPTIONS_H
#define CLI_OPTIONS_H

void cli_crear_receta(RecipeData *data);
void cli_eliminar_receta();
void cli_modificar_receta();
void cli_buscar_receta(RecipeData *data);
void cli_mostrar_todas_recetas(RecipeData *data);

#endif
