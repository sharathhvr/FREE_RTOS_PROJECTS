################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../StdPeriph_Driver/Third_party/FreeRTOS/org/Source/croutine.c \
../StdPeriph_Driver/Third_party/FreeRTOS/org/Source/event_groups.c \
../StdPeriph_Driver/Third_party/FreeRTOS/org/Source/list.c \
../StdPeriph_Driver/Third_party/FreeRTOS/org/Source/queue.c \
../StdPeriph_Driver/Third_party/FreeRTOS/org/Source/stream_buffer.c \
../StdPeriph_Driver/Third_party/FreeRTOS/org/Source/tasks.c \
../StdPeriph_Driver/Third_party/FreeRTOS/org/Source/timers.c 

OBJS += \
./StdPeriph_Driver/Third_party/FreeRTOS/org/Source/croutine.o \
./StdPeriph_Driver/Third_party/FreeRTOS/org/Source/event_groups.o \
./StdPeriph_Driver/Third_party/FreeRTOS/org/Source/list.o \
./StdPeriph_Driver/Third_party/FreeRTOS/org/Source/queue.o \
./StdPeriph_Driver/Third_party/FreeRTOS/org/Source/stream_buffer.o \
./StdPeriph_Driver/Third_party/FreeRTOS/org/Source/tasks.o \
./StdPeriph_Driver/Third_party/FreeRTOS/org/Source/timers.o 

C_DEPS += \
./StdPeriph_Driver/Third_party/FreeRTOS/org/Source/croutine.d \
./StdPeriph_Driver/Third_party/FreeRTOS/org/Source/event_groups.d \
./StdPeriph_Driver/Third_party/FreeRTOS/org/Source/list.d \
./StdPeriph_Driver/Third_party/FreeRTOS/org/Source/queue.d \
./StdPeriph_Driver/Third_party/FreeRTOS/org/Source/stream_buffer.d \
./StdPeriph_Driver/Third_party/FreeRTOS/org/Source/tasks.d \
./StdPeriph_Driver/Third_party/FreeRTOS/org/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
StdPeriph_Driver/Third_party/FreeRTOS/org/Source/%.o: ../StdPeriph_Driver/Third_party/FreeRTOS/org/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/StdPeriph_Driver/inc" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/Third_party/SEGGER/Config" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/Third_party/SEGGER/OS" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/Third_party/SEGGER/SEGGER" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/config" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/Third_party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/Third_party/FreeRTOS/org/Source/include" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/inc" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/CMSIS/device" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


