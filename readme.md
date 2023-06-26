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

### Compilación Linux (master)

```
$ gcc main.c include/cJSON.c -o main -lpthread -lncurses -lcurl
```

### Compilación Raspbian (Raspberry)

```
$ gcc espiral.s rebote.s choque.s autofantastico.s main.c include/cJSON.c -o main -lpthread -lncurses -lcurl
```

### Bot Token

```
6210586888:AAGU5lfXxmB7kqxDL6gTvINlwfUD0xanUqw
```

### Obtener ChatID

### https://api.telegram.org/bot6210586888:AAGU5lfXxmB7kqxDL6gTvINlwfUD0xanUqw/getUpdates
