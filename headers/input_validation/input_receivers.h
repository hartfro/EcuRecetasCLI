#include <stdbool.h>

#ifndef INPUT_RECEIVERS_H
#define INPUT_RECEIVERS_H

/**
 * Recibe input de tipo int por el stdin y no permite continuar hasta
 * que este sea válido.
 *
 * @param *x es la variable que guardará el input del usuario.
 * @param *validator es una función que devuelve true si el input es correcto.
 */
void int_input(int *x, bool(*validator)(int a));

#endif
