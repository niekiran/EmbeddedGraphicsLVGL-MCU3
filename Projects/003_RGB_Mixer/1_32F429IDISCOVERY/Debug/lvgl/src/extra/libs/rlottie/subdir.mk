################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/extra/libs/rlottie/lv_rlottie.c 

OBJS += \
./lvgl/src/extra/libs/rlottie/lv_rlottie.o 

C_DEPS += \
./lvgl/src/extra/libs/rlottie/lv_rlottie.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/extra/libs/rlottie/%.o lvgl/src/extra/libs/rlottie/%.su: ../lvgl/src/extra/libs/rlottie/%.c lvgl/src/extra/libs/rlottie/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I"D:/fastbit/courses/mcu3/git/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/1_32F429IDISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-extra-2f-libs-2f-rlottie

clean-lvgl-2f-src-2f-extra-2f-libs-2f-rlottie:
	-$(RM) ./lvgl/src/extra/libs/rlottie/lv_rlottie.d ./lvgl/src/extra/libs/rlottie/lv_rlottie.o ./lvgl/src/extra/libs/rlottie/lv_rlottie.su

.PHONY: clean-lvgl-2f-src-2f-extra-2f-libs-2f-rlottie

