################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/gpu/lv_gpu_nxp_pxp.c \
../lvgl/src/gpu/lv_gpu_nxp_pxp_osa.c \
../lvgl/src/gpu/lv_gpu_nxp_vglite.c \
../lvgl/src/gpu/lv_gpu_stm32_dma2d.c 

OBJS += \
./lvgl/src/gpu/lv_gpu_nxp_pxp.o \
./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.o \
./lvgl/src/gpu/lv_gpu_nxp_vglite.o \
./lvgl/src/gpu/lv_gpu_stm32_dma2d.o 

C_DEPS += \
./lvgl/src/gpu/lv_gpu_nxp_pxp.d \
./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.d \
./lvgl/src/gpu/lv_gpu_nxp_vglite.d \
./lvgl/src/gpu/lv_gpu_stm32_dma2d.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/gpu/%.o lvgl/src/gpu/%.su: ../lvgl/src/gpu/%.c lvgl/src/gpu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I"F:/Workspace/my_work/002_LVGL_sample" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-gpu

clean-lvgl-2f-src-2f-gpu:
	-$(RM) ./lvgl/src/gpu/lv_gpu_nxp_pxp.d ./lvgl/src/gpu/lv_gpu_nxp_pxp.o ./lvgl/src/gpu/lv_gpu_nxp_pxp.su ./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.d ./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.o ./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.su ./lvgl/src/gpu/lv_gpu_nxp_vglite.d ./lvgl/src/gpu/lv_gpu_nxp_vglite.o ./lvgl/src/gpu/lv_gpu_nxp_vglite.su ./lvgl/src/gpu/lv_gpu_stm32_dma2d.d ./lvgl/src/gpu/lv_gpu_stm32_dma2d.o ./lvgl/src/gpu/lv_gpu_stm32_dma2d.su

.PHONY: clean-lvgl-2f-src-2f-gpu

