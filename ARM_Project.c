#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// CONSTANTS
#define PASSWORD "12345"
#define QUIT_KEY 'q'
#define DELAY_INTERVAL 250
#define DEFAULT_DELAY 1000

unsigned int QUIT;
size_t DELAY = DEFAULT_DELAY;

void Delay(size_t a) {
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

void DisplayBinary(unsigned char DISPLAY, unsigned int option) {
  system("CLS");
  char display[8];
  int i = 0;
  for (unsigned int POINTER = 0x80; POINTER > 0; POINTER = POINTER >> 1) {
    if (POINTER & DISPLAY) {
      display[i] = '*';
      i++;
    } else {
      display[i] = '_';
      i++;
    }
  }

  switch (option) {
  case 1:
    printf("SECUENCIA: Auto Fantastico\n\n");
    break;
  case 2:
    printf("SECUENCIA: El Choque\n\n");
    break;
  case 3:
    printf("SECUENCIA: El Rebote\n\n");
    break;
  case 4:
    printf("SECUENCIA: El Espiral\n\n");
    break;
  case 5:
    printf("SECUENCIA: El Caos\n\n");
    break;
  case 0:
    break;
  }

  printf(display);
  if (option) {
    printf("\n\n");
    printf("Presione la tecla Q para salir");
  }
}

DWORD WINAPI keyListener() {
  while (!QUIT) {
    if (kbhit()) {
      char key = getch();
      if (key == QUIT_KEY)
        QUIT = 1;
      else if (key == 0 || key == -32) {
        char arrow = getch();
        if (arrow == 72) {
          if (DELAY - DELAY_INTERVAL != 0)
            DELAY -= DELAY_INTERVAL;
        } else if (arrow == 80) {
          DELAY += DELAY_INTERVAL;
        }
      }
    }
  }
}

DWORD WINAPI AutoFantastico() {
  system("CLS");
  while (!QUIT) {
    unsigned char DISPLAY = 0x80;
    for (int i = 0; i < 7; i++) {
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 1);
      DISPLAY = DISPLAY >> 1;
      Delay(DELAY);
    }
    for (int i = 0; i < 7; i++) {
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 1);
      DISPLAY = DISPLAY << 1;
      Delay(DELAY);
    }
  }
}

DWORD WINAPI ElChoque() {
  system("CLS");
  while (!QUIT) {
    unsigned char SUB_DISPLAY_1 = 0x80;
    unsigned char SUB_DISPLAY_2 = 0x01;
    unsigned char DISPLAY = 0;

    for (int i = 0; i < 7; i++) {
      DISPLAY = SUB_DISPLAY_1 + SUB_DISPLAY_2;
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 2);
      SUB_DISPLAY_1 = SUB_DISPLAY_1 >> 1;
      SUB_DISPLAY_2 = SUB_DISPLAY_2 << 1;
      Delay(DELAY);
    }
  }
}

DWORD WINAPI ElRebote() {
  system("CLS");
  while (!QUIT) {
    unsigned char DISPLAY = 0x80;

    for (int r = 7; r > 0; r--) {
      for (DISPLAY; DISPLAY != 0b1; DISPLAY = DISPLAY >> 1) {
        if (QUIT)
          break;
        DisplayBinary(DISPLAY, 3);
        Delay(DELAY);
      }
      for (int j = 0; j < r - 1; j++) {
        if (QUIT)
          break;
        DisplayBinary(DISPLAY, 3);
        DISPLAY = DISPLAY << 1;
        Delay(DELAY);
      }
    }
    if (QUIT)
      break;
    DisplayBinary(DISPLAY, 3);
    Delay(DELAY);
  }
}

DWORD WINAPI ElEspiral() {
  system("CLS");
  unsigned char DISPLAY = 0;

  DisplayBinary(DISPLAY, 4);

  while (!QUIT) {
    unsigned char SUB_DISPLAY_1 = 0x80;
    unsigned char SUB_DISPLAY_2 = 0x01;
    DISPLAY = 0;

    for (int i = 0; i < 4; i++) {
      DISPLAY += SUB_DISPLAY_1;
      SUB_DISPLAY_1 = SUB_DISPLAY_1 >> 1;
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 4);
      Delay(DELAY);
      DISPLAY += SUB_DISPLAY_2;
      SUB_DISPLAY_2 = SUB_DISPLAY_2 << 1;
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 4);
      Delay(DELAY);
    }
    for (int i = 0; i < 4; i++) {
      DISPLAY -= SUB_DISPLAY_2;
      SUB_DISPLAY_2 = SUB_DISPLAY_2 << 1;
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 4);
      Delay(DELAY);
      DISPLAY -= SUB_DISPLAY_1;
      SUB_DISPLAY_1 = SUB_DISPLAY_1 >> 1;
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 4);
      Delay(DELAY);
    }
  }
}

DWORD WINAPI ElCaos() {
  system("CLS");
  unsigned char DISPLAY = 0;
  while (!QUIT) {
    unsigned char SUB_DISPLAY_1 = 0x80;
    unsigned char SUB_DISPLAY_2 = 0x01;

    for (int i = 0; i < 4; i++) {
      DISPLAY += SUB_DISPLAY_1;
      SUB_DISPLAY_1 = SUB_DISPLAY_1 >> 1;
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 5);
      Delay(DELAY);
      DISPLAY += SUB_DISPLAY_2;
      SUB_DISPLAY_2 = SUB_DISPLAY_2 << 1;
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 5);
      Delay(DELAY);
    }
    for (int i = 0; i < 4; i++) {
      DISPLAY -= SUB_DISPLAY_2;
      SUB_DISPLAY_2 = SUB_DISPLAY_2 >> 1;
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 5);
      Delay(DELAY);
      DISPLAY -= SUB_DISPLAY_1;
      SUB_DISPLAY_1 = SUB_DISPLAY_1 << 1;
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 5);
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
    DisplayBinary(0, 0);
    system("CLS");
    printf("\033[?25h");
    QUIT = 0;
    // DELAY = DEFAULT_DELAY;

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
    printf("\033[?25l");

    HANDLE threads[2];
    DWORD threadIds[2];
    switch (option) {
    case 1:
      threads[0] = CreateThread(NULL, 0, keyListener, NULL, 0, &threadIds[0]);
      threads[1] =
          CreateThread(NULL, 0, AutoFantastico, NULL, 0, &threadIds[1]);
      WaitForMultipleObjects(2, threads, TRUE, INFINITE);
      CloseHandle(threads[0]);
      CloseHandle(threads[1]);
      break;
    case 2:
      threads[0] = CreateThread(NULL, 0, keyListener, NULL, 0, &threadIds[0]);
      threads[1] = CreateThread(NULL, 0, ElChoque, NULL, 0, &threadIds[1]);
      WaitForMultipleObjects(2, threads, TRUE, INFINITE);
      CloseHandle(threads[0]);
      CloseHandle(threads[1]);
      break;
    case 3:
      threads[0] = CreateThread(NULL, 0, keyListener, NULL, 0, &threadIds[0]);
      threads[1] = CreateThread(NULL, 0, ElRebote, NULL, 0, &threadIds[1]);
      WaitForMultipleObjects(2, threads, TRUE, INFINITE);
      CloseHandle(threads[0]);
      CloseHandle(threads[1]);
      break;
    case 4:
      threads[0] = CreateThread(NULL, 0, keyListener, NULL, 0, &threadIds[0]);
      threads[1] = CreateThread(NULL, 0, ElEspiral, NULL, 0, &threadIds[1]);
      WaitForMultipleObjects(2, threads, TRUE, INFINITE);
      CloseHandle(threads[0]);
      CloseHandle(threads[1]);
      break;
    case 5:
      threads[0] = CreateThread(NULL, 0, keyListener, NULL, 0, &threadIds[0]);
      threads[1] = CreateThread(NULL, 0, ElCaos, NULL, 0, &threadIds[1]);
      WaitForMultipleObjects(2, threads, TRUE, INFINITE);
      CloseHandle(threads[0]);
      CloseHandle(threads[1]);
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