################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third_party/SEGGER/SEGGER/SEGGER_RTT.c \
../Third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.c 

OBJS += \
./Third_party/SEGGER/SEGGER/SEGGER_RTT.o \
./Third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.o 

C_DEPS += \
./Third_party/SEGGER/SEGGER/SEGGER_RTT.d \
./Third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
Third_party/SEGGER/SEGGER/%.o: ../Third_party/SEGGER/SEGGER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/StdPeriph_Driver/inc" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/Third_party/SEGGER/Config" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/Third_party/SEGGER/OS" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/Third_party/SEGGER/SEGGER" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/config" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/Third_party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/Third_party/FreeRTOS/org/Source/include" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/inc" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/CMSIS/device" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_LED_BUTTON/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


