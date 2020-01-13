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
#include "queue.h"

// common function prototypes
static void prvSetupHardware(void);
static void prvSetupUART2(void);
static void printmsg(char *msg);
void rtos_delay(uint32_t delay_in_ms);

//Task handler function prototypes
void vCmd_Handling_Task (void *params);
void vMenu_Print_Task (void *params);
void vCmd_Processing_Task(void *params);
void vUART_Write_Task(void *params);
void USART2_IRQHandler(void);

/*
 *  helper functions
 */
void func_LedOn(void);
void func_LedOff(void);
void func_LedToggle(void);
void func_LedToggleOff(void);
void func_LedStatus(char *task_msg);
void func_DateTime(char *task_msg);
void print_error_msg(char *task_msg);

/*
 * 	Task Handles
 */
TaskHandle_t xTaskHandle_Cmd_Handle=NULL;
TaskHandle_t xTaskHandle_Menu=NULL;
TaskHandle_t xTaskHandle_Cmd_Process=NULL;
TaskHandle_t xTaskHandle_UART_Write=NULL;

/*
 * Queue Handles
 */

QueueHandle_t QueueHandle_cmd=NULL;
QueueHandle_t QueueHandle_uart_write=NULL;


//for semi-hosting
#ifdef USE_SEMIHOSTING
	extern void initialise_monitor_handles();
#endif

/*
 * General Macros
 */
#define HIGH 	1
#define LOW 	0

#define OPEN	1
#define CLOSE 	0

#define STACK_SIZE500		500

uint8_t UART_ACCESS_KEY=OPEN;

/* GLOBAL VARIABLES */
uint8_t BUTTON_FLAG = LOW;
uint8_t command_buffer[20];
uint8_t command_len =0;

//command structure
typedef struct
{
	uint8_t COMMAND_NUM;
	uint8_t COMMAND_ARGS[10];
}APP_CMD_t;

/* This is the MENU  */

char menu[]={"\
\r\nLED_ON             ----> 1 \
\r\nLED_OFF            ----> 2 \
\r\nLED_TOGGLE         ----> 3 \
\r\nLED_TOGGLE_OFF     ----> 4 \
\r\nLED_READ_STATUS    ----> 5 \
\r\nRTC_PRINT_DATETIME ----> 6 \
\r\nEXIT_APP           ----> 0 \
\r\nType your option here : "};


/*
 *  command Macros
 */

# define LED_ON					1
# define LED_OFF				2
# define LED_TOGGLE				3
# define LED_TOGGLE_OFF			4
# define LED_READ_STATUS		5
# define RTC_PRINT_DATETIME     6
# define EXIT_APP				0


int main(void)
{
	//for semi-hosting
#ifdef USE_SEMIHOSTING
	initialise_monitor_handles();
#endif

	/*
	 * Enable DWT_CYCCNT in ARM Cortex M4 processor for time-stamping for SEGGER SYSVIEW
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


	//command QUEUE Creation
	QueueHandle_cmd = xQueueCreate(10,sizeof(APP_CMD_t*));//it can hold 10 structure pointers

	//UART write queue
	QueueHandle_uart_write = xQueueCreate(10,sizeof(char*));


	if((QueueHandle_cmd !=NULL) && (QueueHandle_uart_write !=NULL)) //check if queue was created and create task
	{
		//3.Create two tasks
		xTaskCreate(	vCmd_Handling_Task,
						"Cmd_Handling_Task",
						STACK_SIZE500,
						NULL,
						2,
						&xTaskHandle_Cmd_Handle );

		xTaskCreate(	vMenu_Print_Task,
						"Menu_Print_Task",
						STACK_SIZE500,
						NULL,
						1,
						&xTaskHandle_Menu );

		xTaskCreate(	vCmd_Processing_Task,
						"Cmd_Processing_Task",
						STACK_SIZE500,
						NULL,
						2,
						&xTaskHandle_Cmd_Process );

		xTaskCreate(	vUART_Write_Task,
						"UART_Write_Task",
						STACK_SIZE500,
						NULL,
						2,
						&xTaskHandle_UART_Write );

		//4. Start the task scheduler
			vTaskStartScheduler();

	}
	else
	{
		//print queue creation failed
		printmsg("queue creation failed /r/n");

	}

	for(;;); //infinite loop for RTOS application


}

void vCmd_Handling_Task (void *params)
{
	uint8_t command_code= 0;
	//create a command struct variable
	APP_CMD_t *new_cmd; //Pointer cuz xQueueSend needs &pointer

	while(1)
	{
		//wait for a task to notify from UART IRQ handler
		xTaskNotifyWait(0,0,NULL,portMAX_DELAY);
		new_cmd = (APP_CMD_t*) pvPortMalloc(sizeof(APP_CMD_t));
		//generate command code and send it to queue
		command_code=command_buffer[0]-48;
		 new_cmd->COMMAND_NUM=command_code;
		//now send the command structure to the queue
		xQueueSend(QueueHandle_cmd,&new_cmd,portMAX_DELAY);

	}
}

void vMenu_Print_Task (void *params)
{
	char *pData= menu;
	while(1)
	{
		//send menu to queue
		xQueueSend(QueueHandle_uart_write,&pData,portMAX_DELAY);

		//lets wait until someone notifies
		xTaskNotifyWait(0,0,NULL,portMAX_DELAY);

	}

}

void vCmd_Processing_Task(void *params)
{
	APP_CMD_t *new_cmd;
	char task_msg[50];

	while(1)
	{
		//store the command in a struct
		xQueueReceive(QueueHandle_cmd,(void*)&new_cmd,portMAX_DELAY);

		if(new_cmd->COMMAND_NUM == LED_ON )
		{
			func_LedOn();

		}
		else if(new_cmd->COMMAND_NUM == LED_OFF)
		{
			func_LedOff();

		}
		else if(new_cmd->COMMAND_NUM == LED_TOGGLE)
		{
			func_LedToggle();
		}
		else if(new_cmd->COMMAND_NUM == LED_TOGGLE_OFF)
		{
			func_LedToggleOff();
		}
		else if(new_cmd->COMMAND_NUM == LED_READ_STATUS)
		{
			func_LedStatus(task_msg);
			xQueueSend(QueueHandle_uart_write,&task_msg,portMAX_DELAY);
		}
		else if(new_cmd->COMMAND_NUM == RTC_PRINT_DATETIME)
		{
			func_DateTime(task_msg);
			xQueueSend(QueueHandle_uart_write,&task_msg,portMAX_DELAY);
		}
		else if(new_cmd->COMMAND_NUM == EXIT_APP)
		{
			print_error_msg(task_msg);
			xQueueSend(QueueHandle_uart_write,&task_msg,portMAX_DELAY);
		}
	}
}


void vUART_Write_Task(void *params)
{
	char *pData=NULL;
	while(1)
	{
		xQueueReceive(QueueHandle_uart_write,&pData,portMAX_DELAY);
		printmsg(pData);

	}
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

		//4.Enable UART2 byte reception interrupt(there are many other interrupts)
			USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);

		//Lets set NVIC priority of USART2
			NVIC_SetPriority(USART2_IRQn,5);

		//enable the USART2 IRQ in the NVIC
			NVIC_EnableIRQ(USART2_IRQn);

		//5.Enable USART2 peripheral
			USART_Cmd(USART2,ENABLE);

}

/*
 *   HARDWARE SETUP FUNCTIONS
 */

static void prvSetupLED_GPIO(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef LED_GPIO;
	LED_GPIO.GPIO_Mode=GPIO_Mode_OUT;
	LED_GPIO.GPIO_OType=GPIO_OType_PP;
	LED_GPIO.GPIO_Pin=GPIO_Pin_5;
	LED_GPIO.GPIO_PuPd=GPIO_PuPd_NOPULL;
	LED_GPIO.GPIO_Speed=GPIO_Low_Speed;

	GPIO_Init(GPIOA,&LED_GPIO);

}


static void prvSetupHardware(void)
{

	//Setup LED GPIO
	prvSetupLED_GPIO();

	//setup UART2
	prvSetupUART2();

}

/*
 *   BASIC FUNCTIONS
 */
static void printmsg(char *msg)
{
	for(int i=0;i< strlen(msg);i++)
	{
		//wait untill DR empty
		while(!USART_GetFlagStatus(USART2,USART_FLAG_TXE));
		USART_SendData(USART2,msg[i]);
	}
}

void rtos_delay(uint32_t delay_in_ms)
{
	uint32_t current_tick_count= xTaskGetTickCount();

	uint32_t delay_in_ticks = (delay_in_ms * configTICK_RATE_HZ)/1000;

	while(xTaskGetTickCount() < current_tick_count + delay_in_ticks);
}

/*
 *   INTERRUPT HANDLER
 */


void USART2_IRQHandler(void)
{
	uint16_t data_byte;
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	if( USART_GetFlagStatus(USART2,USART_FLAG_RXNE) )
	{
		//a data byte is received from the user
		data_byte = USART_ReceiveData(USART2);

		command_buffer[command_len++] = (data_byte & 0xFF) ;

		if(data_byte == '\r')
		{
			//then user is finished entering the data
			//reset the command_len variable
			command_len = 0;

			//lets notify the command handling task
			xTaskNotifyFromISR(xTaskHandle_Cmd_Handle,0,eNoAction,&xHigherPriorityTaskWoken);

			xTaskNotifyFromISR(xTaskHandle_Menu,0,eNoAction,&xHigherPriorityTaskWoken);
		}

	}

	// if the above freertos apis wake up any higher priority task, then yield the processor to the
	//higher priority task which is just woken up.

	if(xHigherPriorityTaskWoken)
	{
		taskYIELD();
	}

}

/*
 *  Helper Functions
 */

void func_LedOn(void)
{
	GPIO_WriteBit(GPIOA,GPIO_Pin_5,ENABLE);
}

void func_LedOff(void)
{
	GPIO_WriteBit(GPIOA,GPIO_Pin_5,DISABLE);
}

void func_LedToggle(void)
{

}

void func_LedToggleOff(void)
{

}
void func_LedStatus(char *task_msg)
{

	sprintf(task_msg,"LED status is: %d\n",GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_5));

}

void func_DateTime(char *task_msg)
{

	sprintf(task_msg,"Invalid command received\n");
}

void print_error_msg(char *task_msg)
{

}






