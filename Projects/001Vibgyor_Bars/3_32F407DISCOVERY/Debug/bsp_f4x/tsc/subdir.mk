################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bsp_f4x/tsc/XPT2046.c 

OBJS += \
./bsp_f4x/tsc/XPT2046.o 

C_DEPS += \
./bsp_f4x/tsc/XPT2046.d 


# Each subdirectory must supply rules for building sources it contributes
bsp_f4x/tsc/%.o bsp_f4x/tsc/%.su: ../bsp_f4x/tsc/%.c bsp_f4x/tsc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/001Vibgyor_Bars/3_32F407DISCOVERY/bsp_f4x/lcd" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/001Vibgyor_Bars/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/001Vibgyor_Bars/3_32F407DISCOVERY/bsp_f4x/tsc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-bsp_f4x-2f-tsc

clean-bsp_f4x-2f-tsc:
	-$(RM) ./bsp_f4x/tsc/XPT2046.d ./bsp_f4x/tsc/XPT2046.o ./bsp_f4x/tsc/XPT2046.su

.PHONY: clean-bsp_f4x-2f-tsc

