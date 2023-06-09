#include <stdlib.h>
#include "login.c"
#include "app.c"

int main() {
  pioInit();
  
  char led[8] = {7, 8, 25, 24, 23, 18, 15, 14};

  for (int i = 0; i < 8; i++) {
    pinMode(led[i], OUTPUT);
  }

  initscr();              // Inicializar la pantalla de ncurses
  keypad(stdscr, TRUE);   // Habilitar la entrada de teclado especial
  nodelay(stdscr, TRUE);  // Configurar getch() para no bloquear
  noecho();               // No mostrar los caracteres ingresados en pantalla

  App();

  endwin();
}