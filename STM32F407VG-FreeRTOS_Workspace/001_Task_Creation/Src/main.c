//User led
// led green PD12
//led orange PD13
//led red PD14
//led blue PD15
#include "stm32f407xx.h"
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"

#define GPIODEN  (1U<<3)

#define LED_PIN_PD12_GREEN  	(1U<<12)
#define LED_PIN_PD13_ORANGE  	(1U<<13)
#define LED_PIN_PD14_RED  		(1U<<14)
#define LED_PIN_PD15_BLUE  		(1U<<15)

void vGreenLedTask(void *pvParameters);
void vOrangeLedTask(void *pvParameters);

void vGreenLedTask(void *pvParameters){
	while(1){
		//Toggle user leds on PD12
		GPIOD->ODR ^= LED_PIN_PD12_GREEN;
		for(uint32_t i=0;i<1000000; i++);
	}
}

void vOrangeLedTask(void *pvParameters){
	while(1){
		//Toggle user leds on PD13
		GPIOD->ODR ^= LED_PIN_PD13_ORANGE;
		for(uint32_t i=0;i<100000; i++);
	}
}

int main(void){

	// Initialize the GPIO for the LED
	//enable clock access to GPIOA
	RCC->AHB1ENR |= GPIODEN;

	//set PD12 as output pin
	GPIOD->MODER |=(1<<24);
	GPIOD->MODER &=~(1<<25);

	//set PD13 as output pin
	GPIOD->MODER |=(1<<26);
	GPIOD->MODER &=~(1<<27);
//
//	//set PD14 as output pin
//	GPIOD->MODER |=(1<<28);
//	GPIOD->MODER &=~(1<<29);
//
//	//set PD15 as output pin
//	GPIOD->MODER |=(1<<30);
//	GPIOD->MODER &=~(1<<31);


	// Create the FreeRTOS task to blink the LED
	xTaskCreate(vGreenLedTask, "green led", 128, NULL, 1, NULL);
	xTaskCreate(vOrangeLedTask, "orange led", 128, NULL, 1, NULL);

	// Start the scheduler
	vTaskStartScheduler();

	// The scheduler should never return, but just in case:
	while(1);

}

