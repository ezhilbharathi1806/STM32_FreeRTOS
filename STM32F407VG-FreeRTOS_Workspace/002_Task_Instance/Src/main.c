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

const uint32_t greenLed 	= (uint32_t) (1U<<12);
const uint32_t orangeLed 	= (uint32_t) (1U<<13);
const uint32_t redLed 		= (uint32_t) (1U<<14);
const uint32_t blueLed 		= (uint32_t) (1U<<15);

void vLedTask(void *pvParameters);


void vLedTask(void *pvParameters){
	uint32_t *ledPin;
	ledPin = (uint32_t *) pvParameters;
	while(1){
		//Toggle user leds on PD12
		GPIOD->ODR ^= *ledPin;
		vTaskDelay(pdMS_TO_TICKS(1000));
		//for(uint32_t i=0;i<1000000; i++);
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

	//set PD14 as output pin
	GPIOD->MODER |=(1<<28);
	GPIOD->MODER &=~(1<<29);

	//set PD15 as output pin
	GPIOD->MODER |=(1<<30);
	GPIOD->MODER &=~(1<<31);

	//set all leds to 0
	GPIOD->ODR = 0;

	// Create the FreeRTOS task to blink the LED
	xTaskCreate(vLedTask, "led tasks", 128, (void *) &greenLed , 1, NULL);
	xTaskCreate(vLedTask, "led tasks", 128, (void *) &orangeLed, 1, NULL);
	xTaskCreate(vLedTask, "led tasks", 128, (void *) &redLed   , 1, NULL);
	xTaskCreate(vLedTask, "led tasks", 128, (void *) &blueLed  , 1, NULL);


	// Start the scheduler
	vTaskStartScheduler();

	// The scheduler should never return, but just in case:
	while(1);

}

