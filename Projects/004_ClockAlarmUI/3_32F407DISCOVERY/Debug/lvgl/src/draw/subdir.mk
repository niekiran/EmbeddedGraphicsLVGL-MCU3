################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/lv_draw.c \
../lvgl/src/draw/lv_draw_arc.c \
../lvgl/src/draw/lv_draw_img.c \
../lvgl/src/draw/lv_draw_label.c \
../lvgl/src/draw/lv_draw_layer.c \
../lvgl/src/draw/lv_draw_line.c \
../lvgl/src/draw/lv_draw_mask.c \
../lvgl/src/draw/lv_draw_rect.c \
../lvgl/src/draw/lv_draw_transform.c \
../lvgl/src/draw/lv_draw_triangle.c \
../lvgl/src/draw/lv_img_buf.c \
../lvgl/src/draw/lv_img_cache.c \
../lvgl/src/draw/lv_img_decoder.c 

OBJS += \
./lvgl/src/draw/lv_draw.o \
./lvgl/src/draw/lv_draw_arc.o \
./lvgl/src/draw/lv_draw_img.o \
./lvgl/src/draw/lv_draw_label.o \
./lvgl/src/draw/lv_draw_layer.o \
./lvgl/src/draw/lv_draw_line.o \
./lvgl/src/draw/lv_draw_mask.o \
./lvgl/src/draw/lv_draw_rect.o \
./lvgl/src/draw/lv_draw_transform.o \
./lvgl/src/draw/lv_draw_triangle.o \
./lvgl/src/draw/lv_img_buf.o \
./lvgl/src/draw/lv_img_cache.o \
./lvgl/src/draw/lv_img_decoder.o 

C_DEPS += \
./lvgl/src/draw/lv_draw.d \
./lvgl/src/draw/lv_draw_arc.d \
./lvgl/src/draw/lv_draw_img.d \
./lvgl/src/draw/lv_draw_label.d \
./lvgl/src/draw/lv_draw_layer.d \
./lvgl/src/draw/lv_draw_line.d \
./lvgl/src/draw/lv_draw_mask.d \
./lvgl/src/draw/lv_draw_rect.d \
./lvgl/src/draw/lv_draw_transform.d \
./lvgl/src/draw/lv_draw_triangle.d \
./lvgl/src/draw/lv_img_buf.d \
./lvgl/src/draw/lv_img_cache.d \
./lvgl/src/draw/lv_img_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/%.o lvgl/src/draw/%.su: ../lvgl/src/draw/%.c lvgl/src/draw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY" -I../Core/Inc -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/lcd" -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/lvgl" -I"F:/Workspace/git/EmbeddedGraphicsLVGL-MCU3-main/Projects/004ClockAlarmUI/3_32F407DISCOVERY/bsp_f4x/tsc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-draw

clean-lvgl-2f-src-2f-draw:
	-$(RM) ./lvgl/src/draw/lv_draw.d ./lvgl/src/draw/lv_draw.o ./lvgl/src/draw/lv_draw.su ./lvgl/src/draw/lv_draw_arc.d ./lvgl/src/draw/lv_draw_arc.o ./lvgl/src/draw/lv_draw_arc.su ./lvgl/src/draw/lv_draw_img.d ./lvgl/src/draw/lv_draw_img.o ./lvgl/src/draw/lv_draw_img.su ./lvgl/src/draw/lv_draw_label.d ./lvgl/src/draw/lv_draw_label.o ./lvgl/src/draw/lv_draw_label.su ./lvgl/src/draw/lv_draw_layer.d ./lvgl/src/draw/lv_draw_layer.o ./lvgl/src/draw/lv_draw_layer.su ./lvgl/src/draw/lv_draw_line.d ./lvgl/src/draw/lv_draw_line.o ./lvgl/src/draw/lv_draw_line.su ./lvgl/src/draw/lv_draw_mask.d ./lvgl/src/draw/lv_draw_mask.o ./lvgl/src/draw/lv_draw_mask.su ./lvgl/src/draw/lv_draw_rect.d ./lvgl/src/draw/lv_draw_rect.o ./lvgl/src/draw/lv_draw_rect.su ./lvgl/src/draw/lv_draw_transform.d ./lvgl/src/draw/lv_draw_transform.o ./lvgl/src/draw/lv_draw_transform.su ./lvgl/src/draw/lv_draw_triangle.d ./lvgl/src/draw/lv_draw_triangle.o ./lvgl/src/draw/lv_draw_triangle.su ./lvgl/src/draw/lv_img_buf.d ./lvgl/src/draw/lv_img_buf.o ./lvgl/src/draw/lv_img_buf.su ./lvgl/src/draw/lv_img_cache.d ./lvgl/src/draw/lv_img_cache.o ./lvgl/src/draw/lv_img_cache.su ./lvgl/src/draw/lv_img_decoder.d ./lvgl/src/draw/lv_img_decoder.o ./lvgl/src/draw/lv_img_decoder.su

.PHONY: clean-lvgl-2f-src-2f-draw

