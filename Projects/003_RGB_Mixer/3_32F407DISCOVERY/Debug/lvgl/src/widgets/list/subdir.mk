################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/widgets/list/lv_list.c 

OBJS += \
./lvgl/src/widgets/list/lv_list.o 

C_DEPS += \
./lvgl/src/widgets/list/lv_list.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/widgets/list/%.o lvgl/src/widgets/list/%.su: ../lvgl/src/widgets/list/%.c lvgl/src/widgets/list/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/lcd" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/tsc" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-widgets-2f-list

clean-lvgl-2f-src-2f-widgets-2f-list:
	-$(RM) ./lvgl/src/widgets/list/lv_list.d ./lvgl/src/widgets/list/lv_list.o ./lvgl/src/widgets/list/lv_list.su

.PHONY: clean-lvgl-2f-src-2f-widgets-2f-list

