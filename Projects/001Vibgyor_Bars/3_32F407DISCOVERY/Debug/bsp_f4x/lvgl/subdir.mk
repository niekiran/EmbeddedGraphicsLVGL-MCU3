################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bsp_f4x/lvgl/tft.c \
../bsp_f4x/lvgl/touchpad.c 

OBJS += \
./bsp_f4x/lvgl/tft.o \
./bsp_f4x/lvgl/touchpad.o 

C_DEPS += \
./bsp_f4x/lvgl/tft.d \
./bsp_f4x/lvgl/touchpad.d 


# Each subdirectory must supply rules for building sources it contributes
bsp_f4x/lvgl/%.o bsp_f4x/lvgl/%.su: ../bsp_f4x/lvgl/%.c bsp_f4x/lvgl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/001Vibgyor_Bars/3_32F407DISCOVERY/bsp_f4x/lcd" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/001Vibgyor_Bars/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/001Vibgyor_Bars/3_32F407DISCOVERY/bsp_f4x/tsc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-bsp_f4x-2f-lvgl

clean-bsp_f4x-2f-lvgl:
	-$(RM) ./bsp_f4x/lvgl/tft.d ./bsp_f4x/lvgl/tft.o ./bsp_f4x/lvgl/tft.su ./bsp_f4x/lvgl/touchpad.d ./bsp_f4x/lvgl/touchpad.o ./bsp_f4x/lvgl/touchpad.su

.PHONY: clean-bsp_f4x-2f-lvgl

