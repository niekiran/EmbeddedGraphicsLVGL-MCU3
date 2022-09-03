################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/libs/rlottie/lv_example_rlottie_1.c \
../lvgl/examples/libs/rlottie/lv_example_rlottie_2.c \
../lvgl/examples/libs/rlottie/lv_example_rlottie_approve.c 

OBJS += \
./lvgl/examples/libs/rlottie/lv_example_rlottie_1.o \
./lvgl/examples/libs/rlottie/lv_example_rlottie_2.o \
./lvgl/examples/libs/rlottie/lv_example_rlottie_approve.o 

C_DEPS += \
./lvgl/examples/libs/rlottie/lv_example_rlottie_1.d \
./lvgl/examples/libs/rlottie/lv_example_rlottie_2.d \
./lvgl/examples/libs/rlottie/lv_example_rlottie_approve.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/libs/rlottie/%.o lvgl/examples/libs/rlottie/%.su: ../lvgl/examples/libs/rlottie/%.c lvgl/examples/libs/rlottie/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY/bsp_f4x/lcd" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY/bsp_f4x/tsc" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/002_LVGL_sample/3_32F407DISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-libs-2f-rlottie

clean-lvgl-2f-examples-2f-libs-2f-rlottie:
	-$(RM) ./lvgl/examples/libs/rlottie/lv_example_rlottie_1.d ./lvgl/examples/libs/rlottie/lv_example_rlottie_1.o ./lvgl/examples/libs/rlottie/lv_example_rlottie_1.su ./lvgl/examples/libs/rlottie/lv_example_rlottie_2.d ./lvgl/examples/libs/rlottie/lv_example_rlottie_2.o ./lvgl/examples/libs/rlottie/lv_example_rlottie_2.su ./lvgl/examples/libs/rlottie/lv_example_rlottie_approve.d ./lvgl/examples/libs/rlottie/lv_example_rlottie_approve.o ./lvgl/examples/libs/rlottie/lv_example_rlottie_approve.su

.PHONY: clean-lvgl-2f-examples-2f-libs-2f-rlottie

