################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/gd32_ipa/lv_gpu_gd32_ipa.c 

OBJS += \
./lvgl/src/draw/gd32_ipa/lv_gpu_gd32_ipa.o 

C_DEPS += \
./lvgl/src/draw/gd32_ipa/lv_gpu_gd32_ipa.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/gd32_ipa/%.o lvgl/src/draw/gd32_ipa/%.su: ../lvgl/src/draw/gd32_ipa/%.c lvgl/src/draw/gd32_ipa/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY" -I../Core/Inc -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/lcd" -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/tsc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-draw-2f-gd32_ipa

clean-lvgl-2f-src-2f-draw-2f-gd32_ipa:
	-$(RM) ./lvgl/src/draw/gd32_ipa/lv_gpu_gd32_ipa.d ./lvgl/src/draw/gd32_ipa/lv_gpu_gd32_ipa.o ./lvgl/src/draw/gd32_ipa/lv_gpu_gd32_ipa.su

.PHONY: clean-lvgl-2f-src-2f-draw-2f-gd32_ipa

