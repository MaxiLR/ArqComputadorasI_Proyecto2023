# Proyecto Arquitectura de Computadoras I

### Año: 2023
### Integrantes:
- LUCERO RUIZ, Maximo
- QUESADA, Santiago

### Instalar Librerías

```
$ sudo apt install libncurses5-dev
$ sudo apt install libcurl4-openssl-dev
```
### Compilación Linux/Raspbian

```
$ gcc espiral.s rebote.s main.c -o main -lpthread -lncurses -lcurl
``` 