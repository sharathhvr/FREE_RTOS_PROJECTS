################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third_party/FreeRTOS/org/Source/portable/MemMang/heap_4.c 

OBJS += \
./Third_party/FreeRTOS/org/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./Third_party/FreeRTOS/org/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Third_party/FreeRTOS/org/Source/portable/MemMang/%.o: ../Third_party/FreeRTOS/org/Source/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Idle_Hook_PowerSaving/StdPeriph_Driver/inc" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Idle_Hook_PowerSaving/Third_party/SEGGER/Config" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Idle_Hook_PowerSaving/Third_party/SEGGER/OS" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Idle_Hook_PowerSaving/Third_party/SEGGER/SEGGER" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Idle_Hook_PowerSaving/config" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Idle_Hook_PowerSaving/Third_party/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Idle_Hook_PowerSaving/Third_party/FreeRTOS/org/Source/include" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Idle_Hook_PowerSaving/inc" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Idle_Hook_PowerSaving/CMSIS/device" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_FreeRTOS_Idle_Hook_PowerSaving/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


