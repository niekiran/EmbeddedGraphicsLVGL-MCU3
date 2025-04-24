################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/widgets/roller/lv_roller.c 

OBJS += \
./lvgl/src/widgets/roller/lv_roller.o 

C_DEPS += \
./lvgl/src/widgets/roller/lv_roller.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/widgets/roller/%.o lvgl/src/widgets/roller/%.su lvgl/src/widgets/roller/%.cyclo: ../lvgl/src/widgets/roller/%.c lvgl/src/widgets/roller/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"C:/Users/shrey/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/lcd" -I"C:/Users/shrey/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"C:/Users/shrey/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/tsc" -I"C:/Users/shrey/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-widgets-2f-roller

clean-lvgl-2f-src-2f-widgets-2f-roller:
	-$(RM) ./lvgl/src/widgets/roller/lv_roller.cyclo ./lvgl/src/widgets/roller/lv_roller.d ./lvgl/src/widgets/roller/lv_roller.o ./lvgl/src/widgets/roller/lv_roller.su

.PHONY: clean-lvgl-2f-src-2f-widgets-2f-roller

