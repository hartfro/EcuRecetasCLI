/*
 * Constants to style terminal output with colors and decorations.
 */
#ifndef COLORS_H
#define COLORS_H

#define ESC "\x1B"
#define RESET ESC "[0m"

#define CLR "\e[1;1H\e[2J"

#define BLD ESC "[1m"
#define DIM ESC "[2m"
#define ITL ESC "[3m"
#define UNDR ESC "[4m"
#define BLNK ESC "[5m"
#define STRK ESC "[9m"

#define RED ESC "[31m"
#define GRN ESC "[32m"
#define YEL ESC "[33m"
#define BLU ESC "[34m"
#define MAG ESC "[35m"
#define CYN ESC "[36m"
#define WHT ESC "[37m"

#endif
