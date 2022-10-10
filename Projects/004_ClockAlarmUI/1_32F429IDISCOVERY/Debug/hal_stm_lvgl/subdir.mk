################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal_stm_lvgl/stm32f429i_discovery.c 

OBJS += \
./hal_stm_lvgl/stm32f429i_discovery.o 

C_DEPS += \
./hal_stm_lvgl/stm32f429i_discovery.d 


# Each subdirectory must supply rules for building sources it contributes
hal_stm_lvgl/%.o hal_stm_lvgl/%.su: ../hal_stm_lvgl/%.c hal_stm_lvgl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/1_32F429IDISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-hal_stm_lvgl

clean-hal_stm_lvgl:
	-$(RM) ./hal_stm_lvgl/stm32f429i_discovery.d ./hal_stm_lvgl/stm32f429i_discovery.o ./hal_stm_lvgl/stm32f429i_discovery.su

.PHONY: clean-hal_stm_lvgl

