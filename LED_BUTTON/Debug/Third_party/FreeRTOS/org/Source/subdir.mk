################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third_party/FreeRTOS/org/Source/croutine.c \
../Third_party/FreeRTOS/org/Source/event_groups.c \
../Third_party/FreeRTOS/org/Source/list.c \
../Third_party/FreeRTOS/org/Source/queue.c \
../Third_party/FreeRTOS/org/Source/stream_buffer.c \
../Third_party/FreeRTOS/org/Source/tasks.c \
../Third_party/FreeRTOS/org/Source/timers.c 

OBJS += \
./Third_party/FreeRTOS/org/Source/croutine.o \
./Third_party/FreeRTOS/org/Source/event_groups.o \
./Third_party/FreeRTOS/org/Source/list.o \
./Third_party/FreeRTOS/org/Source/queue.o \
./Third_party/FreeRTOS/org/Source/stream_buffer.o \
./Third_party/FreeRTOS/org/Source/tasks.o \
./Third_party/FreeRTOS/org/Source/timers.o 

C_DEPS += \
./Third_party/FreeRTOS/org/Source/croutine.d \
./Third_party/FreeRTOS/org/Source/event_groups.d \
./Third_party/FreeRTOS/org/Source/list.d \
./Third_party/FreeRTOS/org/Source/queue.d \
./Third_party/FreeRTOS/org/Source/stream_buffer.d \
./Third_party/FreeRTOS/org/Source/tasks.d \
./Third_party/FreeRTOS/org/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Third_party/FreeRTOS/org/Source/%.o: ../Third_party/FreeRTOS/org/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/StdPeriph_Driver/inc" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/Third_party/SEGGER/Config" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/Third_party/SEGGER/OS" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/Third_party/SEGGER/SEGGER" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/config" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/Third_party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/Third_party/FreeRTOS/org/Source/include" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/inc" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/CMSIS/device" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


