################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/widgets/label/lv_label.c 

OBJS += \
./lvgl/src/widgets/label/lv_label.o 

C_DEPS += \
./lvgl/src/widgets/label/lv_label.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/widgets/label/%.o lvgl/src/widgets/label/%.su: ../lvgl/src/widgets/label/%.c lvgl/src/widgets/label/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/1_32F429IDISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-widgets-2f-label

clean-lvgl-2f-src-2f-widgets-2f-label:
	-$(RM) ./lvgl/src/widgets/label/lv_label.d ./lvgl/src/widgets/label/lv_label.o ./lvgl/src/widgets/label/lv_label.su

.PHONY: clean-lvgl-2f-src-2f-widgets-2f-label

