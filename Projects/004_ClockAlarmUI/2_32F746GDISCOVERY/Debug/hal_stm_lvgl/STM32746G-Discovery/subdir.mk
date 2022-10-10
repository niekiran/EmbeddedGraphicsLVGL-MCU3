################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery.c \
../hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery_sdram.c \
../hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery_ts.c 

OBJS += \
./hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery.o \
./hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery_sdram.o \
./hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery_ts.o 

C_DEPS += \
./hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery.d \
./hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery_sdram.d \
./hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery_ts.d 


# Each subdirectory must supply rules for building sources it contributes
hal_stm_lvgl/STM32746G-Discovery/%.o hal_stm_lvgl/STM32746G-Discovery/%.su: ../hal_stm_lvgl/STM32746G-Discovery/%.c hal_stm_lvgl/STM32746G-Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/2_32F746GDISCOVERY/hal_stm_lvgl/STM32746G-Discovery" -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/2_32F746GDISCOVERY" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-hal_stm_lvgl-2f-STM32746G-2d-Discovery

clean-hal_stm_lvgl-2f-STM32746G-2d-Discovery:
	-$(RM) ./hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery.d ./hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery.o ./hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery.su ./hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery_sdram.d ./hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery_sdram.o ./hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery_sdram.su ./hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery_ts.d ./hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery_ts.o ./hal_stm_lvgl/STM32746G-Discovery/stm32746g_discovery_ts.su

.PHONY: clean-hal_stm_lvgl-2f-STM32746G-2d-Discovery

