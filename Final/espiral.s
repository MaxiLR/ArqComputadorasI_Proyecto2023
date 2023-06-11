.text
.global	ElEspiralASMB

ElEspiralASMB:
	PUSH {R4,R5,R6,R7,R8,LR}
	MOV R4, #0 // Init DISPLAY with 0
	LDR R6, =DELAY_4 // DELAY(Value)
	STR R6, =DELAY
	LDR R8, =table

	while:
		MOV R5, #0 // Init i = 0, for loop
		for:
			LDR R7, =QUIT // QUIT(Value)
			CMP R7, #1
			BEQ break

			MOV R0, R4
			MOV R1, #4
			BL DisplayBinary
			
			MOV R0, R4
			BL LedOutput
			
			LDRB R4, [R8, R5] // DISPLAY = table[i]

			LDR R6, =DELAY
			MOV R0, R6
			BL Delay

			ADD R5, R5, #1
			CMP R5, #16
			BLT for

		LDR R7, =QUIT // QUIT(Value)
		CMP R7, #0
		BEQ while

	break:
	STR R6, =DELAY_4
	STR #0, =QUIT
	POP {R4,R5,R6,R7,R8,PC}
		
.data
		
table: // #16
	.byte 0x80
	.byte 0x81
	.byte 0xC1
	.byte 0xC3
	.byte 0xE3
	.byte 0xE7
	.byte 0xF7
	.byte 0xFF
	.byte 0xEF
	.byte 0xE7
	.byte 0xC7
	.byte 0xC3
	.byte 0x83
	.byte 0x81
	.byte 0x1
	.byte 0x0
.end

