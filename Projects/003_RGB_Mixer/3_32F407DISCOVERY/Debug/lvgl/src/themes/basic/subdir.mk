################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/themes/basic/lv_theme_basic.c 

OBJS += \
./lvgl/src/themes/basic/lv_theme_basic.o 

C_DEPS += \
./lvgl/src/themes/basic/lv_theme_basic.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/themes/basic/%.o lvgl/src/themes/basic/%.su lvgl/src/themes/basic/%.cyclo: ../lvgl/src/themes/basic/%.c lvgl/src/themes/basic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/lcd" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/tsc" -I"C:/Users/bhara/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-themes-2f-basic

clean-lvgl-2f-src-2f-themes-2f-basic:
	-$(RM) ./lvgl/src/themes/basic/lv_theme_basic.cyclo ./lvgl/src/themes/basic/lv_theme_basic.d ./lvgl/src/themes/basic/lv_theme_basic.o ./lvgl/src/themes/basic/lv_theme_basic.su

.PHONY: clean-lvgl-2f-src-2f-themes-2f-basic

