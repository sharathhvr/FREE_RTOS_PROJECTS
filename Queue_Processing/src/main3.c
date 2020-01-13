/*
 * main3.c
 *
 *  Created on: Nov 5, 2019
 *      Author: SHARATH
 */
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include <stm32f4xx.h>
#include "FreeRTOS.h"
#include "task.h"


/*
 * Function declarations
 */
void printmsg(char *msg);
static void setupHardware(void);
static void setupUART(void);
static void setupLedGpio(void);
char usr_msg[250];
int main(void)
{
	RCC_DeInit();
	SystemCoreClockUpdate();
	//Hardware Setup
	setupHardware();
	sprintf(usr_msg,"Fuck you");
	printmsg(usr_msg);

	return 0;
}

/*
 * 	Hardware Setup
 */
static void setupHardware(void)
{
	//Setup UART
	setupUART();
	//setup gpio for led
	setupLedGpio();

}

static void setupUART(void)
{
	USART_InitTypeDef uart2_init;
	GPIO_InitTypeDef  UART_gpio;

	//1.first enable clocks for the peripherals
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	//2.PA2,PA3 should be configd in AF7 mode for them to work as USART2 Tx,Rx
		memset(&UART_gpio,0,sizeof(UART_gpio));
		UART_gpio.GPIO_Mode=GPIO_Mode_AF;
		UART_gpio.GPIO_Pin= GPIO_Pin_2 | GPIO_Pin_3;
		UART_gpio.GPIO_PuPd=GPIO_PuPd_UP ;
		GPIO_Init(GPIOA,&UART_gpio);

	//3. configure the pins to particular AF mode
		GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_UART7);
		GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_UART7);
	//4.configure the UART peripheral
		memset(&uart2_init,0,sizeof(uart2_init));
		uart2_init.USART_BaudRate = 9600;
		uart2_init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		uart2_init.USART_Mode =  USART_Mode_Tx | USART_Mode_Rx;
		uart2_init.USART_Parity = USART_Parity_No;
		uart2_init.USART_StopBits = USART_StopBits_1;
		uart2_init.USART_WordLength = USART_WordLength_8b;
		USART_Init(USART2,&uart2_init);
	//5. Enable the UART2 peripheral
		USART_Cmd(USART2,ENABLE);
}

void setupLedGpio(void)
{
// this function is board specific

	//Peripheral clock enable for GPIOA for led
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);

	GPIO_InitTypeDef led_init;
	memset(&led_init,0,sizeof(led_init));
	led_init.GPIO_Mode = GPIO_Mode_OUT;
	led_init.GPIO_OType = GPIO_OType_PP;
	led_init.GPIO_Pin = GPIO_Pin_5;
	led_init.GPIO_Speed = GPIO_Low_Speed;
	led_init.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA,&led_init);

}

void printmsg(char *msg)
{
	for(uint32_t i=0; i < strlen(msg); i++)
	{
		while ( USART_GetFlagStatus(USART2,USART_FLAG_TXE) != SET);
		USART_SendData(USART2,msg[i]);
	}

	while ( USART_GetFlagStatus(USART2,USART_FLAG_TC) != SET);

}
