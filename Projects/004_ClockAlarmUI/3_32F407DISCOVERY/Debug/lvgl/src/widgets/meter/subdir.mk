################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/widgets/meter/lv_meter.c 

OBJS += \
./lvgl/src/widgets/meter/lv_meter.o 

C_DEPS += \
./lvgl/src/widgets/meter/lv_meter.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/widgets/meter/%.o lvgl/src/widgets/meter/%.su lvgl/src/widgets/meter/%.cyclo: ../lvgl/src/widgets/meter/%.c lvgl/src/widgets/meter/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/004_ClockAlarmUI/3_32F407DISCOVERY" -I../Core/Inc -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/004_ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/lcd" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/004_ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/004_ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/tsc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-widgets-2f-meter

clean-lvgl-2f-src-2f-widgets-2f-meter:
	-$(RM) ./lvgl/src/widgets/meter/lv_meter.cyclo ./lvgl/src/widgets/meter/lv_meter.d ./lvgl/src/widgets/meter/lv_meter.o ./lvgl/src/widgets/meter/lv_meter.su

.PHONY: clean-lvgl-2f-src-2f-widgets-2f-meter

