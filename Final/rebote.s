.text
.global ELReboteASMB
.global QUIT
.global DELAY
.global DELAY_3
.global DisplayBinary
.global LedOutput
.global Delay


ElReboteASMB:
    PUSH {R0, R4, R5, R6, R7, R8, R9, R10, R11, R12, LR}
    MOV R4, #0 // Init DISPLAY with 0
    LDR R11, =DELAY_3 // DELAY_3(Address)
    LDR R6, [R11] // DELAY_3(Value)
    LDR R9, =DELAY // DELAY(Address)
    STR R6, [R9] // DELAY = DELAY_3
    LDR R10, =QUIT // QUIT(Address)

    while:
        MOV R8, #7 // Init r = 0, for loop
        for:
        MOV R4, #0 // Init DISPLAYcounter = 0, for loop_outer
        MOV R12, #0 // Init j = 0, for loop_inner
            for_outer:
                LDR R7, [R10]
                CMP R7, #1
                BEQ break

                MOV R0, R4
                MOV R1, #4
                BL DisplayBinary

                MOV R0, R4
                BL LedOutput

                LSR R4, R5, #1
                 
                LDR R6, [R9]
                CMP R0, R6
                BL Delay

                ADD R5, R5, #1
                CMP R5, 0b1
                BLT for_outer

            for_inner:
                LDR R7, [R10]
                CMP R7, #1
                BEQ break

                MOV R0, R4
                MOV R1, #4
                BL DisplayBinary

                MOV R0, R4
                BL LedOutput

                LSL R4, R12, #1

                LDR R6, [R9]
                CMP R0, R6
                BL Delay

                ADD R12, R12, #1
                SUB R8, R8, #1
                CMP R12, R8
                ADD R8, R8, #1
                BLT for_inner

            SUB R8, R8, #1
            CMP R8, #7
            BLT for


        LDR R6, [R1]
        CMP R7, #0
        BEQ while

    break:
    STR R6, [R11]
    MOV R0, #0
    STR R0, [R10]
    POP {R0, R4, R5, R6, R7, R8, R9, R10, R11, PC}

.data

/*ELReboteASMB:
    PUSH {LR}                      // Guardar LR en la pila
    BL Clear                       // Llamar a la función Clear
    LDR R0, =DELAY_3               // Cargar la dirección de memoria de DELAY_3 en R0
    LDR R1, [R0]                   // Cargar el valor de DELAY_3 en R1
    MOV R6, R1                     // Guardar el valor de DELAY_3 en R6

LoopOuter:
    LDRB R2, =QUIT                 // Cargar la dirección de memoria de QUIT en R2
    LDRB R2, [R2]                  // Cargar el valor de QUIT en R2
    CMP R2, #1                     // Comparar QUIT con 0
    BEQ exit_loop_outer            // Si QUIT es igual a 0, salir del bucle

    MOV R3, #0x80                  // Inicializar DISPLAY con 0x80

    MOV R4, #7                     // Inicializar r con 7

LoopInner:
    CMP R4, #0                     // Comparar r con 0
    BEQ next_outer_loop            // Si r es igual a 0, pasar al siguiente bucle externo

    LDR R5, =QUIT                  // Cargar la dirección de memoria de QUIT en R5
    LDRB R5, [R5]                  // Cargar el valor de QUIT en R5
    CMP R5, #1                     // Comparar QUIT con 0
    BEQ ExitLoopInner            // Si QUIT es igual a 0, salir del bucle

    BL DisplayBinary               // Llamar a la función DisplayBinary con DISPLAY y 3 como argumentos
    BL LedOutput                   // Llamar a la función LedOutput con DISPLAY como argumento
    MOV R5, R3                     // Guardar el valor de DISPLAY en R5
    MOV R3, R3, LSR #1             // Desplazar lógicamente DISPLAY hacia la derecha en 1 posición
    BL Delay                       // Llamar a la función Delay con el valor de DELAY en R6 como argumento

    B LoopInner                   // Saltar al principio del bucle interno

ExitLoopInner:
    SUB R4, R4, #1                 // Restar 1 a r

    MOV R5, #0x00                  // Inicializar R5 con 0x00

    CMP R4, #0                     // Comparar r con 0
    BEQ next_outer_loop            // Si r es igual a 0, pasar al siguiente bucle externo

    BL DisplayBinary               // Llamar a la función DisplayBinary con DISPLAY y 3 como argumentos
    BL LedOutput                   // Llamar a la función LedOutput con DISPLAY como argumento
    MOV R5, R3                     // Guardar el valor de DISPLAY en R5
    MOV R3, R3, LSL #1             // Desplazar lógicamente DISPLAY hacia la izquierda en 1 posición
    BL Delay*/                      
