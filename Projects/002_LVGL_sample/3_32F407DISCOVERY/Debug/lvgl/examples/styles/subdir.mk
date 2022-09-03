################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/styles/lv_example_style_1.c \
../lvgl/examples/styles/lv_example_style_10.c \
../lvgl/examples/styles/lv_example_style_11.c \
../lvgl/examples/styles/lv_example_style_12.c \
../lvgl/examples/styles/lv_example_style_13.c \
../lvgl/examples/styles/lv_example_style_14.c \
../lvgl/examples/styles/lv_example_style_15.c \
../lvgl/examples/styles/lv_example_style_2.c \
../lvgl/examples/styles/lv_example_style_3.c \
../lvgl/examples/styles/lv_example_style_4.c \
../lvgl/examples/styles/lv_example_style_5.c \
../lvgl/examples/styles/lv_example_style_6.c \
../lvgl/examples/styles/lv_example_style_7.c \
../lvgl/examples/styles/lv_example_style_8.c \
../lvgl/examples/styles/lv_example_style_9.c 

OBJS += \
./lvgl/examples/styles/lv_example_style_1.o \
./lvgl/examples/styles/lv_example_style_10.o \
./lvgl/examples/styles/lv_example_style_11.o \
./lvgl/examples/styles/lv_example_style_12.o \
./lvgl/examples/styles/lv_example_style_13.o \
./lvgl/examples/styles/lv_example_style_14.o \
./lvgl/examples/styles/lv_example_style_15.o \
./lvgl/examples/styles/lv_example_style_2.o \
./lvgl/examples/styles/lv_example_style_3.o \
./lvgl/examples/styles/lv_example_style_4.o \
./lvgl/examples/styles/lv_example_style_5.o \
./lvgl/examples/styles/lv_example_style_6.o \
./lvgl/examples/styles/lv_example_style_7.o \
./lvgl/examples/styles/lv_example_style_8.o \
./lvgl/examples/styles/lv_example_style_9.o 

C_DEPS += \
./lvgl/examples/styles/lv_example_style_1.d \
./lvgl/examples/styles/lv_example_style_10.d \
./lvgl/examples/styles/lv_example_style_11.d \
./lvgl/examples/styles/lv_example_style_12.d \
./lvgl/examples/styles/lv_example_style_13.d \
./lvgl/examples/styles/lv_example_style_14.d \
./lvgl/examples/styles/lv_example_style_15.d \
./lvgl/examples/styles/lv_example_style_2.d \
./lvgl/examples/styles/lv_example_style_3.d \
./lvgl/examples/styles/lv_example_style_4.d \
./lvgl/examples/styles/lv_example_style_5.d \
./lvgl/examples/styles/lv_example_style_6.d \
./lvgl/examples/styles/lv_example_style_7.d \
./lvgl/examples/styles/lv_example_style_8.d \
./lvgl/examples/styles/lv_example_style_9.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/styles/%.o lvgl/examples/styles/%.su: ../lvgl/examples/styles/%.c lvgl/examples/styles/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY/bsp_f4x/lcd" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY/bsp_f4x/tsc" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-styles

clean-lvgl-2f-examples-2f-styles:
	-$(RM) ./lvgl/examples/styles/lv_example_style_1.d ./lvgl/examples/styles/lv_example_style_1.o ./lvgl/examples/styles/lv_example_style_1.su ./lvgl/examples/styles/lv_example_style_10.d ./lvgl/examples/styles/lv_example_style_10.o ./lvgl/examples/styles/lv_example_style_10.su ./lvgl/examples/styles/lv_example_style_11.d ./lvgl/examples/styles/lv_example_style_11.o ./lvgl/examples/styles/lv_example_style_11.su ./lvgl/examples/styles/lv_example_style_12.d ./lvgl/examples/styles/lv_example_style_12.o ./lvgl/examples/styles/lv_example_style_12.su ./lvgl/examples/styles/lv_example_style_13.d ./lvgl/examples/styles/lv_example_style_13.o ./lvgl/examples/styles/lv_example_style_13.su ./lvgl/examples/styles/lv_example_style_14.d ./lvgl/examples/styles/lv_example_style_14.o ./lvgl/examples/styles/lv_example_style_14.su ./lvgl/examples/styles/lv_example_style_15.d ./lvgl/examples/styles/lv_example_style_15.o ./lvgl/examples/styles/lv_example_style_15.su ./lvgl/examples/styles/lv_example_style_2.d ./lvgl/examples/styles/lv_example_style_2.o ./lvgl/examples/styles/lv_example_style_2.su ./lvgl/examples/styles/lv_example_style_3.d ./lvgl/examples/styles/lv_example_style_3.o ./lvgl/examples/styles/lv_example_style_3.su ./lvgl/examples/styles/lv_example_style_4.d ./lvgl/examples/styles/lv_example_style_4.o ./lvgl/examples/styles/lv_example_style_4.su ./lvgl/examples/styles/lv_example_style_5.d ./lvgl/examples/styles/lv_example_style_5.o ./lvgl/examples/styles/lv_example_style_5.su ./lvgl/examples/styles/lv_example_style_6.d ./lvgl/examples/styles/lv_example_style_6.o ./lvgl/examples/styles/lv_example_style_6.su ./lvgl/examples/styles/lv_example_style_7.d ./lvgl/examples/styles/lv_example_style_7.o ./lvgl/examples/styles/lv_example_style_7.su ./lvgl/examples/styles/lv_example_style_8.d ./lvgl/examples/styles/lv_example_style_8.o ./lvgl/examples/styles/lv_example_style_8.su ./lvgl/examples/styles/lv_example_style_9.d ./lvgl/examples/styles/lv_example_style_9.o ./lvgl/examples/styles/lv_example_style_9.su

.PHONY: clean-lvgl-2f-examples-2f-styles

