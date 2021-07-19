#include <stdio.h>
#include <string.h>

void remove_last_char(char *string) {
  string[strlen(string) - 1] = '\0'; // Remove last \n character.
}
