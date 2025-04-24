################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/swm341_dma2d/lv_gpu_swm341_dma2d.c 

OBJS += \
./lvgl/src/draw/swm341_dma2d/lv_gpu_swm341_dma2d.o 

C_DEPS += \
./lvgl/src/draw/swm341_dma2d/lv_gpu_swm341_dma2d.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/swm341_dma2d/%.o lvgl/src/draw/swm341_dma2d/%.su lvgl/src/draw/swm341_dma2d/%.cyclo: ../lvgl/src/draw/swm341_dma2d/%.c lvgl/src/draw/swm341_dma2d/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"C:/Users/shrey/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/lcd" -I"C:/Users/shrey/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"C:/Users/shrey/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY/bsp_f4x/tsc" -I"C:/Users/shrey/STM32CubeIDE/EmbeddedGraphicsLVGL-MCU3/Projects/003_RGB_Mixer/3_32F407DISCOVERY" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-draw-2f-swm341_dma2d

clean-lvgl-2f-src-2f-draw-2f-swm341_dma2d:
	-$(RM) ./lvgl/src/draw/swm341_dma2d/lv_gpu_swm341_dma2d.cyclo ./lvgl/src/draw/swm341_dma2d/lv_gpu_swm341_dma2d.d ./lvgl/src/draw/swm341_dma2d/lv_gpu_swm341_dma2d.o ./lvgl/src/draw/swm341_dma2d/lv_gpu_swm341_dma2d.su

.PHONY: clean-lvgl-2f-src-2f-draw-2f-swm341_dma2d

