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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"C:/Users/shrey/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/Demo_Roaring_tiger/3_32F407DISCOVERY/bsp_f4x/lcd" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-bsp_f4x-2f-lcd

clean-bsp_f4x-2f-lcd:
	-$(RM) ./bsp_f4x/lcd/bsp_lcd.cyclo ./bsp_f4x/lcd/bsp_lcd.d ./bsp_f4x/lcd/bsp_lcd.o ./bsp_f4x/lcd/bsp_lcd.su

.PHONY: clean-bsp_f4x-2f-lcd

