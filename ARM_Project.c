#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delay(unsigned long int a) {
  while (a--)
    ;
}

int login() {
  char *right_password = "MAXIG";
  char input[5];
  int i = 0;
  char c;
  printf("Ingrese su password de 5 digitos: ");

  while (c = getch()) {
    if (c == 13) {
      input[i] = '\0';
      break;

    } else if (c == 8) {
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

  int Auth = 0;
  for (int i = 0; i < 5; i++) {
    if (input[i] != right_password[i]) {
      Auth = 0;
      break;
    }
    Auth = 1;
  }

  if (Auth) {
    printf("\nAccess Granted!");
  } else {
    printf("\nAccess Denied!");
    exit(0);
  }
}

int main() { login("HOLA"); }