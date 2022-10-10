################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/widgets/slider/lv_slider.c 

OBJS += \
./lvgl/src/widgets/slider/lv_slider.o 

C_DEPS += \
./lvgl/src/widgets/slider/lv_slider.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/widgets/slider/%.o lvgl/src/widgets/slider/%.su: ../lvgl/src/widgets/slider/%.c lvgl/src/widgets/slider/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/2_32F746GDISCOVERY/hal_stm_lvgl/STM32746G-Discovery" -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/2_32F746GDISCOVERY" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-widgets-2f-slider

clean-lvgl-2f-src-2f-widgets-2f-slider:
	-$(RM) ./lvgl/src/widgets/slider/lv_slider.d ./lvgl/src/widgets/slider/lv_slider.o ./lvgl/src/widgets/slider/lv_slider.su

.PHONY: clean-lvgl-2f-src-2f-widgets-2f-slider

