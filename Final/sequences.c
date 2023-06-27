#include "httpget.c"
//#include "include/EasyPIO.h"
#include <stdio.h>

#define QUIT_KEY 'q'
#define DELAY_INTERVAL 250
#define DEFAULT_DELAY 1000

#define BOT_TOKEN "6210586888:AAGU5lfXxmB7kqxDL6gTvINlwfUD0xanUqw"
#define CHAT_ID "1544265357"

unsigned int OFFSET = 0;

unsigned int QUIT;
size_t DELAY;
size_t DELAY_1 = DEFAULT_DELAY;
size_t DELAY_2 = DEFAULT_DELAY;
size_t DELAY_3 = DEFAULT_DELAY;
size_t DELAY_4 = DEFAULT_DELAY;
size_t DELAY_5 = DEFAULT_DELAY;

char led[8] = {7, 8, 25, 24, 23, 18, 15, 14};

void Delay(size_t a) {
  a = a * 100000;
  while (a--)
    ;
}

void MoveCursorToOrigin() {
  unsigned int i = 10;
  while (i--)
    printf("\033[F");
}

void Clear() {
  printf("\033[2J");
  MoveCursorToOrigin();
}

void DisplayBinary(unsigned char DISPLAY, unsigned int option) {
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
    printf(
        "\033[1;31mSECUENCIA:\033[0m \033[1;36mAuto Fantastico\033[0m\n\r\n\r");
    break;
  case 2:
    printf("\033[1;31mSECUENCIA:\033[0m \033[1;36mEl Choque\033[0m\n\r\n\r");
    break;
  case 3:
    printf("\033[1;31mSECUENCIA:\033[0m \033[1;36mEl Rebote\033[0m\n\r\n\r");
    break;
  case 4:
    printf("\033[1;31mSECUENCIA:\033[0m \033[1;36mEl Espiral\033[0m\n\r\n\r");
    break;
  case 5:
    printf("\033[1;31mSECUENCIA:\033[0m \033[1;36mEl Caos\033[0m\n\r\n\r");
    break;
  case 0:
    break;
  }

  printf("%s\n\n\r\033[1;33mDELAY: \033[0m%d   ", display, DELAY);

  if (option) {
    printf("\n\r\n\r");
    printf("\033[1;30mPresione la tecla Q para salir\033[0m\n\r");
  }

  MoveCursorToOrigin();
}

void LedOutput(unsigned char DISPLAY) {
  /*
  int i = 0;
  for (unsigned int POINTER = 0x80; POINTER > 0; POINTER = POINTER >> 1) {
    if (POINTER & DISPLAY) {
      digitalWrite(led[i], 1);
      i++;
    } else {
      digitalWrite(led[i], 0);
      i++;
    }
  }
  */
}

void *TelegramListener() {
  SendMessage(BOT_TOKEN, CHAT_ID,
              "¡SECUENCIA INICIADA!\n\n\rComandos:\n\r- /speedup\n\r- /speeddown\n\r- /exit");

  while (!QUIT) {
    http_return telegram_option = GetMessage(BOT_TOKEN, OFFSET);
    if (telegram_option.update_id != 0) {
      OFFSET = telegram_option.update_id + 1;
    }

    char *op = telegram_option.text;

    if (strcmp(op, "/exit") == 0)
      QUIT = 1;
    else if (strcmp(op, "/speedup") == 0) {
      if (DELAY - DELAY_INTERVAL != 0)
        DELAY -= DELAY_INTERVAL;
    } else if (strcmp(op, "/speeddown") == 0) {
      DELAY += DELAY_INTERVAL;
    }
  }
}

void *KeyListener() {
  while (!QUIT) {
    int key = getch();
    if (key == QUIT_KEY)
      QUIT = 1;
    else if (key == KEY_UP) {
      if (DELAY - DELAY_INTERVAL != 0)
        DELAY -= DELAY_INTERVAL;
    } else if (key == KEY_DOWN) {
      DELAY += DELAY_INTERVAL;
    }
  }
}

void *AutoFantastico() {
  Clear();
  DELAY = DELAY_1;
  while (!QUIT) {
    unsigned char DISPLAY = 0x80;
    for (int i = 0; i < 7; i++) {
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 1);
      LedOutput(DISPLAY);
      DISPLAY = DISPLAY >> 1;
      Delay(DELAY);
    }
    for (int i = 0; i < 7; i++) {
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 1);
      LedOutput(DISPLAY);
      DISPLAY = DISPLAY << 1;
      Delay(DELAY);
    }
  }
  DELAY_1 = DELAY;
}

void *ElChoque() {
  Clear();
  DELAY = DELAY_2;
  unsigned int table[] = {0x42, 0x24, 0x18, 0x24, 0x42, 0x81};
  unsigned char DISPLAY = 0x81;
  while (!QUIT) {

    int table_size = sizeof(table) / sizeof(table[0]);

    for (int i = 0; i < table_size; i++) {
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 2);
      LedOutput(DISPLAY);
      DISPLAY = table[i];
      Delay(DELAY);
    }
  }
  DELAY_2 = DELAY;
}

void *ElRebote() {
  Clear();
  DELAY = DELAY_3;
  while (!QUIT) {
    unsigned char DISPLAY = 0x80;

    for (int r = 7; r > 0; r--) {
      for (DISPLAY; DISPLAY != 0b1; DISPLAY = DISPLAY >> 1) {
        if (QUIT)
          break;
        DisplayBinary(DISPLAY, 3);
        LedOutput(DISPLAY);
        Delay(DELAY);
      }
      for (int j = 0; j < r - 1; j++) {
        if (QUIT)
          break;
        DisplayBinary(DISPLAY, 3);
        LedOutput(DISPLAY);
        DISPLAY = DISPLAY << 1;
        Delay(DELAY);
      }
    }
    if (QUIT)
      break;
    DisplayBinary(DISPLAY, 3);
    LedOutput(DISPLAY);
    Delay(DELAY);
  }
  DELAY_3 = DELAY;
}

void *ElEspiral() {
  Clear();
  DELAY = DELAY_4;
  unsigned int table[] = {0x80, 0x81, 0xC1, 0xC3, 0xE3, 0xE7, 0xF7, 0xFF,
                          0xEF, 0xE7, 0xC7, 0xC3, 0x83, 0x81, 0x1,  0x0};
  unsigned char DISPLAY = 0;
  while (!QUIT) {

    int table_size = sizeof(table) / sizeof(table[0]);

    for (int i = 0; i < table_size; i++) {
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 4);
      LedOutput(DISPLAY);
      DISPLAY = table[i];
      Delay(DELAY);
    }
  }
  DELAY_4 = DELAY;
}

void *ElCaos() {
  Clear();
  DELAY = DELAY_5;
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
      LedOutput(DISPLAY);
      Delay(DELAY);
      DISPLAY += SUB_DISPLAY_2;
      SUB_DISPLAY_2 = SUB_DISPLAY_2 << 1;
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 5);
      LedOutput(DISPLAY);
      Delay(DELAY);
    }
    for (int i = 0; i < 4; i++) {
      DISPLAY -= SUB_DISPLAY_2;
      SUB_DISPLAY_2 = SUB_DISPLAY_2 >> 1;
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 5);
      LedOutput(DISPLAY);
      Delay(DELAY);
      DISPLAY -= SUB_DISPLAY_1;
      SUB_DISPLAY_1 = SUB_DISPLAY_1 << 1;
      if (QUIT)
        break;
      DisplayBinary(DISPLAY, 5);
      LedOutput(DISPLAY);
      Delay(DELAY);
    }
  }
  DELAY_5 = DELAY;
}