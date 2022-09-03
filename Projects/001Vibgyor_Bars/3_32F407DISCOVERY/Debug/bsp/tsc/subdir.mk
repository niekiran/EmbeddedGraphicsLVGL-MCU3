################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/Workspace/git/EmbeddedGraphics/Projects/bsp/tsc/XPT2046.c 

OBJS += \
./bsp/tsc/XPT2046.o 

C_DEPS += \
./bsp/tsc/XPT2046.d 


# Each subdirectory must supply rules for building sources it contributes
bsp/tsc/XPT2046.o: F:/Workspace/git/EmbeddedGraphics/Projects/bsp/tsc/XPT2046.c bsp/tsc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-bsp-2f-tsc

clean-bsp-2f-tsc:
	-$(RM) ./bsp/tsc/XPT2046.d ./bsp/tsc/XPT2046.o ./bsp/tsc/XPT2046.su

.PHONY: clean-bsp-2f-tsc

