################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bsp_f7x/lcd/bsp_lcd.c \
../bsp_f7x/lcd/bsp_lcd_ex.c 

OBJS += \
./bsp_f7x/lcd/bsp_lcd.o \
./bsp_f7x/lcd/bsp_lcd_ex.o 

C_DEPS += \
./bsp_f7x/lcd/bsp_lcd.d \
./bsp_f7x/lcd/bsp_lcd_ex.d 


# Each subdirectory must supply rules for building sources it contributes
bsp_f7x/lcd/%.o bsp_f7x/lcd/%.su: ../bsp_f7x/lcd/%.c bsp_f7x/lcd/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F746NGHx -DSTM32F746G_DISCO -DSTM32F7 -c -I../Inc -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/001Vibgyor_Bars/2_32F746GDISCOVERY/bsp_f7x/lcd" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-bsp_f7x-2f-lcd

clean-bsp_f7x-2f-lcd:
	-$(RM) ./bsp_f7x/lcd/bsp_lcd.d ./bsp_f7x/lcd/bsp_lcd.o ./bsp_f7x/lcd/bsp_lcd.su ./bsp_f7x/lcd/bsp_lcd_ex.d ./bsp_f7x/lcd/bsp_lcd_ex.o ./bsp_f7x/lcd/bsp_lcd_ex.su

.PHONY: clean-bsp_f7x-2f-lcd

