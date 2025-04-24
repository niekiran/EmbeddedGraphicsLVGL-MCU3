################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bsp_f4x/lcd/bsp_lcd.c 

OBJS += \
./bsp_f4x/lcd/bsp_lcd.o 

C_DEPS += \
./bsp_f4x/lcd/bsp_lcd.d 


# Each subdirectory must supply rules for building sources it contributes
bsp_f4x/lcd/%.o bsp_f4x/lcd/%.su bsp_f4x/lcd/%.cyclo: ../bsp_f4x/lcd/%.c bsp_f4x/lcd/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"C:/Users/shrey/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/001Vibgyor_Bars/3_32F407DISCOVERY/bsp_f4x/lcd" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-bsp_f4x-2f-lcd

clean-bsp_f4x-2f-lcd:
	-$(RM) ./bsp_f4x/lcd/bsp_lcd.cyclo ./bsp_f4x/lcd/bsp_lcd.d ./bsp_f4x/lcd/bsp_lcd.o ./bsp_f4x/lcd/bsp_lcd.su

.PHONY: clean-bsp_f4x-2f-lcd

