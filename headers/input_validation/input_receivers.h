#include <stdbool.h>

#ifndef INPUT_RECEIVERS_H
#define INPUT_RECEIVERS_H

/**
 * Recibe input de tipo int por el stdin y no permite continuar hasta
 * que este sea válido. Devuelve true a menos que el usuario haya ingresado
 * un valor en blanco (solo si blank=true).
 *
 * @param *x es la variable que guardará el input del usuario.
 * @param *validator es una función que devuelve true si el input es correcto.
 * @param blank si se permiten inputs en blanco.
 */
bool int_input(int *x, bool (*validator)(int a), bool blank);

/**
 * Recibe input de tipo float por el stdin y no permite continuar hasta
 * que este sea válido.
 *
 * @param *x es la variable que guardará el input del usuario.
 * @param *validator es una función que devuelve true si el input es correcto.
 */
bool float_input(float *x, bool (*validator)(float a), bool blank);

#endif
