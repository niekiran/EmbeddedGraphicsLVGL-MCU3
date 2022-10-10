################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.c \
../lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.c \
../lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.c 

OBJS += \
./lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.o \
./lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.o \
./lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.o 

C_DEPS += \
./lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.d \
./lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.d \
./lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/nxp/pxp/%.o lvgl/src/draw/nxp/pxp/%.su: ../lvgl/src/draw/nxp/pxp/%.c lvgl/src/draw/nxp/pxp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY" -I../Core/Inc -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/lcd" -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/tsc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp

clean-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp:
	-$(RM) ./lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.d ./lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.o ./lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.su ./lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.d ./lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.o ./lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.su ./lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.d ./lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.o ./lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.su

.PHONY: clean-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp

