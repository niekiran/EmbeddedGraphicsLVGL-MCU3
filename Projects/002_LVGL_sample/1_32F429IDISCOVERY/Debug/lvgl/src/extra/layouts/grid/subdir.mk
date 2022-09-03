################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/extra/layouts/grid/lv_grid.c 

OBJS += \
./lvgl/src/extra/layouts/grid/lv_grid.o 

C_DEPS += \
./lvgl/src/extra/layouts/grid/lv_grid.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/extra/layouts/grid/%.o lvgl/src/extra/layouts/grid/%.su: ../lvgl/src/extra/layouts/grid/%.c lvgl/src/extra/layouts/grid/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/1_32F429IDISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-extra-2f-layouts-2f-grid

clean-lvgl-2f-src-2f-extra-2f-layouts-2f-grid:
	-$(RM) ./lvgl/src/extra/layouts/grid/lv_grid.d ./lvgl/src/extra/layouts/grid/lv_grid.o ./lvgl/src/extra/layouts/grid/lv_grid.su

.PHONY: clean-lvgl-2f-src-2f-extra-2f-layouts-2f-grid

