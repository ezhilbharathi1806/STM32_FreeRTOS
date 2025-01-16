################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/Source/portable/MemMang/heap_4.c 

OBJS += \
./FreeRTOS/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./FreeRTOS/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/portable/MemMang/%.o FreeRTOS/Source/portable/MemMang/%.su FreeRTOS/Source/portable/MemMang/%.cyclo: ../FreeRTOS/Source/portable/MemMang/%.c FreeRTOS/Source/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407G_DISC1 -c -I../Inc -I"G:/Embedded/STM32_FreeRTOS/Chip_headers/CMSIS/Include" -I"G:/Embedded/STM32_FreeRTOS/Chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I"G:/Embedded/STM32_FreeRTOS/STM32F407VG-FreeRTOS_Workspace/003_Task_Priorities/FreeRTOS/Source/include" -I"G:/Embedded/STM32_FreeRTOS/STM32F407VG-FreeRTOS_Workspace/003_Task_Priorities/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"G:/Embedded/STM32_FreeRTOS/STM32F407VG-FreeRTOS_Workspace/003_Task_Priorities/FreeRTOS/Source/portable/MemMang" -I"G:/Embedded/STM32_FreeRTOS/STM32F407VG-FreeRTOS_Workspace/003_Task_Priorities/FreeRTOS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-FreeRTOS-2f-Source-2f-portable-2f-MemMang

clean-FreeRTOS-2f-Source-2f-portable-2f-MemMang:
	-$(RM) ./FreeRTOS/Source/portable/MemMang/heap_4.cyclo ./FreeRTOS/Source/portable/MemMang/heap_4.d ./FreeRTOS/Source/portable/MemMang/heap_4.o ./FreeRTOS/Source/portable/MemMang/heap_4.su

.PHONY: clean-FreeRTOS-2f-Source-2f-portable-2f-MemMang

