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

//task function declaration
void vGreenLedTask(void *pvParameters);
void vOrangeLedTask(void *pvParameters);
void vRedLedTask(void *pvParameters);
void vBlueLedTask(void *pvParameters);

//task function definitions
void vGreenLedTask(void *pvParameters){
	while(1){
		//Toggle user leds on PD12
		GPIOD->ODR ^= LED_PIN_PD12_GREEN;
		//vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

void vOrangeLedTask(void *pvParameters){
	while(1){
		//Toggle user leds on PD13
		GPIOD->ODR ^= LED_PIN_PD13_ORANGE;
		//vTaskDelay(pdMS_TO_TICKS(500));
	}
}

void vRedLedTask(void *pvParameters){
	while(1){
		//Toggle user leds on PD13
		GPIOD->ODR ^= LED_PIN_PD14_RED;
		//vTaskDelay(pdMS_TO_TICKS(100));
	}
}

void vBlueLedTask(void *pvParameters){
	while(1){
		//Toggle user leds on PD13
		GPIOD->ODR ^= LED_PIN_PD15_BLUE;
		//vTaskDelay(pdMS_TO_TICKS(50));
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


	// Create the FreeRTOS task to blink the LED
	xTaskCreate(vGreenLedTask,	"green led",	128, NULL, (configMAX_PRIORITIES -1), NULL);
	xTaskCreate(vOrangeLedTask, "orange led", 	128, NULL, (configMAX_PRIORITIES -1), NULL);
	xTaskCreate(vRedLedTask, 	"red led",	 	128, NULL, 1, NULL);
	xTaskCreate(vBlueLedTask,	"blue led", 	128, NULL, 1, NULL);

	//due to task priority only green and orange led will be glowing

	// Start the scheduler
	vTaskStartScheduler();

	// The scheduler should never return, but just in case:
	while(1);

}

