			.cdecls C,"msp430f5529.h";import the header for the msp

			.def set_port
			.text

set_port;
			;bic.b #00h,&P6OUT
			mov.b R12,&P6OUT
			ret
