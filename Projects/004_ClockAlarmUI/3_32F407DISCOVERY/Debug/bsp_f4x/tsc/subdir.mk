################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bsp_f4x/tsc/FT6336U.c \
../bsp_f4x/tsc/XPT2046.c 

OBJS += \
./bsp_f4x/tsc/FT6336U.o \
./bsp_f4x/tsc/XPT2046.o 

C_DEPS += \
./bsp_f4x/tsc/FT6336U.d \
./bsp_f4x/tsc/XPT2046.d 


# Each subdirectory must supply rules for building sources it contributes
bsp_f4x/tsc/%.o bsp_f4x/tsc/%.su bsp_f4x/tsc/%.cyclo: ../bsp_f4x/tsc/%.c bsp_f4x/tsc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/004_ClockAlarmUI/3_32F407DISCOVERY" -I../Core/Inc -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/004_ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/lcd" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/004_ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/004_ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/tsc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-bsp_f4x-2f-tsc

clean-bsp_f4x-2f-tsc:
	-$(RM) ./bsp_f4x/tsc/FT6336U.cyclo ./bsp_f4x/tsc/FT6336U.d ./bsp_f4x/tsc/FT6336U.o ./bsp_f4x/tsc/FT6336U.su ./bsp_f4x/tsc/XPT2046.cyclo ./bsp_f4x/tsc/XPT2046.d ./bsp_f4x/tsc/XPT2046.o ./bsp_f4x/tsc/XPT2046.su

.PHONY: clean-bsp_f4x-2f-tsc

