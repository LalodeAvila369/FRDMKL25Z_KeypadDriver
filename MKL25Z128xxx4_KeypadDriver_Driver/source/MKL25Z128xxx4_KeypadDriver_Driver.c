#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "fsl_tpm.h"
#include "keypad.h"


void DelayTPM();

keypad k;
int main(void) {


    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	BOARD_InitDebugConsole();


	//Keypad Configuración
	keypad k;
	keypad_config config1;
	get_default_keypad_config(&config1);
	set_keypad_config(&k, &config1);
	char key=0, anterior;


	while(1) {
	    	anterior=key;
	    	key=read_keypad(&k);
	    	if(key==0 && anterior!=0){
	    		key=anterior;
	    		if(key=='#'){
	    			printf("\n");
	    			DelayTPM();

	    		}else{
	    			printf("%c",key);
	    			DelayTPM();
	    		}
	    		key=0;
	    	}
	    }
	}


