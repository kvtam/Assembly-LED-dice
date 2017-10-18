;Kyle Tam
; Assembly function definition
			.cdecls C,"msp430f5529.h";import the header for the msp
			.def set_port			; Define the symbol
			.text					; this section is runable code

set_port;							; section name
			mov.b R12,&P6OUT		; move R12's value into port 6 where my LED's are
			ret
