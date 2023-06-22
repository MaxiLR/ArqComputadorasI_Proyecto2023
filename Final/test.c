#include "httpget.c"
#include <stdio.h>

#define BOT_TOKEN "6210586888:AAGU5lfXxmB7kqxDL6gTvINlwfUD0xanUqw"
#define CHAT_ID "1544265357"

unsigned int OFFSET = 0;

void TelegramMenuOptionListener() {
  http_return telegram_option = GetMessage(BOT_TOKEN, OFFSET);
  int lastUpdateID = telegram_option.update_id;

  SendMessage(BOT_TOKEN, CHAT_ID,
              "------ S E C U E N C I A S  D E  L U C E S ------\n\r1. Auto "
              "Fantastico\n\r2. El Choque\n\r3. El Rebote\n\r4. El "
              "Espiral\n\r5. El Caos\n\r0. "
              "Salir\n\r-------------------------------------------------------"
              "-------");
  SendMessage(BOT_TOKEN, CHAT_ID, "Ingrese una opción");

  do {
    telegram_option = GetMessage(BOT_TOKEN, OFFSET);
  } while (telegram_option.update_id == lastUpdateID);

  char *TelegramMenuOption = telegram_option.text;

  printf("%s", TelegramMenuOption);
}

int main() { TelegramMenuOptionListener(); }