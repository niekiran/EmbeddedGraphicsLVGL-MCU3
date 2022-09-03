################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal_stm_lvgl/XPT2046.c \
../hal_stm_lvgl/bsp_lcd.c \
../hal_stm_lvgl/tft.c \
../hal_stm_lvgl/touchpad.c 

OBJS += \
./hal_stm_lvgl/XPT2046.o \
./hal_stm_lvgl/bsp_lcd.o \
./hal_stm_lvgl/tft.o \
./hal_stm_lvgl/touchpad.o 

C_DEPS += \
./hal_stm_lvgl/XPT2046.d \
./hal_stm_lvgl/bsp_lcd.d \
./hal_stm_lvgl/tft.d \
./hal_stm_lvgl/touchpad.d 


# Each subdirectory must supply rules for building sources it contributes
hal_stm_lvgl/%.o hal_stm_lvgl/%.su: ../hal_stm_lvgl/%.c hal_stm_lvgl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"F:/Workspace/git/EmbeddedGraphics/Projects/002_LVGL_sample/3_32F407DISCOVERY/F407x_LVGL_sample" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-hal_stm_lvgl

clean-hal_stm_lvgl:
	-$(RM) ./hal_stm_lvgl/XPT2046.d ./hal_stm_lvgl/XPT2046.o ./hal_stm_lvgl/XPT2046.su ./hal_stm_lvgl/bsp_lcd.d ./hal_stm_lvgl/bsp_lcd.o ./hal_stm_lvgl/bsp_lcd.su ./hal_stm_lvgl/tft.d ./hal_stm_lvgl/tft.o ./hal_stm_lvgl/tft.su ./hal_stm_lvgl/touchpad.d ./hal_stm_lvgl/touchpad.o ./hal_stm_lvgl/touchpad.su

.PHONY: clean-hal_stm_lvgl

