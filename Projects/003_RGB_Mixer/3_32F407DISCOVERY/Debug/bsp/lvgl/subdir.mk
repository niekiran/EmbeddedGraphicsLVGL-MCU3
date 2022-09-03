################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/Workspace/git/EmbeddedGraphics/Projects/bsp/lvgl/tft.c \
F:/Workspace/git/EmbeddedGraphics/Projects/bsp/lvgl/touchpad.c 

OBJS += \
./bsp/lvgl/tft.o \
./bsp/lvgl/touchpad.o 

C_DEPS += \
./bsp/lvgl/tft.d \
./bsp/lvgl/touchpad.d 


# Each subdirectory must supply rules for building sources it contributes
bsp/lvgl/tft.o: F:/Workspace/git/EmbeddedGraphics/Projects/bsp/lvgl/tft.c bsp/lvgl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"F:/Workspace/git/EmbeddedGraphics/Projects/bsp/lcd" -I"F:/Workspace/git/EmbeddedGraphics/Projects/bsp/tsc" -I"F:/Workspace/git/EmbeddedGraphics/Projects/bsp/lvgl" -I"F:/Workspace/git/EmbeddedGraphics/Projects/003_RGB_Mixer/3_32F407DISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
bsp/lvgl/touchpad.o: F:/Workspace/git/EmbeddedGraphics/Projects/bsp/lvgl/touchpad.c bsp/lvgl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"F:/Workspace/git/EmbeddedGraphics/Projects/bsp/lcd" -I"F:/Workspace/git/EmbeddedGraphics/Projects/bsp/tsc" -I"F:/Workspace/git/EmbeddedGraphics/Projects/bsp/lvgl" -I"F:/Workspace/git/EmbeddedGraphics/Projects/003_RGB_Mixer/3_32F407DISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-bsp-2f-lvgl

clean-bsp-2f-lvgl:
	-$(RM) ./bsp/lvgl/tft.d ./bsp/lvgl/tft.o ./bsp/lvgl/tft.su ./bsp/lvgl/touchpad.d ./bsp/lvgl/touchpad.o ./bsp/lvgl/touchpad.su

.PHONY: clean-bsp-2f-lvgl

