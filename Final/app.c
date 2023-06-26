#include "sequences.c"
#include <pthread.h>

// extern void AutoFantasticoASMB();
// extern void ElChoqueASMB();
// extern void ElReboteASMB();
// extern void ElEspiralASMB();

char OPTION = 'O';

// void *AutoFantasticoASMBP() {
//   AutoFantasticoASMB();
//   return NULL;
// }

// void *ElChoqueASMBP() {
//   ElChoqueASMB();
//   return NULL;
// }

// void *ElReboteASMBP() {
//   ElReboteASMB();
//   return NULL;
// }

// void *ElEspiralASMBP() {
//   ElEspiralASMB();
//   return NULL;
// }

void *ConsoleMenu() {
  printf("------ S E C U E N C I A S  D E  L U C E S ------\n\r");
  printf("1. Auto Fantastico\n\r");
  printf("2. El Choque\n\r");
  printf("3. El Rebote\n\r");
  printf("4. El Espiral\n\r");
  printf("5. El Caos\n\r");
  printf("0. Salir\n\r");
  printf("-------------------------------------------------\n\r");
  printf("\n\rSeleccione una opcion: ");

  OPTION = getchar();
}

void *TelegramMenu() {
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
  } while (telegram_option.update_id == lastUpdateID && OPTION == 'O');

  char *TelegramMenuOption = telegram_option.text;

  if (OPTION == 'O') {
    OPTION = telegram_option.text[0];
  }
}

void App() {
  Clear();

  int i = 0, a = 0;
  for (i; i < 3; i++) {
    Delay(2000);
    Clear();
    if (Login())
      break;
  }

  if (i == 3)
    exit(0);

  do {
    OPTION = 'O';
    Delay(2000);
    DisplayBinary(0, 0);
    LedOutput(0);
    Clear();
    printf("\033[?25h");

    pthread_t menuThreads[2];

    pthread_create(&menuThreads[0], NULL, ConsoleMenu, NULL);
    pthread_create(&menuThreads[1], NULL, TelegramMenu, NULL);
    pthread_join(menuThreads[1], NULL);
    pthread_cancel(menuThreads[0]);

    printf("\033[?25l");

    switch (OPTION) {
      pthread_t threads[3];

    case '1':
      pthread_create(&threads[0], NULL, AutoFantastico, NULL);
      pthread_create(&threads[1], NULL, KeyListener, NULL);
      pthread_create(&threads[2], NULL, TelegramListener, NULL);
      pthread_join(threads[0], NULL);
      pthread_join(threads[1], NULL);
      pthread_join(threads[2], NULL);
      QUIT = 0;
      break;

    case '2':
      pthread_create(&threads[0], NULL, ElChoque, NULL);
      pthread_create(&threads[1], NULL, KeyListener, NULL);
      pthread_create(&threads[2], NULL, TelegramListener, NULL);
      pthread_join(threads[0], NULL);
      pthread_join(threads[1], NULL);
      pthread_join(threads[2], NULL);
      QUIT = 0;
      break;

    case '3':
      pthread_create(&threads[0], NULL, ElRebote, NULL);
      pthread_create(&threads[1], NULL, KeyListener, NULL);
      pthread_create(&threads[2], NULL, TelegramListener, NULL);
      pthread_join(threads[0], NULL);
      pthread_join(threads[1], NULL);
      pthread_join(threads[2], NULL);
      QUIT = 0;
      break;

    case '4':
      pthread_create(&threads[0], NULL, ElEspiral, NULL);
      pthread_create(&threads[1], NULL, KeyListener, NULL);
      pthread_create(&threads[2], NULL, TelegramListener, NULL);
      pthread_join(threads[0], NULL);
      pthread_join(threads[1], NULL);
      pthread_join(threads[2], NULL);
      QUIT = 0;
      break;

    case '5':
      pthread_create(&threads[0], NULL, ElCaos, NULL);
      pthread_create(&threads[1], NULL, KeyListener, NULL);
      pthread_create(&threads[2], NULL, TelegramListener, NULL);
      pthread_join(threads[0], NULL);
      pthread_join(threads[1], NULL);
      pthread_join(threads[2], NULL);
      QUIT = 0;
      break;

    case '0':
      printf("\n\rSaliendo del programa...\n\r");
      Delay(2000);
      Clear();
      a = 1;
      break;

    default:
      printf("\n\rIngrese una opcion valida\n\r");
      break;
    }
  } while (a == 0);
}
