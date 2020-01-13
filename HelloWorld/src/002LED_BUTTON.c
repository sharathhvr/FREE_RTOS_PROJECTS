/*
 * 002LED_BUTTON.c
 *
 *  Created on: Sep 29, 2019
 *      Author: SHARATH
 */

/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"


static void prvSetupHardware(void);
static void prvSetupUART2(void);
static void printmsg(char *msg);
//Task handler function prototypes
void vTask1_Handler (void *params);
void vTask2_Handler (void *params);

TaskHandle_t xTaskHandle1=NULL;
TaskHandle_t xTaskHandle2=NULL;

//for semi-hosting
#ifdef USE_SEMIHOSTING
	extern void initialise_monitor_handles();
#endif

#define OPEN 1
#define CLOSE 0

uint8_t UART_ACCESS_KEY=OPEN;

int main(void)
{
	//for semi-hosting
#ifdef USE_SEMIHOSTING
	initialise_monitor_handles();
#endif

	/*
	 * Enable DWT_CYCCNT in ARM Cortex M4 processor for time-stamping
	 */
 		DWT->CTRL |= (1 << 0);

	//1.Reset the RCC clock configuration
	//HSI ON, PLL OFF, HSE OFF , system clock= 16MHz, cpu_clock=16MHz
	RCC_DeInit();

	//2.Update the sys clock, make sys clock point to HSI
	SystemCoreClockUpdate();

	//call hardware setup
	prvSetupHardware();

	//Start SEGGER sys view
	SEGGER_SYSVIEW_Conf();
	SEGGER_SYSVIEW_Start();


	//3.Create two tasks
	xTaskCreate(	vTask1_Handler,
					"Task-1",
					configMINIMAL_STACK_SIZE,
					NULL,
					2,
					&xTaskHandle1 );

	xTaskCreate(	vTask2_Handler,
					"Task-2",
					configMINIMAL_STACK_SIZE,
					NULL,
					2,
					&xTaskHandle2 );
	//4. Start the task scheduler
	vTaskStartScheduler();

	for(;;);


}

void vTask1_Handler (void *params)
{



}

void vTask2_Handler (void *params)
{


}


static void prvSetupUART2(void)
{
	//1.Enable UART2 peripheral clock and GPIO portA
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);

		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);

		//USART pins PA2-Rx ,PA3-Tx

		//2.Alternate function configuration of MCU pins to behave as USART2 RX and TX

			// lets first initialize GPIO pins
			//populate GPIO init structure and then pass
			GPIO_InitTypeDef gpio_uart_pins;

			//GPIO PA2 and PA3
			memset(&gpio_uart_pins,0,sizeof(gpio_uart_pins));//setting all struct member elements to 0
			gpio_uart_pins.GPIO_Pin=GPIO_Pin_2 | GPIO_Pin_3;
			gpio_uart_pins.GPIO_Mode=GPIO_Mode_AF;
			gpio_uart_pins.GPIO_PuPd= GPIO_PuPd_UP; // USART initial state is UP
			GPIO_Init(GPIOA,&gpio_uart_pins);

			//AF mode setting for pins
			GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2);// now PA2 is Rx
			GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2);// now PA3 is Tx

		//3.UART peripheral configuration
		USART_InitTypeDef usart_peri_init;
		memset(&usart_peri_init,0,sizeof(usart_peri_init));//setting all struct member elements to 0
		usart_peri_init.USART_BaudRate=9600;
		usart_peri_init.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
		usart_peri_init.USART_Mode=  USART_Mode_Tx | USART_Mode_Rx;
		usart_peri_init.USART_Parity=USART_Parity_No;
		usart_peri_init.USART_StopBits=USART_StopBits_1;
		usart_peri_init.USART_WordLength=USART_WordLength_8b;
		USART_Init(USART2,&usart_peri_init);

		//5.Enable USART peripheral
		USART_Cmd(USART2,ENABLE);

}

static void prvSetupHardware(void)
{

	//setup UART2
		prvSetupUART2();

}

static void printmsg(char *msg)
{
	for(int i=0;i< strlen(msg);i++)
	{
		//wait untill DR empty
		while(!USART_GetFlagStatus(USART2,USART_FLAG_TXE));
		USART_SendData(USART2,msg[i]);
	}
}


