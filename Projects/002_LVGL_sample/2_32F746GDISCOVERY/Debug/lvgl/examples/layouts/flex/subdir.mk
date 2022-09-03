################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/layouts/flex/lv_example_flex_1.c \
../lvgl/examples/layouts/flex/lv_example_flex_2.c \
../lvgl/examples/layouts/flex/lv_example_flex_3.c \
../lvgl/examples/layouts/flex/lv_example_flex_4.c \
../lvgl/examples/layouts/flex/lv_example_flex_5.c \
../lvgl/examples/layouts/flex/lv_example_flex_6.c 

OBJS += \
./lvgl/examples/layouts/flex/lv_example_flex_1.o \
./lvgl/examples/layouts/flex/lv_example_flex_2.o \
./lvgl/examples/layouts/flex/lv_example_flex_3.o \
./lvgl/examples/layouts/flex/lv_example_flex_4.o \
./lvgl/examples/layouts/flex/lv_example_flex_5.o \
./lvgl/examples/layouts/flex/lv_example_flex_6.o 

C_DEPS += \
./lvgl/examples/layouts/flex/lv_example_flex_1.d \
./lvgl/examples/layouts/flex/lv_example_flex_2.d \
./lvgl/examples/layouts/flex/lv_example_flex_3.d \
./lvgl/examples/layouts/flex/lv_example_flex_4.d \
./lvgl/examples/layouts/flex/lv_example_flex_5.d \
./lvgl/examples/layouts/flex/lv_example_flex_6.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/layouts/flex/%.o lvgl/examples/layouts/flex/%.su: ../lvgl/examples/layouts/flex/%.c lvgl/examples/layouts/flex/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/2_32F746GDISCOVERY/hal_stm_lvgl/Components" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/2_32F746GDISCOVERY/hal_stm_lvgl/STM32746G-Discovery" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/2_32F746GDISCOVERY" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-layouts-2f-flex

clean-lvgl-2f-examples-2f-layouts-2f-flex:
	-$(RM) ./lvgl/examples/layouts/flex/lv_example_flex_1.d ./lvgl/examples/layouts/flex/lv_example_flex_1.o ./lvgl/examples/layouts/flex/lv_example_flex_1.su ./lvgl/examples/layouts/flex/lv_example_flex_2.d ./lvgl/examples/layouts/flex/lv_example_flex_2.o ./lvgl/examples/layouts/flex/lv_example_flex_2.su ./lvgl/examples/layouts/flex/lv_example_flex_3.d ./lvgl/examples/layouts/flex/lv_example_flex_3.o ./lvgl/examples/layouts/flex/lv_example_flex_3.su ./lvgl/examples/layouts/flex/lv_example_flex_4.d ./lvgl/examples/layouts/flex/lv_example_flex_4.o ./lvgl/examples/layouts/flex/lv_example_flex_4.su ./lvgl/examples/layouts/flex/lv_example_flex_5.d ./lvgl/examples/layouts/flex/lv_example_flex_5.o ./lvgl/examples/layouts/flex/lv_example_flex_5.su ./lvgl/examples/layouts/flex/lv_example_flex_6.d ./lvgl/examples/layouts/flex/lv_example_flex_6.o ./lvgl/examples/layouts/flex/lv_example_flex_6.su

.PHONY: clean-lvgl-2f-examples-2f-layouts-2f-flex

