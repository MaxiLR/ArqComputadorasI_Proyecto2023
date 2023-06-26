.text
.global	ElChoqueASMB
.global QUIT
.global DELAY
.global DELAY_2
.global DisplayBinary
.global LedOutput
.global Delay
.global Clear

ElChoqueASMB:
	PUSH {R0,R4,R5,R6,R7,R8,R9,R10,R11,LR}
	BL Clear
	MOV R4, #0 // Init DISPLAY with 0
	LDR R11, =DELAY_2 // DELAY_2(Address)
	LDR R6, [R11] // DELAY_2(Value)
	LDR R9, =DELAY // DELAY(Address)
	STR R6, [R9] // DELAY = DELAY_2
	LDR R10, =QUIT // QUIT(Address)
	LDR R8, =table

	while:
		MOV R5, #0 // Init i = 0, for loop
		for:
			LDR R7, [R10] // QUIT(Value)
			CMP R7, #1
			BEQ break

			MOV R0, R4
			MOV R1, #4
			BL DisplayBinary
			
			MOV R0, R4
			BL LedOutput
			
			LDRB R4, [R8, R5] // DISPLAY = table[i]

			LDR R6, [R9] // DELAY(Value)
			MOV R0, R6
			BL Delay

			ADD R5, R5, #1
			CMP R5, #7
			BLT for

		LDR R7, [R10] // QUIT(Value)
		CMP R7, #0
		BEQ while

	break:
	STR R6, [R11]
	MOV R0, #0
	STR R0, [R10]
	POP {R0,R4,R5,R6,R7,R8,R9,R10,R11,PC}
		
.data
		
table: // #7
	.byte 0x81
	.byte 0x42
	.byte 0x24
	.byte 0x18
	.byte 0x18
	.byte 0x24
	.byte 0x42
	
.end

