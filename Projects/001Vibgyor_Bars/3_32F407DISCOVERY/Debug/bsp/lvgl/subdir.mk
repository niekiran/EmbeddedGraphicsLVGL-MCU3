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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
bsp/lvgl/touchpad.o: F:/Workspace/git/EmbeddedGraphics/Projects/bsp/lvgl/touchpad.c bsp/lvgl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-bsp-2f-lvgl

clean-bsp-2f-lvgl:
	-$(RM) ./bsp/lvgl/tft.d ./bsp/lvgl/tft.o ./bsp/lvgl/tft.su ./bsp/lvgl/touchpad.d ./bsp/lvgl/touchpad.o ./bsp/lvgl/touchpad.su

.PHONY: clean-bsp-2f-lvgl

