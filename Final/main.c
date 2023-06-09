#include <stdlib.h>
#include "login.c"
#include "app.c"

int main() {
  //pioInit();

  /*for (int i = 0; i < 8; i++) {
    pinMode(led[i], OUTPUT);
  }*/

  initscr();              // Inicializar la pantalla de ncurses
  keypad(stdscr, TRUE);   // Habilitar la entrada de teclado especial
  nodelay(stdscr, TRUE);  // Configurar getch() para no bloquear
  noecho();               // No mostrar los caracteres ingresados en pantalla

  App();

  endwin();
}