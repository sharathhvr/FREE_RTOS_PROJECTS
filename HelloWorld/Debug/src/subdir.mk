################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/002LED_BUTTON.c \
../src/system_stm32f4xx.c 

OBJS += \
./src/002LED_BUTTON.o \
./src/system_stm32f4xx.o 

C_DEPS += \
./src/002LED_BUTTON.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/StdPeriph_Driver/inc" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/Third_party/SEGGER/Config" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/Third_party/SEGGER/OS" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/Third_party/SEGGER/SEGGER" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/config" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/Third_party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/Third_party/FreeRTOS/org/Source/include" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/inc" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/CMSIS/device" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_HelloWorld/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


