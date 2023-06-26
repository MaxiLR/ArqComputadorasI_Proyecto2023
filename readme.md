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
$ gcc espiral.s rebote.s choque.s autofantastico.s main.c include/cJSON.c -o main -lpthread -lncurses -lcurl
``` 