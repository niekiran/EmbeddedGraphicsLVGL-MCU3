################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/themes/mono/lv_theme_mono.c 

OBJS += \
./lvgl/src/themes/mono/lv_theme_mono.o 

C_DEPS += \
./lvgl/src/themes/mono/lv_theme_mono.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/themes/mono/%.o lvgl/src/themes/mono/%.su: ../lvgl/src/themes/mono/%.c lvgl/src/themes/mono/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/2_32F746GDISCOVERY" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/2_32F746GDISCOVERY/hal_stm_lvgl/STM32746G-Discovery" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-themes-2f-mono

clean-lvgl-2f-src-2f-themes-2f-mono:
	-$(RM) ./lvgl/src/themes/mono/lv_theme_mono.d ./lvgl/src/themes/mono/lv_theme_mono.o ./lvgl/src/themes/mono/lv_theme_mono.su

.PHONY: clean-lvgl-2f-src-2f-themes-2f-mono

