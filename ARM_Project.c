#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PASSWORD "12345"
#define QUIT_KEY 'q'

void Delay(unsigned long int a) {
  a = a * 100000;
  while (a--)
    ;
}

unsigned int Login() {
  char *right_password = PASSWORD;
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
    return 1;
  } else {
    printf("\nAccess Denied!");
    return 0;
  }
}

void DisplayBinary(unsigned char DISPLAY) {
  for (unsigned int POINTER = 0x80; POINTER > 0; POINTER = POINTER >> 1) {
    if (POINTER & DISPLAY)
      printf("*");
    else
      printf("_");
  }
  printf("\n");
}

// unsigned int keyListener(unsigned int Kbhit, unsigned long int DELAY) {
//   if (Kbhit) {
//     char key = getch();
//     if (key == QUIT_KEY)
//       return 1;
//     if (key == 0 || key == -32) {
//       char flecha = getch();
//       if (flecha == 72) {
//         DELAY += 1000;
//       } else if (flecha == 80) {
//         DELAY -= 1000;
//       }
//     }
//     return 0;
//   }
// }

void AutoFantastico() {
  system("CLS");
  unsigned long int DELAY = 1000;
  while (1) {
    unsigned char DISPLAY = 0x80;
    for (int i = 0; i < 7; i++) {
      DisplayBinary(DISPLAY);
      DISPLAY = DISPLAY >> 1;
      Delay(DELAY);
    }
    for (int i = 0; i < 7; i++) {
      DisplayBinary(DISPLAY);
      DISPLAY = DISPLAY << 1;
      Delay(DELAY);
    }
  }
}

void ElChoque() {
  system("CLS");
  unsigned long int DELAY = 1000;
  while (1) {
    unsigned char SUB_DISPLAY_1 = 0x80;
    unsigned char SUB_DISPLAY_2 = 0x01;
    unsigned char DISPLAY = 0;

    for (int i = 0; i < 7; i++) {
      DISPLAY = SUB_DISPLAY_1 + SUB_DISPLAY_2;
      DisplayBinary(DISPLAY);
      SUB_DISPLAY_1 = SUB_DISPLAY_1 >> 1;
      SUB_DISPLAY_2 = SUB_DISPLAY_2 << 1;
      Delay(DELAY);
    }
  }
}

void ElRebote() {
  system("CLS");
  unsigned long int DELAY = 1000;
  while (1) {
    unsigned char DISPLAY = 0x80;

    for (int r = 7; r > 0; r--) {
      for (DISPLAY; DISPLAY != 0b1; DISPLAY = DISPLAY >> 1) {
        DisplayBinary(DISPLAY);
        Delay(DELAY);
      }
      for (int j = 0; j < r - 1; j++) {
        DisplayBinary(DISPLAY);
        DISPLAY = DISPLAY << 1;
        Delay(DELAY);
      }
    }
    DisplayBinary(DISPLAY);
    Delay(DELAY);
  }
}

void ElEspiral() {
  system("CLS");
  unsigned long int DELAY = 1000;

  unsigned char DISPLAY = 0;

  DisplayBinary(DISPLAY);

  while (1) {
    unsigned char SUB_DISPLAY_1 = 0x80;
    unsigned char SUB_DISPLAY_2 = 0x01;
    DISPLAY = 0;

    for (int i = 0; i < 4; i++) {
      DISPLAY += SUB_DISPLAY_1;
      SUB_DISPLAY_1 = SUB_DISPLAY_1 >> 1;
      DisplayBinary(DISPLAY);
      Delay(DELAY);
      DISPLAY += SUB_DISPLAY_2;
      SUB_DISPLAY_2 = SUB_DISPLAY_2 << 1;
      DisplayBinary(DISPLAY);
      Delay(DELAY);
    }
    for (int i = 0; i < 4; i++) {
      DISPLAY -= SUB_DISPLAY_2;
      SUB_DISPLAY_2 = SUB_DISPLAY_2 << 1;
      DisplayBinary(DISPLAY);
      Delay(DELAY);
      DISPLAY -= SUB_DISPLAY_1;
      SUB_DISPLAY_1 = SUB_DISPLAY_1 >> 1;
      DisplayBinary(DISPLAY);
      Delay(DELAY);
    }
  }
}

void ElCaos() {
  system("CLS");
  unsigned long int DELAY = 1000;

  unsigned char DISPLAY = 0;
  while (1) {
    unsigned char SUB_DISPLAY_1 = 0x80;
    unsigned char SUB_DISPLAY_2 = 0x01;

    for (int i = 0; i < 4; i++) {
      DISPLAY += SUB_DISPLAY_1;
      SUB_DISPLAY_1 = SUB_DISPLAY_1 >> 1;
      DisplayBinary(DISPLAY);
      Delay(DELAY);
      DISPLAY += SUB_DISPLAY_2;
      SUB_DISPLAY_2 = SUB_DISPLAY_2 << 1;
      DisplayBinary(DISPLAY);
      Delay(DELAY);
    }
    for (int i = 0; i < 4; i++) {
      DISPLAY -= SUB_DISPLAY_2;
      SUB_DISPLAY_2 = SUB_DISPLAY_2 >> 1;
      DisplayBinary(DISPLAY);
      Delay(DELAY);
      DISPLAY -= SUB_DISPLAY_1;
      SUB_DISPLAY_1 = SUB_DISPLAY_1 << 1;
      DisplayBinary(DISPLAY);
      Delay(DELAY);
    }
  }
}

void App() {
  unsigned int option;

  int i = 0;
  for (i; i < 3; i++) {
    Delay(2000);
    system("CLS");
    if (Login())
      break;
  }

  if (i == 3)
    exit(0);

  do {
    Delay(2000);
    // DisplayBinary(0);
    system("CLS");

    printf("------ S E C U E N C I A S  D E  L U C E S ------\n");
    printf("1. Auto Fantastico\n");
    printf("2. El Choque\n");
    printf("3. El Rebote\n");
    printf("4. El Espiral\n");
    printf("5. El Caos\n");
    printf("0. Salir\n");
    printf("-------------------------------------------------\n");
    printf("\nSeleccione una opcion: ");

    scanf("%d", &option);

    switch (option) {
    case 1:
      AutoFantastico();
      break;
    case 2:
      ElChoque();
      break;
    case 3:
      ElRebote();
      break;
    case 4:
      ElEspiral();
      break;
    case 5:
      ElCaos();
      break;
    case 0:
      printf("\nSaliendo del programa...\n");
      Delay(2000);
      exit(0);
      break;
    default:
      printf("\nIngrese una opcion valida\n");
      break;
    }
  } while (1);
}

int main() { App(); }