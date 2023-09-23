/* 
	*Actividad Fundamental 2
	*Bryan Alberto Flores García, 1866566 
	*Diego Alfonso Monteverde Salas, 1948273
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

//Outputs

#define LEDS_DDRX DDRD
#define LEDS_PORTX PORTD
#define LED1 PORTD1
#define LED2 PORTD2
#define LED3 PORTD3
#define LED4 PORTD4

//Inputs
#define BTNS_DDRX DDRB
#define BTNS_PINX PINB
#define BTN0 PORTB0
#define BTN0_READ BTNS_PINX & (1 << BTN0)
#define BTN1 PORTB1
#define BTN1_READ BTNS_PINX & (1 << BTN1)

#define NUM_LEDS 4
#define RETARDO 500
#define RETARDO2 200

void init_ports (void);
void auto_fantastico(uint8_t);
void apagar_leds(uint8_t);
void secuencia_libre(void);
void encender_leds(uint8_t);

int main(void)
{
	init_ports();
    while (1) 
    {
		if(!(BTN0_READ) &&  !(BTN1_READ)){
			auto_fantastico(NUM_LEDS);
			
		}else if(!(BTN0_READ) && (BTN1_READ)){	
			apagar_leds(NUM_LEDS);
			
		}else if((BTN0_READ) && !(BTN1_READ)){
			secuencia_libre();
		}else{		
			encender_leds(NUM_LEDS);	
		}
    }
}

void init_ports(void){
	//Outputs
	LEDS_DDRX |= (1 << LED1);
	LEDS_DDRX |= (1 << LED2);
	LEDS_DDRX |= (1 << LED3);
	LEDS_DDRX |= (1 << LED4);
	
	//Inputs
	BTNS_DDRX &= ~(1 << BTN0);
	BTNS_DDRX &= ~(1 << BTN1);
}
void auto_fantastico(uint8_t num_leds){
	for(uint8_t i=1; i<=num_leds;i++){
		if(i!=1){
			LEDS_PORTX &= ~(1 << (i-1));
			}else{
			LEDS_PORTX &= ~(1 << (i+1));
		}
		//LEDS_PORTX &= 0b11100001;
		LEDS_PORTX |= (1 << i);
		_delay_ms(RETARDO);
		if(!(!(BTN0_READ) &&  !(BTN1_READ))){
			break;
		}
		
	}
	for(uint8_t i=num_leds-1;i>1;i--){
		LEDS_PORTX &= ~(1 << (i+1));
		LEDS_PORTX |= (1 << i);
		_delay_ms(RETARDO);
		if(!(!(BTN0_READ) &&  !(BTN1_READ))){
			break;
		}
	}
}

void apagar_leds(uint8_t num_leds) {
	for (uint8_t i=1; i<num_leds+1;i++){
		LEDS_PORTX &= ~(1 << i);
	}
}

void secuencia_libre(void){
	LEDS_PORTX |= (1 << LED1);
	LEDS_PORTX |= (1 << LED2);
	_delay_ms(RETARDO2);
	LEDS_PORTX &= ~(1 << LED1);
	LEDS_PORTX &= ~(1 << LED2);
	_delay_ms(RETARDO2);
	LEDS_PORTX |= (1 << LED1);
	LEDS_PORTX |= (1 << LED2);
	_delay_ms(RETARDO2);
	LEDS_PORTX &= ~(1 << LED1);
	LEDS_PORTX &= ~(1 << LED2);
	LEDS_PORTX |= (1 << LED3);
	LEDS_PORTX |= (1 << LED4);
	_delay_ms(RETARDO2);
	LEDS_PORTX &= ~(1 << LED3);
	LEDS_PORTX &= ~(1 << LED4);
	_delay_ms(RETARDO2);
	LEDS_PORTX |= (1 << LED3);
	LEDS_PORTX |= (1 << LED4);
	_delay_ms(RETARDO2);
	LEDS_PORTX &= ~(1 << LED3);
	LEDS_PORTX &= ~(1 << LED4);
}

void encender_leds(uint8_t num_leds) {
	for (uint8_t i=1; i<num_leds+1;i++){
		LEDS_PORTX |= (1 << i);
	}
}


