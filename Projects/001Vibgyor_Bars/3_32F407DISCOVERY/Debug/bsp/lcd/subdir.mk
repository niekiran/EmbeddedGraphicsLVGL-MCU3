################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/Workspace/git/EmbeddedGraphics/Projects/bsp/lcd/bsp_lcd.c 

OBJS += \
./bsp/lcd/bsp_lcd.o 

C_DEPS += \
./bsp/lcd/bsp_lcd.d 


# Each subdirectory must supply rules for building sources it contributes
bsp/lcd/bsp_lcd.o: F:/Workspace/git/EmbeddedGraphics/Projects/bsp/lcd/bsp_lcd.c bsp/lcd/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"F:/Workspace/git/EmbeddedGraphics/Projects/bsp/lcd" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-bsp-2f-lcd

clean-bsp-2f-lcd:
	-$(RM) ./bsp/lcd/bsp_lcd.d ./bsp/lcd/bsp_lcd.o ./bsp/lcd/bsp_lcd.su

.PHONY: clean-bsp-2f-lcd

