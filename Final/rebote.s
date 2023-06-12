.text

.global ElReboteASMB
.global QUIT
.global DELAY
.global DELAY_3
.global DisplayBinary
.global LedOutput
.global Delay
.global Clear

ElReboteASMB:
    PUSH {R0,R1,R2,R3,R4,R5,R6,LR}                      // Guardar LR en la pila
    BL Clear                       // Llamar a la función Clear
    LDR R0, =DELAY_3               // Cargar la dirección de memoria de DELAY_3 en R0
    LDR R1, [R0]                   // Cargar el valor de DELAY_3 en R1
    MOV R6, R1                     // Guardar el valor de DELAY_3 en R6

loop_outer:
    LDRB R2, =QUIT                 // Cargar la dirección de memoria de QUIT en R2
    LDRB R2, [R2]                  // Cargar el valor de QUIT en R2
    CMP R2, #0                     // Comparar QUIT con 0
    BEQ exit_loop_outer            // Si QUIT es igual a 0, salir del bucle

    MOV R3, #0x80                  // Inicializar DISPLAY con 0x80

    MOV R4, #7                     // Inicializar r con 7

loop_inner:
    CMP R4, #0                     // Comparar r con 0
    BEQ next_outer_loop            // Si r es igual a 0, pasar al siguiente bucle externo

    LDR R5, =QUIT                  // Cargar la dirección de memoria de QUIT en R5
    LDRB R5, [R5]                  // Cargar el valor de QUIT en R5
    CMP R5, #0                     // Comparar QUIT con 0
    BEQ exit_loop_inner            // Si QUIT es igual a 0, salir del bucle

    BL DisplayBinary               // Llamar a la función DisplayBinary con DISPLAY y 3 como argumentos
    BL LedOutput                   // Llamar a la función LedOutput con DISPLAY como argumento
    MOV R5, R3                     // Guardar el valor de DISPLAY en R5
    MOV R3, R3, LSR #1             // Desplazar lógicamente DISPLAY hacia la derecha en 1 posición
    BL Delay                       // Llamar a la función Delay con el valor de DELAY en R6 como argumento

    B loop_inner                   // Saltar al principio del bucle interno

exit_loop_inner:
    SUB R4, R4, #1                 // Restar 1 a r

    MOV R5, #0x00                  // Inicializar R5 con 0x00

    CMP R4, #0                     // Comparar r con 0
    BEQ next_outer_loop            // Si r es igual a 0, pasar al siguiente bucle externo

    BL DisplayBinary               // Llamar a la función DisplayBinary con DISPLAY y 3 como argumentos
    BL LedOutput                   // Llamar a la función LedOutput con DISPLAY como argumento
    MOV R5, R3                     // Guardar el valor de DISPLAY en R5
    MOV R3, R3, LSL #1             // Desplazar lógicamente DISPLAY hacia la izquierda en 1 posición
    BL Delay                      
    POP {R0,R1,R2,R3,R4,R5,R6,PC} 