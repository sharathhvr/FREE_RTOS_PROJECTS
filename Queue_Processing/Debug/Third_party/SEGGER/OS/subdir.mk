################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.c 

OBJS += \
./Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o 

C_DEPS += \
./Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
Third_party/SEGGER/OS/%.o: ../Third_party/SEGGER/OS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Queue_Processing/StdPeriph_Driver/inc" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Queue_Processing/Third_party/FreeRTOS/org/Source" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Queue_Processing/Third_party/SEGGER/Config" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Queue_Processing/Third_party/SEGGER/OS" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Queue_Processing/Third_party/SEGGER/SEGGER" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Queue_Processing/config" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Queue_Processing/Third_party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Queue_Processing/Third_party/FreeRTOS/org/Source/include" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Queue_Processing/inc" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Queue_Processing/CMSIS/device" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Queue_Processing/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


