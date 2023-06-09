#include <ncurses.h>
#include <string.h>

#define PASSWORD "12345"

unsigned int Login() {
  char *right_password = PASSWORD;
  char input[5];
  int i = 0;
  char c;
  printf("Ingrese su password de 5 digitos: ");

 while (1) {
    c = getchar();

    if (c == '\n') {
      input[i] = '\0';
      break;
    } else if (c == 127 || c == '\b') {
      if (i > 0) {
        i--;
        printf("\b \b");
      }
    } else {
      if (i < 5) {
        printf("*");
        input[i] = c;
        i++;
      }
    }
    if (i == 5)
      break;
  }

input[i] = '\0';

if (strcmp(input, right_password) == 0) {
  printf("\n\rAcceso concedido\n\r");
  return 1;
} else {
  printf("\n\rAcceso denegado\n\r");
  return 0;
}
}
